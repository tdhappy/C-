#include"calculator.h"
#include<iostream>
#include<sstream>
#include<string>

using namespace std;

    string calculator::getstr() {
        return str1;
    }

    calculator::calculator(string str) {
        int k;
        this->str1 = str;
        k = expression(this->getstr());
        cout << k <<endl;
    }

    double calculator::expression(string str) {
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(' || str[i] == '*' || str[i] == '/')
            {
                term(str);
                break;
            }else if (str[i] == '+')
            {
                return (term(str.substr(0, i )) + term(str.substr(i + 1, str.length() -i )));
                break;
            }else if (str[i] == '-')
            {
                return (term(str.substr(0, i )) - term(str.substr(i + 1, str.length() -i )));
                break;
            }

        }
        return term(str);
    }

    double calculator::term(string str) {
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(') {
                factor(str);
                break;
            }
            if (str[i] == '*') {
                return (factor(str.substr(0, i )) * factor(str.substr(i + 1, str.length() -i )));

            }
            if (str[i] == '/') {
                double x = factor(str.substr(i + 1, str.length() - i ));
                if(x==0) throw string ("Missing )");
                return (factor(str.substr(0, i )) / x );

            }
        }
        return factor(str);
    }

    double calculator::factor(string str) {
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(') {
                for (int j = i; j < str.length() - i; j++) {
                    if (str[j] == ')') {
                        expression(str.substr(i + 1, j - 1));
                    }

                }
            }
            stringstream ss(str);
            double n = 0;
            ss >> n;
            return n;
        }

    }
