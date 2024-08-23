cmake_minimum_required(VERSION 3.24)
set(VERSION "0.0.1")
set(PROJECT_NAME "test15")

project(${PROJECT_NAME} VERSION ${VERSION} LANGUAGES C)

# add_executable(${PROJECT_NAME} main.c)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)

# include(CTest)
# enable_testing()
include(FetchContent)

set(RAYLIB_VERSION 4.5.0)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    FIND_PACKAGE_ARGS ${RAYLIB_VERSION}
)
FetchContent_MakeAvailable(raylib)

# Update the commit to point to whatever libsodium-cmake-commit you want to target.
FetchContent_Declare(Sodium
    GIT_REPOSITORY https://github.com/robinlinden/libsodium-cmake.git
    GIT_TAG 99f14233eab1d4f7f49c2af4ec836f2e701c445e # HEAD as of 2022-05-28
)
set(SODIUM_DISABLE_TESTS ON)

FetchContent_MakeAvailable(Sodium)

add_subdirectory(src)

if(APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()

if(UNIX)
    find_package(PkgConfig QUIET)

    if(PKG_CONFIG_FOUND)
        pkg_check_modules(sodium_PKG QUIET libsodium)
    endif()
endif()

if(EMSCRIPTEN)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s GL_ENABLE_GET_PROC_ADDRESS=1")
    set(CMAKE_EXECUTABLE_SUFFIX ".html") # This line is used to set your executable to build with the emscripten html template so that you can directly open it.
endif()
