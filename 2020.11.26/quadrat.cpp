#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;


// Вводится число натуральное

// Выводится его разложения на натуральные числа, являющиеся полными квадратами, с наименьшим числом слагаемых
struct quw{
    double len;
    vector <double> v;

    quw(){
        len = 0;
        v = {};
    }
};
int main() {
    double n;
    cin >> n;
    vector <quw> vec(n+1);
    for (double i = 0; i <= n; i++){
        vec[i] = quw();
        if (i == 1){
            vec[i].len = 1;
            vec[i].v.push_back(1);
        }
        else if (i == 2) {
            vec[i].len = 2;
            vec[i].v.push_back(1);
            vec[i].v.push_back(1);
        }
        else if (i == 0) {
            vec[i].len = 1000000000000000;
            vec[i].v.push_back(1);
        }
        else if (sqrt(i) == round(sqrt(i))) {
            vec[i].len = 1;
            vec[i].v.push_back(sqrt(i));
        }
        else{
            double minlen = 4;
            for (double j = 1; (int) j <= round((int)i/2)+1; j++){
                if (vec[j].len + vec[i-j].len == 2){
                    vec[i].len = 2;
                    minlen = 2;
                    vec[i].v = {};
                    for (double h = 0; h < vec[j].v.size(); h++) vec[i].v.push_back(vec[j].v[h]);
                    for (double h = 0; h < vec[i-j].v.size(); h++) vec[i].v.push_back(vec[i-j].v[h]);
                    break;
                }
                else if (vec[j].len + vec[i-j].len <= minlen){
                    minlen = vec[j].len + vec[i-j].len;
                    vec[i].len = minlen;
                    vec[i].v = {};
                    for (double h = 0; h < vec[j].v.size(); h++) vec[i].v.push_back(vec[j].v[h]);
                    for (double h = 0; h < vec[i-j].v.size(); h++) vec[i].v.push_back(vec[i-j].v[h]);
                }
            }
        }
    }
    cout << n << " = ";
    for (int j = 0; j < vec[n].len; j++) {
        cout << vec[n].v[j] << "^2 ";
        if (j < vec[n].len - 1) cout << "+ ";
    }

    return 0;
}
