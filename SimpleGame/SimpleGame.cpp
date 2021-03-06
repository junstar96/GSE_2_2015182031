/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include <iostream>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"
#include "Renderer.h"
#include "SceneMgr.h"

SceneMgr* test = NULL;


void RenderScene(void)
{
	//// Renderer Test
	//g_Renderer->DrawSolidRect(0, 0, 0, 4, 1, 0, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.f);

	test->draw();




	glutSwapBuffers();

}

void Idle(void)
{
	RenderScene();

	
}

void MouseInput(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_UP)
		{
			if ((y_size / 2 - y) < 0 && FmakeTime >= 2)
			{
				test->get_object_character((double)(x - x_size / 2), (double)(y_size / 2 - y), 2, 1);
				FmakeTime = 0;
			}
		}
		break;
	}
}

void KeyInput(unsigned char key, int x, int y)
{

	switch (key)
	{
	case 'a':
	case 'A':
		delete test;
		exit(1);
		break;
	case 'd':
	case 'D':
		test->del_object();
		break;
	case 'w':
	case 'W':
		if ((y_size / 2 - y) < 0 && FmakeTime >= 2)
		{
			test->get_object_character((double)(x - x_size / 2), (double)(y_size / 2 - y), 2, 2);
			FmakeTime = 0;
		}
		break;
	case 's':
	case 'S':
		break;
	}
}

void SpecialKeyInput(int key, int x, int y)
{
}

void timer(int value)
{
	test->update();

	glutTimerFunc(30, timer, 1);
}

int main(int argc, char **argv)
{
	

	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(x_size, y_size);
	glutCreateWindow("Game Software Engineering KPU");

	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}

	test = new SceneMgr();
	// Initialize Renderer
	

	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);
	glutTimerFunc(30, timer, 1);

	glutMainLoop();

	

	return 0;
}

