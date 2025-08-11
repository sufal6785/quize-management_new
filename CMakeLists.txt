# This MUST be the first line
cmake_minimum_required(VERSION 3.31)

# This MUST be the second line
project(quiz-management-new)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)

# Create executable - add your source files here
add_executable(quiz-management-new
        main.cpp
        include/models/User.cpp
        include/models/User.h
        include/models/Student.cpp
        include/models/Student.h
        include/views/StudentPortal.cpp
        include/views/StudentPortal.h
)

# If you have header files in an include directory
# include_directories(include)