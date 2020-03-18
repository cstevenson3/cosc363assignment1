/*
 * camera.cpp
 *
 *  Created on: 17/03/2020
 *      Author: Cameron Stevenson
 */

#include "camera.h"
#include "math.h"

Camera::Camera () {
	this->mode = Camera::FREECAM;
}

Camera::Camera (MODE mode) {
	this->mode = mode;
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
	return this->pos + Vector3f(0, 0, 1); //TODO
}

Vector3f Camera::lookAtUp() {
	return Vector3f(0, 1, 0); //TODO
}
