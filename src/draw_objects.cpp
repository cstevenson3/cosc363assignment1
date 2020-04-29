/*
 * draw_objects.cpp
 *
 *  Created on: 19/03/2020
 *      Author: Cameron Stevenson
 */

#include "draw_objects.h"

#include <iostream>
#include <algorithm>
#include <GL/freeglut.h>

#include "math.h"
#include "vector3f.h"
#include "floor_solid.h"

void drawWall(Vector3f dimensions, Vector3f color) {
	glColor3f(color.f1(), color.f2(), color.f3());
	glPushMatrix();
		glScalef(dimensions.f1(), dimensions.f2(), dimensions.f3());
		glutSolidCube(1.0);
	glPopMatrix();
}

void drawRoofSection(float height, float radius, float outerWidth, float wallThickness, GLuint textureID) {
	Vector3f apex = Vector3f(0, height, 0);
	Vector3f leftOuter = Vector3f(-outerWidth / 2, 0, radius);
	Vector3f rightOuter = Vector3f(outerWidth / 2, 0, radius);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glBegin(GL_TRIANGLES);
		//outer roof
		glTexCoord2f(0.5, 0.);
		glVertex3f(apex[0], apex[1], apex[2]);
		glTexCoord2f(0., 1.);
		glVertex3f(leftOuter[0], leftOuter[1], leftOuter[2]);
		glTexCoord2f(1., 1.);
		glVertex3f(rightOuter[0], rightOuter[1], rightOuter[2]);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void drawMuseum(Museum& museum, float numWalls, float radius, float height, float thickness, Vector3f color) {
	float angle = (360.0 / numWalls);
	for(int i = 1; i < numWalls; i++) {
		float rotation = angle * i;
		float outerWidth = 2 * radius * math::tan(angle / 2.0);
		glPushMatrix();
			glRotatef(rotation, 0.0, 1.0, 0.0); // rotate wall around to a side of the building
			glPushMatrix();
				glTranslatef(0.0, height / 2.0, radius - thickness / 2.0); // move outside of wall to building edge
				drawWall(Vector3f(outerWidth, height, thickness), color);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.0, height, 0);
				drawRoofSection(height, radius, outerWidth, thickness, *(museum.roofTextureID()));
			glPopMatrix();
		glPopMatrix();
	}
}

void drawFloorWireframe() {
	glDisable(GL_LIGHTING);
	glColor3f(0., 0.5,  0.);

	for(int i = -50; i <= 50; i ++)
	{
		glBegin(GL_LINES);
			glVertex3f(-50, 0.0, i);
			glVertex3f(50, 0.0, i);
			glVertex3f(i, 0.0, -50);
			glVertex3f(i, 0.0, 50);
		glEnd();
	}
	glEnable(GL_LIGHTING);
}

void drawFloorSolid(FloorSolid& floor) {
	glColor3f(0.5, 0.5, 0.5);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, *(floor.textureID()));
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	float res = 0.2;
	float size = 20;
	for(float x = -size; x < size; x += res) {
		for(float z = -size; z < size; z += res) {
			glBegin(GL_QUADS);
				glNormal3f(0., 1., 0.);
				glTexCoord2f(x, z);
				glVertex3f(x, 0., z);
				glTexCoord2f(x, z + res);
				glVertex3f(x, 0., z + res);
				glTexCoord2f(x + res, z + res);
				glVertex3f(x + res, 0., z + res);
				glTexCoord2f(x + res, z);
				glVertex3f(x + res, 0., z);
			glEnd();
		}
	}
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glDisable(GL_TEXTURE_2D);
}

void drawPendulum(float length, Vector3f armColor, Vector3f ballColor) {
	//arm
	glColor3f(armColor.f1(), armColor.f2(), armColor.f3());
	glPushMatrix();
		glScalef(0.05, length, 0.05);
		glTranslatef(0., -0.5, 0.);
		glutSolidCube(1.0);
	glPopMatrix();

	//ball
	glColor3f(ballColor.f1(), ballColor.f2(), ballColor.f3());
	glPushMatrix();
		glTranslatef(0., -length, 0.);
		glutSolidSphere(0.1, 32, 32);
	glPopMatrix();
}

