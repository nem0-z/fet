#pragma once

struct Equation{
    int a;
    int b;
    int c;
    int d;
    int xmax;
    int ymax;
    int type;
};

enum EquationType {
    LINEAR,
    SQUARE,
    CUBIC
};
