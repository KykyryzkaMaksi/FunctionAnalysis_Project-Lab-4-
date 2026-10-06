cmake_minimum_required (VERSION 3.20)
project (FunctionAnalysisProject LANGUAGES CXX)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(FunctionAnalysis)
add_subdirectory(App)