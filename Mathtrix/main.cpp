#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <map>
#include <glm/glm.hpp>
#include <map>
//Classes
#include "Shader.h"
#include "RenderText.h"
#include "NavigationController.h"
#include "ArithmeticOperation.h"
std::map<int, int> choices;
const unsigned int SCREEN_WIDTH = 1080;
const unsigned int SCREEN_HEIGHT = 640;
void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
static void cursorPositionCallback(GLFWwindow *window, double xPos, double yPos);
NavigationController nvt;
ArithmeticOpertaion aop;
int refpoint = 1;
int selpoint = 1;
int op1 = 0;
int op2 = 0;
int ans = 0;
int severity = 0;
int score = 0;
std::string a;
std::string b;
std::string c;
std::string d;
int menu_b = 0;
string variable = "Mathrtix";
//IMPORTANT

//I changed the include links, so please change the, on your end

//IMPORTANT
int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "MathTrix", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, keyCallBack);
	//glfwSetCursorPosCallback(window, cursorPositionCallback);
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		printf("Error\n");

	// When user resizes the screen
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// OpenGL state
	// ------------
	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	Shader shader("Shaders/glyph.vs", "Shaders/glyph.fs");
	glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(SCREEN_WIDTH), 0.0f, static_cast<float>(SCREEN_HEIGHT));
	shader.use();
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

	// FreeType
	TextRenderer txt("Fonts/Antonio-Bold.ttf");

	// While window is open
