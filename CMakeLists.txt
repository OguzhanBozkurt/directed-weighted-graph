cmake_minimum_required(VERSION 3.0.0)

project(directed-weighted-graph
    DESCRIPTION
    "Directed weighted graph implementation using C++")

add_subdirectory(src)
add_subdirectory(test)

find_package(Doxygen)
if (DOXYGEN_FOUND)
    message ("Doxygen is found")
    set (DOXYGEN_IN ${PROJECT_SOURCE_DIR}/build/CMakeDoxyfile.in)
    set (DOXYGEN_OUT ${PROJECT_SOURCE_DIR}/build/CMakeDoxyfile.out)
    set (DOXYGEN_INPUT ${PROJECT_SOURCE_DIR}/src/include)
    set (DOXYGEN_PROJECT_NAME "Directed Weighted Graph")
    set (DOXYGEN_MARKDOWN_SUPPORT YES)
    set (DOXYGEN_SHOW_USED_FILES NO)
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    add_custom_target(docs ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "*****Generating Documentation*****")
else (DOXYGEN_FOUND)
    message ("Doxygen is not found")
endif (DOXYGEN_FOUND)
