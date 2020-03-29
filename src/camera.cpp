/*
 * camera.cpp
 *
 *  Created on: 17/03/2020
 *      Author: Cameron Stevenson
 */

#include "camera.h"

#include "math.h"
#include "our_time.h"
#include "keyboard.h"
#include "vector4f.h"

Camera::Camera () {
	this->_mode = Camera::FREECAM;
	lastTime = our_time::unixTimeMS();
}

Camera::Camera (MODE mode) {
	this->_mode = mode;
	lastTime = our_time::unixTimeMS();
}

Camera::MODE Camera::mode() {
	return _mode;
}

void Camera::setMode(Camera::MODE mode) {
	_mode = mode;
}

Vector3f Camera::position() {
	return this->pos;
}

Vector3f Camera::rotation() {
	return this->rot;
}

void Camera::deltaPosition(Vector3f deltaPosition) {
	this->pos += deltaPosition;
}

void Camera::deltaRotation(Vector3f deltaRotation) {
	this->rot += deltaRotation;
}

Vector3f Camera::lookAtReference() {
	return this->pos + freecamMotionWorldspace(Vector3f(0, 0, 1));
}

Vector3f Camera::lookAtUp() {
	return Vector3f(0, 1, 0); // TODO if pitch is introduced
}

void Camera::update() {
	long int currentTime = our_time::unixTimeMS();
	switch(_mode) {
	case DOOM:
		if(isKeyDown(KEY_UP)) {
			deltaPosition(freecamMotionWorldspace(Vector3f(0, 0, 0.05)));
		}
		if(isKeyDown(KEY_DOWN)) {
			deltaPosition(freecamMotionWorldspace(Vector3f(0, 0, -0.05)));
		}

		if(isKeyDown(KEY_LEFT)) {
			deltaRotation(Vector3f(0, 2, 0));
		}
		if(isKeyDown(KEY_RIGHT)) {
			deltaRotation(Vector3f(0, -2, 0));
		}
	}
}

Vector3f Camera::freecamMotionWorldspace(Vector3f motionViewspace) {
	Matrix4f freecamMotionTransform = Camera::freecamMotionTransform();
	Vector3f freecamMotionWorldspace = Vector3f(freecamMotionTransform * Vector4f(motionViewspace));
	return freecamMotionWorldspace;
}

Matrix4f Camera::freecamMotionTransform() {
	Matrix4f result = Matrix4f::identity();

	float cosPitch = math::cos(rot.f1());
	float cosYaw = math::cos(rot.f2());

	float sinPitch = math::sin(rot.f1());
	float sinYaw = math::sin(rot.f2());

	result[0][0] = cosYaw;
	result[0][2] = -sinYaw;
	result[2][0] = -sinYaw;//*cosPitch;
	result[2][2] = -cosYaw;//*cosPitch
	return result;
}