void drawDoublePendulum(float angle1, float angle2, float length1, float length2, Vector3f armColor, Vector3f ballColor) {
	glPushMatrix();
		glRotatef(angle1, 0., 0., 1.);
		drawPendulum(length1, armColor, ballColor);
		glPushMatrix();
			glTranslatef(0., -length1, 0.);
			glRotatef(angle2 - angle1, 0., 0., 1.);
			drawPendulum(length2, armColor, ballColor);
		glPopMatrix();
	glPopMatrix();
}

void drawRubixBlock(RubixBlock& block) {
	glPushMatrix();
		int* location = block.location();
		glTranslatef(location[0] * 1., location[1] * 1., location[2] * 1.);

		//pass 0 is solid cubes, pass 1 is the thick black borders
		for(int i = 0; i < 2; i++) {
			Vector3f colors[6];
			if(i == 0) {
				for(int j = 0; j < 6; j++) {
					colors[j] = block.colorToRGB(block.colors()[j]);
				}
				glPolygonOffset(1,1);
				glEnable(GL_POLYGON_OFFSET_FILL);
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			}
			if(i == 1) {
				for(int j = 0; j < 6; j++) {
					colors[j] = Vector3f(0., 0., 0.);
				}
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				glLineWidth(1.);
			}
			Vector3f color;
			glBegin(GL_QUADS);
				//left
				color = colors[0];
				glNormal3f(-1., 0., 0.);
				glColor3f(color[0], color[1], color[2]);
				glVertex3f(-0.5, -0.5, -0.5);
				glVertex3f(-0.5, -0.5, 0.5);
				glVertex3f(-0.5, 0.5, 0.5);
				glVertex3f(-0.5, 0.5, -0.5);

				//right
				color = colors[1];
				glNormal3f(1., 0., 0.);
				glColor3f(color[0], color[1], color[2]);
				glVertex3f(0.5, -0.5, -0.5);
				glVertex3f(0.5, 0.5, -0.5);
				glVertex3f(0.5, 0.5, 0.5);
				glVertex3f(0.5, -0.5, 0.5);

				//bottom
				color = colors[2];
				glNormal3f(0., -1., 0.);
				glColor3f(color[0], color[1], color[2]);
				glVertex3f(-0.5, -0.5, -0.5);
				glVertex3f(0.5, -0.5, -0.5);
				glVertex3f(0.5, -0.5, 0.5);
				glVertex3f(-0.5, -0.5, 0.5);

				//top
				color = colors[3];
				glNormal3f(0., 1., 0.);
				glColor3f(color[0], color[1], color[2]);
				glVertex3f(-0.5, 0.5, -0.5);
				glVertex3f(-0.5, 0.5, 0.5);
				glVertex3f(0.5, 0.5, 0.5);
				glVertex3f(0.5, 0.5, -0.5);

				//back
				color = colors[4];
				glNormal3f(0., 0., -1.);
				glColor3f(color[0], color[1], color[2]);
				glVertex3f(-0.5, -0.5, -0.5);
				glVertex3f(-0.5, 0.5, -0.5);
				glVertex3f(0.5, 0.5, -0.5);
				glVertex3f(0.5, -0.5, -0.5);

				//front
				color = colors[5];
				glNormal3f(0., 0., 1.);
				glColor3f(color[0], color[1], color[2]);
				glVertex3f(-0.5, -0.5, 0.5);
				glVertex3f(0.5, -0.5, 0.5);
				glVertex3f(0.5, 0.5, 0.5);
				glVertex3f(-0.5, 0.5, 0.5);
			glEnd();
		}
	glPopMatrix();

	//reset
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glLineWidth(1.);
	glDisable(GL_POLYGON_OFFSET_FILL);
}

