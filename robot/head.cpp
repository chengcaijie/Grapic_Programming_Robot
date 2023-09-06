//#include <Windows.h>
//#include <gl/GL.h>
//#include <math.h>
//#include<gl/GLU.h>
//#include <GL\GL.h>
//#define PI 3.14159265
//#pragma comment (lib, "OpenGL32.lib")
//
//#define WINDOW_TITLE "Practical Exercise 5"
//
////Projection
//float tx = 0, tz = 0, tSpeed = 1.0;					//tSPeed = moving how many steps each time  
//boolean isOrtho = true;						//is Orthographic view ? 
//float ONear = -30, OFar = 30;				//Ortho near and far
//float PNear = 6, PFar = 10;				//Perspective near and far 
//float ptx = 0, pty = 0, ptSpeed = 1; // transalte for projection
//float pry = 0; float prSpeed = 1;	//rotate y for projection 
//
//double optOrangeColor[3] = { 0.847 ,0.129 ,0.129 }; //D92121
//double optRedColor[3] = { 0.691 , 0.0705 , 0.149 }; //B1126
//double optLightRed[3] = { 0.847, 0.13, 0.13 };
//double optlightGrey[3] = { 0.82,0.82,0.82 }; //D3D3D3
//double optGrey[3] = { 0.656,0.662,0.675 }; //A8A9AD
//double optBlue[3] = { 0,0.06,0.66 }; //4682BF
//double optlightBColor[3] = { 0.274, 0.509, 0.749 }; //4682BF
//
////Lightning 
//float amb[3] = { 1.0 , 1.0 , 1.0 }; //red color ambient light 
//float posA[3] = { 0.0 ,6.0 , 0.0 }; //amb light position (0,6,0) 
//float posD[3] = { 6 ,0 , 0.0 }; //amb light position (0,6,0) 
//float diff[3] = { 1,1,1 }; //difuse light 
//float ambM[3] = { 0 ,0.0,1.0 }; //blue color amb material 
//float difM[3] = { 0,0,1 }; //red color diff
//bool isLightOn = false; //is light on? 
//
//LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//	switch (msg)
//	{
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//
//	case WM_KEYDOWN:
//		/*
//		//ice cream key
//		if (wParam == VK_ESCAPE)
//			PostQuitMessage(0);
//		else if (wParam == 0x58) {
//			//X
//			glRotatef(2, 1.0, 0, 0);
//		}
//		else if (wParam == 0x59) {
//			//y
//			glRotatef(2, 0, 1, 0);
//		}
//		else if (wParam == 0x5A) {
//			//z
//			glRotatef(2, 0, 0, 1);
//		}
//		//ice cream end
//		*/
//
//
//		if (wParam == VK_ESCAPE) {
//			PostQuitMessage(0);
//		}
//		else if (wParam == VK_UP) {
//			if (isOrtho) {
//				if (tz < OFar) {
//					tz += tSpeed;
//				}
//			}
//			else {
//				if (tz < PFar ) {
//					tz += tSpeed;
//				}
//			}
//
//		}
//		else if (wParam == VK_DOWN) {
//			if (isOrtho) {
//				if (tz > ONear) {
//					tz -= tSpeed;
//				}
//			}
//			else {
//				if (tz > PNear) {
//					tz -= tSpeed;
//				}
//			}
//
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
//			tz = 4.0;
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
//		else if (wParam == VK_SPACE) {
//			isLightOn = !isLightOn;
//		}
//
//		break;
//
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
//void drawSphere(double r) {
//	GLUquadricObj* sphere = NULL;
//
//	//glRotatef(0.01, 1.0, 1.0, 1.0);
//	sphere = gluNewQuadric();
//
//	glPointSize(3.0);
//	//drawstyle by default is glu fill 
//	gluQuadricDrawStyle(sphere, GLU_FILL);
//	gluSphere(sphere, r, 30, 10);
//	gluDeleteQuadric(sphere);
//
//}
//
//void drawCylinderOutline(double baseRadius, double topRadius, double height) {
//	GLUquadricObj* cylinder = NULL;
//
//	//glRotatef(0.01, 1.0, 1.0, 1.0);
//	cylinder = gluNewQuadric();
//	glColor3f(0.5, 0, 0);
//	//drawstyle by default is glu fill 
//	gluQuadricDrawStyle(cylinder, GLU_LINE);
//	gluCylinder(cylinder, baseRadius, topRadius, height, 15, 5);
//	gluDeleteQuadric(cylinder);
//}
//
////void drawSphereWithoutGLU()
////{
////	const float PI = 3.141592f;
////	GLfloat x, y, z, sliceA, stackA;
////	GLfloat radius = 0.5;
////	int sliceNo = 30, stackNo = 30;
////	for (sliceA = 0.0; sliceA < PI; sliceA += PI / sliceNo)
////	{
////		glBegin(GL_POLYGON);
////		for (stackA = 0.0; stackA < PI; stackA += PI / stackNo)
////		{
////			x = radius * cos(stackA) * sin(sliceA);
////			y = radius * sin(stackA) * sin(sliceA);
////			z = radius * cos(sliceA);
////			glVertex3f(x, y, z);
////			x = radius * cos(stackA) * sin(sliceA + PI / stackNo);
////			y = radius * sin(stackA) * sin(sliceA + PI / sliceNo);
////			z = radius * cos(sliceA + PI / sliceNo);
////			glVertex3f(x, y, z);
////		}
////		glEnd();
////	}
////}
////void projection() {
////	glMatrixMode(GL_PROJECTION); // refer to projection matrix
////	glLoadIdentity(); // reset the projection matrix
////
////	glTranslatef(tx, 0, 0);
////	glTranslatef(ptx, pty, 0); // translate for projection
////	glRotatef(pry, 0, 1, 0); // rotate y-axis for projection
////
////	if (isOrtho) {
////		// === Ortho View ===
////		// ortho view has no zoom in and zoom out feature
////		// ratio is 1:1, must match with windows resolution
////		// (search CreateWindow, after USEDEFAULT value)
////		glOrtho(-5, 5, -5, 5, ONear, OFar);
////	}
////	else {
////		// === Perspective View ===
////		// use when u want to zoom in and zoom out
////		gluPerspective(20, 1, -1, 1);
////		glFrustum(-5, 5, -5, 5, PNear, PFar); // z value must be positive
////	}
////}
//void projection() {
//	//ortho viewpoints
//	glMatrixMode(GL_PROJECTION); //refer to projection matrix
//	glLoadIdentity(); //reset projection matrix
//
//	glTranslatef(tx, 0, 0);
//	glTranslatef(ptx, pty, 0.0); //translate for projection 
//	glRotatef(pry, 0, 1, 0); //rotate y for projection
//
//	if (isOrtho) {
//		glOrtho(-30.0, 30.0, -30.0, 30.0, ONear, OFar); //ortho view
//	}
//	else {
//		//perspective view
//		gluPerspective(20, 1, -2, 2);
//		glFrustum(-30.0, 30.0, -30.0, 30.0, PNear, PFar);
//	}
//
//}
//
//void lighting() {
//
//	if (isLightOn) {
//		glEnable(GL_LIGHTING);
//	}
//	else {
//		glDisable(GL_LIGHTING);
//	}
//	//light 0 : red color amb light at pos (0,6,0) above enable lightning 
//	glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
//	glLightfv(GL_LIGHT0, GL_POSITION, posA);
//	glEnable(GL_LIGHT0);
//
//	//light 1 : Green color dif light at pos(6,0,0) above
//	glLightfv(GL_LIGHT1, GL_DIFFUSE, diff);
//	glLightfv(GL_LIGHT1, GL_POSITION, posD);
//	glEnable(GL_LIGHT1);
//
//
//
//	glMatrixMode(GL_MODELVIEW);//refer to modelview matrix
//	//glLoadIdentity(); //to reset the modelview (Delete this if u want always spin)
//	glTranslatef(tx, 0, tz); //translate along the z-axis 
//
//	//red color ambient Material
//	glMaterialfv(GL_FRONT, GL_AMBIENT, ambM);
//
//	//blue color diff Material
//	//glMaterialfv(GL_FRONT, GL_DIFFUSE, difM);
//
//}
//
//void drawCustomRectangle(double length, double width, double height) {
//	glBegin(GL_QUADS);
//
//	//Bottom
//	glVertex3f(0, 0, 0);// A
//	glVertex3f(0, length, 0);// B
//	glVertex3f(width, length, 0);// C
//	glVertex3f(width, 0, 0);// D
//
//	//RIGHT
//	glVertex3f(width, 0, 0);// D
//	glVertex3f(width, 0, height);// L
//	glVertex3f(width, length, height);// K
//	glVertex3f(width, length, 0);// C
//
//	//BEHIND 
//	glVertex3f(width, length, 0);// C
//	glVertex3f(width, length, height);// K
//	glVertex3f(0, length, height);// J
//	glVertex3f(0, length, 0);// B
//
//	//LEFT
//	glVertex3f(0, length, 0);// B
//	glVertex3f(0, length, height);// J
//	glVertex3f(0, 0, height);// I
//	glVertex3f(0, 0, 0);// A
//
//	//FRONT 
//	glVertex3f(0, 0, 0);// A
//	glVertex3f(width, 0, 0);// D
//	glVertex3f(width, 0, height);// L
//	glVertex3f(0, 0, height);// I
//
//	//TOP
//	glVertex3f(0, 0, height);// I
//	glVertex3f(width, 0, height);// L
//	glVertex3f(width, length, height);// K
//	glVertex3f(0, length, height);// J
//
//	glEnd();
//
//}
//
//void drawCube(float size) {
//	glBegin(GL_QUADS);
//	//face size :Bottom
//	glColor3f(1, 0, 0);
//	glVertex3f(0, 0, size);
//	glVertex3f(size, 0, size);
//	glVertex3f(size, 0, 0);
//	glVertex3f(0, 0, 0);//stop here , and this will be the next point 
//	//face 2 :left 
//	glColor3f(0, 1, 0);
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, size, 0);
//	glVertex3f(0, size, size);
//	glVertex3f(0, 0, size);
//	//face 3: front
//	glColor3f(0, 0, 1);
//	glVertex3f(0, 0, size);
//	glVertex3f(0, size, size);
//	glVertex3f(size, size, size);
//	glVertex3f(size, 0, size);
//	//face 4: right face
//	glColor3f(1, 1, 0);
//	glVertex3f(size, 0, size);
//	glVertex3f(size, size, size);
//	glVertex3f(size, size, 0);
//	glVertex3f(size, 0, 0);
//	//face 5:back
//	glColor3f(1, 0, 1);
//	glVertex3f(size, 0, 0);
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, size, 0);
//	glVertex3f(size, size, 0);
//	//face 6 top
//	glColor3f(0, 1, 1);
//	glVertex3f(size, size, 0);
//	glVertex3f(0, size, 0);
//	glVertex3f(0, size, size);
//	glVertex3f(size, size, size);
//
//	glEnd();
//}
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
//
//void drawCylinder(double baseRadius, double topRadius, double height) {
//	GLUquadricObj* cylinder = NULL;
//
//	//glRotatef(0.01, 1.0, 1.0, 1.0);
//	cylinder = gluNewQuadric();
//	//drawstyle by default is glu fill 
//	gluQuadricDrawStyle(cylinder, GLU_FILL);
//	gluCylinder(cylinder, baseRadius, topRadius, height, 20, 20);
//	gluDeleteQuadric(cylinder);
//
//	double x = 0, y = 0, x2 = 0, y2 = 0, noOfTriangle = 0;
//
//	glBegin(GL_TRIANGLE_FAN);
//	glVertex2f(x, y);
//
//	for (float angle = 0; angle <= 2 * PI; angle += (2 * PI) / noOfTriangle) {
//		x2 = x + 0.2 * cos(angle);
//		y2 = y + 0.2 * sin(angle);
//		glVertex2f(x2, y2);
//	}
//	glEnd();
//
//	glPushMatrix();
//	//Top Circle
//	drawCircle(0, 0, baseRadius, 360);
//
//	//btm circle
//	glTranslatef(0, 0, height);
//	drawCircle(0, 0, topRadius, 360);
//	glPopMatrix();
//}
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
//	lighting(); //lightning function
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
//	drawQuads(5, 20, 5);
//	//cylindersline(3,3,3);
//	glPopMatrix();
//	//gun handle
//	glPushMatrix();
//	glColor3f(1, 1, 1);
//	glTranslatef(4, -5, 0.3);
//	drawQuads(9.5, 3.5, 3.5);
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
//		700, 10, 800, 800,
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
//
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