cmake_minimum_required( VERSION 3.10 )
set ( CMAKE_BUILD_TYPE Release )
#add_definitions ( -Wall )
add_definitions(-DTMW_LIBRARY ${QT_DEFINITIONS} -DQT_PLUGIN -DQT_SHARED)
find_package ( Qt6 REQUIRED )
include_directories (
	${CMAKE_CURRENT_SOURCE_DIR}/../../tiled
	${CMAKE_CURRENT_SOURCE_DIR}/../../libtiled
	${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
	${QT_QTCORE_INCLUDE_DIR} ${QT_QTGUI_INCLUDE_DIR}
	)
set ( tmw_HDRS
	tmw_global.h
	)

set ( tmw_SRCS
	tmwplugin.cpp
	)

set ( tmw_MOCS
	tmwplugin.h
	)
qt_wrap_cpp(MOCS ${tmw_MOCS})

add_library ( tmw SHARED ${tmw_SRCS} ${UIS} ${RSCS} ${TRS} ${MOCS} )
target_link_libraries ( tmw libtiled ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} )

INSTALL(TARGETS tmw RUNTIME DESTINATION plugins/tiled LIBRARY DESTINATION plugins/tiled)
