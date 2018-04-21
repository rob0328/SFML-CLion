cmake_minimum_required(VERSION 3.9)
project(FinalTest)

set(CMAKE_CXX_STANDARD 11)

set(SFML_ROOT "C:/Users/rober/Program_Libraries/SFML(1)")

set(SOURCE_FILES main.cpp)
add_executable(FinalTest ${SOURCE_FILES})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system graphics window network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()