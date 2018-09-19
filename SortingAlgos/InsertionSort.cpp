/*
 * InsertionSort.cpp
 *
 *  Created on: Apr 26, 2018
 *      Author: admin
 */

#include "InsertionSort.h"
#include "VectorSorter.h"

InsertionSort::InsertionSort() : VectorSorter("Insertion sort") {}

void run_sort_algorithm()

{
   for (int i = 1; i < size; i++) 
   {
                                Element val = data[i];
                                //move_count++;
                                int j = i - 1;
                                while (j >= 0) {
                                                compare_count++;
                                                if (data[j] > val) 
                                                {
                                                      data[j + 1] = data[j];
                                                      move_count++;
                                                      j = j - 1;

                                                } else

                                              break;
                                } //end while
                                data[j + 1] = val;
                }

}
