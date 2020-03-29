/*
 * float_proxy.cpp
 *
 *  Created on: 21/03/2020
 *      Author: Cameron Stevenson
 */

#include "float_proxy.h"

FloatProxy::FloatProxy(float* pointer) {
	_pointer = pointer;
}

FloatProxy& FloatProxy::operator=(float f) {
	*_pointer = f;
	return *this;
}
