#pragma once
#include <iostream>
#include <map>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
class NavigationController {
public:
	void processInput(GLFWwindow* window)
	{
		if (glfwGetKey(window, GL_RETURN) == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, true);
		}
	}
	void escController(GLFWwindow* window, int& refpoint, int& selpoint) {
		if (refpoint == 1) {
			glfwSetWindowShouldClose(window, true);
		}
		else if (refpoint == 2) {
			refpoint -= 1;
		}
		else {
			refpoint = 2;
		}
	}
	void enterController(int& refpoint, int& selpoint) {
		if (refpoint == 1) {
			refpoint += 1;
		}
		else if (refpoint == 2) {
			refpoint += selpoint;
		}
	}
	void KeyUController(int& refpoint, int& selpoint) {
		if (selpoint == 7)
		{
			selpoint = 1;
		}
		else {
			selpoint += 1;
		}
	}
	void KeyDController(int& refpoint, int& selpoint) {
		if (selpoint == 1)
		{
			selpoint = 7;
		}
		else {
			selpoint -= 1;
		}
	}
};