/*
 * float_proxy.h
 *
 *  Created on: 21/03/2020
 *      Author: Cameron Stevenson
 */

#ifndef SRC_FLOAT_PROXY_H_
#define SRC_FLOAT_PROXY_H_

/* a proxy object to make operator[] assignable to for other objects */
class FloatProxy {
	public:
		FloatProxy(float* pointer);
		FloatProxy& operator=(float f);
		operator float() {return *_pointer;};
	private:
		float* _pointer;
};


#endif /* SRC_FLOAT_PROXY_H_ */
