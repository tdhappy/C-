/*
 * DataAllZeroes.cpp
 *
 *  Created on: Apr 26, 2018
 *      Author: admin
 */

#include "DataAllZeros.h"



DataAllZeros::DataAllZeros() : DataGenerator("All zeroes") {}


//DataAllZeros::~DataAllZeros() : DataGenerator("All zeroes") {}


/***** Complete this file. *****/



void generate_data(vector<Element>& data, const int size)

{

   for(int i=0;i<size;i++)

   {
      data.push_back(0);
   }

}

