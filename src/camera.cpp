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
	return this->pos + Vector3f(0, 0, -1); //TODO
}

Vector3f Camera::lookAtUp() {
	return Vector3f(0, 1, 0); //TODO
}

void Camera::update() {
	long int currentTime = our_time::unixTimeMS();
	switch(_mode) {
	case DOOM:
		if(isKeyDown(KEY_UP)) {
			deltaPosition(Vector3f(0, 0, -0.05));
		}
		if(isKeyDown(KEY_DOWN)) {
			deltaPosition(Vector3f(0, 0, 0.05));
		}
	}
}
