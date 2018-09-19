/*
 * DataReverseSorted.cpp
 *
 *  Created on: Apr 26, 2018
 *      Author: admin
 */


#include "DataReverseSorted.h"



DataReverseSorted::DataReverseSorted() : DataGenerator("Reverse sorted") {}



/***** Complete this file. *****/



void generate_data(vector<Element>& data, const int size)

{

 Element temp;

int i, j, min_idx;


    // One by one move boundary of unsorted subarray

    for (i = 0; i < size-1; i++)

    {
        min_idx = i;

        for (j = i+1; j < size; j++)

          if (data[j] > data[min_idx])

            min_idx = j;

        temp=data[min_idx];

        data[min_idx]=data[i];

        data[i]=temp;

    }



}
