/*
 * time.cpp
 *
 *  Created on: 20/03/2020
 *      Author: Cameron Stevenson
 */

#include "our_time.h"

#include <sys/time.h>
#include <iostream>

long int our_time::unixTimeMS() {
	struct timeval tp;
	gettimeofday(&tp, NULL);
	long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	//std::cout << ms << std::endl;
	return ms;
}
