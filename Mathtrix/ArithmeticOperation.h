#pragma once
#include <iostream>
#include <map>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
class ArithmeticOpertaion {
public:
	void equationMaker(int& op1, int& op2, int& selpoint, std::map<int, int>& temp_map, int& severity) {
		temp_map.clear();
		switch (severity) {
		case 1: {
			op1 = rand() % 50;
			op2 = rand() % 50;
		}
			 break;
		case 2: {
			op1 = rand() % 100;
			op2 = rand() % 100;
		}
			  break;
		default: {
			op1 = rand() % 10;
			op2 = rand() % 10;
		}
			break;
		}
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
					int x = 0;
					switch (severity) {
						case 1: {
							x = rand() % 100;
						}
							  break;
						case 2: {
							x = rand() % 200;
						}
							  break;
						default: {
							x = rand() % 20;
						}
							   break;
					}
					temp_map.emplace(i, x);
				}
			}
		}
			break;

		case 7: {
			ans = op1 * op1;
			int choice = rand() % 4;
			int i = 0;
			for (i = 0; i < 4; i++)
			{
				if (i == choice)
				{
					temp_map.emplace(i, ans);
				}
				else {
					int x = 0;
					switch (severity) {
					case 1: {
						x = rand() % 100;
					}
						  break;
					case 2: {
						x = rand() % 200;
					}
						  break;
					default: {
						x = rand() % 20;
					}
						   break;
					}
					temp_map.emplace(i, x);
				}
			}
		}
			  break;

		case 8: {
			op1 = rand() % 5;
			ans = op1 * op1 * op1;
			int choice = rand() % 4;
			int i = 0;
			for (i = 0; i < 4; i++)
			{
				if (i == choice)
				{
					temp_map.emplace(i, ans);
				}
				else {
					int x = 0;
					switch (severity) {
					case 1: {
						x = rand() % 100;
					}
						  break;
					case 2: {
						x = rand() % 200;
					}
						  break;
					default: {
						x = rand() % 20;
					}
						   break;
					}
					temp_map.emplace(i, x);
				}
			}
		}
			  break;

		case 9: {
			op1 *= op1;
			ans = (int) sqrt(op1);
			int choice = rand() % 4;
			int i = 0;
			for (i = 0; i < 4; i++)
			{
				if (i == choice)
				{
					temp_map.emplace(i, ans);
				}
				else {
					int x = 0;
					switch (severity) {
					case 1: {
						x = rand() % 100;
					}
						  break;
					case 2: {
						x = rand() % 200;
					}
						  break;
					default: {
						x = rand() % 20;
					}
						   break;
					}
					temp_map.emplace(i, x);
				}
			}
		}
			  break;
		default:
			break;
		}
	}
	void equationChecker(int& op1, int& op2, int& selpoint, int key,int& menu, std::map<int, int>& temp_map, int& score, int& severity) {
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
				if (score > 100) {
					severity = 1;
				}
				else if (score > 200) {
					severity = 2;
				}
			}
			else {
				menu = 1;
			}
		}
			  break;

		case 7: {
			int ans = op1 * op1;
			if (ans == u_ans)
			{
				score += 10;
				if (score > 100) {
					severity = 1;
				}
				else if (score > 200) {
					severity = 2;
				}
			}
			else {
				menu = 1;
			}
		}
			  break;

		case 8: {
			int ans = op1 * op1 * op1;
			if (ans == u_ans)
			{
				score += 10;
				if (score > 100) {
					severity = 1;
				}
				else if (score > 200) {
					severity = 2;
				}
			}
			else {
				menu = 1;
			}
		}
			  break;

		case 9: {
			int ans = (int) sqrt(op1);
			if (ans == u_ans)
			{
				score += 10;
				if (score > 100) {
					severity = 1;
				}
				else if (score > 200) {
					severity = 2;
				}
			}
			else {
				menu = 1;
			}
		}
			  break;
		default:
			break;
		}
		equationMaker(op1, op2, selpoint, temp_map, severity);
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

		case 7: {
			int ans = op1 * op1;
			if (ans == key)
			{

			}
			else {
				menu = 1;
			}
		}
			  break;

		case 8: {
			int ans = op1 * op1 * op1;
			if (ans == key)
			{

			}
			else {
				menu = 1;
			}
		}
			  break;

		case 9: {
			int ans = (int) sqrt(op1);
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