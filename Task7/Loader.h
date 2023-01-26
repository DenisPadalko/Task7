#pragma once
#include "Matrix.h"

class Loader
{
public:
    static const Matrix& ConsoleLoader();
    static const Matrix& FileLoader();
};
