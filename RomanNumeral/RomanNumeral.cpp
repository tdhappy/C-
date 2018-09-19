#include <iostream>
#include <string>
#include <cstring>
#include "RomanNumeral.h"

using namespace std;

string RomanNumeral::to_roman(int n) //Function to convert integer decimal to roman number
{
				string A[]	= {"","M","MM","MMM"};
				string B[]	= {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
				string C[]	= {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
				string D[]	= {"","I","II","III","IV","V","VI","VII","VIII","IX"};

				string result;
				result += A[(int)(n/1000)%10];
				result += B[(int)(n/100)%10];
				result += C[(int)(n/10)%10];
				result += D[n%10];

				return result;
}

int RomanNumeral::to_decimal(string s) //Function to convert roman number to integer decimal
{
	int m=0;
	int n=0;
	int result=0;
	char p[10];
	strcpy(p, s.c_str());

	for (int i=0; i<strlen(p); i++){

		switch (p[i]){

		case 'I': n=1; break;
		case 'V': n=5; break;
		case 'X': n=10; break;
		case 'L': n=50; break;
		case 'C': n=100; break;
		case 'D': n=500; break;
		case 'M': n=1000; break;

		}

		if(p[i+1]!='\0')
		{
		switch (p[i+1]){

		case 'I': m=1; break;
		case 'V': m=5; break;
		case 'X': m=10; break;
		case 'L': m=50; break;
		case 'C': m=100; break;
		case 'D': m=500; break;
		case 'M': m=1000; break;

		}

		if(n>=m){
			result=result+n;
		}else{
			result=result+m-n;
			i++;
		}

		}
		else{
			result=result+n;
		}


	}
	return result;

}
 
 //getter functions definations
string RomanNumeral::get_roman() const{
	return roman;
}
int RomanNumeral::get_decimal() const{
	return decimal;
}

// constructor definations
RomanNumeral::RomanNumeral() : roman(""), decimal(0)
{
	
}
RomanNumeral::RomanNumeral(string rn) : roman(rn), decimal(0)
{
	decimal=to_decimal(rn);
}

RomanNumeral::RomanNumeral(int dc) : roman(""), decimal(dc)
{
	roman=to_roman(dc);

}

//operator overloading defiations

//arithmatic operators
int operator +(const RomanNumeral& rn1, const RomanNumeral& rn2){

	return (rn1.decimal+rn2.decimal);
}
int operator -(const RomanNumeral& rn1, const RomanNumeral& rn2){

	return (rn1.decimal-rn2.decimal);
}
int operator *(const RomanNumeral& rn1, const RomanNumeral& rn2){

	return (rn1.decimal*rn2.decimal);
}
int operator /(const RomanNumeral& rn1, const RomanNumeral& rn2){

	return (rn1.decimal/rn2.decimal);
}

//equality operators
bool operator ==(const RomanNumeral& rn1, const RomanNumeral& rn2){
	if((rn1.decimal==rn2.decimal)&&(rn1.roman==rn2.roman)){
		return true;
	}else{
		return false;
	}

}
bool operator !=(const RomanNumeral& rn1, const RomanNumeral& rn2){
	if((rn1.decimal!=rn2.decimal)||(rn1.roman!=rn2.roman)){
			return true;
		}else{
			return false;
		}
}

//stream operators
ostream& operator <<(ostream& outs, const RomanNumeral& rn){

	outs<<"["<<rn.decimal<<":"<<rn.roman<<"]";
	return outs;
}
istream& operator >>(istream& ins, RomanNumeral& rn){

	ins>>rn.roman;
	rn.decimal=rn.to_decimal(rn.roman);
	return ins;
}
