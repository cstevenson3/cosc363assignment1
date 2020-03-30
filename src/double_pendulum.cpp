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
	a1 = angle1;
	a2 = angle2;
	w1 = 0.0;
	w2 = 0.0;
}

void DoublePendulum::update(float deltaTime) {
	float dt = deltaTime;

	a1 = math::floatMod(a1 + w1 * dt, 2 * PI);
	a2 = math::floatMod(a2 + w2 * dt, 2 * PI);

	// sourced from https://web.mit.edu/jorloff/www/chaosTalk/double-pendulum/double-pendulum-en.html
	float dw1dt = (-g*(2*m1+m2)*math::sinrad(a1) - m2*g*math::sinrad(a1-2*a2) - 2*math::sinrad(a1-a2)*m2*(w2*w2*l2+w1*w1*l1*math::cosrad(a1-a2))) / (l1*(2*m1+m2-m2*math::cosrad(2*a1-2*a2)));
	float dw2dt = (2*math::sinrad(a1-a2)*(w1*w1*l1*(m1+m2)) + g*(m1+m2)*math::cosrad(a1)+w2*w2*l2*m2*math::cosrad(a1-a2)) / (l2*(2*m1+m2-m2*math::cosrad(2*a1-2*a2)));

	float dw1 = dw1dt * dt;
	float dw2 = dw2dt * dt;

	w1 += dw1;
	w2 += dw2;


}

void DoublePendulum::draw() {
	drawDoublePendulum(math::radiansToDegrees(a1), math::radiansToDegrees(a2), l1, l2, armColor, ballColor);
}
