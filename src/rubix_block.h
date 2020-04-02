/*
 * rubix_block.h
 *
 *  Created on: 2/04/2020
 *      Author: Cameron Stevenson
 */

#ifndef SRC_RUBIX_BLOCK_H_
#define SRC_RUBIX_BLOCK_H_

#include "vector3f.h"
#include "rubix_turn.h"

class RubixBlock {
	public:
		RubixBlock();
		enum COLORS {ORANGE, RED, YELLOW, WHITE, BLUE, GREEN, INSIDE};
		int* location();
		//left, right, bottom, top, back, front
		COLORS* colors();

		Vector3f colorToRGB(COLORS color);
		void updateWithTurn(RubixTurn& turn);
	private:
		int _location[3];
		//left, right, bottom, top, back, front
		COLORS _colors[6];
};


#endif /* SRC_RUBIX_BLOCK_H_ */
