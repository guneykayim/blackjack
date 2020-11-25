cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(BlackJack VERSION 1.0)

# create the variable EXEC and sets it to blackjack
set(EXEC blackjack)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# bring the headers
include_directories(include)

# puts all .cpp files inside src to the SOURCES variable
file(GLOB SOURCES src/*.cpp)

# compile the files defined by SOURCES to generante the executable defined by EXEC
add_executable(${EXEC} ${SOURCES})
