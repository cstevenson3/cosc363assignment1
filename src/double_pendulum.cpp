/*
 * double_pendulum.cpp
 *
 *  Created on: 30/03/2020
 *      Author: Cameron Stevenson
 */

#include "double_pendulum.h"

#include "math.h"
#include "draw_objects.h"
#include <iostream>

DoublePendulum::DoublePendulum(Vector3f armColor, Vector3f ballColor, float gravity, float length1, float length2, float mass1, float mass2, float angle1, float angle2) {
	this->armColor = armColor;
	this->ballColor = ballColor;
	g = gravity;
	l1 = length1;
	l2 = length2;
	m1 = mass1;
	m2 = mass2;
	a1 = math::degreesToRadians(angle1);
	a2 = math::degreesToRadians(angle2);
	w1 = 0.0;
	w2 = 0.0;
	initialEnergy = energy();
}

void DoublePendulum::draw() {
	drawDoublePendulum(math::radiansToDegrees(a1), math::radiansToDegrees(a2), l1, l2, armColor, ballColor);
}

void DoublePendulum::update(float deltaTime) {
	long double dt = deltaTime;

	// sourced from https://web.mit.edu/jorloff/www/chaosTalk/double-pendulum/double-pendulum-en.html
	long double dw1dt = (-g*(2*m1+m2)*math::sinrad(a1) - m2*g*math::sinrad(a1-2*a2) - 2*math::sinrad(a1-a2)*m2*(w2*w2*l2+w1*w1*l1*math::cosrad(a1-a2))) / (l1*(2*m1+m2-m2*math::cosrad(2*a1-2*a2)));
	long double dw2dt = (2*math::sinrad(a1-a2)*(w1*w1*l1*(m1+m2) + g*(m1+m2)*math::cosrad(a1)+w2*w2*l2*m2*math::cosrad(a1-a2))) / (l2*(2*m1+m2-m2*math::cosrad(2*a1-2*a2)));

//	//weights
//	float Fg1 = - m1 * g * math::sinrad(a1);
//	float Fg2 = - m2 * g * math::sinrad(a2);
//
//	//centripetal acceleration
//	float Fc2 = m2 * w2 * w2 * l2;
//
//	//tensions
//	float T2 = m2 * g * math::cosrad(a2) + Fc2;
//	float T2p = T2 * math::sinrad(a2 - a1); // T2 acting perpendicular on ball 1
//
//	//torques
//	float tau1 = (T2p + Fg1) * l1;
//	float tau2 = Fg2 * l2;
//
//	//moment of inertias
//	float i1 = m1 * l1 * l1;
//	float i2 = m2 * l2 * l2;
//
//	float dw1dt = tau1/i1;
//	float dw2dt = tau2/i2;

	long double dw1 = dw1dt * dt;
	long double dw2 = dw2dt * dt;

	w1 += dw1;
	w2 += dw2;

	//error correction
	long double energyLost = initialEnergy - energy();
	std::cout << energyLost << std::endl;
	//inject lost energy back into pendulum 1
	long double desiredEk1 = Ek1() + energyLost;
	if(desiredEk1 > 0) {
		long double w1abs = math::sqrt(2 * desiredEk1 / (m1 * l1 * l1));
		if(w1 > 0){
			w1 = w1abs;
		} else {
			w1 = -w1abs;
		}
	}

	std::cout << energyLost << std::endl << std::endl;

	a1 += w1 * dt;
	a2 += w2 * dt;
}

long double DoublePendulum::energy() {
	//total energy
	return Eg1() + Eg2() + Ek1() + Ek2();
}

long double DoublePendulum::Ek1() {
	//kinectic
	long double vx1 = w1 * l1 * math::cosrad(a1);
	long double vy1 = w1 * l1 * math::sinrad(a1);

	long double v1 = math::sqrt(vx1 * vx1 + vy1 * vy1);

	long double _Ek1 = 0.5 * m1 * v1 * v1;

	return _Ek1;
}

long double DoublePendulum::Ek2() {
	//kinetic
	long double vx1 = w1 * l1 * math::cosrad(a1);
	long double vy1 = w1 * l1 * math::sinrad(a1);

	long double vx2 = vx1 + w2 * l2 * math::cosrad(a2);
	long double vy2 = vy1 + w2 * l2 * math::sinrad(a2);

	long double v2 = math::sqrt(vx2 * vx2 + vy2 * vy2);

	long double _Ek2 = 0.5 * m2 * v2 * v2;

	return _Ek2;
}

long double DoublePendulum::Eg1() {
	//gravitational
	long double x1 = l1 * math::sinrad(a1);
	long double y1 = - l1 * math::cosrad(a1);

	long double _Eg1 = m1 * g * y1;

	return _Eg1;
}

long double DoublePendulum::Eg2() {
	long double x1 = l1 * math::sinrad(a1);
	long double y1 = - l1 * math::cosrad(a1);

	long double x2 = x1 + l2 * math::sinrad(a2);
	long double y2 = y1 - l2 * math::cosrad(a2);

	long double _Eg2 = m2 * g * y2;

	return _Eg2;
}
