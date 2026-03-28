cmake_minimum_required( VERSION 3.16 )

project(libtiled LANGUAGES CXX)
set ( CMAKE_BUILD_TYPE Release )
#add_definitions ( -Wall )

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

qt_standard_project_setup()

include_directories (
	${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
	../zlib)

set ( tiled_HDRS
	compression.h
	imagelayer.h
	isometricrenderer.h
	layer.h
	map.h
	mapobject.h
	mapreader.h
	maprenderer.h
	mapwriter.h
	object.h
	objectgroup.h
	orthogonalrenderer.h
	properties.h
	staggeredrenderer.h
	tile.h
	tiled_global.h
	tilelayer.h
	tileset.h
	gidmapper.h

	zlevelrenderer.h
	ztilelayergroup.h
	)

set ( tiled_SRCS
	compression.cpp
	imagelayer.cpp
	isometricrenderer.cpp
	layer.cpp
	map.cpp
	mapobject.cpp
	mapreader.cpp
	maprenderer.cpp
	mapwriter.cpp
	objectgroup.cpp
	orthogonalrenderer.cpp
	properties.cpp
	staggeredrenderer.cpp
	tilelayer.cpp
    tile.cpp
	tileset.cpp
	gidmapper.cpp

	zlevelrenderer.cpp
	ztilelayergroup.cpp
	)

add_library ( libtiled SHARED ${tiled_SRCS} ${tiled_HDRS} )
target_link_libraries ( libtiled  Qt6::Core Qt6::Widgets qtlockedfile )
target_include_directories(libtiled PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )
target_compile_definitions(libtiled PRIVATE TILED_LIBRARY)

INSTALL(TARGETS libtiled RUNTIME DESTINATION "." LIBRARY DESTINATION ".")
