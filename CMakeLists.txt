cmake_minimum_required(VERSION 3.10)

project(Algebruh VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRC_DIR src)
set(MATH_DIR Math)
set(CHEM_DIR Chemistry)
set(PHYSICS_DIR Physics)
set(INCLUDE_DIR include)
set(BUILD_DIR ${CMAKE_BINARY_DIR})
set(DIST_DIR ${CMAKE_BINARY_DIR}/dist)

if(WIN32)
    set(TARGET_NAME algebruh.exe)
else()
    set(TARGET_NAME algebruh)
endif()

set(SRCS
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/${MATH_DIR}/area.cpp
    ${SRC_DIR}/${MATH_DIR}/quadratic.cpp
    ${SRC_DIR}/${CHEM_DIR}/stoichiometry.cpp
    ${SRC_DIR}/${PHYSICS_DIR}/kinematic.cpp
    ${SRC_DIR}/${PHYSICS_DIR}/gravity.cpp
)

include_directories(${INCLUDE_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DIST_DIR})

add_executable(${TARGET_NAME} ${SRCS})

target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -pedantic)
