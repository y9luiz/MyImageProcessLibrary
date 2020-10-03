project(MyImageLibrary)

add_library(MIL_IO STATIC io.h io.cpp)
target_include_directories(MIL_IO PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR})

