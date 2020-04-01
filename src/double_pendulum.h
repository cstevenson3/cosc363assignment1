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

		long double energy();
		long double Ek1();
		long double Ek2();
		long double Eg1();
		long double Eg2();
	private:
		Vector3f armColor;
		Vector3f ballColor;

		//gravity
		long double g;

		//lengths
		long double l1;
		long double l2;

		//mass
		long double m1;
		long double m2;

		//in radians

		//angles
		long double a1;
		long double a2;
		//angular velocities
		long double w1;
		long double w2;

		long double initialEnergy;
};



#endif /* SRC_DOUBLE_PENDULUM_H_ */
