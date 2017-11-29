#include "keys.h"
#include <ncurses.h>

bool is_enter(int c) {
    return c == KEY_ENTER || c == 10 || c == 13;
}

bool is_escape(int c) {
    return c == 27;
}

bool is_left(int c) {
    return c == KEY_LEFT;
}

bool is_down(int c) {
    return c == KEY_DOWN;
}

bool is_up(int c) {
    return c == KEY_UP;
}

bool is_right(int c) {
    return c == KEY_RIGHT;
}

bool is_backspace(int c) {
    return c == KEY_BACKSPACE || c == KEY_DC || c == 127;
}
