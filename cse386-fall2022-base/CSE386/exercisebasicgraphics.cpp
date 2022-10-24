/****************************************************
 * 2016-2022 Eric Bachmann and Mike Zmuda
 * All Rights Reserved.
 * PLEASE NOTE:
 * Dissemination of this information or reproduction
 * of this material is prohibited unless prior written
 * permission is granted.
 ****************************************************/

#include <ctime>
#include <vector>
#include "defs.h"
#include "utilities.h"
#include "framebuffer.h"
#include "colorandmaterials.h"
#include "rasterization.h"
#include "io.h"

FrameBuffer frameBuffer(WINDOW_WIDTH, WINDOW_HEIGHT);

void render() {
	frameBuffer.clearColorBuffer();
	drawLine(frameBuffer, 0, 0, 100, 100, red);
	drawLine(frameBuffer, 100, 100, 200, 100, blue);
	frameBuffer.showColorBuffer();
}

void resize(int width, int height) {
	frameBuffer.setFrameBufferSize(width, height);
	glutPostRedisplay();
}

int old_main(int argc, char* argv[]) {
	// This is where you will do your testing of the functions
		// you implement in utilities.cpp
	double roots[2];
	int numRoots = quadratic(-1, 2, 5, roots);
	if (numRoots == 0) {
		std::cout << "There are no real roots" << endl;
		
	}
	else if (numRoots == 1) {
		std::cout << "Only one root: " << roots[0] << endl;
		
	}
	else if (numRoots == 2) {
		if (roots[0] > roots[1])
			std::cout << "Something is wrong. This should not happen" << endl;
		else
			std::cout << "Two roots: " << roots[0] << " and " << roots[1] << endl;
	}
	else {
		cout << "Something is wrong. This should not happen" << endl;
		
	}
	return 0;
}