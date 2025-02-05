#include <iostream>

#define N 10000

using namespace std;

int main()
{



for(int exponent = 3; exponent <=6; exponent++){
        int powOfTen = 1;
        for(int i = 0; i < exponent; i++){
            powOfTen *= 10;
        }
            cout << powOfTen;
            cout << endl;
}
}