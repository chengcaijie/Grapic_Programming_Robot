//#include <Windows.h>
//#include <gl/GL.h>
//#include <gl/GLU.h>
//#include <math.h>
//#define PI 3.14159265
//#pragma comment (lib, "OpenGL32.lib")
//
//#define WINDOW_TITLE "Assignment"
//
///*
//Minimum 4 different textures
//head: 1 texture
//body: 1 texture
//hand: 1 texture
//leg: 1 texture
//need can change to another texture
//
//Lighting: must have ambient and diffuse, must be able to move light source
//Lighting and texture both need to do on and off
//
//
//Interactive Features
//all parts must move freely
//
//Walking: leg and hand must move, other model translate
//Attacking
//
//Viewport: Must have ortho and perspective
//Fully transformation: do the tx, ty, rx, ry
//
//Specific Features: must have one weapon
//*/
//
//bool isMove = false;
//
//// ==== PROJECTION ====
//float tx = 0, tz = 0, tSpeed = 1; // translate for model along the z-axis
//bool isOrtho = true; // is orthographic view?
//float ONear = -10, OFar = 10; // ortho near and far
//float PNear = 4, PFar = 21; // perspective near and far
//float ptx = 0, pty = 0, ptSpeed = 0.1; // translate for projection
//float pry = 0, prSpeed = 1;
//
//double optOrangeColor[3] = { 0.847 ,0.129 ,0.129 }; //D92121
//double optRedColor[3] = { 0.691 , 0.0705 , 0.149 }; //B1126
//double optLightRed[3] = { 0.847, 0.13, 0.13 };
//double optlightGrey[3] = { 0.82,0.82,0.82 }; //D3D3D3
//double optGrey[3] = { 0.656,0.662,0.675 }; //A8A9AD
//double optBlue[3] = { 0,0.06,0.66 }; //4682BF
//double optlightBColor[3] = { 0.274, 0.509, 0.749 }; //4682BF
//LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//	switch (msg)
//	{
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//
//	case WM_KEYDOWN:
//		if (wParam == VK_ESCAPE)
//			PostQuitMessage(0);
//		/*if (wParam == VK_SPACE) {
//			if (isMove == false) {
//				isMove = true;
//			}
//			else {
//				isMove = false;
//			}
//		}*/
//
//		// ==== PROJECTION ====
//		else if (wParam == VK_UP) {
//			if (isOrtho) {
//				if (tz < OFar)
//					tz += tSpeed;
//			}
//			else {
//				if (tz < PFar)
//					tz += tSpeed;
//			}
//		}
//		else if (wParam == VK_DOWN) {
//			if (isOrtho) {
//				if (tz > ONear)
//					tz -= tSpeed;
//			}
//			else {
//				if (tz > PNear)
//					tz -= tSpeed;
//			}
//		}
//		else if (wParam == VK_LEFT) {
//			tx -= tSpeed;
//		}
//		else if (wParam == VK_RIGHT) {
//			tx += tSpeed;
//		}
//		else if (wParam == 'O') {
//			isOrtho = true;
//			tz = 0;
//		}
//		else if (wParam == 'P') {
//			isOrtho = false;
//			tz = 0;
//		}
//		else if (wParam == 'A') {
//			ptx -= ptSpeed;
//		}
//		else if (wParam == 'D') {
//			ptx += ptSpeed;
//		}
//		else if (wParam == 'L') {
//			pry -= prSpeed;
//		}
//		else if (wParam == 'R') {
//			pry += prSpeed;
//		}
//		break;
//	default:
//		break;
//	}
//
//	return DefWindowProc(hWnd, msg, wParam, lParam);
//}
////--------------------------------------------------------------------
//
//bool initPixelFormat(HDC hdc)
//{
//	PIXELFORMATDESCRIPTOR pfd;
//	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));
//
//	pfd.cAlphaBits = 8;
//	pfd.cColorBits = 32;
//	pfd.cDepthBits = 24;
//	pfd.cStencilBits = 0;
//
//	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
//
//	pfd.iLayerType = PFD_MAIN_PLANE;
//	pfd.iPixelType = PFD_TYPE_RGBA;
//	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
//	pfd.nVersion = 1;
//
//	// choose pixel format returns the number most similar pixel format available
//	int n = ChoosePixelFormat(hdc, &pfd);
//
//	// set pixel format returns whether it sucessfully set the pixel format
//	if (SetPixelFormat(hdc, n, &pfd))
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
////--------------------------------------------------------------------
//
//// ==== PROJECTION =====
//void projection() {
//	glMatrixMode(GL_PROJECTION); // refer to projection matrix
//	glLoadIdentity(); // reset the projection matrix
//
//	glTranslatef(tx, 0, 0);
//	glTranslatef(ptx, pty, 0); // translate for projection
//	glRotatef(pry, 0, 1, 0); // rotate y-axis for projection
//
//	if (isOrtho) {
//		// === Ortho View ===
//		// ortho view has no zoom in and zoom out feature
//		// ratio is 1:1, must match with windows resolution
//		// (search CreateWindow, after USEDEFAULT value)
//		glOrtho(-5, 5, -5, 5, ONear, OFar);
//	}
//	else {
//		// === Perspective View ===
//		// use when u want to zoom in and zoom out
//		gluPerspective(20, 1, -1, 1);
//		glFrustum(-5, 5, -5, 5, PNear, PFar); // z value must be positive
//	}
//}
//
//// ==== DRAWINGS ====
//void drawLine(float x1, float y1, float z1, float x2, float y2, float z2) {
//	glBegin(GL_LINES);
//	glVertex3f(x1, y1, z1);
//	glVertex3f(x2, y2, z2);
//	glEnd();
//}
////
////void drawHemisphere(float r) {
////	const float PI = 3.141592f;
////	float x, y, z, sliceA, stackA;
////	int sliceNo = 30, stackNo = 30;
////	glColor3f(0.2, 0.6, 0.1);
////	for (sliceA = 0.0; sliceA < PI; sliceA += PI / sliceNo) {
////		glBegin(GL_POLYGON);
////		for (stackA = 0.0; stackA < PI; stackA += PI / stackNo) {
////			x = r * cos(stackA) * sin(sliceA);
////			y = r * sin(stackA) * sin(sliceA);
////			z = r * cos(sliceA);
////			glVertex3f(x, y, z);
////			x = r * cos(stackA) * sin(sliceA + PI / stackNo);
////			y = r * sin(stackA) * sin(sliceA + PI / sliceNo);
////			z = r * cos(sliceA + PI / sliceNo);
////			glVertex3f(x, y, z);
////		}
////		glEnd();
////	}
////}
//
//void drawCube(float sz) {
//	// 6 quads each call
//	glBegin(GL_QUADS);
//	// Face 1: Bottom
//	glColor3f(1, 0, 0);
//	glVertex3f(0, 0, sz);
//	glVertex3f(sz, 0, sz);
//	glVertex3f(sz, 0, 0);
//	glVertex3f(0, 0, 0);
//	// Face 2: Left
//	glColor3f(0, 1, 0);
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, sz, 0);
//	glVertex3f(0, sz, sz);
//	glVertex3f(0, 0, sz);
//	// Face 3: Front
//	glColor3f(0, 0, 1);
//	glVertex3f(0, 0, sz);
//	glVertex3f(0, sz, sz);
//	glVertex3f(sz, sz, sz);
//	glVertex3f(sz, 0, sz);
//	// Face 4: Right
//	glColor3f(1, 1, 0);
//	glVertex3f(sz, 0, sz);
//	glVertex3f(sz, sz, sz);
//	glVertex3f(sz, sz, 0);
//	glVertex3f(sz, 0, 0);
//	// Face 5: Back
//	glColor3f(0, 1, 1);
//	glVertex3f(sz, 0, 0);
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, sz, 0);
//	glVertex3f(sz, sz, 0);
//	// Face 6: Top
//	glColor3f(1, 0, 1);
//	glVertex3f(sz, sz, 0);
//	glVertex3f(0, sz, 0);
//	glVertex3f(0, sz, sz);
//	glVertex3f(sz, sz, sz);
//	glEnd();
//}
//
//void drawCuboid(float x, float y, float sz) {
//	// 6 quads each call
//	glBegin(GL_QUADS);
//	// Face 1: Bottom
//	glColor3f(1, 0, 0);
//	glVertex3f(0, 0, sz);
//	glVertex3f(x, 0, sz);
//	glVertex3f(x, 0, 0);
//	glVertex3f(0, 0, 0); // last point of the face will be the 1st point for next face
//	// Face 2: Left
//	glColor3f(0, 1, 1);
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, y, 0);
//	glVertex3f(0, y, sz);
//	glVertex3f(0, 0, sz);
//	// Face 3: Front
//	glColor3f(0, 1, 0);
//	glVertex3f(0, 0, sz);
//	glVertex3f(0, y, sz);
//	glVertex3f(x, y, sz);
//	glVertex3f(x, 0, sz);
//	// Face 4: Right
//	glColor3f(1, 0, 1);
//	glVertex3f(x, 0, sz);
//	glVertex3f(x, y, sz);
//	glVertex3f(x, y, 0);
//	glVertex3f(x, 0, 0);
//	// Face 5: Back
//	glColor3f(0, 0, 1);
//	glVertex3f(x, 0, 0);
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, y, 0);
//	glVertex3f(x, y, 0);
//	// Face 6: Top
//	glColor3f(1, 1, 1);
//	glVertex3f(x, y, 0);
//	glVertex3f(0, y, 0);
//	glVertex3f(0, y, sz);
//	glVertex3f(x, y, sz);
//	glEnd();
//}
//
//void drawCuboid2(float size, float ratio) {
//	//front
//	glColor3f(0, 0, 1);
//	glBegin(GL_QUADS);
//	/*glTexCoord2f(0.0, 1.0);*/
//	glVertex3f(0, size, size);
//	//glTexCoord2f(1.0, 1.0);
//	glVertex3f(0, 0, size);
//	//glTexCoord2f(1.0, 0.0);
//	glVertex3f(size * ratio, 0, size);
//	//glTexCoord2f(0.0, 0.0);
//	glVertex3f(size * ratio, size, size);
//	//glEnd();
//
//	//right
//	glColor3f(0, 1, 0);
//	//glBegin(type);
//	/*glTexCoord2f(0.0, 1.0), */glVertex3f(size * ratio, size, size);
//	/*glTexCoord2f(1.0, 1.0),*/ glVertex3f(size * ratio, 0, size);
//	/*glTexCoord2f(1.0, 0.0),*/ glVertex3f(size * ratio, 0, 0);
//	/*glTexCoord2f(0.0, 0.0),*/ glVertex3f(size * ratio, size, 0);
//	//glEnd();
//
//	//left
//	glColor3f(1, 1, 1);
//	//glBegin(type);
//	/*glTexCoord2f(0.0, 1.0),*/ glVertex3f(0, size, size);
//	/*glTexCoord2f(1.0, 1.0),*/ glVertex3f(0, 0, size);
//	/*glTexCoord2f(1.0, 0.0),*/ glVertex3f(0, 0, 0);
//	/*glTexCoord2f(0.0, 0.0),*/ glVertex3f(0, size, 0);
//	//glEnd();
//	//bottom
//
//	glColor3f(0, 1, 0);
//	//glBegin(type);
//	/*glTexCoord2f(0.0, 1.0)*/ glVertex3f(0, 0, size);
//	/*glTexCoord2f(1.0, 1.0),*/ glVertex3f(size * ratio, 0, size);
//	/*glTexCoord2f(1.0, 0.0),*/ glVertex3f(size * ratio, 0, 0);
//	/*glTexCoord2f(0.0, 0.0),*/ glVertex3f(0, 0, 0);
//	//glEnd();
//
//	//top
//	//glBegin(type);
//	glColor3f(1.0, 1.0, 0.0);
//	//glTexCoord2f(0.0, 1.0);
//	glVertex3f(0, size, size);
//	//glTexCoord2f(1.0, 1.0);
//	glVertex3f(size * ratio, size, size);
//	//glTexCoord2f(1.0, 0.0);
//	glVertex3f(size * ratio, size, 0);
//	//glTexCoord2f(0.0, 0.0);
//	glVertex3f(0, size, 0);
//	//glEnd();
//
//	//back
//	glColor3f(0, 1.0, 1.0);
//	//glBegin(type);
//	//glTexCoord2f(0.0, 1.0);
//	glVertex3f(0, size, 0);
//	//glTexCoord2f(1.0, 1.0);
//	glVertex3f(size * ratio, size, 0);
//	//glTexCoord2f(1.0, 0.0);
//	glVertex3f(size * ratio, 0, 0);
//	//glTexCoord2f(0.0, 0.0);
//	glVertex3f(0, 0, 0);
//	glEnd();
//}
//
//void drawPrism(float x1, float x2, float y, float z) {
//	// 3 quads, 2 triangles each call
//	// Face 1
//	glColor3f(0.4, 0.4, 0);
//	glBegin(GL_QUADS);
//	glVertex3f(x1, 0, 0);
//	glVertex3f(x2, 0, 0);
//	glVertex3f(x2, y, 0);
//	glVertex3f(x1, y, 0);
//
//	// Face 2
//	glVertex3f(x1, y, 0);
//	glVertex3f(x1, 0, 0);
//	glVertex3f(x1, 0, z);
//	glVertex3f(x1, y, z);
//
//	// Face 3
//	glVertex3f(x1, y, z);
//	glVertex3f(x2, y, 0); // 0.35, 0.2, 0
//	glVertex3f(x2, 0, 0); // 0.35, 0, 0
//	glVertex3f(x1, 0, z); // 0.2, 0, 0.4
//	glEnd();
//
//	// Face 4
//	glBegin(GL_TRIANGLES);
//	glVertex3f(x1, 0, z); // 0.2, 0, 0.4
//	glVertex3f(x1, 0, 0);
//	glVertex3f(x2, 0, 0);
//
//	// Face 5
//	glVertex3f(x2, y, 0);
//	glVertex3f(x1, y, 0);
//	glVertex3f(x1, y, z);
//	glEnd();
//}
//
//void drawPyramid(float sz) {
//	glLineWidth(5);
//	glBegin(GL_QUADS);
//	glColor3f(1, 0, 1);
//	// Face 1: Base
//	glVertex3f(0, 0, sz);
//	glVertex3f(sz, 0, sz);
//	glVertex3f(sz, 0, 0);
//	glVertex3f(0, 0, 0);
//	glEnd();
//	glBegin(GL_TRIANGLE_STRIP);
//	// Face 2
//	glVertex3f(sz / 2, sz, sz / 2);
//	glVertex3f(0, 0, sz);
//	glVertex3f(sz / 2, sz, sz / 2);
//	glVertex3f(sz, 0, sz);
//	glVertex3f(sz / 2, sz, sz / 2);
//	glVertex3f(sz, 0, 0);
//	glVertex3f(sz / 2, sz, sz / 2);
//	glVertex3f(0, 0, 0);
//	glVertex3f(sz / 2, sz, sz / 2);
//	glVertex3f(0, 0, sz);
//	glEnd();
//}
//
//void drawRectangleLine() {
//	glScalef(0.5, 0.5, 1);
//	glBegin(GL_LINE_LOOP);
//	glVertex2f(0, 0);
//	glVertex2f(0.2, 0);
//	glVertex2f(0.2, -0.5);
//	glVertex2f(0, -0.5);
//	glEnd();
//}
//
//void drawSphere(double r) {
//	GLUquadricObj* sphere = NULL;
//	sphere = gluNewQuadric();
//	glColor3f(1, 1, 0);
//	glRotatef(0.01, 1, 1, 1);
//	gluQuadricDrawStyle(sphere, GLU_LINE);
//	gluSphere(sphere, r, 30, 30);
//	gluDeleteQuadric(sphere);
//}
//
//void drawCylinder(double br, double tr, double h) {
//	GLUquadricObj* cylinder = NULL;
//	cylinder = gluNewQuadric();
//	glColor3f(1, 1, 0);
//	glRotatef(0.01, 1, 1, 1);
//	gluQuadricDrawStyle(cylinder, GLU_LINE);
//	gluCylinder(cylinder, br, tr, h, 10, 10);
//	gluDeleteQuadric(cylinder);
//}
//
//// ==== ROBOT MODEL (PARTIAL) ====
//void lowerChest() {
//	// back
//		// lower left
//	glPushMatrix();
//	{
//		glTranslatef(-0.375, 1.59, -0.2);
//		glRotatef(-30, 0, 0, 1);
//		drawCuboid2(0.25, 2);
//		glPushMatrix();
//		{
//			glTranslatef(0, 0.25, 0);
//			drawCuboid2(0.25, 2);
//			glPushMatrix();
//			{
//				glTranslatef(0, 0.25, 0);
//				drawCuboid2(0.25, 2);
//			}
//			glPopMatrix();
//		}
//		glPopMatrix();
//	}
//	glPopMatrix();
//
//	// lower right
//	glPushMatrix();
//	{
//		glTranslatef(0.72, 1.29, -0.2);
//		glRotatef(30, 0, 0, 1);
//		drawCuboid2(0.25, 2);
//		glPushMatrix();
//		{
//			glTranslatef(0, 0.25, 0);
//			drawCuboid2(0.25, 2);
//			glPushMatrix();
//			{
//				glTranslatef(0, 0.25, 0);
//				drawCuboid2(0.25, 2);
//			}
//			glPopMatrix();
//		}
//		glPopMatrix();
//	}
//	glPopMatrix();
//
//	// center
//	glPushMatrix();
//	{
//		glTranslatef(0.13, 1.2, -0.2);
//		drawCuboid2(0.25, 2);
//		glPushMatrix();
//		{
//			glTranslatef(0, 0.25, 0);
//			drawCuboid2(0.25, 2);
//			glPushMatrix();
//			{
//				glTranslatef(0, 0.25, 0);
//				drawCuboid2(0.25, 2);
//				glPushMatrix();
//				{
//					glTranslatef(0, 0.25, 0);
//					drawCuboid2(0.25, 2);
//					glPushMatrix();
//					{
//						glTranslatef(0, 0.25, 0);
//						drawCuboid2(0.25, 2);
//						glPushMatrix();
//						{
//							glTranslatef(0, 0.25, 0);
//							drawCuboid2(0.25, 2);
//							//glPushMatrix();
//							//{
//							//	glTranslatef(0, 0.25, 0);
//							//	drawCuboid2(0.25, 2);
//							//}
//							//glPopMatrix();
//						}
//						glPopMatrix();
//					}
//					glPopMatrix();
//				}
//				glPopMatrix();
//			}
//			glPopMatrix();
//		}
//		glPopMatrix();
//	}
//	glPopMatrix();
//
//	// upper left
//	glPushMatrix();
//	{
//		glTranslatef(0.1, 2, -0.2);
//		glRotatef(30, 0, 0, 1);
//		drawCuboid2(0.25, 2);
//		glPushMatrix();
//		{
//			glTranslatef(0, 0.25, 0);
//			drawCuboid2(0.25, 2);
//			//glPushMatrix();
//			//{
//			//	glTranslatef(0, 0.25, 0);
//			//	drawCuboid2(0.25, 2);
//			//}
//			//glPopMatrix();
//		}
//		glPopMatrix();
//	}
//	glPopMatrix();
//
//	// upper right
//	glPushMatrix();
//	{
//		glTranslatef(0.2, 2.2, -0.2);
//		glRotatef(-30, 0, 0, 1);
//		drawCuboid2(0.25, 2);
//		glPushMatrix();
//		{
//			glTranslatef(0, 0.25, 0);
//			drawCuboid2(0.25, 2);
//			//glPushMatrix();
//			//{
//			//	glTranslatef(0, 0.25, 0);
//			//	drawCuboid2(0.25, 2);
//			//}
//			//glPopMatrix();
//		}
//		glPopMatrix();
//	}
//	glPopMatrix();
//
//	// front
//	drawLine(0.2, 1.3, 0.075, 0.575, 1.3, 0.075);
//	drawLine(0.2, 1.3, 0.075, 0.15, 2.5, 0.075);
//	drawLine(0.575, 1.3, 0.075, 0.625, 2.5, 0.075);
//	drawLine(0.15, 2.5, 0.075, 0.625, 2.5, 0.075);
//	drawLine(0.19, 1.5, 0.075, 0.075, 1.5, 0.075);
//	drawLine(0.565, 1.5, 0.075, 0.68, 1.5, 0.075);
//	drawLine(0.17, 1.7, 0.075, 0.0, 1.37, 0.075);
//	drawLine(0.6, 1.7, 0.075, 0.755, 1.325, 0.075);
//	drawLine(0.6, 1.7, 0.075, 0.17, 1.7, 0.075);
//	drawLine(0.27, 1.7, 0.075, 0.4, 1.6, 0.075);
//	drawLine(0.52, 1.7, 0.075, 0.4, 1.6, 0.075);
//	drawLine(0.27, 1.7, 0.075, 0.27, 2.5, 0.075);
//	drawLine(0.52, 1.7, 0.075, 0.52, 2.5, 0.075);
//	drawLine(0.27, 1.7, 0.075, 0.33, 1.8, 0.075);
//	drawLine(0.52, 1.7, 0.075, 0.46, 1.8, 0.075);
//	drawLine(0.33, 1.8, 0.075, 0.46, 1.8, 0.075);
//	drawLine(-0.05, 1.4, 0.075, 0.18, 1.9, 0.075);
//	drawLine(0.85, 1.36, 0.075, 0.62, 1.9, 0.075);
//	drawLine(0.18, 1.9, 0.075, 0.62, 1.9, 0.075);
//	//drawLine(0.27, 2.0, 0.075, 0.4, 1.9, 0.075);
//	//drawLine(0.52, 2.0, 0.075, 0.4, 1.9, 0.075);
//	drawLine(0.27, 1.9, 0.075, 0.33, 2.0, 0.075);
//	drawLine(0.52, 1.9, 0.075, 0.46, 2.0, 0.075);
//	drawLine(0.33, 2.0, 0.075, 0.46, 2.0, 0.075);
//	drawLine(-0.15, 1.45, 0.075, 0.18, 2.1, 0.075);
//	drawLine(0.95, 1.4, 0.075, 0.62, 2.1, 0.075);
//	drawLine(0.18, 2.1, 0.075, 0.62, 2.1, 0.075);
//	drawLine(0.27, 2.1, 0.075, 0.33, 2.2, 0.075);
//	drawLine(0.52, 2.1, 0.075, 0.46, 2.2, 0.075);
//	drawLine(0.33, 2.2, 0.075, 0.46, 2.2, 0.075);
//	drawLine(-0.25, 1.5, 0.075, 0.1, 2.3, 0.075);
//	drawLine(0.1, 2.3, 0.075, -0.07, 2.48, 0.075);
//	drawLine(1.0, 1.45, 0.075, 0.7, 2.3, 0.075);
//	drawLine(0.7, 2.3, 0.075, 0.84, 2.415, 0.075);
//	drawLine(0.15, 2.3, 0.075, 0.6, 2.3, 0.075);
//	drawLine(0.27, 2.3, 0.075, 0.33, 2.4, 0.075);
//	drawLine(0.52, 2.3, 0.075, 0.46, 2.4, 0.075);
//	drawLine(0.33, 2.4, 0.075, 0.46, 2.4, 0.075);
//	drawLine(-0.07, 2.47, 0.075, 0.27, 2.5, 0.075);
//	drawLine(0.84, 2.415, 0.075, 0.52, 2.5, 0.075);
//	drawLine(0.27, 2.5, 0.075, 0.4, 2.6, 0.075);
//	drawLine(0.52, 2.5, 0.075, 0.4, 2.6, 0.075);
//}
//
////void legpt1() {
////	glPushMatrix();
////	{
////		//glScalef(1.5, 1.5, 1);
////		glTranslatef(0, 1.2, 0);
////		glPushMatrix();
////		{
////			glTranslatef(-0.5, 0, 0);
////			glPushMatrix();
////			{
////				glRotatef(-20, 0, 0, 1);
////				glPushMatrix();
////				{
////					glRotatef(-90, 1, 0, 0);
////					drawCuboid(0.2, 0.2, 0.4);
////					drawPrism(0.2, 0.35, 0.2, 0.4);
////				}
////				glPopMatrix();
////			}
////			glPopMatrix();
////		}
////		glPopMatrix();
////		glPushMatrix();
////		{
////			glTranslatef(-0.5, -0.12, -0.2);
////			glRotatef(90, 1, 0, 0);
////			drawPrism(0, 0.33, 0.2, -0.12);
////		}
////		glPopMatrix();
////		glPushMatrix();
////		{
////			glTranslatef(-0.5, -0.522, 0);
////			glRotatef(-90, 1, 0, 0);
////			drawCuboid(0.2, 0.2, 0.4);
////			glPushMatrix();
////			{
////				glTranslatef(0, 0.2, 0.42);
////				glRotatef(180, 1, 0, 0);
////				drawPrism(0.2, 0.325, 0.2, 0.4);
////			}
////			glPopMatrix();
////		}
////		glPopMatrix();
////		glPushMatrix();
////		{
////			glTranslatef(-0.5, -0.05, -0.31);
////			glRotatef(90, 0, 1, 0);
////			glRotatef(90, 0, 0, 1);
////			glRotatef(180, 0, 1, 0);
////			glRotatef(-90, 1, 0, 0);
////			drawPrism(0.6, 0.3, 0.2, 0.2);
////		}
////		glPopMatrix();
////		glPushMatrix();
////		{
////			glTranslatef(-0.3, -0.6, -0.15);
////			glRotatef(-90, 0, 0, 1);
////			drawHemisphere(0.12);
////		}
////		glPopMatrix();
////		glPushMatrix();
////		{
////			glTranslatef(-0.5, -0.85, -0.2);
////			drawCube(0.2);
////		}
////		glPopMatrix();
////		glPushMatrix();
////		{
////			glTranslatef(-0.5, -0.9, -0.25);
////			glRotatef(45, 1, 0, 0);
////			glRotatef(90, 0, 0, 1);
////			glRotatef(90, 1, 0, 0);
////			drawCube(0.2);
////			glPopMatrix();
////		}
////		glPopMatrix();
////	}
////	glPopMatrix();
////}
//
//void legpt2() {
//	glPushMatrix();
//	{
//		//glScalef(1.5, 1.5, 1);
//		glTranslatef(0, 1.2, 0);
//		glPushMatrix();
//		{
//			glTranslatef(-0.3, -0.76, -0.1);
//			glRotatef(45, 1, 0, 0);
//			glRotatef(-90, 0, 0, 1);
//			drawPyramid(0.2);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		{
//			glTranslatef(-0.5, -1.15, -0.2);
//			drawCube(0.2);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		{
//			glTranslatef(-0.47, -2.4, -0.025);
//			glRotatef(-90, 1, 0, 0);
//			drawCuboid(0.15, 0.15, 1.4);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		{
//			glTranslatef(-0.45, -1.2, -0.001);
//			drawRectangleLine();
//		}
//		glPopMatrix();
//		glPushMatrix();
//		{
//			glTranslatef(-0.45, -1.6, -0.001);
//			drawRectangleLine();
//		}
//		glPopMatrix();
//		glPushMatrix();
//		{
//			glTranslatef(-0.45, -2, -0.001);
//			drawRectangleLine();
//		}
//		glPopMatrix();
//		glPushMatrix();
//		{
//			glTranslatef(-0.55, -1.5, -0.8);
//			glRotatef(90, 0, 1, 0);
//			glRotatef(90, 1, 0, 0);
//			glRotatef(180, 0, 1, 0);
//			drawPrism(0.6, 0.3, 0.3, 0.4);
//		}
//		glPopMatrix();
//	}
//	glPopMatrix();
//}
//
//void legpt3() {
//	glPushMatrix();
//	{
//		glTranslatef(-0.25, -1.2, -0.15);
//		glRotatef(90, 0, 0, 1);
//		glRotatef(90, 0, 1, 0);
//		drawCuboid(0.15, 0.3, 0.9);
//	}
//	glPopMatrix();
//
//	/*glPushMatrix();
//	{
//		glTranslatef(-0.68, -1.74, -0.3);
//		drawCube(0.275);
//		glPushMatrix();
//		{
//			glTranslatef(0.275, 0, 0);
//			drawCube(0.275);
//		}
//		glPopMatrix();
//	}
//	glPopMatrix();*/
//
//	glPushMatrix();
//	{
//		glTranslatef(-0.11, -1.4, 0.4);
//		glRotatef(90, 0, 1, 0);
//		glRotatef(-90, 1, 0, 0);
//		drawPrism(0.8, 0.3, 0.55, 0.3);
//	}
//	glPopMatrix();
//
//	glColor3f(1, 1, 1);
//	glPushMatrix();
//	{
//		glTranslatef(-0.26, -1.35, 0.05);
//		glRotatef(45, 1, 0, 0);
//		glRotatef(90, 0, 1, 0);
//		glRotatef(90, 1, 0, 0);
//		drawRectangleLine();
//	}
//	glPopMatrix();
//
//	glPushMatrix();
//	{
//		// translate (x, y, z)
//		glTranslatef(-0.8, -1.8, -0.32);
//		drawCuboid2(0.4, 2);
//	}
//	glPopMatrix();
//	glPushMatrix();
//	{
//		glTranslatef(-0.8, -1.7, -0.05);
//		drawCuboid2(0.3, 2.67);
//	}
//	glPopMatrix();
//
//	glPushMatrix();
//	{
//		glTranslatef(-0.8, -1.8, -0.05);
//		drawCube(0.3);
//		glPushMatrix();
//		{
//			glTranslatef(0.3, 0, 0);
//			drawCube(0.3);
//			glPushMatrix();
//			{
//				glTranslatef(0.2, 0, 0);
//				drawCube(0.3);
//			}
//			glPopMatrix();
//		}
//		glPopMatrix();
//	}
//	glPopMatrix();
//}
//
////void leg() {
////	legpt1();
////	legpt2();
////	legpt3();
////}
//
//// ==== MISCELLANEOUS / EXTRA THINGS ====
//void hiddenFloor() {
//	glBegin(GL_QUADS);
//	glNormal3f(0, 1, 0);
//	glVertex3f(0, -1.0, 1.0);
//	glVertex3f(0, -1.0, -1.0);
//	glVertex3f(0, 1.0, -1.0);
//	glVertex3f(0, 1.0, 1.0);
//	glEnd();
//}
//
////void stencil() {
////	glEnable(GL_STENCIL_TEST); // Enable using the stencil buffer
////	glColorMask(0, 0, 0, 0); // Disable drawing colors to the screen
////	glDisable(GL_DEPTH_TEST); // Disable depth testing
////	glStencilFunc(GL_ALWAYS, 1, 1); // Make the stencil test always pass
////	// Make pixels in the stencil buffer be set to 1 when the stencil test buffer
////	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
////	// Set all of the pixels covered by the floor to be 1 in the stencil buffer
////	hiddenFloor();
////
////	glColorMask(1, 1, 1, 1); // Enable drawing colors to the screen
////	glEnable(GL_DEPTH_TEST); // Enable depth testing
////	// Make the stencil test pass only when the pixel is 1 in the stencil buffer
////	glStencilFunc(GL_EQUAL, 1, 1);
////	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP); // Make the stencil buffer not change
////
////	// Reflect horizontally
////	glPushMatrix();
////	{
////		glTranslatef(1, 0, 0);
////		glScalef(-1, 1, 1);
////		leg();
////	}
////	glPopMatrix();
////
////	glDisable(GL_STENCIL_TEST); // Disable using the stencil buffer
////}
////void drawCube(float size) {
////	glBegin(GL_QUADS);
////	//face size :Bottom
////	glColor3f(1, 0, 0);
////	glVertex3f(0, 0, size);
////	glVertex3f(size, 0, size);
////	glVertex3f(size, 0, 0);
////	glVertex3f(0, 0, 0);//stop here , and this will be the next point 
////	//face 2 :left 
////	glColor3f(0, 1, 0);
////	glVertex3f(0, 0, 0);
////	glVertex3f(0, size, 0);
////	glVertex3f(0, size, size);
////	glVertex3f(0, 0, size);
////	//face 3: front
////	glColor3f(0, 0, 1);
////	glVertex3f(0, 0, size);
////	glVertex3f(0, size, size);
////	glVertex3f(size, size, size);
////	glVertex3f(size, 0, size);
////	//face 4: right face
////	glColor3f(1, 1, 0);
////	glVertex3f(size, 0, size);
////	glVertex3f(size, size, size);
////	glVertex3f(size, size, 0);
////	glVertex3f(size, 0, 0);
////	//face 5:back
////	glColor3f(1, 0, 1);
////	glVertex3f(size, 0, 0);
////	glVertex3f(0, 0, 0);
////	glVertex3f(0, size, 0);
////	glVertex3f(size, size, 0);
////	//face 6 top
////	glColor3f(0, 1, 1);
////	glVertex3f(size, size, 0);
////	glVertex3f(0, size, 0);
////	glVertex3f(0, size, size);
////	glVertex3f(size, size, size);
////
////	glEnd();
////}
//
//void drawQuads(double length, double width, double height) {
//	glPushMatrix();
//	glBegin(GL_QUADS);
//		//Bottom
//		glVertex3f(0, 0, 0);// A
//		glVertex3f(0, length, 0);// B
//		glVertex3f(width, length, 0);// C
//		glVertex3f(width, 0, 0);// D
//	
//		//RIGHT
//		glVertex3f(width, 0, 0);// D
//		glVertex3f(width, 0, height);// L
//		glVertex3f(width, length, height);// K
//		glVertex3f(width, length, 0);// C
//	
//		//BEHIND 
//		glVertex3f(width, length, 0);// C
//		glVertex3f(width, length, height);// K
//		glVertex3f(0, length, height);// J
//		glVertex3f(0, length, 0);// B
//	
//		//LEFT
//		glVertex3f(0, length, 0);// B
//		glVertex3f(0, length, height);// J
//		glVertex3f(0, 0, height);// I
//		glVertex3f(0, 0, 0);// A
//	
//		//FRONT 
//		glVertex3f(0, 0, 0);// A
//		glVertex3f(width, 0, 0);// D
//		glVertex3f(width, 0, height);// L
//		glVertex3f(0, 0, height);// I
//	
//		//TOP
//		glVertex3f(0, 0, height);// I
//		glVertex3f(width, 0, height);// L
//		glVertex3f(width, length, height);// K
//		glVertex3f(0, length, height);// J
//		glEnd();
//		glPopMatrix();
//	
//}
//
//void headPyramid(float sz) {
//	glPushMatrix();
//	//glLineWidth(5);
//	glBegin(GL_QUADS);
//	//glColor3f(1, 0, 1);
//	// Face 1: Base
//	glTexCoord2f(0, 1);
//	glVertex3f(0, 0, sz);
//	glTexCoord2f(1, 1);
//	glVertex3f(sz, 0, sz);
//	glTexCoord2f(1, 0);
//	glVertex3f(sz, 0, 0);
//	glTexCoord2f(0, 0);
//	glVertex3f(0, 0, 0);
//	glEnd();
//	glBegin(GL_TRIANGLE_STRIP);
//	// Face 2
//	glTexCoord3f(0.5, 1, 0.5);
//	glVertex3f(sz / 2, sz, sz / 2);
//	glTexCoord3f(0, 0, 1);
//	glVertex3f(0, 0, sz);
//	glTexCoord3f(0.5, 1, 0.5);
//	glVertex3f(sz / 2, sz, sz / 2);
//	glTexCoord3f(1, 0, 1);
//	glVertex3f(sz, 0, sz);
//	glTexCoord3f(0.5, 1, 0.5);
//	glVertex3f(sz / 2, sz, sz / 2);
//	glTexCoord3f(1, 0, 0);
//	glVertex3f(sz, 0, 0);
//	glTexCoord3f(0.5, 1, 0.5);
//	glVertex3f(sz / 2, sz, sz / 2);
//	glTexCoord3f(0, 0, 0);
//	glVertex3f(0, 0, 0);
//	glTexCoord3f(0.5, 1, 0.5);
//	glVertex3f(sz / 2, sz, sz / 2);
//	glTexCoord3f(0, 0, 1);
//	glVertex3f(0, 0, sz);
//	glEnd();
//
//	glPopMatrix();
//}
//
//void cylindersline(double br, double tr, double h) {
//	GLUquadricObj* cylinder = NULL;
//	cylinder = gluNewQuadric();
//	glColor3f(1.0, 0, 0);
//	//glPointSize(3.0);
//	gluQuadricDrawStyle(cylinder, GLU_LINE);
//	gluCylinder(cylinder, br, tr, h, 10, 10);
//	gluDeleteQuadric(cylinder);
//}
//void cylinders(double br, double tr, double h) {
//	GLUquadricObj* cylinder = NULL;
//	cylinder = gluNewQuadric();
//	glColor3f(1.0, 0, 0);
//	//glPointSize(3.0);
//	gluQuadricDrawStyle(cylinder, GLU_FILL);
//	gluCylinder(cylinder, br, tr, h, 10, 10);
//	gluDeleteQuadric(cylinder);
//}
//void drawCircle(float cx, float cy, float r, int num_segments) {
//	glBegin(GL_TRIANGLE_FAN);
//	for (int ii = 0; ii < num_segments; ii++) {
//		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 
//		float x = r * cosf(theta);//calculate the x component 
//		float y = r * sinf(theta);//calculate the y component 
//		glVertex2f(x + cx, y + cy);//output vertex 
//	}
//	glEnd();
//}
////
////void drawCylinder(double baseRadius, double topRadius, double height) {
////	GLUquadricObj* cylinder = NULL;
////
////	//glRotatef(0.01, 1.0, 1.0, 1.0);
////	cylinder = gluNewQuadric();
////	//drawstyle by default is glu fill 
////	gluQuadricDrawStyle(cylinder, GLU_FILL);
////	gluCylinder(cylinder, baseRadius, topRadius, height, 20, 20);
////	gluDeleteQuadric(cylinder);
////
////	double x = 0, y = 0, x2 = 0, y2 = 0, noOfTriangle = 0;
////
////	glBegin(GL_TRIANGLE_FAN);
////	glVertex2f(x, y);
////
////	for (float angle = 0; angle <= 2 * PI; angle += (2 * PI) / noOfTriangle) {
////		x2 = x + 0.2 * cos(angle);
////		y2 = y + 0.2 * sin(angle);
////		glVertex2f(x2, y2);
////	}
////	glEnd();
////
////	glPushMatrix();
////	//Top Circle
////	drawCircle(0, 0, baseRadius, 360);
////
////	//btm circle
////	glTranslatef(0, 0, height);
////	drawCircle(0, 0, topRadius, 360);
////	glPopMatrix();
////}
//
//
//void head() {
//	// top head
//	glPushMatrix();
//	glColor3f(optBlue[3], optLightRed[1], optLightRed[2]);
//	glTranslatef(-3, 21, 0);
//	headPyramid(10);
//	glPopMatrix();
//	// head cube
//	glPushMatrix();
//	glColor3f(0, 1, 1);
//	glTranslatef(1, 22, 6);
//	drawQuads(5, 2, 3);
//	glPopMatrix();
//	//head
//	glPushMatrix();
//	glColor3f(optlightGrey[3], optLightRed[1], optLightRed[2]);
//	glTranslatef(-3, 11, 0);
//	drawQuads(10, 10, 10);
//	glPopMatrix();
//	//lefteye
//	glPushMatrix();
//	glColor3f(0, 1, 1);
//	glTranslatef(-2, 17, 0.1);
//	drawQuads(2, 3, 10.2);
//	glPopMatrix();
//	//right eye
//	glPushMatrix();
//	glColor3f(0, 1, 1);
//	glTranslatef(3, 17, 0.1);
//	drawQuads(2, 3, 10.2);
//	glPopMatrix();
//	//left ear
//	glPushMatrix();
//	glColor3f(0, 1, 1);
//	glTranslatef(-3.5, 15, 3);
//	drawQuads(3, 3, 3);
//	glPopMatrix();
//	//right ear
//	glPushMatrix();
//	glColor3f(0, 1, 1);
//	glTranslatef(4.5, 15, 3);
//	drawQuads(3, 3, 3);
//	glPopMatrix();
//	//left ear line
//	glPushMatrix();
//	glColor3f(0, 1, 1);
//	glTranslatef(-3.5, 15, 3);
//	drawQuads(10, 0.2, 3);
//	glPopMatrix();
//	//right ear line
//	glPushMatrix();
//	glColor3f(0, 1, 1);
//	glTranslatef(7.2, 15, 3);
//	drawQuads(10, 0.2, 3);
//	glPopMatrix();
//	//left mask
//	glPushMatrix();
//	glColor3f(0, 1, 1);
//	//glTranslatef(-3, 11, 0);
//	glTranslatef(-3.5, 11, 4.5);
//	drawQuads(5, 5.5, 6);
//	glPopMatrix();
//	//right mask
//	glPushMatrix();
//	glColor3f(0, 1, 1);
//	glTranslatef(2, 11, 4.5);
//	drawQuads(5, 5.5, 6);
//	glPopMatrix();
//
//}
//
//
//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glEnable(GL_DEPTH_TEST);
//
//	projection();	//projection code
//
//	//lighting(); //lightning function
//
//	glColor3f(0, 0, 1); //Color blue 
//
//	//drawSphere(3);
//
//	//drawCustomRectangle(11, 2, 2);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	//glRotatef(0.5, 1, 1, 0);
//	head();
//
//	//weapon();
//	//cylinders(3, 3, 3);
//	//drawCylinder(3,3,3);
//
//	// gun body
//	glPushMatrix();
//	glColor3f(0, 1, 1);
//	drawQuads(0.05, 0.20, 0.05);
//	//cylindersline(3,3,3);
//	glPopMatrix();
//	//gun handle
//	glPushMatrix();
//	glColor3f(1, 1, 1);
//	glTranslatef(0.4, -0.5, -0.3);
//	drawQuads(0.95, 0.35, 0.35);
//	glPopMatrix();
//	 //cylinder gun
//	glPushMatrix();
//	glColor3f(0, 0, 1);
//	glRotatef(0,90,0,0);
//	glTranslatef(22, 2, 5);
//	drawCylinder(2, 2, 2);
//	glPopMatrix();
//
//
//}
//
////void display()
////{
////	/*glMatrixMode(GL_PROJECTION);
////	glLoadIdentity();
////	double w = 900;
////	double h = 900;
////	double ar = w / h;
////	glOrtho(-3 * ar, 3 * ar, -3, 3, -5, 5);
////	glMatrixMode(GL_MODELVIEW);*/
////
////	glClearColor(0, 0, 0, 0);
////	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
////	glEnable(GL_DEPTH_TEST);
////
////	projection();
////
////	glRotatef(0.1, 0, 1, 0);
////	/*if (isMove == true) {
////		glTranslatef(0.001, 0, 0);
////	}*/
////	//glLoadIdentity();
////	//glScalef(0.5, 0.5, 0.5);
////	lowerChest();
////	leg();
////
////	glPushMatrix();
////	{
////		glTranslatef(1, 0, 0);
////		glScalef(-1, 1, 1);
////		leg();
////	}
////	glPopMatrix();
////
////	//stencil();
////	//
////}
//
////--------------------------------------------------------------------
//
//int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
//{
//	WNDCLASSEX wc;
//	ZeroMemory(&wc, sizeof(WNDCLASSEX));
//
//	wc.cbSize = sizeof(WNDCLASSEX);
//	wc.hInstance = GetModuleHandle(NULL);
//	wc.lpfnWndProc = WindowProcedure;
//	wc.lpszClassName = WINDOW_TITLE;
//	wc.style = CS_HREDRAW | CS_VREDRAW;
//
//	if (!RegisterClassEx(&wc)) return false;
//
//	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT, CW_USEDEFAULT, 900, 900,
//		NULL, NULL, wc.hInstance, NULL);
//
//	//--------------------------------
//	//	Initialize window for OpenGL
//	//--------------------------------
//
//	HDC hdc = GetDC(hWnd);
//
//	//	initialize pixel format for the window
//	initPixelFormat(hdc);
//
//	//	get an openGL context
//	HGLRC hglrc = wglCreateContext(hdc);
//
//	//	make context current
//	if (!wglMakeCurrent(hdc, hglrc)) return false;
//
//	//--------------------------------
//	//	End initialization
//	//--------------------------------
//
//	ShowWindow(hWnd, nCmdShow);
//
//	MSG msg;
//	ZeroMemory(&msg, sizeof(msg));
//
//	while (true)
//	{
//		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
//		{
//			if (msg.message == WM_QUIT) break;
//
//			TranslateMessage(&msg);
//			DispatchMessage(&msg);
//		}
//
//		display();
//
//		SwapBuffers(hdc);
//	}
//
//	UnregisterClass(WINDOW_TITLE, wc.hInstance);
//
//	return true;
//}
////--------------------------------------------------------------------
//
//
