#include <GLFW/glfw3.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

//***************************************************************************//

static GLFWwindow *glfw_window;

void error(const char *message) {
  fprintf(stderr, "\033[91;1merror:\033[0m %s\n", message);
  exit(EXIT_FAILURE);
}

static void failure(int errorno, const char *description) {
  fprintf(stderr, "callback (%d)\n", errorno);
  error(description);
}

void gib_window_init() {
  if (!glfwInit())
    error("unnable to initialize glfw");

  if (!(glfw_window = glfwCreateWindow(1, 1, "gib window", NULL, NULL)))
    error("unnable to create window");

  glfwMakeContextCurrent(glfw_window);
  glfwSwapInterval(0);

  glfwSetErrorCallback(failure);

  // set default values
  gib_window.width = 1;
  gib_window.height = 1;
  gib_window.active = true;
  gib_window.title = "gib window";
  gib_window_fullscreen(false);
  gib_window_resizeable(false);
  gib_window_vsync(false);
}

void gib_window_dimensions(int width, int height) {
  gib_window.width = width;
  gib_window.height = height;
  glfwSetWindowSize(glfw_window, width, height);
}

void gib_window_fill_screen() {
  GLFWmonitor *active_monitor = glfwGetPrimaryMonitor();
  const GLFWvidmode *active_mode = glfwGetVideoMode(active_monitor);
  gib_window_dimensions(active_mode->width, active_mode->height);
}

void gib_window_resizeable(bool resizable) {
  gib_window.resizeable = resizable;
  if (resizable)
    glfwSetWindowSizeLimits(glfw_window, GLFW_DONT_CARE, GLFW_DONT_CARE,
                            GLFW_DONT_CARE, GLFW_DONT_CARE);
  else
    glfwSetWindowSizeLimits(glfw_window, gib_window.width, gib_window.height,
                            gib_window.width, gib_window.height);
}

void gib_window_fullscreen(bool fullscreen) {
  gib_window.fullscreen = fullscreen;
  if (fullscreen) {
    GLFWmonitor *active_monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *active_mode = glfwGetVideoMode(active_monitor);
    glfwSetWindowMonitor(glfw_window, active_monitor, 0, 0, active_mode->width,
                         active_mode->height, GLFW_DONT_CARE);
  } else {
    glfwSetWindowMonitor(glfw_window, NULL, 0, 0, 1, 1, GLFW_DONT_CARE);
    gib_window_fill_screen();
  }
}

void gib_window_vsync(bool vsync) {
  gib_window.vsync = vsync;
  glfwSwapInterval((vsync) ? 1 : 0);
}

void gib_window_title(char *title) {
  gib_window.title = title;
  glfwSetWindowTitle(glfw_window, title);
}

void gib_window_refresh() {
  gib_window.active = !glfwWindowShouldClose(glfw_window);
  glfwSwapBuffers(glfw_window);
  glfwPollEvents();
}

void gib_window_destroy() {
  glfwDestroyWindow(glfw_window);
  glfwTerminate();
}

//***************************************************************************//

gib_key GIB_KEY_A = {.peripheral = GLFW_KEY_A, .state = false};
gib_key GIB_KEY_B = {.peripheral = GLFW_KEY_B, .state = false};
gib_key GIB_KEY_C = {.peripheral = GLFW_KEY_C, .state = false};
gib_key GIB_KEY_D = {.peripheral = GLFW_KEY_D, .state = false};
gib_key GIB_KEY_E = {.peripheral = GLFW_KEY_E, .state = false};
gib_key GIB_KEY_F = {.peripheral = GLFW_KEY_F, .state = false};
gib_key GIB_KEY_G = {.peripheral = GLFW_KEY_G, .state = false};
gib_key GIB_KEY_H = {.peripheral = GLFW_KEY_H, .state = false};
gib_key GIB_KEY_I = {.peripheral = GLFW_KEY_I, .state = false};
gib_key GIB_KEY_J = {.peripheral = GLFW_KEY_J, .state = false};
gib_key GIB_KEY_K = {.peripheral = GLFW_KEY_K, .state = false};
gib_key GIB_KEY_L = {.peripheral = GLFW_KEY_L, .state = false};
gib_key GIB_KEY_M = {.peripheral = GLFW_KEY_M, .state = false};
gib_key GIB_KEY_N = {.peripheral = GLFW_KEY_N, .state = false};
gib_key GIB_KEY_O = {.peripheral = GLFW_KEY_O, .state = false};
gib_key GIB_KEY_P = {.peripheral = GLFW_KEY_P, .state = false};
gib_key GIB_KEY_Q = {.peripheral = GLFW_KEY_Q, .state = false};
gib_key GIB_KEY_R = {.peripheral = GLFW_KEY_R, .state = false};
gib_key GIB_KEY_S = {.peripheral = GLFW_KEY_S, .state = false};
gib_key GIB_KEY_T = {.peripheral = GLFW_KEY_T, .state = false};
gib_key GIB_KEY_U = {.peripheral = GLFW_KEY_U, .state = false};
gib_key GIB_KEY_V = {.peripheral = GLFW_KEY_V, .state = false};
gib_key GIB_KEY_W = {.peripheral = GLFW_KEY_W, .state = false};
gib_key GIB_KEY_X = {.peripheral = GLFW_KEY_X, .state = false};
gib_key GIB_KEY_Y = {.peripheral = GLFW_KEY_Y, .state = false};
gib_key GIB_KEY_Z = {.peripheral = GLFW_KEY_Z, .state = false};

bool gib_keypressed(gib_key *key) { return !key->state && gib_keydown(key); }

bool gib_keyreleased(gib_key *key) { return key->state && !gib_keydown(key); }

bool gib_keydown(gib_key *key) {
  key->state = glfwGetKey(glfw_window, key->peripheral);
  return key->state;
}

//***************************************************************************//