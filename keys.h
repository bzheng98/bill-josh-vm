#include <ncurses.h>

bool is_enter(int c) {
    return c == KEY_ENTER || c == 10 || c == 13;
}

bool is_escape(int c) {
    return c == 27;
}
