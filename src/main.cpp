//
// Created by User on 2020-03-22.
//
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
// value_s function to calculate the V for that sate and a direction
float value_s (float y, float reward, float current_V) {
    return y * current_V + reward;
}

void value_iteration( float y,vector<pair<float,vector<string>>>states) {
    int count = 1000; //dummy value
    int iter_count = 1;
    while (count != 0) { //stopping condition if there no new values added count will be 0
        cout << "Iteration: " << iter_count << endl;
        count = 0;

        for (int i = 0; i < states.size(); i++) {
            for (int j = 0; j < states[i].second.size(); j++) {
                float reward = 0.0f;
                //s6->s3 then reward is 100
                if (i == 5 && states[i].second[j] == "up") {
                    reward = 100;
                }
                //s2->s3 then reward is 50
                if (i == 1 && states[i].second[j] == "right") {
                    reward = 50;
                }
                int adjacent=0;
                string direction = (states[i].second[j]);
                //Set the adjacent position for that state and direction
                if(direction=="right"){
                    adjacent = 1;
                } else if (direction=="left"){
                    adjacent = -1;
                } else if (direction=="up"){
                    adjacent = -3;
                } else if (direction=="down"){
                    adjacent = 3;
                }
                // setting the s_val for that direction and then will come back if there multiply actions as add to that value
                float s_val = value_s(y, reward, states[i+adjacent].first);
                //Update state value if it needs to be which will increase the count to keep track if its converging
                if (s_val > states[i].first) {
                    states[i].first = s_val;
                    count++;
                }
            }
        }
        //Output grid
        for (int i = 0; i < 2; i++) {
            for (int j = 0 + i*3; j < 3 + i*3; j++) {
                cout << setw(4) << states[j].first;
            }
            cout << endl;
        }
        iter_count++;
    }
}

int main () {
    float y = 0.8f; //discount factor

    //State actions set
    vector<string> s1_actions = {"down","right"};
    vector<string> s2_actions = {"left","down","right"};
    vector<string> s3_actions = {"terminal_state"};
    vector<string> s4_actions = {"up","right"};
    vector<string> s5_actions = {"left","up","right"};
    vector<string> s6_actions = {"left","up"};

    //State values initialized to 0 and paired with actions
    pair<float,vector<string>> s1(0.0f,s1_actions);
    pair<float,vector<string>> s2(0.0f,s2_actions);
    pair<float,vector<string>> s3(0.0f,s3_actions);
    pair<float,vector<string>> s4(0.0f,s4_actions);
    pair<float,vector<string>> s5(0.0f,s5_actions);
    pair<float,vector<string>> s6(0.0f,s6_actions);
    //Vector holding all the states with they directions
    vector<pair<float,vector<string>>>states;
    //Pushed all into the vector
    states.push_back(s1);
    states.push_back(s2);
    states.push_back(s3);
    states.push_back(s4);
    states.push_back(s5);
    states.push_back(s6);
    //Initial grid output test
    cout<<"Initial grid state:"<<endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0 + i*3; j < 3 + i*3; j++) {
            cout << setw(4) << states[j].first;
        }
        cout << endl;
    }
    value_iteration(y,states);
}