//	aop.equationMaker(op1, op2, selpoint, choices, severity);
	while (!glfwWindowShouldClose(window))
	{
		// input

		nvt.processInput(window);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		
		switch (refpoint)
		{
		case 1:
			txt.RenderText(shader, "MATHTRIX", 440.0f, 570.0f, 1.0f, glm::vec3(0.89, 0.29f, 0.27f));
			txt.RenderText(shader, "GROUP 3", 460.0f, 500.0f, 0.8f, glm::vec3(1.0f, 0.63f, 0.48f));
			txt.RenderText(shader, "115325 Dennis Kipkorir Koech", 300.0f, 400.0f, 0.5f, glm::vec3(0.93, 0.91f, 0.67f));
			txt.RenderText(shader, "097770 Gitonga MaryAnn Mwendwa", 300.0f, 320.0f, 0.5f, glm::vec3(0.93, 0.91f, 0.67f));
			txt.RenderText(shader, "121800 Wariua Nicholas Kanyi", 300.0f, 240.0f, 0.5f, glm::vec3(0.93, 0.91f, 0.67f));
			txt.RenderText(shader, "118640 Tevin Musau Mutua", 300.0f, 160.0f, 0.5f, glm::vec3(0.93, 0.91f, 0.67f));
			txt.RenderText(shader, "Welcome to the Jungle", 600.0f, 25.0f, 0.8f, glm::vec3(0.16, 0.67f, 0.53f)); //0.5, 0.8f, 0.2f
			break;
		case 2:
			menu_b = 0;
			txt.RenderText(shader, "Level Select", 460.0f, 540.0f, 0.8f, glm::vec3(1.0f, 0.63f, 0.48f));
			switch (selpoint)
			{
			case 1:
				txt.RenderText(shader, "Level 1: Addition", 470.0f, 450.0f, 0.5f, glm::vec3(0.93f, 0.91f, 0.67f));
				break;
			case 2:
				txt.RenderText(shader, "Level 2: Subtraction", 470.0f, 450.0f, 0.5f, glm::vec3(0.93f, 0.91f, 0.67f));
				break;
			case 3:
				txt.RenderText(shader, "Level 3: Multiplication", 470.0f, 450.0f, 0.5f, glm::vec3(0.93f, 0.91f, 0.67f));
				break;
			case 4:
				txt.RenderText(shader, "Level 4: Division", 470.0f, 450.0f, 0.5f, glm::vec3(0.93f, 0.91f, 0.67f));
				break;
			case 5:
				txt.RenderText(shader, "Level 5: Squares", 470.0f, 450.0f, 0.5f, glm::vec3(0.93f, 0.91f, 0.67f));
				break;
			case 6:
				txt.RenderText(shader, "Level 6: Cubes", 470.0f, 450.0f, 0.5f, glm::vec3(0.93f, 0.91f, 0.67f));
				break;
			case 7:
				txt.RenderText(shader, "Level 7: Square Root", 470.0f, 450.0f, 0.5f, glm::vec3(0.93f, 0.91f, 0.67f));
				break;
			default:
				break;
			}
			break;
		case 3:
		{
			if (menu_b == 0)
			{
				string op1_s = to_string(op1);
				string op2_s = to_string(op2);
				txt.RenderText(shader, "Level 1: Addition", 460.0f, 540.0f, 0.8f, glm::vec3(1.0f, 0.63f, 0.48f));
				txt.RenderText(shader, "Add the following numbers: " + op1_s + " + " + op2_s, 430.0f, 450.0f, 0.5f, glm::vec3(0.93f, 0.91f, 0.67f));
				a = "A. " + to_string(choices[0]);
				b = "B. " + to_string(choices[1]);
				c = "C. " + to_string(choices[2]);
				d = "D. " + to_string(choices[3]);
				txt.RenderText(shader, a, 470.0f, 380.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
				txt.RenderText(shader, b, 470.0f, 320.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
				txt.RenderText(shader, c, 600.0f, 380.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
				txt.RenderText(shader, d, 600.0f, 320.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
			}
			else
			{
				string s_score = "This is your score: "+to_string(score);
				txt.RenderText(shader, "Game Over! Press Escape", 150.0f, 450.0f, 0.5f, glm::vec3(1.0f, 0.0f, 0.0f));
				txt.RenderText(shader, s_score, 150.0f, 350.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
			}
			
		}
			break;
		case 4:
		{
			if (menu_b == 0)
			{
				string op1_s = to_string(op1);
				string op2_s = to_string(op2);
				txt.RenderText(shader, "Level 2: Subtraction", 460.0f, 540.0f, 0.8f, glm::vec3(1.0f, 0.63f, 0.48f));
				txt.RenderText(shader, "Subtract the following numbers: " + op1_s + " - " + op2_s, 430.0f, 450.0f, 0.5f, glm::vec3(0.93f, 0.91f, 0.67f));
				a = "A. " + to_string(choices[0]);
				b = "B. " + to_string(choices[1]);
				c = "C. " + to_string(choices[2]);
				d = "D. " + to_string(choices[3]);
				//txt.RenderText(shader, op1_s, 400.0f, 400.0f, 1.0f, glm::vec3(0.3, 0.7f, 0.9f));
				//txt.RenderText(shader, op2_s, 800.0f, 400.0f, 1.0f, glm::vec3(0.3, 0.7f, 0.9f));
				txt.RenderText(shader, a, 470.0f, 380.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
				txt.RenderText(shader, b, 470.0f, 320.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
				txt.RenderText(shader, c, 600.0f, 380.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
				txt.RenderText(shader, d, 600.0f, 320.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
			}
			else
			{
				string s_score = "This is your score: " + to_string(score);
				txt.RenderText(shader, "Game Over! Press Escape", 150.0f, 450.0f, 0.5f, glm::vec3(1.0f, 0.0f, 0.0f));
				txt.RenderText(shader, s_score, 150.0f, 350.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
			}

		}
		break;
		case 5:
		{
			if (menu_b == 0)
			{
				string op1_s = to_string(op1);
				string op2_s = to_string(op2);
				txt.RenderText(shader, "Level 3: Multiplication", 460.0f, 540.0f, 0.8f, glm::vec3(1.0f, 0.63f, 0.48f));
				txt.RenderText(shader, "Multiply the following numbers: " + op1_s + " x " + op2_s, 430.0f, 450.0f, 0.5f, glm::vec3(0.93f, 0.91f, 0.67f));
				a = "A. " + to_string(choices[0]);
				b = "B. " + to_string(choices[1]);
				c = "C. " + to_string(choices[2]);
				d = "D. " + to_string(choices[3]);
				//txt.RenderText(shader, op1_s, 400.0f, 400.0f, 1.0f, glm::vec3(0.3, 0.7f, 0.9f));
				//txt.RenderText(shader, op2_s, 800.0f, 400.0f, 1.0f, glm::vec3(0.3, 0.7f, 0.9f));
				txt.RenderText(shader, a, 470.0f, 380.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
				txt.RenderText(shader, b, 470.0f, 320.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
				txt.RenderText(shader, c, 600.0f, 380.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
				txt.RenderText(shader, d, 600.0f, 320.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
			}
			else
			{
				string s_score = "This is your score: " + to_string(score);
				txt.RenderText(shader, "Game Over! Press Escape", 150.0f, 450.0f, 0.5f, glm::vec3(1.0f, 0.0f, 0.0f));
				txt.RenderText(shader, s_score, 150.0f, 350.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
			}

		}
		break;
		case 6:
		{
			if (menu_b == 0)
			{
				string op1_s = to_string(op1);
				string op2_s = to_string(op2);
				txt.RenderText(shader, "Level 4: Division", 460.0f, 540.0f, 0.8f, glm::vec3(1.0f, 0.63f, 0.48f));
				txt.RenderText(shader, "Divide the following numbers: " + op1_s + " / " + op2_s, 430.0f, 450.0f, 0.5f, glm::vec3(0.93f, 0.91f, 0.67f));
				a = "A. " + to_string(choices[0]);
				b = "B. " + to_string(choices[1]);
				c = "C. " + to_string(choices[2]);
				d = "D. " + to_string(choices[3]);
				//txt.RenderText(shader, op1_s, 400.0f, 400.0f, 1.0f, glm::vec3(0.3, 0.7f, 0.9f));
				//txt.RenderText(shader, op2_s, 800.0f, 400.0f, 1.0f, glm::vec3(0.3, 0.7f, 0.9f));
				txt.RenderText(shader, a, 470.0f, 380.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
				txt.RenderText(shader, b, 470.0f, 320.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
				txt.RenderText(shader, c, 600.0f, 380.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
				txt.RenderText(shader, d, 600.0f, 320.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
			}
			else
			{
				string s_score = "This is your score: " + to_string(score);
				txt.RenderText(shader, "Game Over! Press Escape", 150.0f, 450.0f, 0.5f, glm::vec3(1.0f, 0.0f, 0.0f));
				txt.RenderText(shader, s_score, 150.0f, 350.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
			}

		}
		break;
		case 7:
		{
			if (menu_b == 0)
			{
				string op1_s = to_string(op1);
				txt.RenderText(shader, "Level 5: Squares", 460.0f, 540.0f, 0.8f, glm::vec3(1.0f, 0.63f, 0.48f));
				txt.RenderText(shader, "What is " + op1_s + " Squared?", 430.0f, 450.0f, 0.5f, glm::vec3(0.93f, 0.91f, 0.67f));
				a = "A. " + to_string(choices[0]);
				b = "B. " + to_string(choices[1]);
				c = "C. " + to_string(choices[2]);
				d = "D. " + to_string(choices[3]);
				txt.RenderText(shader, a, 470.0f, 380.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
				txt.RenderText(shader, b, 470.0f, 320.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
				txt.RenderText(shader, c, 600.0f, 380.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
				txt.RenderText(shader, d, 600.0f, 320.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
			}
			else
			{
				string s_score = "This is your score: " + to_string(score);
				txt.RenderText(shader, "Game Over! Press Escape", 150.0f, 450.0f, 0.5f, glm::vec3(1.0f, 0.0f, 0.0f));
				txt.RenderText(shader, s_score, 150.0f, 350.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
			}

		}
			break;
		case 8:
		{
			if (menu_b == 0)
			{
				string op1_s = to_string(op1);
				txt.RenderText(shader, "Level 6: Cubes", 460.0f, 540.0f, 0.8f, glm::vec3(1.0f, 0.63f, 0.48f));
				txt.RenderText(shader, "What is " + op1_s + " Cubed?", 430.0f, 450.0f, 0.5f, glm::vec3(0.93f, 0.91f, 0.67f));
				a = "A. " + to_string(choices[0]);
				b = "B. " + to_string(choices[1]);
				c = "C. " + to_string(choices[2]);
				d = "D. " + to_string(choices[3]);
				txt.RenderText(shader, a, 470.0f, 380.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
				txt.RenderText(shader, b, 470.0f, 320.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
				txt.RenderText(shader, c, 600.0f, 380.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
				txt.RenderText(shader, d, 600.0f, 320.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
			}
			else
			{
				string s_score = "This is your score: " + to_string(score);
				txt.RenderText(shader, "Game Over! Press Escape", 150.0f, 450.0f, 0.5f, glm::vec3(1.0f, 0.0f, 0.0f));
				txt.RenderText(shader, s_score, 150.0f, 350.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
			}

		}
		break;

		case 9:
		{
			if (menu_b == 0)
			{
				string op1_s = to_string(op1);
				txt.RenderText(shader, "Level 7: Square Root", 460.0f, 540.0f, 0.8f, glm::vec3(1.0f, 0.63f, 0.48f));
				txt.RenderText(shader, "Square Root of " + op1_s + " is?", 430.0f, 450.0f, 0.5f, glm::vec3(0.93f, 0.91f, 0.67f));
				a = "A. " + to_string(choices[0]);
				b = "B. " + to_string(choices[1]);
				c = "C. " + to_string(choices[2]);
				d = "D. " + to_string(choices[3]);
				txt.RenderText(shader, a, 470.0f, 380.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
				txt.RenderText(shader, b, 470.0f, 320.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
				txt.RenderText(shader, c, 600.0f, 380.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
				txt.RenderText(shader, d, 600.0f, 320.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
			}
			else
			{
				string s_score = "This is your score: " + to_string(score);
				txt.RenderText(shader, "Game Over! Press Escape", 150.0f, 450.0f, 0.5f, glm::vec3(1.0f, 0.0f, 0.0f));
				txt.RenderText(shader, s_score, 150.0f, 350.0f, 0.5f, glm::vec3(0.19, 0.8f, 0.19f));
			}

		}
		break;
			break;
		default:
			break;
		}

		//Render the window

		// Swap the front and back buffers - we draw into the back, thus we swap.
		glfwSwapBuffers(window);

		glfwPollEvents();

	}
	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS)
	{
		switch (key)
		{
		case GLFW_KEY_ENTER:
			nvt.enterController(refpoint, selpoint, op1, op2, choices, severity);
			std::cout << refpoint << std::endl;
			break;
		case GLFW_KEY_DOWN:
			nvt.KeyDController(refpoint, selpoint);
			break;
		case GLFW_KEY_UP:
			nvt.KeyUController(refpoint, selpoint);
			break;
		case GLFW_KEY_ESCAPE:
			nvt.escController(window, refpoint, selpoint, menu_b, score);
			break;
		default:
			std::cout << key << std::endl;
			aop.equationChecker(op1, op2, selpoint, key, menu_b, choices, score, severity);
			break;
		}
	}
};

void cursorPositionCallback(GLFWwindow *window, double xPos, double yPos) {
	std::cout << xPos << ":" << yPos << std::endl;
}
