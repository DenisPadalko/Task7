#pragma once
#include "Matrix.h"

class Sorter
{
public:
    virtual void Sort(vector<Matrix*>& OutVectorOfMatrices, const int = 0, const int = 0) const = 0;
};

class QuickSorter : public Sorter
{
public:
    virtual void Sort(vector<Matrix*>& OutVectorOfMatrices, const int Start = 0, const int End = 0) const override;
};

class UsualSorter : public Sorter
{
public:
    virtual void Sort(vector<Matrix*>& OutVectorOfMatrices, const int = 0, const int = 0) const override;
};