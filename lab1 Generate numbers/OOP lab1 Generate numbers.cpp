/*
Generation of random numbers
Author: Tarasiuk Oleksandr
*/

#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <numeric>

using namespace std;

const int k = 10000;

int nums[10] = {};
int nums2[10] = {};

bool question() {
    cout << "want to insert your parameters ? (y|n)" << endl;
    char ans;
    cin >> ans;
    if (ans == 'y') return true;
    else return false;
}

int enter1(int& a,int& c,int& m) {
    cout << "Enter m: ";
    cin >> m;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter c: ";
    cin >> c;
    if (gcd(m, c) != 1) {
        cout << "m and c must be coprime" << endl;
        enter1(a, c, m);
    }
    if (m % 4 == 0 && (a - 1) % 4 != 0) {
        cout << "if m is a multiple of 4 then b must be a multiple of 4" << endl;
        enter1(a, c, m);
    }
    cout << "\n";
    return 0;
}

// 1) Linear congruent method
void method_1() {
    int x, a, c, m;
    srand(time(NULL));
    x = rand();
    a = 3797;
    c = 9;
    m = 22004;

    if (question()) {
        enter1(a,c,m);
    }

    double returnValue;
    for (int i = 0; i <= k; i++) {
        x = (a * x + c) % m;
        returnValue = double(x) / m;
        nums2[int(returnValue * 10)]++;
    }
}

int enter2(int& a, int& c, int& m, int& d) {
    cout << "Enter m: ";
    cin >> m;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter c: ";
    cin >> c;
    cout << "Enter d: ";
    cin >> d;
    if (gcd(m, c) != 1) {
        cout << "m and c must be coprime" << endl;
        enter2(a, c, m, d);
    }
    if (m % 4 == 0 && !(d % 2 == 0 && d % 4 == (a - 1) % 4)) {
        cout << "if m is a multiple of 4 then d must be a multiple of 2 and d must be congruent to b modulo 2" << endl;
        enter2(a, c, m, d);
    }
    if (m % 3 == 0 && d % 9 == (3 * c) % 9) { 
        cout << "if m is a multiple of 3 then d must be congruent to 3 modulo 9" << endl; 
        enter2(a, c, m, d);
    }
    cout << "\n";
    return 0;
}

//2) Quadratic congruent method
void method_2() {
    srand(time(NULL));
    int x = rand();
    int a = 160;
    int c = 1450;
    int m = 1293;
    int d = 159;

    if (question()) {
        enter2(a,c,m,d);
    }

    double returnValue;
    for (int i = 0; i <= k; i++) {
        x = (d * int(pow(x, 2)) + a * x + c) % m;
        returnValue = double(x) / m;
        nums2[int(returnValue * 10)]++;
    }
}

int enter3(int& m) {
    cout << "Enter m: ";
    cin >> m;
    cout << "\n";
    return 0;
}
//3) Fibonacci numbers
void method_3() {
    srand(time(NULL));
    int xn1 = rand();
    int x0 = rand();
    int m = 23234;
    double returnValue;
    if (question()) {
        enter3(m);
    }
    for (int i = 0; i < k; i++) {
        x0 = (x0 + xn1) % m;
        returnValue = double(x0) / m;
        nums2[int(returnValue * 10)]++;
    }
}

int invers(int x, int paramtr) {
    for (int i = 0; i < paramtr; i++) {
        if ((x * i) % paramtr == 1) {
            return i;
        }
    }
    return 0;
}

int enter4(int& a, int& c, int& p) {
    cout << "Enter p: ";
    cin >> p;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter c: ";
    cin >> c;
    cout << "\n";
    return 0;
}

//4) Inverse congruent sequence
void method_4() {
    srand(time(NULL));
    int a = 31, c = 17;
    int p = 6499, X = rand() % p;
    double returnValue;
    if (question()) {
        enter4(a,c,p);
    }
    for (int i = 0; i < k; i++) {
        X = (a * invers(X, p) + c) % p;
        returnValue = double(X) / p;
        nums2[int(returnValue * 10)]++;
    }
}

//5) The asociations method
void method_5() {
    srand(time(NULL));
    int zn = 0, xn = rand(), yn = rand();
    int a = 160;
    int c = 1450;
    int m = 1293;
    int d = 159;
    double returnValue;
    for (int i = 0; i < k; i++) {
        yn = (d * int(pow(yn, 2)) + a * yn + c) % m;
        zn = abs((xn - yn)) % m;
        xn = (a * xn + c) % m;
        returnValue = double(zn) / m;
        nums2[int(returnValue * 10)]++;
    }
}

