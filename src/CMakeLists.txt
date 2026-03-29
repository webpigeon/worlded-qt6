cmake_minimum_required( VERSION 3.10 )
set ( CMAKE_BUILD_TYPE Release )

#add_definitions ( -Wall )
find_package ( Qt6 REQUIRED )
include_directories (
	${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
	)


add_subdirectory( lua )
add_subdirectory( tolua )

add_subdirectory( config )
add_subdirectory( libtiled )
add_subdirectory( worlded )
add_subdirectory( tiled )
add_subdirectory( plugins )
add_subdirectory( tmxviewer )
add_subdirectory( automappingconverter )
