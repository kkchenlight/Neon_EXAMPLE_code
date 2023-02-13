cmake_minimum_required(VERSION 3.10)
project(arithmetic)

add_executable(${PROJECT_NAME} ./arithmetic.cpp)
set_target_properties(${PROJECT_NAME}
PROPERTIES
ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${PROJECT_NAME}"
)