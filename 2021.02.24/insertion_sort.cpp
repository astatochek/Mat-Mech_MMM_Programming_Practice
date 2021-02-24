#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector <int> &vec){
    for(int i = 1;i < vec.size(); i++)
        for(int j = i; j > 0 && vec[j-1] > vec[j]; j--)
            swap(vec[j-1], vec[j]);
}
