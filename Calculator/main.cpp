#include <iostream>
#include <string>
#include<fstream>
#include <iomanip>


#include "calculator.h"
using namespace std;
double expression();
double term();
double factor();

int main() {

    try {
        string str, str1, str2;
        string factor, expression;
        int count = 0;
        char p, q;
        string s;
        do {
            cout << "Expression? ";
            p = (cin >> ws).peek();
            getline(cin, str, '=');

            calculator c(str);
        } while (p != '.');

        cout << "Done!";
    }
    catch(string& str){
        cout << " ***** "<< str << endl;

    }
    return 0;
}
