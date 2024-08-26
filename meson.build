project(
	'luau',
	'cpp',
	license: 'MIT',
	meson_version: '>=0.52.0',
	default_options: [
		'cpp_std=c++17',
		'c_std=c11',
		'warning_level=2',
		'werror=true',
	],
)

# arguments
common_args = [
	'-Wno-implicit-fallthrough',
	'-Wno-unused-variable',
	'-Wno-unused-parameter',
	'-Wno-missing-field-initializers',
]

inc = include_directories(
	'VM/include',
	'Ast/include',
	'Compiler/include',
	'Common/include',
)

src = files(
	'Ast/src/Ast.cpp',
	'Ast/src/Confusables.cpp',
	'Ast/src/Lexer.cpp',
	'Ast/src/Location.cpp',
	'Ast/src/Parser.cpp',
	'Ast/src/StringUtils.cpp',
	'Ast/src/TimeTrace.cpp',

	'VM/src/lapi.cpp',
	'VM/src/laux.cpp',
	'VM/src/lbaselib.cpp',
	'VM/src/lbitlib.cpp',
	'VM/src/lbuffer.cpp',
	'VM/src/lbuflib.cpp',
	'VM/src/lbuiltins.cpp',
	'VM/src/lcorolib.cpp',
	'VM/src/ldblib.cpp',
	'VM/src/ldebug.cpp',
	'VM/src/ldo.cpp',
	'VM/src/lfunc.cpp',
	'VM/src/lgc.cpp',
	'VM/src/lgcdebug.cpp',
	'VM/src/linit.cpp',
	'VM/src/lmathlib.cpp',
	'VM/src/lmem.cpp',
	'VM/src/lnumprint.cpp',
	'VM/src/lobject.cpp',
	'VM/src/loslib.cpp',
	'VM/src/lperf.cpp',
	'VM/src/lstate.cpp',
	'VM/src/lstring.cpp',
	'VM/src/lstrlib.cpp',
	'VM/src/ltable.cpp',
	'VM/src/ltablib.cpp',
	'VM/src/ltm.cpp',
	'VM/src/ludata.cpp',
	'VM/src/lutf8lib.cpp',
	'VM/src/lvmexecute.cpp',
	'VM/src/lvmload.cpp',
	'VM/src/lvmutils.cpp',

	'Compiler/src/BuiltinFolding.cpp',
	'Compiler/src/Builtins.cpp',
	'Compiler/src/BytecodeBuilder.cpp',
	'Compiler/src/Compiler.cpp',
	'Compiler/src/ConstantFolding.cpp',
	'Compiler/src/CostModel.cpp',
	'Compiler/src/TableShape.cpp',
	'Compiler/src/Types.cpp',
	'Compiler/src/ValueTracking.cpp',
	'Compiler/src/lcode.cpp',
)

lib_luau = library('luau', src,
	include_directories: inc,
	cpp_args: common_args)

dep_luau = declare_dependency(
	link_with: lib_luau,
	dependencies: [],
	include_directories: inc)

sample = executable('sample', 'sample.cpp',
	dependencies: [dep_luau])
