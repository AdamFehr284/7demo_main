//============================================================================
// Name        : 7demo_main.cpp
// Author      : 
// Version     :
// Copyright   : Steal this code!
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include "../includes/constants.h"
#include "../../7demo_fileio/src/fileio.h"
#include "../includes/filters.h"

using namespace std;

const int FAIL_WRONG_NUMBER_ARGS = -5;
const int EXPECTED_NUMBER_ARGUMENTS =3;
const string WRONG_NUMB_ARGS = "This program expects 2 arguments, infile outfile";
const string WHAT_I_DO = "Data is read from infile, transformed, and then written to outfile";

int main( int argc, char *argv[] )  {
	//argc = how many arguments passed in (including this program)
	//char *argv[] char array of those arguments

	//expect progname infile outfile  
   if( argc != EXPECTED_NUMBER_ARGUMENTS ) {
	   cout<< WRONG_NUMB_ARGS <<endl;
	   
	   if (argc == 2 && ((argv[1][1]) == 'h' || (argv[1][1] == 'H' )))
		   cout<< WHAT_I_DO <<endl;			   
	   return FAIL_WRONG_NUMBER_ARGS;
   }
   string infile = argv[1];
   string outfile = argv[2];
   
   //get the data
   std::vector<Data> allData;
   int iret = readFileIntoVector(allData, infile);
   if (iret != SUCCESS)
	   return iret;
   
   //process the data with filters
   replaceMissingAgeWithAverageAge(allData);
   
   //save the data
   iret = writeDataToFile(allData, outfile);
  
}
