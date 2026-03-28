qt_add_library(qtsingleapplication STATIC
    qtsingleapplication.h
    qtsingleapplication.cpp
    qtlocalpeer.h
    qtlocalpeer.cpp
    QtSingleApplication
)

set_target_properties(qtsingleapplication PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    AUTOMOC ON
)

target_include_directories(qtsingleapplication PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(qtsingleapplication PUBLIC
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Network
    qtlockedfile
)
