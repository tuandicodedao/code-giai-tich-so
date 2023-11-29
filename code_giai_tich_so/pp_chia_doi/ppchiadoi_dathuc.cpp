#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;

double f(double x){
    return pow(x, 3) - 4*pow(x, 2) + x + 1;
}

bool check_DK(double a, double b);
void halving_method(double a, double b, double epsi);

int main() {
    double a, b, epsi;
    cout << "\nNhap vao khoang cach li nghiem: ";
    cout << "\na = ";
    cin >> a;
    cout << "\nb = ";
    cin >> b;
    cout << "\nNhap vao sai so epsilon: ";
    cin >> epsi;
    halving_method(a, b, epsi);
    return 0;
}

bool check_DK(double a, double b){
    if (f(a) * f(b) >= 0)
        return false;
    else
        return true;
}

void halving_method(double a, double b, double epsi) {
    fstream out;
    out.open("output.txt", ios::out);
    out << "Phuong pháp chia dôi giai gan dúng nghiem bài toán f(x) = 0";
    out << "\nInput: ";
    out << "\nPhuong trình: x^3 - 4x^2 + x + 1 = 0";
    out << "\nKhoang cách li nghiem: (a, b) = (" << a << ", " << b << ")";
    out << "\nSai so epsilon: " << epsi << "\n";
    out << "\nChay code theo công thuc sai so huu nghiem \n";
    if (check_DK(a, b)) {
        int lan_lap = 0;
        double a1 = a;
        double b1 = b;
        double c, delta;
        do {
            lan_lap ++;
            out << "\nLan lap thu " << lan_lap << ": ";
            c = (a1 + b1) / 2;
            if (f(c) == 0)
                out << "Nghiem x = " << fixed << setprecision(20) << c;
            else {
                if (f(a1) * f(c) < 0)
                    b1 = c;
                else
                    a1 = c;
            }
            delta = fabs(a1 - b1);
            out << "Nghiem x =  " << fixed << setprecision(20) << c << ",  Sai so = " << delta;
        }
        while (delta > epsi);
        out << "\n\nKet luan: \nSo lan lap: " << lan_lap << "\nNghiem gan dúng: " << c;
    }
    else
        out << "\n Không su dung duoc phuong pháp !";
}
