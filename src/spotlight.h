/*
 * spotlight.h
 *
 *  Created on: 5/04/2020
 *      Author: Cameron Stevenson
 */

#ifndef SRC_SPOTLIGHT_H_
#define SRC_SPOTLIGHT_H_

#include "drawable.h"

class Spotlight : public Drawable {
	public:
		Spotlight() = default;
		Spotlight(unsigned int lightID);
		void draw();
		void update(float deltaTime);

		unsigned int* lightID();
		float* phase();
	private:
		unsigned int _lightID;
		float _phase;
};


#endif /* SRC_SPOTLIGHT_H_ */
