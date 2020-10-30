/*
The data we want to collect is 
    presented cue
    response cue
    response time
    session (training or testing)

so make a custom type that will hold that and test out using it
*/

#include<Mahi/Util.hpp>

using namespace mahi::util;

enum Session{
    training, // 0
    testing   // 1
};

int main(int argc, char* argv[]) {
    std::vector<std::string> session_strings = {"training", "testing"};
    
    Time train_time = seconds(10);
    Time  test_time = seconds(15);

    std::vector<Time> session_times = { train_time , test_time };

    Session current_session = training;

    Clock session_clock;
    Clock trial_clock;

    print("Starting Training session. You have {} seconds.\n", train_time.as_seconds());

    while ( session_clock.get_elapsed_time() < session_times[current_session]){
        print("Press \"C\" to print the current time.\nIf it is after the alotted session time, the session will end.");
        trial_clock.restart();
        
        // wait until the 'C' key is pressed
        while(get_key() != 'c'){};
        
        print("Session: {}", session_strings[current_session]);
        print("Trial time: {} seconds. Session time remaining: {} seconds.\n", trial_clock.get_elapsed_time().as_seconds(), (session_times[current_session]-session_clock.get_elapsed_time()).as_seconds());

        // if the sessions 
        if (session_clock.get_elapsed_time() > session_times[current_session] && current_session == training){
            current_session = testing;
            session_clock.restart();
        }
    }
    
}