void drawRubixCube(RubixCube& cube) {
	glPushMatrix();
		glScalef(1./3., 1./3., 1./3.); // cube is initially drawn with size 3 for convenience
		//turning face
		vector<RubixBlock*> turningBlocks = cube.turningBlocks();
		Vector3f axis;
		float direction = *(cube.currentTurn()->direction()) == RubixTurn::DIRECTION::CC ? 1. : -1.;
		float angle = direction * 90.0 * *(cube.currentTurn()->progress());
		switch(*(cube.currentTurn()->axis())) {
		case RubixTurn::AXIS::X:
			axis = Vector3f(1., 0., 0.);
			break;
		case RubixTurn::AXIS::Y:
			axis = Vector3f(0., 1., 0.);
			break;
		case RubixTurn::AXIS::Z:
			axis = Vector3f(0., 0., 1.);
			break;
		}
		for(int x = -1; x < 2; x++) {
			for(int y = -1; y < 2; y++) {
				for(int z = -1; z < 2; z++) {
					if(std::find(turningBlocks.begin(), turningBlocks.end(), cube.block(x, y, z)) != turningBlocks.end()){
						glPushMatrix();
							glRotatef(angle, axis[0], axis[1], axis[2]);
							drawRubixBlock(*(cube.block(x, y, z)));
						glPopMatrix();
					} else {
						drawRubixBlock(*(cube.block(x, y, z)));
					}
				}
			}
		}
	glPopMatrix();
}

void drawSkybox(Skybox& skybox) {

	glPushMatrix();
		glScalef(1000., 1000., 1000.);
		glEnable(GL_TEXTURE_2D);

		//left
		glBindTexture(GL_TEXTURE_2D, skybox.texIDs()[0]);
		glBegin(GL_QUADS);
			glTexCoord2f(0., 0.);
			glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(1., 0.);
			glVertex3f(-0.5, -0.5, -0.5);
			glTexCoord2f(1., 1.);
			glVertex3f(-0.5, 0.5, -0.5);
			glTexCoord2f(0., 1.);
			glVertex3f(-0.5, 0.5, 0.5);
		glEnd();

		//right
		glBindTexture(GL_TEXTURE_2D, skybox.texIDs()[1]);
		glBegin(GL_QUADS);
			glTexCoord2f(0., 0.);
			glVertex3f(0.5, -0.5, -0.5);
			glTexCoord2f(1., 0.);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(1., 1.);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(0., 1.);
			glVertex3f(0.5, 0.5, -0.5);
		glEnd();

		//bottom
		glBindTexture(GL_TEXTURE_2D, skybox.texIDs()[2]);
		glBegin(GL_QUADS);
			glTexCoord2f(0., 0.);
			glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(1., 0.);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(1., 1.);
			glVertex3f(0.5, -0.5, -0.5);
			glTexCoord2f(0., 1.);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();

		//top
		glBindTexture(GL_TEXTURE_2D, skybox.texIDs()[3]);
		glBegin(GL_QUADS);
			glTexCoord2f(0., 0.);
			glVertex3f(-0.5, 0.5, -0.5);
			glTexCoord2f(1., 0.);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(1., 1.);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(0., 1.);
			glVertex3f(-0.5, 0.5, 0.5);
		glEnd();

		//back
		glBindTexture(GL_TEXTURE_2D, skybox.texIDs()[4]);
		glBegin(GL_QUADS);
			glTexCoord2f(0., 0.);
			glVertex3f(-0.5, -0.5, -0.5);
			glTexCoord2f(1., 0.);
			glVertex3f(0.5, -0.5, -0.5);
			glTexCoord2f(1., 1.);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(0., 1.);
			glVertex3f(-0.5, 0.5, -0.5);
		glEnd();

		//front
		glBindTexture(GL_TEXTURE_2D, skybox.texIDs()[5]);
		glBegin(GL_QUADS);
			glTexCoord2f(0., 0.);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(1., 0.);
			glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(1., 1.);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(0., 1.);
			glVertex3f(0.5, 0.5, 0.5);
		glEnd();

	glPopMatrix();

	//reset
	glDisable(GL_TEXTURE_2D);
}

