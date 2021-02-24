#include <algorithm>
#include <random>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;


void random_sort(vector<int> &vec){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    bool check = true;
    while (check){
        for (int i = 0; i < vec.size()-1; i++){
            if (vec[i] > vec[i+1]) {
                std::shuffle(std::begin(vec), std::end(vec), e);
                break;
            }
            else if (i == vec.size()-2) check = false;
        }
    }
}