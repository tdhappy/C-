#include <vector>
#include <string>
#include "WordVector.h"

using namespace std;

WordVector::WordVector() {}

WordVector::~WordVector() {}

int WordVector::get_count(const string text) const
{
    int index = find(text, 0, data.size()-1);
    
    if(index >= 0)
    {
       return data[index].get_count();
       
    }else
    {
       return -1;
    }

}

void WordVector::insert(const string text)
{

   
	steady_clock::time_point start_time = steady_clock::now();

	if (data.size() == 0)
	{
		data.push_back(Word(text));
	}

	else
	{

		int index = find(text, 0, data.size()-1);

	
		if (index < 0)
		{
			vector<Word>::iterator it = data.begin();
			while ((it != data.end()) && (text > it->get_text())) it++;
			it = data.insert(it, Word(text));
		}

		else
		{
			data[index].increment_count();
		}
	}

	steady_clock::time_point end_time = steady_clock::now();

	increment_elapsed_time(start_time, end_time);
}


vector<Word>::iterator WordVector::search(const string text)
{

    steady_clock::time_point start_time = steady_clock::now();

    int index = find(text, 0, data.size()-1);


   steady_clock::time_point end_time = steady_clock::now();
	increment_elapsed_time( start_time, end_time);

	if(index >= 0)
	{
	   return data.begin() + index;
	   
	}else
	{
	   return data.end();
	}
	
}


Word &WordVector::operator [] (int index)
{
	return data[index];
}

int WordVector::find(const string text, int low, int high) const
{
    while (low <= high) {
        int mid = (low + high)/2;

        if (text == data[mid].get_text()) {
            return mid;
        }
        else if (text < data[mid].get_text()) {
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }

    return -1;
}

int WordVector::size() const
{
 return data.size();
}