void drawSpotlightEnclosure() {
	// bottom face will be the "source" of the light, with size 1 by 1
	// top face will be smaller with size (TOP * 2)  by (TOP * 2)
	float TOP = 0.25;

	glDisable(GL_LIGHTING);
	glBegin(GL_QUADS);
		//bottom
		glColor3f(1., 1., 1.); // white bottom
		glVertex3f(-0.5, -0.5, -0.5);
		glVertex3f(0.5, -0.5, -0.5);
		glVertex3f(0.5, -0.5, 0.5);
		glVertex3f(-0.5, -0.5, 0.5);
	glEnd();
	glEnable(GL_LIGHTING);

	glBegin(GL_QUADS);
		//top
		glColor3f(0.5, 0.5, 0.5); // grey for everything else
		glVertex3f(-TOP, 0.5, -TOP);
		glVertex3f(-TOP, 0.5, TOP);
		glVertex3f(TOP, 0.5, TOP);
		glVertex3f(TOP, 0.5, -TOP);

		//left
		glVertex3f(-0.5, -0.5, -0.5);
		glVertex3f(-0.5, -0.5, 0.5);
		glVertex3f(-TOP, 0.5, TOP);
		glVertex3f(-TOP, 0.5, -TOP);

		//right
		glVertex3f(0.5, -0.5, -0.5);
		glVertex3f(TOP, 0.5, -TOP);
		glVertex3f(TOP, 0.5, TOP);
		glVertex3f(0.5, -0.5, 0.5);

		//back
		glVertex3f(-0.5, -0.5, -0.5);
		glVertex3f(-TOP, 0.5, -TOP);
		glVertex3f(TOP, 0.5, -TOP);
		glVertex3f(0.5, -0.5, -0.5);

		//front
		glVertex3f(-0.5, -0.5, 0.5);
		glVertex3f(0.5, -0.5, 0.5);
		glVertex3f(TOP, 0.5, TOP);
		glVertex3f(-TOP, 0.5, TOP);
	glEnd();
}

void drawSpotlight(Spotlight& spotlight) {
	float angle = 20.0;

	drawSpotlightEnclosure();

	float lpos[4] = {0., 0., 0., 1.0};  //spotlight's position
	float ldiffuse[4] = {1., 1., 1., 1.0};
	float ldirection[3] = {0., -1., 0.};
	unsigned int lightID = *(spotlight.lightID());
	glLightfv(lightID, GL_POSITION, lpos);   //Set spotlight position
	glLightfv(lightID, GL_DIFFUSE, ldiffuse);   //Set spotlight diffuse
	glLightfv(lightID, GL_SPECULAR, ldiffuse);   //Set spotlight diffuse
	glLightfv(lightID, GL_SPOT_DIRECTION, ldirection);
	glLightf(lightID, GL_SPOT_CUTOFF, angle);
	glLightf(lightID, GL_SPOT_EXPONENT,0.01);
}

void drawVase(Vase& vase) {
	glScalef(1./3., 1./4.5, 1./3.);
	glTranslatef(0., 1., 0.);
	vector<vector<int> > tris = *(vase.tris());
	vector<Vector3f > vertices = *(vase.vertices());
	vector<Vector3f > normals = *(vase.normals());
	glColor3f(0.,1.,0.);
	glBegin(GL_TRIANGLES);
		for(int q = 0; q < tris.size(); q++) {
			Vector3f normal = normals[q];
			for(int v = 0; v < 3; v++) {
				Vector3f vertex = vertices[tris[q][v]];
				glNormal3f(normal[0], normal[1], normal[2]);
				glVertex3f(vertex[0], vertex[1], vertex[2]);
			}
		}
	glEnd();
}
