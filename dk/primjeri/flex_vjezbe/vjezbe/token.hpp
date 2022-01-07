#pragma once

#include <string>
#include <iostream>

enum {
    STRING = 1,
    NUMBER,
    COLON,
    OPEN_BRACES,
    CLOSED_BRACES,
    OPEN_BRACKET,
    CLOSED_BRACKET,
    BOOLEAN,
    COMMA,
    NULLJSON
};

struct Token {
    int id;
    std::string lexeme;
};

std::ostream& operator<<(std::ostream& out, const Token& token);

