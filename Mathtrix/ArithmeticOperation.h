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
			op1 = 1 + (rand() % 50);
			op2 = 1 + (rand() % 50);
		}
			 break;
		case 2: {
			op1 = 1 + (rand() % 100);
			op2 = 1 + (rand() % 100);
		}
			  break;
		default: {
			op1 = 1 + (rand() % 10);
			op2 = 1 + (rand() % 10);
		}
			break;
		}
		int ans;
		int mod;
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
		case 2: {
			ans = op1 - op2;
			int choice = rand() % 4;
			if (ans > 0) {

			
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
			else {
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
							x = x * -1;
						}
							  break;
						case 2: {
							x = rand() % 200;
							x = x * -1;
						}
							  break;
						default: {
							x = rand() % 20;
							x = x * -1;
						}
							   break;
						}
						temp_map.emplace(i, x);
					}
				}
			}
		}
			break;
		case 3: {
			ans = op1 * op2;
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
						x = rand() % 100;
					}
						   break;
					}
					temp_map.emplace(i, x);
				}
			}
		}
			break;
		case 4: {
			while (op1 % op2 != 0) {
				if (severity == 1) {
					op1 = 1 + (rand() % 50);
					op2 = 1 + (rand() % 50);
				}
				else if (severity == 2) {
					op1 = 1 + (rand() % 100);
					op2 = 1 + (rand() % 100);
				}
				else {
					op1 = 1 + (rand() % 10);
					op2 = 1 + (rand() % 10);
				}
			}
			ans = op1 / op2;
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
		case 2: {
			int ans = op1 - op2;
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
		case 3: {
			int ans = op1 * op2;
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
		case 4: {
			int ans = op1 / op2;
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
		case 2: {
			int ans = op1 - op2;
			if (ans == key)
			{

			}
			else {
				menu = 1;
			}
		}
			  break;
		case 3: {
			int ans = op1 * op2;
			if (ans == key)
			{

			}
			else {
				menu = 1;
			}
		}
			  break;
		case 4: {
			int ans = op1 / op2;
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