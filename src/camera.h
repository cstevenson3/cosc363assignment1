/*
 * camera.h
 *
 *  Created on: 17/03/2020
 *      Author: Cameron Stevenson
 */

#ifndef SRC_CAMERA_H_
#define SRC_CAMERA_H_

#include "vector3f.h"
#include "matrix4f.h"

class Camera {
	public:
		enum MODE {DOOM, FREECAM};
		Camera();
		Camera(MODE mode);

		MODE mode();
		void setMode(MODE mode);

		//right-hand coordinates
		Vector3f position();
		//anticlockwise looking in negative direction of axis, right-hand coordinates
		Vector3f rotation();

		//right-hand coordinates
		void deltaPosition(Vector3f deltaPosition);
		//anticlockwise looking in negative direction of axis, right-hand coordinates
		void deltaRotation(Vector3f deltaRotation);

		Vector3f lookAtReference();
		Vector3f lookAtUp();

		/* consider keys pressed etc. and update position, rotation etc. */
		void update(float dt);

		Vector3f freecamMotionWorldspace(Vector3f motionViewspace);
		Matrix4f freecamMotionTransform();
	private:
		MODE _mode;

		Vector3f pos;
		Vector3f rot;
};

#endif /* SRC_CAMERA_H_ */
