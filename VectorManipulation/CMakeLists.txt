cmake_minimum_required(VERSION 3.10)
project(vectormanipulation)

add_executable(${PROJECT_NAME} vectormanipulation.cpp)
set_target_properties(${PROJECT_NAME}
PROPERTIES
ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${PROJECT_NAME}"
)