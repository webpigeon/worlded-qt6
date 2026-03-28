cmake_minimum_required( VERSION 3.10)
set ( CMAKE_BUILD_TYPE Release )
#add_definitions ( -Wall )
add_definitions(-DTENGINE_LIBRARY ${QT_DEFINITIONS} -DQT_PLUGIN -DQT_SHARED)
find_package ( Qt6 REQUIRED )
include_directories (
	${CMAKE_CURRENT_SOURCE_DIR}/../../tiled
	${CMAKE_CURRENT_SOURCE_DIR}/../../libtiled
	${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
	${QT_QTCORE_INCLUDE_DIR} ${QT_QTGUI_INCLUDE_DIR}
	)
set ( tengine_HDRS
	tengine_global.h
	)

set ( tengine_SRCS
	tengineplugin.cpp
	)

set ( tengine_MOCS
	tengineplugin.h
	)
qt_wrap_cpp(MOCS ${tengine_MOCS})

add_library ( tengine SHARED ${tengine_SRCS} ${UIS} ${RSCS} ${TRS} ${MOCS} )
target_link_libraries ( tengine libtiled ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} )

INSTALL(TARGETS tengine RUNTIME DESTINATION plugins/tiled LIBRARY DESTINATION plugins/tiled)
