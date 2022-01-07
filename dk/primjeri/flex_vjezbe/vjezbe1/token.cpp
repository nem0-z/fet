#include <stack>
#include "token.hpp"

std::ostream& operator<<(std::ostream& out, const Token& token) {
    return out << token.id << "-" << token.lexeme;
}

bool analiziraj(const std::vector<Token>& tokeni) {
    std::stack<Token> tstack;

    for (const auto& token : tokeni) {
        switch (token.id) {
            OPEN_BRACES:
            OPEN_BRACKET:
            OPEN_PAREN:
                    std::cout << "push" << std::endl;
                    tstack.push(token);
                    break;
            CLOSED_PAREN:
                    if (tstack.top().id == OPEN_PAREN){
                        std::cout << "pop" << std::endl;
                        tstack.pop();
                    } else {
                        std::cout << "false" << std::endl;
                        return false;
                    }
                    break;
            CLOSED_BRACKET:
                    if (tstack.top().id == OPEN_BRACKET){
                        std::cout << "pop" << std::endl;
                        tstack.pop();
                    } else {
                        std::cout << "false" << std::endl;
                        return false;
                    }
                    break;
            CLOSED_BRACES:
                    if (tstack.top().id == OPEN_BRACES){
                        std::cout << "pop" << std::endl;
                        tstack.pop();
                    } else {
                        std::cout << "false" << std::endl;
                        return false;
                    }
                    break;
        }
    }

    return tstack.empty();
}
