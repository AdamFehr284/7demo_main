/*
 * constants.h
 *
 *  Created on: Oct 5, 2017
 *      Author: keith
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_
#include <string>

const int 			SUCCESS			 				=  0;
const int 			USER_CHOSE_TO_EXIT 				= -1;
const int 			COULD_NOT_OPEN_FILE				= -2;
const int 			UNINITIALIZED 					= -5;

struct Data{
	std::string name;
	int age;
	std::string tshirt;
	void clear(){name.clear();tshirt.clear(); age=UNINITIALIZED;}
};

#endif /* CONSTANTS_H_ */
