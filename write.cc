#include "write.h"
#include "vm.h"
#include "keys.h"

void Write::update(const CommandInfo &c) {
    if (c.getCommandType() != CommandType::WRITE)
        return;
    int in = vm->getChar();
    std::string s;
    while(!is_enter(in)) {
        s += in;
        in = vm->getChar();
    }
    save(s);
    vm->write(s);
}
