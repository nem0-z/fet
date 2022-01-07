#pragma once

#include <string>
#include <vector>
#include <iostream>

enum {
    OPEN_BRACES = 1,
    CLOSED_BRACES,
    OPEN_BRACKET,
    CLOSED_BRACKET,
    OPEN_PAREN,
    CLOSED_PAREN
};

struct Token {
    int id;
    std::string lexeme;
};

bool analiziraj(const std::vector<Token>& tokeni);

std::ostream& operator<<(std::ostream& out, const Token& token);

