/*
 * rubix_cube.h
 *
 *  Created on: 2/04/2020
 *      Author: Cameron Stevenson
 */

#ifndef SRC_RUBIX_CUBE_H_
#define SRC_RUBIX_CUBE_H_

#include "drawable.h"
#include "rubix_block.h"

class RubixCube : public Drawable {
	public:
		RubixCube();

		//void update(float deltaTime);
		void draw();

		RubixBlock* block(int x, int y, int z);
	private:
		RubixBlock blocks[27];
};



#endif /* SRC_RUBIX_CUBE_H_ */
