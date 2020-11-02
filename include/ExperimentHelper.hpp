#include <string>
#include <vector>

// custom struct to store our data for a single round
struct CollectData{
    int presented_cue;
    int response_cue;
    double response_time;
    std::string session;
};

// enum so that I can use training/testing instead of ambiguous 0 and 1
enum Session{
    training, // 0
    testing   // 1
};

// This is pulled from test_saving_data.cpp and is implemented in ExperimentHelper.cpp
void save_data(std::string filepath, std::vector<CollectData> data);

// This is pulled from test_saving_data.cpp and is implemented in ExperimentHelper.cpp
std::array<std::array<int,2>,5> load_data(std::string filepath);