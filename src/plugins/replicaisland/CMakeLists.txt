cmake_minimum_required(VERSION 3.16)

find_package(Qt6 REQUIRED COMPONENTS Core Gui)

qt_add_library(replicaisland SHARED
    replicaislandplugin.cpp
    replicaislandplugin.h
    replicaisland_global.h
    replicaisland.qrc
)

target_compile_definitions(replicaisland PRIVATE
    REPLICAISLAND_LIBRARY
)

target_include_directories(replicaisland PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src/tiled
    ${CMAKE_SOURCE_DIR}/src/libtiled
)

target_link_libraries(replicaisland PRIVATE
    libtiled
    Qt6::Core
    Qt6::Gui
)

install(TARGETS replicaisland
    RUNTIME DESTINATION plugins/tiled
    LIBRARY DESTINATION plugins/tiled
)
