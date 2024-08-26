#include "luacode.h"
#include "lua.h"
#include "lualib.h"
#include <cstring>
#include <cstdlib>
#include <cstdio>

const auto source = R"LUA(
	print("hello world from lua")
	coroutine.yield(7)

	print("second")
	local table = {a = 7, b = 8}
	coroutine.yield(table)
)LUA";

int main() {
	auto L = luaL_newstate();
	luaL_openlibs(L);

	// needs lua.h and luacode.h
	size_t bytecodeSize = 0;
	char* bytecode = luau_compile(source, std::strlen(source), NULL, &bytecodeSize);
	int result = luau_load(L, "=test", bytecode, bytecodeSize, 0);
	std::free(bytecode);

	if(result != 0) {
		const char* str = lua_tostring(L, -1);
		std::printf("error compiling: error %s\n", str ? str : "<null>");
		return 1;
	}

	// first run
	result = lua_resume(L, nullptr, 0);

	if(result != LUA_OK && result != LUA_YIELD) {
		const char* str = lua_tostring(L, -1);
		std::printf("error running: error %s\n", str ? str : "<null>");
		std::printf("stacktrace: %s\n", lua_debugtrace(L));
		return 1;
	}

	double val = luaL_checknumber(L, 1);
	lua_pop(L, 1);
	std::printf("val: %f\n", val);

	// second run
	result = lua_resume(L, nullptr, 0);

	if(result != LUA_OK && result != LUA_YIELD) {
		const char* str = lua_tostring(L, -1);
		std::printf("error running: error %s\n", str ? str : "<null>");
		std::printf("stacktrace: %s\n", lua_debugtrace(L));
		return 1;
	}

	luaL_checktype(L, 1, LUA_TTABLE);

	lua_getfield(L, 1, "a");
	lua_getfield(L, 1, "b");

	double valA = luaL_checknumber(L, 2);
	double valB = luaL_checknumber(L, 3);
	std::printf("valA: %f, valB: %f\n", valA, valB);

	lua_close(L);
	return 0;
}
