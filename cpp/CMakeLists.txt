#---------------------------------------------------------------------------------------------------
# CMake Build Configuration for srhlab C++ code
#---------------------------------------------------------------------------------------------------

cmake_minimum_required (VERSION 3.2.0)

project (
    srhlab
    VERSION 1.0.0
    LANGUAGES CXX
)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)

add_executable (constants            constants.cpp)
add_executable (expr-vars            expr-vars.cpp)
add_executable (float                float.cpp)
add_executable (float-close          float-close.cpp)
add_executable (floatEpsilonDiffTest floatEpsilonDiffTest.cpp)
add_executable (fpsum                fpsum.cpp)
add_executable (initialization       initialization.cpp)
add_executable (istream              istream.cpp)
add_executable (magic-static         magic-static.cpp)
add_executable (ostream              ostream.cpp)
add_executable (pair                 pair.cpp)
add_executable (partvirt             partvirt.cpp)
add_executable (rgbclamp             rgbclamp.cpp)
add_executable (scope-for            scope-for.cpp)
add_executable (scope-if             scope-if.cpp)
add_executable (sharedPtr            sharedPtr.cpp)
add_executable (string               string.cpp)
add_executable (tuple                tuple.cpp)
add_executable (type-collision       type-collision.cpp)
add_executable (unordered_set        unordered_set.cpp)
add_executable (variadic             variadic.cpp)
add_executable (vector-growth        vector-growth.cpp)
