/*
 * vase.cpp
 *
 *  Created on: 7/04/2020
 *      Author: Cameron Stevenson
 */

#include "vase.h"

#include "draw_objects.h"
#include "math.h"

Vase::Vase(int radialSubdivisions, int verticalSubdivisions) {
	_quads = vector<vector<int> >();
	_vertices = vector<vector<float> >();
	float verticalSegmentSize = 4.5 / verticalSubdivisions;
	float radialSegmentSize = 2. * PI / radialSubdivisions;
	for(int v = 0; v <= verticalSubdivisions; v++) {
		float y = -1 + v * verticalSegmentSize;
		float radius = math::max(0.4, 0.6 + 0.4 * (y + 1) * (y + 1) - math::exp(y - 1));
		for(int r = 0; r < radialSubdivisions; r++) {
			float angle = r * radialSegmentSize;
			float x = radius * math::sinrad(angle);
			float z = radius * math::cosrad(angle);
			vector<float> vertex = vector<float>(3);
			vertex[0] = x;
			vertex[1] = y;
			vertex[2] = z;
			_vertices.push_back(vertex);
		}
	}

	for(int v = 0; v < verticalSubdivisions; v++) {
		for(int r = 0; r < radialSubdivisions; r++) {
			vector<int> quad = vector<int>(4);
			quad[0] = v * radialSubdivisions + r;
			quad[1] = v * radialSubdivisions + (r + 1) % radialSubdivisions;
			quad[2] = (v + 1) * radialSubdivisions + (r + 1) % radialSubdivisions;
			quad[3] = (v + 1) * radialSubdivisions + r;
			_quads.push_back(quad);
		}
	}
}

vector<vector<int> >* Vase::quads() {
	return &_quads;
}

vector<vector<float> >* Vase::vertices() {
	return &_vertices;
}

void Vase::draw() {
	drawVase(*this);
}
