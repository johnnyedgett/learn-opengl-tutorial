#include <glad/glad.h>
#include <GLFW\glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main() {
	glfwInit();

	// Window hints = configuration
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Can change the first NULL to make this full screen
	GLFWwindow* window = glfwCreateWindow(640, 480, "Learn Open GL Tutorial", NULL, NULL);

	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// Set the context of the window to be the main context of the current thread
	glfwMakeContextCurrent(window);

	// GLAD manages function pointers - need to make sure this initializes successfully
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// Tell OpenGL the size of the rendering window so it knows how to display data and coordinates
	//	with respect to the window. 
	glViewport(0, 0, 640, 480);

	// Register callback functions
	// Note -> many callback functions can be added to handle multiple types of events
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// Keep the window open until it needs to be closed
	while (!glfwWindowShouldClose(window)) { 
		glfwSwapBuffers(window);
		glfwPollEvents(); // Pull for any events like keyboard input/mouse movements
	}

	// Release resources 
	glfwTerminate();
	return 0;
}

// Callback function to update the window size
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	std::cout << "User resized the application" << std::endl;
}