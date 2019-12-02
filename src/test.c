// test file

#include "gib.h"
#include <stdio.h>

int main() {
  gib_window_init();
  gib_window_dimensions(800, 600);
  gib_window_title("test");
  gib_window_vsync(true);
  while (gib_window.active) {
    gib_window_refresh();
    if (gib_keypressed(&GIB_KEY_R)) {
      gib_window_resizeable(!gib_window.resizeable);
      printf("window is%s resizable\n", (gib_window.resizeable) ? "" : " not");
    }
  }
  gib_window_destroy();
}