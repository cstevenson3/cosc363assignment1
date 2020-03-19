/*
 * scene.h
 *
 *  Created on: 19/03/2020
 *      Author: Cameron Stevenson
 */

#ifndef SRC_SCENE_H_
#define SRC_SCENE_H_

#include <vector>
#include "drawable.h"

using namespace std;

class Scene {
	public:
		Scene();
		void draw();
		void addDrawable(Drawable& drawable);
	private:
		vector<Drawable*> drawables;
};

#endif /* SRC_SCENE_H_ */
