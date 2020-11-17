cmake_minimum_required(VERSION 3.13)

# create your C++ project
project(MyProject VERSION 0.1.0 LANGUAGES CXX)

# get the relevant libraries to use from github. FetchContent is great because it pulls the most recent version of a library and will add it to your project.
include(FetchContent)
FetchContent_Declare(mahi-util GIT_REPOSITORY https://github.com/mahilab/mahi-util.git)
FetchContent_MakeAvailable(mahi-util)

# add your include directories
include_directories("include")

# create an app from your source files
add_executable(my_app
    "src/MyClass.cpp"
    "src/my_app.cpp"
)

# link your app to MEL libaries
target_link_libraries(my_app mahi::util)