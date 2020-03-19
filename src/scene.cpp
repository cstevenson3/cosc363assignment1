/*
 * scene.cpp
 *
 *  Created on: 19/03/2020
 *      Author: Cameron Stevenson
 */

#include "scene.h"

Scene::Scene() {
	drawables = vector<Drawable*>();
}

void Scene::draw() {
	for(Drawable* drawable : drawables) {
		drawable->draw();
	}
}

void Scene::addDrawable(Drawable& drawable) {
	drawables.push_back(&drawable);
}