//histohram for 1-5 methods
void histohram1_5() {
    cout << "  Range       " << "Frequency" << endl;
    cout << "[0.0;0.1]" << "      " << double(nums2[0]) / k << endl;
    cout << "[0.1;0.2]" << "      " << double(nums2[1]) / k << endl;
    cout << "[0.2;0.3]" << "      " << double(nums2[2]) / k << endl;
    cout << "[0.3;0.4]" << "      " << double(nums2[3]) / k << endl;
    cout << "[0.4;0.5]" << "      " << double(nums2[4]) / k << endl;
    cout << "[0.5;0.6]" << "      " << double(nums2[5]) / k << endl;
    cout << "[0.6;0.7]" << "      " << double(nums2[6]) / k << endl;
    cout << "[0.7;0.8]" << "      " << double(nums2[7]) / k << endl;
    cout << "[0.8;0.9]" << "      " << double(nums2[8]) / k << endl;
    cout << "[0.9;1.0]" << "      " << double(nums2[9]) / k << endl;
}

void for6_8(double SUM) {
    if (-3 <= SUM && SUM < -2.4) {
        nums[0]++;
    }
    if (-2.4 <= SUM && SUM < -1.8) {
        nums[1]++;
    }
    if (-1.8 <= SUM && SUM < -1.2) {
        nums[2]++;
    }
    if (-1.2 <= SUM && SUM < -0.6) {
        nums[3]++;
    }
    if (-0.6 <= SUM && SUM < 0) {
        nums[4]++;
    }
    if (0 <= SUM && SUM < 0.6) {
        nums[5]++;
    }
    if (0.6 <= SUM && SUM < 1.2) {
        nums[6]++;
    }
    if (1.2 <= SUM && SUM < 1.8) {
        nums[7]++;
    }
    if (1.8 <= SUM && SUM < 2.4) {
        nums[8]++;
    }
    if (2.4 <= SUM && SUM <= 3) {
        nums[9]++;
    }
    if (SUM >= 0 && SUM < 1) {
        nums2[int(SUM * 10)] ++;
    } 
}

//6) "3 sigma" rule
void method_6() {
    srand(time(NULL));
    int x = rand(), a = 4699;
    int c = 39, m = 16843;
    double returnValue;
    double SUM = 0;
    for (int i = 0; i < k; i++) {
        for (int n = 0; n < 12; n++) {
            x = (a * x + c) % m;
            returnValue = double(x) / (m-1);
            SUM += returnValue;
        }
        SUM -= 6;
        for6_8(SUM);
        SUM = 0;
    }
    
}

//7) Method of polar coordinates
void method_7() {
    srand(time(NULL));
    int x = rand(), a = 4789;
    int c = 36, m = 21079;
    double U1, U2, V1;
    double V2, s, x1, x2;
    for (int i = 0; i < k; i++) {
        x = (a * x + c) % m;
        U1 = double(x) / m;
        U2 = double(x) / m;
        V1 = 2 * U1 - 1;
        V2 = 2 * U2 - 1;
        s = V1 * V1 + V2 * V2;
        if (s < 1) {
            x1 = V1 * sqrt((-2 * log(s)) / s);
            x2 = V2 * sqrt((-2 * log(s)) / s);
            for6_8(x1);
            for6_8(x2);
        }
    }
}

//8) Method of ratios
void method_8() {
    srand(time(NULL));
    int xn = rand(), Yn = rand(), a = 17000;
    int c = 15, a1 = 16004, c1 = 15;
    int m = 21500, d = 2400;
    double x, U, V;
    for (int i = 0; i < k; i++) {
        xn = (a * xn + c) % m;
        U = double(xn) / m;
        Yn = (d * int(pow(Yn, 2)) + a1 * Yn + c1) % m;
        V = double(Yn) / m;
        if (U != 0) {
            x = sqrt(8 / exp(1)) * (V - 0.5) / U;
            if (pow(x, 2) <= -4 * log(U)) {
                for6_8(x);
            }
        }
    }
}
//histohram for 6-8 methods
void histohram6_8() {
    cout << "Range      " << "Frequency" << endl;
    cout << "[-3.0;-2.4]" << "   " << double(nums[0]) / k << endl;
    cout << "[-2.4;-1.8]" << "   " << double(nums[1]) / k << endl;
    cout << "[-1.8;-1.2]" << "   " << double(nums[2]) / k << endl;
    cout << "[-1.2;-0.6]" << "   " << double(nums[3]) / k << endl;
    cout << "[-0.6;0.0]" << "    " << double(nums[4]) / k << endl;
    cout << "[0.0;0.6]" << "     " << double(nums[5]) / k << endl;
    cout << "[0.6;1.2]" << "     " << double(nums[6]) / k << endl;
    cout << "[1.2;1.8]" << "     " << double(nums[7]) / k << endl;
    cout << "[1.8;2.4]" << "     " << double(nums[8]) / k << endl;
    cout << "[2.4;3.0]" << "     " << double(nums[9]) / k << endl;
}


