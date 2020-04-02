/*
 * rubix_turn.h
 *
 *  Created on: 3/04/2020
 *      Author: Cameron Stevenson
 */

#ifndef SRC_RUBIX_TURN_H_
#define SRC_RUBIX_TURN_H_

#include <vector>
using namespace std;

class RubixTurn {
	public:
		enum AXIS {X, Y, Z};
		enum SIDE {NEGATIVE, POSITIVE}; //e.g. left and right for X
		enum DIRECTION {CC, C};

		AXIS* axis();
		SIDE* side();
		DIRECTION* direction();

		//from 0 to 1
		float* progress();
		vector<vector<int> > affectedLocations();
	private:
		AXIS _axis;
		SIDE _side;
		DIRECTION _direction;
		float _progress;
};



#endif /* SRC_RUBIX_TURN_H_ */
