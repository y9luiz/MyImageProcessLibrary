project(MyImageLibrary)

add_library(MIL_IMAGE_PROC STATIC img_proc.h img_proc.cpp)
target_include_directories(MIL_IMAGE_PROC PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR})

