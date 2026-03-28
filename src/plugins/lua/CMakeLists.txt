cmake_minimum_required( VERSION 3.16 )
set ( CMAKE_BUILD_TYPE Release )
#add_definitions ( -Wall )
find_package ( Qt6 REQUIRED COMPONENTS Core Gui Widgets )
set ( lua_HDRS
	lua_global.h
	luatablewriter.h
	)

set ( lua_SRCS
	luaplugin.cpp
	luatablewriter.cpp
	)

set ( lua_MOCS
	luaplugin.h
	)

qt_add_library ( luaplugin SHARED
    luaplugin.cpp
    luatablewriter.cpp
    luaplugin.h
    lua_global.h
    luatablewriter.h
)

target_compile_definitions(luaplugin PRIVATE LUA_LIBRARY )

target_link_libraries ( luaplugin PRIVATE libtiled Qt6::Core Qt6::Gui )
target_include_directories ( luaplugin PRIVATE ${CMAKE_SOURCE_DIR} )

INSTALL(TARGETS luaplugin
    RUNTIME DESTINATION plugins/tiled 
    LIBRARY DESTINATION plugins/tiled
)
