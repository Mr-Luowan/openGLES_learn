cmake_minimum_required(VERSION 3.10.2)

project("opengldemo")
file(GLOB
        src_files
        ${CMAKE_SOURCE_DIR}/*.cpp
        ${CMAKE_SOURCE_DIR}/render/*.cpp
        ${CMAKE_SOURCE_DIR}/widget/*.cpp
        ${CMAKE_SOURCE_DIR}/util/*.cpp
        )

include_directories(
        render
        widget
        util
)
add_library( # Sets the name of the library.
             native-lib
             SHARED
             ${src_files})

find_library( # Sets the name of the path variable.
              log-lib

              log )

target_link_libraries( # Specifies the target library.
                       native-lib
                       ${log-lib}
                       GLESv3 )