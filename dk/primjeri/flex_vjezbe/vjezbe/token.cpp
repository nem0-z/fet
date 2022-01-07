#include "token.hpp"

std::ostream& operator<<(std::ostream& out, const Token& token) {
    return out << token.id << "-" << token.lexeme;
}
