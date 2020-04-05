/*
 * scene.cpp
 *
 *  Created on: 19/03/2020
 *      Author: Cameron Stevenson
 */

#include "scene.h"

#include <GL/freeglut.h>

Scene::Scene() {
	drawables = vector<Drawable*>();
}

void Scene::draw() {
	for(Drawable* drawable : drawables) {
		if(drawable->isVisible()) {
			glPushMatrix();
				glTranslatef((*(drawable->position()))[0], (*(drawable->position()))[1], (*(drawable->position()))[2]);
				glRotatef((*(drawable->rotationAngle())), (*(drawable->rotationAxis()))[0], (*(drawable->rotationAxis()))[1], (*(drawable->rotationAxis()))[2]);
				drawable->draw();
			glPopMatrix();
		}
	}
}

void Scene::addDrawable(Drawable& drawable) {
	drawables.push_back(&drawable);
}
