#pragma once
#include "Matrix.h"

class Loader
{
public:
    const Matrix& ConsoleLoader();
    const Matrix& FileLoader();
};
