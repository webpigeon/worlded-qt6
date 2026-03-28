qt_add_library(qtlockedfile STATIC
    qtlockedfile.cpp
    qtlockedfile.h
)

if(WIN32)
    target_sources(qtlockedfile PRIVATE qtlockedfile_win.cpp)
else()
    target_sources(qtlockedfile PRIVATE qtlockedfile_unix.cpp)
endif()

set_target_properties(qtlockedfile PROPERTIES
    POSITION_INDEPENDENT_CODE ON
)

target_include_directories(qtlockedfile PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(qtlockedfile PUBLIC
    Qt6::Core
)
