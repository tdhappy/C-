
#ifndef CALCULATORNEW_CALCULATOR_H
#define CALCULATORNEW_CALCULATOR_H
using namespace std;
#include<string>
class calculator{
    public:
    string getstr();
    calculator(string str);
    double expression(string str);
    double term (string str);
    double factor (string str);
    private:
      string str1;

};

#endif //CALCULATORNEW_CALCULATOR_H
