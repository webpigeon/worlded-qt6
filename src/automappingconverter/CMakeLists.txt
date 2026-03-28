project( automappingconverter )
cmake_minimum_required( VERSION 3.10 )
set ( CMAKE_BUILD_TYPE Release )
#add_definitions ( -Wall )

find_package ( Qt6 REQUIRED )
qt_standard_project_setup()

include_directories (
	${CMAKE_CURRENT_SOURCE_DIR}/../libtiled
	${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
	)
#set ( EXECUTABLE_OUTPUT_PATH ../../bin )
set ( automappingconverter_HDRS
	convertercontrol.h
	)

set ( automappingconverter_SRCS
	main.cpp
	converterdatamodel.cpp
	convertercontrol.cpp
	converterwindow.cpp
	)

set ( automappingconverter_UIS
	converterwindow.ui
	)
qt_wrap_ui(UIS ${automappingconverter_UIS})

set ( automappingconverter_MOCS
	converterdatamodel.h
	converterwindow.h
	)
qt_wrap_cpp(MOCS ${automappingconverter_MOCS})

qt_add_executable ( automappingconverter ${automappingconverter_SRCS} ${UIS} ${RSCS} ${TRS} )
target_link_libraries ( automappingconverter PRIVATE libtiled Qt6::Core Qt6::Gui )
