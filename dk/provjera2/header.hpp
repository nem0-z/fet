#pragma once
#include <string>

enum tokenTags {
    TITLE = 1,
    EQUAL,
    STRING,
    TABLE,
    ID,
    BOOLEAN,
    NUM,
    IP
};

inline std::string mapTagToString(int tag) {
    switch(tag) {
        case TITLE:
            return "TITLE";
        case EQUAL:
            return "EQUAL";
        case STRING:
            return "STRING";
        case TABLE:
            return "TABLE";
        case ID:
            return "ID";
        case BOOLEAN:
            return "BOOLEAN";
        case NUM:
            return "NUM";
        case IP:
            return "IP";
    }

    return "";
}
