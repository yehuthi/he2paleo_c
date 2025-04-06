cmake_minimum_required(VERSION 3.16)
project(he2paleo LANGUAGES C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")
add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include)

option(TEST_HE2PALEO "Enable testing for he2paleo" OFF)
if(TEST_HE2PALEO)
	enable_language(CXX)
	set(CMAKE_CXX_STANDARD 17)
	set(CMAKE_CXX_STANDARD_REQUIRED ON)

	enable_testing()
	find_package(GTest REQUIRED)
	add_executable(${PROJECT_NAME}_test test/suite.cpp)
	get_target_property(GTEST_INCLUDE_DIRS GTest::gtest_main INTERFACE_INCLUDE_DIRECTORIES)
	target_link_libraries(${PROJECT_NAME}_test GTest::gtest_main ${PROJECT_NAME})
	include(GoogleTest)
	gtest_discover_tests(${PROJECT_NAME}_test)
endif()