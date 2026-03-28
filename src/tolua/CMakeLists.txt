add_library(tolua STATIC
    src/lib/tolua_event.c
    src/lib/tolua_is.c
    src/lib/tolua_map.c
    src/lib/tolua_push.c
    src/lib/tolua_to.c
)

target_include_directories(tolua PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(tolua PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib
)

target_link_libraries(tolua PUBLIC
    lua
)

add_executable(tolua_generator
    src/bin/tolua.c
    src/bin/toluabind.c
)

target_compile_definitions(tolua_generator PRIVATE
    LUA_SOURCE
    LUA_SOURCE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/src/bin/lua/"
)

target_include_directories(tolua_generator PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib
    ${CMAKE_SOURCE_DIR}/src/lua/src
)

target_link_libraries(tolua_generator PRIVATE
    tolua
    lua
)
