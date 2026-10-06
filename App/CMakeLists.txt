add_executable (MyApplication main.cpp)

target_include_directories (MyApplication PRIVATE ../FunctionAnalysis/include)
target_link_libraries (MyApplication PRIVATE FunctionAnalysis)

target_include_directories (MyApplication PRIVATE ../RootFinder_SDK/include)
target_link_directories (MyApplication PRIVATE ../RootFinder_SDK/lib)
target_link_libraries (MyApplication PRIVATE RootFinder)