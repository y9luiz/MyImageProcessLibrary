cmake_minimum_required(VERSION 3.0.0)
project(MyImageLibrary)
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)
add_subdirectory(common)
add_subdirectory(io)
add_subdirectory(decoder)
add_subdirectory(imgproc)
add_executable(test_load_save_image test_load_save_image.cpp)


target_link_libraries(test_load_save_image PUBLIC MIL_IO MIL_COMMON MIL_DECODER MIL_IMAGE_PROC)
target_include_directories(test_load_save_image PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} common io decoder imgproc)