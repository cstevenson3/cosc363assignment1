/*
 * rubix_cube.cpp
 *
 *  Created on: 2/04/2020
 *      Author: Cameron Stevenson
 */

#include "rubix_cube.h"

#include "rubix_block.h"
#include "draw_objects.h"

RubixCube::RubixCube() {
	for(int x = -1; x < 2; x++) {
		for(int y = -1; y < 2; y++) {
			for(int z = -1; z < 2; z++) {
				*(block(x, y, z)) = RubixBlock();
				block(x, y, z)->location()[0] = x;
				block(x, y, z)->location()[1] = y;
				block(x, y, z)->location()[2] = z;
				if(x == -1) {
					block(x, y, z)->colors()[0] = RubixBlock::COLORS::ORANGE;
				}
				if(x == 1) {
					block(x, y, z)->colors()[1] = RubixBlock::COLORS::RED;
				}
				if(y == -1) {
					block(x, y, z)->colors()[2] = RubixBlock::COLORS::YELLOW;
				}
				if(y == 1) {
					block(x, y, z)->colors()[3] = RubixBlock::COLORS::WHITE;
				}
				if(z == -1) {
					block(x, y, z)->colors()[4] = RubixBlock::COLORS::BLUE;
				}
				if(z == 1) {
					block(x, y, z)->colors()[5] = RubixBlock::COLORS::GREEN;
				}
			}
		}
	}
}

RubixBlock* RubixCube::block(int x, int y, int z) {
	return blocks + (x + 1) * 9 + (y + 1) * 3 + (z + 1);
}

void RubixCube::draw() {
	drawRubixCube(*this);
}
