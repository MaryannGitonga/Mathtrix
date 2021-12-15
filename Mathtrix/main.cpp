#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <map>
#include <GLM/glm.hpp>

//Classes
#include "Shader.h"
#include "RenderText.h"

const unsigned int SCREEN_WIDTH = 1080;
const unsigned int SCREEN_HEIGHT = 640;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

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
		processInput(window);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		txt.RenderText(shader, "Welcome to the Jungle", 25.0f, 25.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f));
		txt.RenderText(shader, "MATHTRIX", 440.0f, 570.0f, 1.0f, glm::vec3(0.3, 0.7f, 0.9f));
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

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GL_RETURN) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}