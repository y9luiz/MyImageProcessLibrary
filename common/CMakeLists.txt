project(MyImageLibrary)

set(COMMON_HEADERS img.h  types.h common.h PARENT_SCOPE)
set(COMMON_SOURCES img.cpp)

add_library(MIL_COMMON SHARED ${COMMON_SOURCES})