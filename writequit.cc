#include "writequit.h"
#include "vm.h"
#include "keys.h"

void WriteQuit::update(const CommandInfo &c) {
    if (c.getCommandType() != CommandType::WRITEQUIT)
        return;
    int in = vm->getChar();
    vm->log("WRITEQUIT_IN");
    vm->log(in);
    std::string s;
    while(!is_enter(in)) {
        s += in;
        in = vm->getChar();
    }
    save(s);
    quit();
}
