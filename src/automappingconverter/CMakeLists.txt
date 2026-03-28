cmake_minimum_required(VERSION 3.16)

project(automappingconverter LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

qt_standard_project_setup()

qt_add_executable(automappingconverter
    main.cpp
    convertercontrol.cpp
    convertercontrol.h
    converterdatamodel.cpp
    converterdatamodel.h
    converterwindow.cpp
    converterwindow.h
    converterwindow.ui
)

target_include_directories(automappingconverter PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src/libtiled
)

target_link_libraries(automappingconverter PRIVATE
    libtiled
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)
