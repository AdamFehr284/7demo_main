/*
 * filters.cpp
 *
 *  Created on: Feb 18, 2018
 *      Author: keith
 */
#include <algorithm>
#include "../includes/filters.h"
using namespace std;

int mysum =0;
int mynumbvals =0;
int myaverage = 0;

void sum(Data &d){
	if (d.age != UNINITIALIZED){
		mysum +=d.age;
		mynumbvals++;
	}
}

void replace_null_with_average(Data &d){
	if (d.age == UNINITIALIZED)
		d.age =myaverage;
}

void replaceMissingAgeWithAverageAge(std::vector<Data> &myData){
	//get total
	for_each(myData.begin(), myData.end(), sum);
	
	//find average
	if (mynumbvals >0)
		myaverage = mysum/mynumbvals;
	
	//replace all the empties by the average
	for_each(myData.begin(), myData.end(), replace_null_with_average);
}