//9) Logarithm method of generating an indicative distribution
void method_9() {
    int  a = 34, c = 19, m = 9111, m1 = 21;
    long long x0 = time(0);
    double U, F;
    for (int i = 0; i <= k; i++) {
        x0 = (a * x0 + c) % m;
        double U = double(x0) / m;
        F = -m1 * log(U);
        if (F < 100) {
            nums[int(F / 10)]++;
        }
    }
}

//10) Ahrens's method for generating a gamma distribution of order a > 1
void method_10() {
    srand(time(NULL));
    int Xn = rand(), Yn = rand(), a = 15999;
    int c = 16, a1 = 15999, c1 = 16, m = 20899, d = 2329;
    double x, y, U, V;

    int A = 2;
    for (int i = 0; i < k; i++) {
        Xn = (a * Xn + c) % m;
        U = double(Xn) / m;
        y = tan(U * exp(1));
        x = sqrt(2 * A - 1) * y + A - 1;
        if (x > 0) {
            Yn = (d * int(pow(Yn, 2)) + a1 * Yn + c1) % m;
            V = double(Yn) / m;
            if (V <= ((1 + pow(y, 2)) * exp((A - 1) * log((x) / (A - 1)) - sqrt(2 * A - 1) * y))) {
                nums[int(x) % 10]++;
            }
        }
    }
}

//histohram for 9-10 methods
void histohram9_10() {
    cout << "Range      " << "Frequency" << endl;
    cout << "[0;10] " << "     " << double(nums[0]) / k << endl;
    cout << "[10;20]" << "     " << double(nums[1]) / k << endl;
    cout << "[20;30]" << "     " << double(nums[2]) / k << endl;
    cout << "[30;40]" << "     " << double(nums[3]) / k << endl;
    cout << "[40;50]" << "     " << double(nums[4]) / k << endl;
    cout << "[50;60]" << "     " << double(nums[5]) / k << endl;
    cout << "[60;70]" << "     " << double(nums[6]) / k << endl;
    cout << "[70;80]" << "     " << double(nums[7]) / k << endl;
    cout << "[80;90]" << "     " << double(nums[8]) / k << endl;
    cout << "[90;100]" << "    " << double(nums[9]) / k << endl;
}


void methods_menu() {
    cout << "Choose a number from 1 to 10 to select a method:" << endl;
    cout << "1) Linear congruent method" << endl;
    cout << "2) Quadratic congruent method" << endl;
    cout << "3) Fibonacci numbers" << endl;
    cout << "4) Inverse congruent sequence" << endl;
    cout << "5) The asociations method" << endl;
    cout << "6) \"3 sigma\" rule" << endl;
    cout << "7) Method of polar coordinates" << endl;
    cout << "8) Method of ratios" << endl;
    cout << "9) Logarithm method of generating an indicative distribution" << endl;
    cout << "10) Ahrens's method for generating a gamma distribution of order a > 1" << endl << endl;

}

int main() {
    int Input;

    try
    {
        methods_menu();
        cin >> Input;
        if (cin.fail() || Input <= 0) {
            return 1;
        }

        switch (Input) {
            case 1:
                method_1();
                histohram1_5();
                break;
            case 2:
                method_2();
                histohram1_5();
                break;
            case 3:
                method_3();
                histohram1_5();
                break;
            case 4:
                method_4();
                histohram1_5();
                break;
            case 5:
                method_5();
                histohram1_5();
                break;
            case 6:
                method_6();
                histohram6_8();
                cout << endl;
                histohram1_5();
                break;
            case 7:
                method_7();
                histohram6_8();
                cout << endl;
                histohram1_5();
                break;
            case 8:
                method_8();
                histohram6_8();
                cout << endl;
                histohram1_5();
                break;
            case 9:
                method_9();
                histohram9_10();
                break;
            case 10:
                method_10();
                histohram9_10();
                break;

            default:
                break;
        }

    }
    catch (int error)
    {
        cout << "Sorry, something is wrong with your input." << std::endl;
    }

}