#include "ykpch.h"
#include "WindowsInput.h"
#include "York/Application.h"

#include <GLFW/glfw3.h>

namespace York {
	
	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::IsKeyPressedImpl(int keyCode)
	{
		auto window = static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, keyCode);
		
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);

		return state == GLFW_PRESS;
	}

	std::pair<float, float> WindowsInput::GetMousePositionImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetNativeWindow());
		double xPos, yPos;

		glfwGetCursorPos(window, &xPos, &yPos);

		return {(float)xPos, (float)yPos};
	}

	float WindowsInput::GetMouseXImpl()
	{
		auto [x, y] = GetMousePositionImpl();
		return x;
	}

	float WindowsInput::GetMouseYImpl()
	{
		auto [x, y] = GetMousePositionImpl();
		return y;
	}
}