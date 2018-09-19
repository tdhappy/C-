#include "City.h"

/***** Complete this class. *****/
string City::get_name() const{

   return name;
}

string City::get_state() const{

   return state;
}

Coordinate City::get_coordinate() const{

	return coordinate;
}

istream& operator >>(istream& ins, City& city){

   string a,b,p,q;
   double c,d;

	getline(ins,a,',');
	city.name=a;
	getline(ins,b,',');
	city.state=b;
	getline(ins,p,',');
	c=stod(p);
   city.coordinate.set_latitude(c);
   getline(ins,q,'\n');
   d=stod(q);
   city.coordinate.set_longitude(d);

	return ins;
}

ostream& operator <<(ostream& outs, const City& city){

   outs<<"*"<<city.name<<" "<<city.state<<endl;

   return outs;
}

