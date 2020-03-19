/*
 * drawable.h
 *
 *  Created on: 19/03/2020
 *      Author: Cameron Stevenson
 */

#ifndef SRC_DRAWABLE_H_
#define SRC_DRAWABLE_H_

class Drawable {
	public:
		virtual void draw() = 0;
		bool isVisible();
		void setVisibility(bool visible);
		Drawable();
		virtual inline ~Drawable() = 0;
	private:
		bool visible;
};
Drawable::~Drawable () {}

#endif /* SRC_DRAWABLE_H_ */
