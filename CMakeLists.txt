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
        include/views/studentviews/StudentPortal.cpp
        include/views/studentviews/StudentPortal.h
        include/views/studentviews/welcome.h
        include/views/studentviews/LoginRegister.h
        include/models/Utility.cpp
        include/models/Utility.h
        include/models/Question.cpp
        include/models/Question.h

        include/models/Admin.cpp
        include/models/Admin.h
        include/models/Quiz.cpp
        include/models/Quiz.h


        include/models/Result.cpp
        include/models/Result.h
        include/views/adminviews/AdminPortal.cpp
        include/views/adminviews/AdminPortal.h
        include/views/adminviews/welcome.h
        include/views/adminviews/LoginRegister.h
)

# If you have header files in an include directory
# include_directories(include)