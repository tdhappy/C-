#include <iostream>
#include "QuickSorter.h"
using namespace std;

QuickSorter::QuickSorter(string name) : VectorSorter(name) {}

QuickSorter::~QuickSorter() {}

void QuickSorter::run_sort_algorithm() throw (string)
{
    quicksort(0, size-1);
}

void QuickSorter::quicksort(const int left, const int right)
{

    if (left <= right)
    {

        Element& pivot = choose_pivot(left, right);
        int p = partition(left, right, pivot);

        quicksort(left, p-1);  
        quicksort(p+1, right); 
    }
}

Element& QuickSorter::choose_pivot(const int left, const int right)
{
    return choose_pivot_strategy(left, right);
}

int QuickSorter::partition(const int left, const int right, const Element& pivot)
{
    /***** Complete this function. *****/
}