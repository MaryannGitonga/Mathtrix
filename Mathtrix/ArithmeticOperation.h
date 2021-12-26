#pragma once
#include <iostream>
#include <map>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
class ArithmeticOpertaion {
public:
	void equationMaker(int& op1, int& op2, int& selpoint, std::map<int, int>& temp_map) {
		temp_map.clear();
		op1 = rand() % 10;
		op2 = rand() % 10;
		int ans;
		switch (selpoint)
		{
		case 1: {
			ans = op1 + op2;
			int choice = rand() % 4;
			int i = 0;
			for ( i = 0; i < 4; i++)
			{
				if (i==choice)
				{
					temp_map.emplace(i, ans);
				}
				else {
					int x = rand() % 20;
					temp_map.emplace(i, x);
				}
			}
		}
			break;
		default:
			break;
		}
	}
	void equationChecker(int& op1, int& op2, int& selpoint, int key,int& menu, std::map<int, int>& temp_map, int& score) {
		int u_ans=0;
		switch (key)
		{
		case 65:
			u_ans = temp_map[0];
			break;
		case 66:
			u_ans = temp_map[1];
			break;
		case 67:
			u_ans = temp_map[2];
			break;
		case 68:
			u_ans = temp_map[3];
			break;
		default:
			break;
		}
		switch (selpoint)
		{
		case 1: {
			int ans = op1 + op2;
			if (ans == u_ans)
			{
				score += 10;
			}
			else {
				menu = 1;
			}
		}
			  break;
		default:
			break;
		}
		equationMaker(op1, op2, selpoint, temp_map);
	}
	void NumberGenerator(int& op1, int& op2) {
		op1 = rand() % 10;
		op2 = rand() % 10;
	}
	void AnswerCheck(int& op1, int& op2, int& selpoint, int key, int& menu) {
		switch (selpoint)
		{
		case 1: {
			int ans = op1 + op2;
			if (ans == key)
			{

			}
			else {
				menu = 1;
			}
		}
			break;
		default:
			break;
		}
		
	}
};