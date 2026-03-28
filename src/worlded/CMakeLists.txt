qt_add_library(worlded STATIC
    worlded/properties.cpp
    worlded/road.cpp
    worlded/world.cpp
    worlded/worldcell.cpp
    worlded/worldcellobject.cpp
    worlded/worldreader.cpp
    worlded/worldedmgr.cpp

    worlded/road.h
    worlded/world.h
    worlded/worldcell.h
    worlded/worldreader.h
    worlded/worldedmgr.h
    worlded/worldproperties.h
)

target_compile_definitions(worlded PRIVATE
    QT_NO_CAST_FROM_ASCII
    QT_NO_CAST_TO_ASCII
    ZOMBOID
    WORLDED
)

target_include_directories(worlded
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src/tiled
)

target_link_libraries(worlded PUBLIC
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    libtiled
)
