/*
 * rubix_cube.cpp
 *
 *  Created on: 2/04/2020
 *      Author: Cameron Stevenson
 */

#include "rubix_cube.h"

#include <iostream>

#include "draw_objects.h"

RubixTurn generateRandomTurn() {
	RubixTurn turn = RubixTurn();

	switch(rand() % 3) {
	case 0:
		*(turn.axis()) = RubixTurn::AXIS::X;
		break;
	case 1:
		*(turn.axis()) = RubixTurn::AXIS::Y;
		break;
	case 2:
		*(turn.axis()) = RubixTurn::AXIS::Z;
		break;
	}

	switch(rand() % 2) {
	case 0:
		*(turn.side()) = RubixTurn::SIDE::NEGATIVE;
		break;
	case 1:
		*(turn.side()) = RubixTurn::SIDE::POSITIVE;
		break;
	}

	switch(rand() % 2) {
	case 0:
		*(turn.direction()) = RubixTurn::DIRECTION::CC;
		break;
	case 1:
		*(turn.direction()) = RubixTurn::DIRECTION::C;
		break;
	}
	*(turn.direction()) = RubixTurn::DIRECTION::CC;
	*(turn.progress()) = 0.0;
	return turn;
}

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
	_currentTurn = generateRandomTurn();
}



RubixBlock* RubixCube::block(int x, int y, int z) {
	return blocks + (x + 1) * 9 + (y + 1) * 3 + (z + 1);
}

void RubixCube::correctBlocksOrdering() {
	RubixBlock tmp[27];
	for(int i = 0; i < 27; i++) {
		tmp[i] = blocks[i];
	}
	//find correct block for each location, put it back into blocks
	for(int x = -1; x < 2; x++) {
		for(int y = -1; y < 2; y++) {
			for(int z = -1; z < 2; z++) {
				for(int t = 0; t < 27; t++) {
					int* loc = tmp[t].location();
					if(x == loc[0] && y == loc[1] && z == loc[2]) {
						//match
						*(block(x, y, z)) = tmp[t];
					}
				}
			}
		}
	}
}

void RubixCube::update(float deltaTime) {
	*(_currentTurn.progress()) += deltaTime;
	if(*(_currentTurn.progress()) > 1.0) {
		for(RubixBlock* block : turningBlocks()) {
			block->updateWithTurn(_currentTurn);
		}
		correctBlocksOrdering();
		_currentTurn = generateRandomTurn();
	}
}

void RubixCube::draw() {
	drawRubixCube(*this);
}

RubixTurn* RubixCube::currentTurn() {
	return &_currentTurn;
}

vector<RubixBlock*> RubixCube::turningBlocks() {
	vector<RubixBlock*> _turningBlocks(9);
	vector<vector<int> > blockLocations = _currentTurn.affectedLocations();
	for(int i = 0; i < 9; i++) {
		_turningBlocks[i] = block(blockLocations[i][0], blockLocations[i][1], blockLocations[i][2]);
	}
	return _turningBlocks;
}
