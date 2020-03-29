/*
 * vector3f.h
 *
 *  Created on: 18/03/2020
 *      Author: Cameron Stevenson
 */

#ifndef SRC_VECTOR3F_H_
#define SRC_VECTOR3F_H_

#include <iostream>
#include <string>

#include "vector4f.h"

class Vector3f {
	public:
		Vector3f();
		Vector3f(float f1, float f2, float f3);
		Vector3f(Vector4f vec4);
		void delta(float deltaF1, float deltaF2, float deltaF3);
		float f1() const;
		float f2() const;
		float f3() const;
		Vector3f operator + (const Vector3f& right);
		Vector3f& operator += (const Vector3f& right);
		friend std::ostream& operator<<(std::ostream &str, const Vector3f& v);
		float& operator[](int index);
	private:
		float _vec[3];
};



#endif /* SRC_VECTOR3F_H_ */
