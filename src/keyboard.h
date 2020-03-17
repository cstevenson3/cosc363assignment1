/*
 * keyboard.h
 *
 *  Created on: 17/03/2020
 *      Author: Cameron Stevenson
 */

#ifndef SRC_KEYBOARD_H_
#define SRC_KEYBOARD_H_

#include <GL/glut.h>

enum KEYS {
	KEY_UP = GLUT_KEY_UP,
	KEY_DOWN = GLUT_KEY_DOWN,
	KEY_LEFT = GLUT_KEY_LEFT,
	KEY_RIGHT = GLUT_KEY_RIGHT
};

void addKeyboardCallback(void (*callback) (int key));
void initKeyboard();

#endif /* SRC_KEYBOARD_H_ */
