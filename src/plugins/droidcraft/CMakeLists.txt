cmake_minimum_required(VERSION 3.16)

project(droidcraft LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Gui)

qt_add_library(droidcraft SHARED
    droidcraftplugin.cpp
    droidcraftplugin.h
    droidcraft_global.h
    droidcraft.qrc
)

target_compile_definitions(droidcraft PRIVATE
    DROIDCRAFT_LIBRARY
)

target_include_directories(droidcraft PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src/tiled
)

target_link_libraries(droidcraft PRIVATE
    libtiled
    Qt6::Core
    Qt6::Gui
)

install(TARGETS droidcraft
    RUNTIME DESTINATION plugins/tiled
    LIBRARY DESTINATION plugins/tiled
)
