#include <iostream>
#include <vector>

using namespace std;

int minimal(vector<int> vec){
    int res = 0;
    for (int i = 1; i < vec.size(); i++) if (vec[i] < vec[res]) res = i;
    return res;
}

void min_sort(vector<int> &vec){
    int min_index;
    vector <int> res;
    while (vec.size() > 0){
        min_index = minimal(vec);
        res.push_back(vec[min_index]);
        vec.erase(vec.begin()+min_index);
    }
    vec = res;
}
