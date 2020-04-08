/*
 * drawable.h
 *
 *  Created on: 19/03/2020
 *      Author: Cameron Stevenson
 */

#ifndef SRC_DRAWABLE_H_
#define SRC_DRAWABLE_H_

#include "vector3f.h"

class Drawable {
	public:
		virtual void draw() = 0;
		bool isVisible();
		void setVisibility(bool visible);
		Drawable();
		virtual inline ~Drawable() = 0;
		Vector3f* position();
		Vector3f* rotationAxis();
		float* rotationAngle();
		float* scale();
	private:
		bool _visible;
		Vector3f _position;
		Vector3f _rotationAxis;
		float _rotationAngle;
		float _scale;
};
Drawable::~Drawable () {}

#endif /* SRC_DRAWABLE_H_ */
