cmake_minimum_required(VERSION 3.10)
project(load&store)

add_executable(load dataload.cpp)
add_executable(store datastore.cpp)

set_target_properties(load store
PROPERTIES
ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${PROJECT_NAME}"
)

