cmake_minimum_required(VERSION 3.0)

project(algo-demo-II-1102)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(OpenGL_GL_PREFERENCE LEGACY)
set(BOOST_ROOT "/opt/homebrew/Cellar/boost/1.80.0")
find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)

file(GLOB IMGUI "src/imgui/imgui*.cpp")
file(GLOB BACKEND "src/imgui/backend/*.cpp")
file(GLOB DEMO "src/demo/*.cpp")

set(SOURCES
    src/main.cpp
    ${IMGUI}
    ${BACKEND}
    ${DEMO}
)

add_executable(main ${SOURCES})

target_link_libraries(main glfw)
target_link_libraries(main OpenGL::GL)

if(Boost_FOUND)
    MESSAGE(STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}")
    MESSAGE(STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}")
    MESSAGE(STATUS "Boost_VERSION = ${Boost_VERSION}")
    MESSAGE(STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(main ${Boost_LIBRARIES})
endif()

include_directories(
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include/imgui
        ${PROJECT_SOURCE_DIR}/include/demo
        ${PROJECT_SOURCE_DIR}/include/imgui/backend
)
