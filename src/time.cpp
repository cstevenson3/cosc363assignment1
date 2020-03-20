/*
 * time.cpp
 *
 *  Created on: 20/03/2020
 *      Author: Cameron Stevenson
 */

#include <sys/time.h>
#include "our_time.h"

long int our_time::unixTimeMS() {
	struct timeval tp;
	gettimeofday(&tp, NULL);
	long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	return ms;
}
