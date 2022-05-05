#ifndef COMMAND_AND_DOMINATE_SRC_WINDOW_WINDOW_FORWARD_H_
#define COMMAND_AND_DOMINATE_SRC_WINDOW_WINDOW_FORWARD_H_

#include <memory>

#include "command_and_dominate/glfw.h"

class Window;
using WindowPtr = std::shared_ptr<Window>;

using WindowFramebufferSizeCallback = void (*)(GLFWwindow *, int, int);
using WindowCharCallback = void (*)(GLFWwindow *, unsigned int);
using WindowCursorPositionCallback = void (*)(GLFWwindow *, double, double);
using WindowKeyCallback = void (*)(GLFWwindow *, int, int, int, int);
using WindowScrollCallback = void (*)(GLFWwindow *, double, double);

#endif // !COMMAND_AND_DOMINATE_SRC_WINDOW_WINDOW_FORWARD_H_
