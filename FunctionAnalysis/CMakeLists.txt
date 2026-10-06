add_library (FunctionAnalysis SHARED src/FunctionAnalysis.cpp)

target_include_directories (FunctionAnalysis PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features (FunctionAnalysis PUBLIC cxx_std_20)

target_compile_definitions (FunctionAnalysis PRIVATE FUNCTIONANALYSIS_EXPORTS)

install (TARGETS FunctionAnalysis
    RUNTIME DESTINATION bin
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib)
install (FILES include/FunctionAnalysis.h DESTINATION include)