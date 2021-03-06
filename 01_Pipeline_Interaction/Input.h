#pragma once
#include "IObject.h"

enum class KeyStatus
{
	UP = 0,
	PRESSED = 1,
	RELEASED = 2,
};

class Input : public IObject
{
protected:
	GLboolean				keyStatus[1024] = { 0 };
	KeyStatus				realKeyStatus[1024] = { KeyStatus::UP };
	glm::vec2				mousePosition = glm::vec2(0);
	glm::vec2				lastMousePosition = glm::vec2(0);
	glm::vec2				mouseInput = glm::vec2(0);
	GLboolean				mouseMoved = false;
public:
	Input() {};
	KeyStatus* GetKeyStatus();
	glm::vec2 GetMousePosition();
	glm::vec2 GetMouseInput();

	virtual void Start() override;
	virtual void Update() override;

	void OnKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void OnMouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	void OnMouseMoveCallback(GLFWwindow* window, double x, double y);
	void OnMouseWheelCallback(GLFWwindow* window, double xoffset, double yoffset);
	void PatchMouseDrift();

	//Singleton
private:
	static Input instance;
public:
	Input(const Input&) = delete;
	Input& operator=(const Input&) = delete;
	static Input& Get() noexcept {
		return instance;
	}

};
