/*
 * vase.h
 *
 *  Created on: 7/04/2020
 *      Author: Cameron Stevenson
 */

#ifndef SRC_VASE_H_
#define SRC_VASE_H_

#include "drawable.h"

#include <vector>

using namespace std;

class Vase : public Drawable {
	public:
		Vase(int radialSubdivisions, int verticalSubdivisions);
		Vase() : Vase(16, 16) {};
		void draw();
		vector<vector<int> >* quads();
		vector<vector<float> >* vertices();
	private:
		vector<vector<int> > _quads;
		vector<vector<float> > _vertices;
};


#endif /* SRC_VASE_H_ */
