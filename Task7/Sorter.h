#pragma once
#include "Matrix.h"
#include <vector>

class Sorter
{
public:
    static void QuickSort(const Matrix** MatrixArray, const size_t Size);
    static void UsualSort(const Matrix** MatrixArray, const size_t Size);
};
