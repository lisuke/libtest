cmake_minimum_required(VERSION 3.8)
project(libtest)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        main.c)

INCLUDE_DIRECTORIES(include/)
# shared lib
ADD_LIBRARY(__test_shared SHARED ${SOURCE_FILES})
SET_TARGET_PROPERTIES (__test_shared PROPERTIES OUTPUT_NAME "test")
GET_TARGET_PROPERTY (OUTPUT_VALUE __test_shared OUTPUT_NAME)
MESSAGE (STATUS "This is the test_share OUTPUT_NAME: " ${OUTPUT_VALUE})

# static lib
ADD_LIBRARY(__test_static STATIC ${SOURCE_FILES})
SET_TARGET_PROPERTIES (__test_static PROPERTIES OUTPUT_NAME "test")
GET_TARGET_PROPERTY (OUTPUT_VALUE __test_static OUTPUT_NAME)
MESSAGE (STATUS "This is the test_static OUTPUT_NAME: " ${OUTPUT_VALUE})

SET_TARGET_PROPERTIES (__test_shared PROPERTIES CLEAN_DIRECT_OUTPUT 1)
SET_TARGET_PROPERTIES (__test_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

SET_TARGET_PROPERTIES (__test_shared PROPERTIES VERSION 1.0 SOVERSION 1)





add_executable(Test ${SOURCE_FILES})
#target_link_libraries(libtest)
#link_libraries(libtest.a)


INSTALL (TARGETS __test_static __test_shared LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)

INSTALL (FILES hello.h DESTINATION include/hello)