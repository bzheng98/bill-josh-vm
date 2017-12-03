#ifndef COMMANDTYPE_H
#define COMMANDTYPE_H
enum CommandType {
    INSERT,
    APPEND,
    PREPEND,
    NEWLINE_ABOVE,
    NEWLINE_BELOW,
    APPEND_TO_LINE,
    ENTER_REPLACE_MODE,
    LEFT,
    RIGHT,
    UP,
    DOWN,
    WRITE,
    WRITEQUIT,
    QUIT, 
	SCROLLUP,
	SCROLLDOWN,
	SCROLLFORWARD,
	SCROLLBACKWARD,
    UNDO,
    DELETE,
    YANK,
    PASTE_AFTER,
    WORD_FORWARD,
    WORD_BACK,
    FIND_FORWARD,
    FIND_BACK,
    PASTE_BEFORE,
    LINE_BEGIN,
    LINE_END,
    LINE_JUMP};
#endif
