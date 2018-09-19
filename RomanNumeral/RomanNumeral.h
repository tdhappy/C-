#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_


#include <iostream>
#include <string>


using namespace std;

class RomanNumeral
{

public:

    // Constructors
    RomanNumeral(string rn);
    RomanNumeral(int dc);
    RomanNumeral();

    //getters
    string get_roman() const;
    int get_decimal() const;

    //operator overloading
    friend int operator +(const RomanNumeral& rn1, const RomanNumeral& rn2);
    friend int operator -(const RomanNumeral& rn1, const RomanNumeral& rn2);
    friend int operator *(const RomanNumeral& rn1, const RomanNumeral& rn2);
    friend int operator /(const RomanNumeral& rn1, const RomanNumeral& rn2);
    friend bool operator ==(const RomanNumeral& rn1, const RomanNumeral& rn2);
    friend bool operator !=(const RomanNumeral& rn1, const RomanNumeral& rn2);
    friend ostream& operator <<(ostream& outs, const RomanNumeral& rn);
    friend istream& operator >>(istream& ins, RomanNumeral& rn);

private:
	
	//member variables
	string roman;
	int decimal;
	
	string to_roman(int n);
	int to_decimal(string s);

};

#endif /* ROMANNUMERAL_H_ */
