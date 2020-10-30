# initialize required cmake options
cmake_minimum_required(VERSION 3.13)
project(experiment_project)

# get the relevant libraries to use from github. FetchContent is great because it pulls the most recent version of a library and will add it to your project.
include(FetchContent)
FetchContent_Declare(mahi-util GIT_REPOSITORY https://github.com/mahilab/mahi-util.git)
FetchContent_MakeAvailable(mahi-util)

# add the include directory for compiler and to add intellisense capabilities
include_directories(include)

# create your executable and link it to the libraries you want to use
add_executable(experiment src/experiment.cpp src/ExperimentHelper.cpp)
target_link_libraries(experiment mahi::util)

# create test executable and link it to mahi-util
add_executable(test_command_line_args src/test_command_line_args.cpp)
target_link_libraries(test_command_line_args mahi::util)

# create test executable and link it to mahi-util
add_executable(test_loading_data src/test_loading_data.cpp)
target_link_libraries(test_loading_data mahi::util)

# create test executable and link it to mahi-util
add_executable(test_console_input src/test_console_input.cpp)
target_link_libraries(test_console_input mahi::util)

# create test executable and link it to mahi-util
add_executable(test_collecting_data src/test_collecting_data.cpp)
target_link_libraries(test_collecting_data mahi::util)

# create test executable and link it to mahi-util
add_executable(test_timing_elements src/test_timing_elements.cpp)
target_link_libraries(test_timing_elements mahi::util)

# create test executable and link it to mahi-util
add_executable(test_saving_data src/test_saving_data.cpp)
target_link_libraries(test_saving_data mahi::util)