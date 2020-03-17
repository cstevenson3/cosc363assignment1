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

void addKeyboardCallback(void (*callback) (int key)) {
	keyboardCallbacks.push_back(callback);
}

void keyboardFunc(int key, int mouseX, int mouseY){
	for(auto &callback : keyboardCallbacks) {
		callback(key);
	}
}

void glutKeyboardCallback(unsigned char key, int mouseX, int mouseY) {
	keyboardFunc(key, mouseX, mouseY);
}

void glutSpecialKeyboardCallback(int key, int mouseX, int mouseY) {
	keyboardFunc(key, mouseX, mouseY);
}


void initKeyboard() {
	glutKeyboardFunc(glutKeyboardCallback);
	glutSpecialFunc(glutSpecialKeyboardCallback);
}
