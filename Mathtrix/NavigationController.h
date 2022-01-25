#pragma once
#include <iostream>
#include <map>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "ArithmeticOperation.h"
class NavigationController {
public:
	void processInput(GLFWwindow* window)
	{
		if (glfwGetKey(window, GL_RETURN) == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, true);
		}
	}
	void escController(GLFWwindow* window, int& refpoint, int& selpoint, int& menu_b, int& score) {
		if (refpoint == 1) {
			glfwSetWindowShouldClose(window, true);
		}
		else if (refpoint == 2) {
			refpoint -= 1;
		}
		else {
			score = 0;
			menu_b = 0;
			refpoint = 2;
		}
	}
	void enterController(int& refpoint, int& selpoint, int& op1, int& op2, std::map<int, int>& choices, int& severity) {
		switch (refpoint)
		{
		case 1:
			refpoint += 1;
			break;
		case 2:
			ArithmeticOpertaion aop;
			aop.equationMaker(op1, op2, selpoint, choices, severity);
			refpoint += selpoint;
			break;
		default:
			break;
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