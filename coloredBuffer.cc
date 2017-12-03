#include "coloredBuffer.h"
ColoredBuffer::ColoredBuffer(const std::vector<std::string> &buffer) {
    //generate the keywords, etc
    //lime green
    keyWords = { "namespace", "class", "template", "typename", "class", "const", "static", "size_t", "void", "bool", "int", "char", "auto" };
    //french fry yellow
    identifiers = { "if", "for", "return", "new", "delete", "throw", "else", "operator", "this", "sizeof" };
    for(int i = 0; i < buffer.size(); i++)colors.push_back(std::vector<int>(buffer[i].size(), 0));
    //match keywords and identifiers first
    std::smatch m;
    for(int i = 0; i < keyWords.size(); i++) {
        std::string &s = keyWords[i];
        std::regex r("(^|[^a-zA-Z0-9])(" + s + ")($|[^a-zA-Z0-9])");
        for(int strIdx = 0; strIdx < buffer.size(); strIdx++) {
            for(auto it = std::sregex_iterator(buffer[strIdx].begin(), buffer[strIdx].end(), r); it != std::sregex_iterator(); ++it) {
                m = *it;           
                int j = m.position(2);
                for(int k = j; k < j + s.size(); k++)colors[strIdx][k] = 1;
            }
        }
    }
    //identifiers
    for(int i = 0; i < identifiers.size(); i++) {
        std::string &s = identifiers[i];
        std::regex r("(^|[^a-zA-Z0-9])(" + s + ")($|[^a-zA-Z0-9])");
        for(int strIdx = 0; strIdx < buffer.size(); strIdx++) {
            for(auto it = std::sregex_iterator(buffer[strIdx].begin(), buffer[strIdx].end(), r); it != std::sregex_iterator(); ++it) {
                m = *it;     
                int j = m.position(2);
                for(int k = j; k < j + s.size(); k++)colors[strIdx][k] = 2;
            }     
        }
    }   
    std::regex num("(^|[^a-zA-Z0-9])([0-9]+)($|[^a-zA-Z0-9])");
    //numerics
    for(int strIdx = 0; strIdx < buffer.size(); strIdx++) {
        for(auto it = std::sregex_iterator(buffer[strIdx].begin(), buffer[strIdx].end(), num); it != std::sregex_iterator(); ++it) {
            m = *it; 
            int j = m.position(2); 
            for(int k = j; k < j + m.length(2); k++)colors[strIdx][k] = 3;
        }
    }
    std::regex closed("(\"[^\"\\\\]*(\\\\.[^\"\\\\]*)*\")|(\"[^\"\\\\]*(\\\\.[^\"\\\\]*)*)");
    //string lits
    for(int strIdx = 0; strIdx < buffer.size(); strIdx++) {
        //closing "" 
        for(auto it = std::sregex_iterator(buffer[strIdx].begin(), buffer[strIdx].end(), closed); it != std::sregex_iterator(); ++it) {
            m = *it;
            int j = m.position(0);
            for(int k = j; k < j + m.length(0); k++)colors[strIdx][k] = 3;           
        }
    }
    std::regex def("^ *(#define|#ifndef)($|[^a-zA-Z0-9]+.*)");
    //#define, #ifndef
    for(int strIdx = 0; strIdx < buffer.size(); strIdx++) {
        for(auto it = std::sregex_iterator(buffer[strIdx].begin(), buffer[strIdx].end(), def); it != std::sregex_iterator(); ++it) {
            m = *it;
            int j = m.position(0);
            for(int k = j; k < j + m.length(0); k++)colors[strIdx][k] = 4;
        }
    }
    std::regex endif("(^ *)(#endif)($|[^a-zA-Z0-9]+.*)");
    //#endif
    for(int strIdx = 0; strIdx < buffer.size(); strIdx++) {
        for(auto it = std::sregex_iterator(buffer[strIdx].begin(), buffer[strIdx].end(), endif); it != std::sregex_iterator(); ++it) {
            m = *it;
            int j = m.position(2);
            for(int k = j; k < j + m.length(2); k++)colors[strIdx][k] = 4;
        }
    }
}

std::vector<int> ColoredBuffer::getColor(const size_t i) {
    return colors[i];
} 

