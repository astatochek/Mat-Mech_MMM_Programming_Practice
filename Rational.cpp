#include <iostream>
using namespace std;
// структура - рациональные числа

// вычисление НОД
int gcd(int a, int b){
    if (b==0) return a;
    return gcd(b, a%b);
};

// вычисление НОК
int lcd(int a, int b){
    return (a * b) / gcd(a, b);
};

struct Rational {

    int nom;
    unsigned int denom;

    Rational(int x, unsigned int y) {
        nom = x / gcd(x, y);
        denom = y / gcd(x, y);
    };


    Rational &operator *= (Rational &x){
        nom *= x.nom;
        denom *= x.denom;
        int current_gcd = gcd(nom, denom);
        nom /= current_gcd;
        denom /= current_gcd;
        return *this;
    };

    Rational &operator /= (Rational &x){
        nom *= x.denom;
        denom *= x.nom;
        int current_gcd = gcd(nom, denom);
        nom /= current_gcd;
        denom /= current_gcd;
        return *this;
    };

    Rational &operator += (Rational &x){
        int current_lcd = lcd(denom, x.denom);
        nom *= current_lcd / denom;
        denom = current_lcd;
        nom += x.nom * current_lcd / x.denom;
        int current_gcd = gcd(nom, denom);
        nom /= current_gcd;
        denom /= current_gcd;
        return *this;
    };

    Rational &operator -= (Rational &x){
        int current_lcd = lcd(denom, x.denom);
        nom *= current_lcd / denom;
        denom = current_lcd;
        nom -= x.nom * current_lcd / x.denom;
        int current_gcd = gcd(nom, denom);
        nom /= current_gcd;
        denom /= current_gcd;
        return *this;
    };


};

Rational &operator * (Rational x, Rational &y){
    return x *= y;
};

Rational &operator / (Rational x, Rational &y){
    return x /= y;
};

Rational &operator + (Rational x, Rational &y){
    return x += y;
};

Rational &operator - (Rational x, Rational &y){
    return x -= y;
};
ostream& operator<< (ostream &out, Rational &x){
    if (x.denom == 0) out << "Inf";
    else if (x.nom == 0) out << 0;
    else out << x.nom << "/" << x.denom;
    return out;
};

int main() {
// код еще сырой, если делить ан ноль, то не возникнет ошибки.
// Так ноль выводится тольо если у дроби числитель равен нулю.
// Бесконечность выводится, если у дроби знаменатель равен нулю
    Rational a(17, 4), b(25, 8);
    Rational c = a*b, d = a/b, e = a+b, f = a-b;
    cout << a << " * " << b << " = " << c << endl;
    cout << a << " : " << b << " = " << d << endl;
    cout << a << " + " << b << " = " << e << endl;
    cout << a << " - " << b << " = " << f << endl;

}
