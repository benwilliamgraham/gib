#include <stdbool.h>

//***************************************************************************//

// gib window structure
struct {
  int width;
  int height;
  bool resizeable;
  bool fullscreen;
  char *title;
  bool active;
  bool vsync;
} gib_window;

// initialize window
// this must be called before changing any window settings
void gib_window_init();

// set dimensions of window
// (default (1, 1))
void gib_window_dimensions(int width, int height);

// set window to screen size
// (default no)
void gib_window_fill_screen();

// set if a window is resizeable
// (default no)
void gib_window_resizeable(bool resizable);

// set if window is fullscreen
// (default no)
void gib_window_fullscreen(bool fullscreen);

// set if vsync
// (default no)
void gib_window_vsync(bool vsync);

// set window title
// (default "gib window")
void gib_window_title(char *title);

// refresh window
void gib_window_refresh();

// destroy window
void gib_window_destroy();

//***************************************************************************//

// gib key structure
typedef struct {
  int peripheral;
  bool state;
} gib_key;

gib_key
    // letters
    GIB_KEY_A,
    GIB_KEY_B, GIB_KEY_C, GIB_KEY_D, GIB_KEY_E, GIB_KEY_F, GIB_KEY_G, GIB_KEY_H,
    GIB_KEY_I, GIB_KEY_J, GIB_KEY_K, GIB_KEY_L, GIB_KEY_M, GIB_KEY_N, GIB_KEY_O,
    GIB_KEY_P, GIB_KEY_Q, GIB_KEY_R, GIB_KEY_S, GIB_KEY_T, GIB_KEY_U, GIB_KEY_V,
    GIB_KEY_W, GIB_KEY_X, GIB_KEY_Y, GIB_KEY_Z,
    // numbers
    GIB_KEY_0, GIB_KEY_1, GIB_KEY_2, GIB_KEY_3, GIB_KEY_4, GIB_KEY_5, GIB_KEY_6,
    GIB_KEY_7, GIB_KEY_8, GIB_KEY_9,
    // specials
    GIB_KEY_UP, GIB_KEY_DOWN, GIB_KEY_LEFT, GIB_KEY_RIGHT, GIB_KEY_CTRL,
    GIB_KEY_LSFHIFT, GIB_KEY_RSHIFT, GIB_KEY_ESC, GIB_KEY_TAB, GIB_KEY_ENTER,
    GIB_KEY_SPACE;

// get if a key is just pressed
bool gib_keypressed(gib_key *key);

// get if a key is just released
bool gib_keyreleased(gib_key *key);

// get if a key is currently down
bool gib_keydown(gib_key *key);

//***************************************************************************//

