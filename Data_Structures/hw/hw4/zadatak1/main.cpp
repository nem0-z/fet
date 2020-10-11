#include "words.hpp"

int main(int argc, char const *argv[])
{
    TextAnalyser t;
    t.getFile(argv[1]);
    t.printFile();
    return 0;
}
