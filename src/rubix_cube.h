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
#include "rubix_turn.h"

class RubixCube : public Drawable {
	public:
		RubixCube();

		void update(float deltaTime);
		void draw();

		RubixBlock* block(int x, int y, int z);

		//animation
		RubixTurn* currentTurn();
		vector<RubixBlock*> turningBlocks();
	private:
		RubixBlock blocks[27];
		RubixTurn _currentTurn;
};



#endif /* SRC_RUBIX_CUBE_H_ */
