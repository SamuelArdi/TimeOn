cmake_minimum_required(VERSION 3.14)

project(timeon)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")
foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} UPPERCONFIG)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${UPPERCONFIG} ${CMAKE_SOURCE_DIR})
endforeach()

find_package(raylib 6.0 QUIET)

include(FetchContent)
if (NOT raylib_FOUND)
    FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/refs/tags/6.0.tar.gz
        DOWNLOAD_EXTRACT_TIMESTAMP True #This option is not required but suppresses a warning
    )
    FetchContent_MakeAvailable(raylib)
endif()

# dont build raylib's examples
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_executable(main
    "src/main.cpp"
)

target_link_libraries(main 
    raylib
)

target_include_directories(main PUBLIC
    "${raylib_SOURCE_DIR}/src"
    "src"
)
