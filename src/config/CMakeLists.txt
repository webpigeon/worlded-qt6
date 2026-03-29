cmake_minimum_required(VERSION 3.16)

find_package(Qt6 REQUIRED COMPONENTS Core Gui)

qt_add_executable(config
    main.cpp
    configdialog.cpp
    configdialog.h
    configdialog.ui
)

target_link_libraries(config PRIVATE
    libtiled
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

INSTALL(TARGETS config DESTINATION ".")
