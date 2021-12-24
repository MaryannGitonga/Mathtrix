#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <map>
#include <glm/glm.hpp>

//Classes
#include "Shader.h"
#include "RenderText.h"
#include "NavigationController.h"
const unsigned int SCREEN_WIDTH = 1080;
const unsigned int SCREEN_HEIGHT = 640;
void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
NavigationController nvt;
int refpoint = 1;
int selpoint = 1;
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
	while (!glfwWindowShouldClose(window))
	{
		// input
		nvt.processInput(window);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		switch (refpoint)
		{
		case 0:
			glfwSetWindowShouldClose(window, true);
			break;
		case 1:
			txt.RenderText(shader, "Welcome to the Jungle", 25.0f, 25.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f));
			txt.RenderText(shader, "MATHTRIX", 440.0f, 570.0f, 1.0f, glm::vec3(0.3, 0.7f, 0.9f));
			break;
		case 2:
			txt.RenderText(shader, "Level Select", 540.0f, 570.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));
			switch (selpoint)
			{
			case 1:
				txt.RenderText(shader, "Level Addition", 540.0f, 250.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));
				break;
			case 2:
				txt.RenderText(shader, "Level Subtraction", 540.0f, 250.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));
				break;
			case 3:
				txt.RenderText(shader, "Level Multiplication", 540.0f, 250.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));
				break;
			case 4:
				txt.RenderText(shader, "Level Division", 540.0f, 250.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));
				break;
			case 5:
				txt.RenderText(shader, "Level Prime Numbers", 540.0f, 250.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));
				break;
			case 6:
				txt.RenderText(shader, "Level Divisibility", 540.0f, 250.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));
				break;
			case 7:
				txt.RenderText(shader, "Level Squares and Square Roots", 540.0f, 250.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));
				break;
			default:
				break;
			}
			break;
		case 3:
			txt.RenderText(shader, "Level Addition", 540.0f, 570.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));
			//Where Functions will be called that'll provide operands
			break;
		case 4:
			txt.RenderText(shader, "Level Subtraction", 540.0f, 570.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));
			//Where Functions will be called that'll provide operands
			break;
		case 5:
			txt.RenderText(shader, "Level Multiplication", 540.0f, 570.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));
			//Where Functions will be called that'll provide operands
			break;
		case 6:
			txt.RenderText(shader, "Level Division", 540.0f, 570.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));
			//Where Functions will be called that'll provide operands
			break;
		case 7:
			txt.RenderText(shader, "Level Prime Numbers", 540.0f, 570.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));
			//Where Functions will be called that'll provide operands
			break;
		case 8:
			txt.RenderText(shader, "Level Divisibility", 540.0f, 570.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));
			break;
		case 9:
			txt.RenderText(shader, "Level Squares and Square Roots", 540.0f, 570.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));
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

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS)
	{
		switch (key)
		{
		case GLFW_KEY_ENTER:
			nvt.enterController(refpoint, selpoint);
			std::cout << refpoint << std::endl;
			break;
		case GLFW_KEY_DOWN:
			nvt.KeyDController(refpoint, selpoint);
			break;
		case GLFW_KEY_UP:
			nvt.KeyUController(refpoint, selpoint);
			break;
		case GLFW_KEY_ESCAPE:
			nvt.escController(window, refpoint, selpoint);
			break;
		default:
			break;
		}
	}
};

