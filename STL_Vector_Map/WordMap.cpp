#include <iostream>
#include <map>
#include <string>
#include "WordMap.h"

using namespace std;
using namespace std::chrono;

WordMap::WordMap() {}

WordMap::~WordMap() {}

int WordMap::get_count(const string text) const
{


    map<string, Word>::const_iterator it = data.find(text);
    
    if(it!= data.end())
    {
         return (it->second).get_count();
    }else
    {
       return -1;
    }
    
}


void WordMap::insert(const string text)
{

    steady_clock::time_point start_time = steady_clock::now();

    map<string, Word>::iterator it = data.find(text);

 
    if (it == data.end())
    {
        data[text] = Word(text);
    }
    else
    {
        (it->second).increment_count();
    }


    steady_clock::time_point end_time = steady_clock::now();

    increment_elapsed_time(start_time, end_time);


}



map<string, Word>::iterator WordMap::search(const string text)
{

       steady_clock::time_point start_time = steady_clock::now();

  
       map<string, Word>::iterator it = data.find(text);


       steady_clock::time_point end_time = steady_clock::now();

	   increment_elapsed_time( start_time, end_time);

	   return it;

}

int WordMap::size() const
{
	return data.size();
}