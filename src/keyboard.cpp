/*
 * keyboard.cpp
 *
 *  Created on: 17/03/2020
 *      Author: Cameron Stevenson
 */

#include "keyboard.h"
#include <iostream>
#include <vector>

using namespace std;

std::vector<void (*)(int key)> keyboardCallbacks;
bool keysPressed[256];

void addKeyboardCallback(void (*callback) (int key)) {
	keyboardCallbacks.push_back(callback);
}

void keyboardFunc(int key, int mouseX, int mouseY){
	for(auto &callback : keyboardCallbacks) {
		callback(key);
	}
}

void glutKeyboardCallback(unsigned char key, int mouseX, int mouseY) {
	keysPressed[key] = true;
	keyboardFunc(key, mouseX, mouseY);
}

void glutKeyboardUpCallback(unsigned char key, int mouseX, int mouseY) {
	keysPressed[key] = false;
}

void glutSpecialKeyboardCallback(int key, int mouseX, int mouseY) {
	keysPressed[key] = true;
	keyboardFunc(key, mouseX, mouseY);
}

void glutSpecialUpKeyboardCallback(int key, int mouseX, int mouseY) {
	keysPressed[key] = false;
}


void initKeyboard() {
	glutKeyboardFunc(glutKeyboardCallback);
	glutKeyboardUpFunc(glutKeyboardUpCallback);
	glutSpecialFunc(glutSpecialKeyboardCallback);
	glutSpecialUpFunc(glutSpecialUpKeyboardCallback);
}

bool isKeyDown(KEYS key) {
	return keysPressed[key];
}
