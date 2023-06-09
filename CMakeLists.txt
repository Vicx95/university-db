cmake_minimum_required(VERSION 3.20)
project(university-db)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

set(SOURCES 
    src/main.cpp
    src/Database.cpp
    src/Student.cpp
    src/PeselValidator.cpp
    )

set(HEADERS 

    )

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
set(FLAGS -Wall -Wextra -Wconversion -Wpedantic -g)
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})

enable_testing()
set(UT-SOURCES
    tests/PeselValidatorTest.cpp
    tests/DatabaseTest.cpp
    src/Database.cpp
    src/Student.cpp
    )

add_library(${PROJECT_NAME}-lib STATIC ${SOURCES})
add_executable(${PROJECT_NAME}-ut ${UT-SOURCES})
link_libraries(gmock)
target_link_libraries(${PROJECT_NAME}-ut gtest_main gmock ${PROJECT_NAME}-lib)
target_compile_options(${PROJECT_NAME}-ut PRIVATE ${FLAGS})
add_test(NAME ${PROJECT_NAME}-test COMMAND ${PROJECT_NAME}-ut)