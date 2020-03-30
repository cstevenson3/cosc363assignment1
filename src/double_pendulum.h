/*
 * double_pendulum.h
 *
 *  Created on: 30/03/2020
 *      Author: Cameron Stevenson
 */

#ifndef SRC_DOUBLE_PENDULUM_H_
#define SRC_DOUBLE_PENDULUM_H_

#include "drawable.h"

#include "vector3f.h"

class DoublePendulum : public Drawable {
	public:
		DoublePendulum() = default;
		DoublePendulum(Vector3f armColor, Vector3f ballColor, float gravity, float length1, float length2, float mass1, float mass2, float angle1, float angle2);

		// deltaTime is in seconds
		void update(float deltaTime);
		void draw();
	private:
		Vector3f armColor;
		Vector3f ballColor;

		//gravity
		float g;

		//lengths
		float l1;
		float l2;

		//mass
		float m1;
		float m2;

		//in radians

		//angles
		float a1;
		float a2;
		//angular velocities
		float w1;
		float w2;
};



#endif /* SRC_DOUBLE_PENDULUM_H_ */
