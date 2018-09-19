/*
 * DataRandom.cpp
 *
 *  Created on: Apr 26, 2018
 *      Author: admin
 */

#include <stdlib.h>

#include <time.h>

#include "DataRandom.h"

#include "Element.h"



DataRandom::DataRandom() : DataGenerator("Unsorted random") {}



/***** Complete this file. *****/



void generate_data(vector<Element>& data, const int size)

{

    srand (time(NULL));

    long i=0;

    for(int j=0;j<size;j++)

    {

      i = rand();

      data.push_back(i);

    }

}
