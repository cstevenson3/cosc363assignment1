/*
 * vase.cpp
 *
 *  Created on: 7/04/2020
 *      Author: Cameron Stevenson
 */

#include "vase.h"

#include "draw_objects.h"
#include "math.h"

Vector3f calculateVertex(float verticalSegmentSize, float radialSegmentSize, float v, float r) {
	float y = -1 + v * verticalSegmentSize;
	float angle = r * radialSegmentSize;
	float radius = math::max(0.4, 0.6 + 0.4 * (y + 1) * (y + 1) - math::exp(y - 1));
	float x = radius * math::sinrad(angle);
	float z = radius * math::cosrad(angle);
	return Vector3f(x, y, z);
}

Vase::Vase(int radialSubdivisions, int verticalSubdivisions) {
	_tris = vector<vector<int> >();
	_vertices = vector<Vector3f >();
	_normals = vector<Vector3f >();
	float verticalSegmentSize = 4.5 / verticalSubdivisions;
	float radialSegmentSize = 2. * PI / radialSubdivisions;
	for(int v = 0; v <= verticalSubdivisions; v++) {
		for(int r = 0; r < radialSubdivisions; r++) {
			Vector3f vec3 = calculateVertex(verticalSegmentSize, radialSegmentSize, v, r);
			_vertices.push_back(vec3);
		}
	}

	for(int v = 0; v < verticalSubdivisions; v++) {
		for(int r = 0; r < radialSubdivisions; r++) {
			vector<int> tri1 = vector<int>(3);
			tri1[0] = v * radialSubdivisions + r; //bottom left
			tri1[1] = v * radialSubdivisions + (r + 1) % radialSubdivisions; //bottom right
			tri1[2] = (v + 1) * radialSubdivisions + r; //top left
			vector<int> tri2 = vector<int>(3);
			tri2[0] = v * radialSubdivisions + (r + 1) % radialSubdivisions; //bottom right
			tri2[1] = (v + 1) * radialSubdivisions + (r + 1) % radialSubdivisions; //top right
			tri2[2] = (v + 1) * radialSubdivisions + r; //top left

			_tris.push_back(tri1);
			_tris.push_back(tri2);

			//normals
			Vector3f u1 = _vertices[tri1[1]] - _vertices[tri1[0]];
			Vector3f v1 = _vertices[tri1[2]] - _vertices[tri1[0]];
			Vector3f normal1 = Vector3f::cross(u1, v1);
			_normals.push_back(normal1);

			Vector3f u2 = _vertices[tri2[1]] - _vertices[tri2[0]];
			Vector3f v2 = _vertices[tri2[2]] - _vertices[tri2[0]];
			Vector3f normal2 = Vector3f::cross(u2, v2);
			_normals.push_back(normal2);
		}
	}
}

vector<vector<int> >* Vase::tris() {
	return &_tris;
}

vector<Vector3f >* Vase::vertices() {
	return &_vertices;
}

vector<Vector3f >* Vase::normals() {
	return &_normals;
}

void Vase::draw() {
	drawVase(*this);
}
