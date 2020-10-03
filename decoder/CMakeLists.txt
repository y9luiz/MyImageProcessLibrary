project(MyImageLibrary)

add_library(MIL_DECODER STATIC decoder.h decoder.cpp)
target_include_directories(MIL_DECODER PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR})

