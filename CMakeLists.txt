cmake_minimum_required (VERSION 3.20)
project (FunctionAnalysisProject LANGUAGES CXX)

# exe i dll потраплять в одну папку bin/ (щоб локальний тест із DLL запускався)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(FunctionAnalysis)
add_subdirectory(App)