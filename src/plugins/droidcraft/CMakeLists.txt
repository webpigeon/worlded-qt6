cmake_minimum_required( VERSION 3.10 )
set ( CMAKE_BUILD_TYPE Release )
#add_definitions ( -Wall )
add_definitions(-DDROIDCRAFT_LIBRARY ${QT_DEFINITIONS} -DQT_PLUGIN -DQT_SHARED)
find_package ( Qt6 REQUIRED )

include_directories (
	${CMAKE_CURRENT_SOURCE_DIR}/../../tiled
	${CMAKE_CURRENT_SOURCE_DIR}/../../libtiled
	${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
	${QT_QTCORE_INCLUDE_DIR} ${QT_QTGUI_INCLUDE_DIR}
	)
set ( droidcraft_HDRS
	droidcraft_global.h
	)

set ( droidcraft_SRCS
	droidcraftplugin.cpp
	)

set ( droidcraft_RSCS
	droidcraft.qrc
	)

qt_add_resources(RSCS ${droidcraft_RSCS})

set ( droidcraft_MOCS
	droidcraftplugin.h
	)
qt_add_resources(MOCS ${droidcraft_MOCS})

add_library ( droidcraft SHARED ${droidcraft_SRCS} ${UIS} ${RSCS} ${TRS} ${MOCS} )
target_link_libraries ( droidcraft libtiled ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} )

INSTALL(TARGETS droidcraft RUNTIME DESTINATION plugins/tiled LIBRARY DESTINATION plugins/tiled)
