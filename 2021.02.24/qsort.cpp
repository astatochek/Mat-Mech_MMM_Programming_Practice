#include <iostream>
#include <vector>

using namespace std;

void qsort(int beg, int end, std::vector<int> &vec) {
    int l = beg, r = end;
    int mid = vec[(l + r) / 2];
    while (l <= r) {
        while (vec[l] < mid)
            l++;
        while (vec[r] > mid)
            r--;
        if (l <= r)
            std::swap(vec[l++], vec[r--]);
    }
    if (beg < r)
        qsort(beg, r, vec);
    if (end > l)
        qsort(l, end, vec);
}