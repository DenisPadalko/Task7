#pragma once
#include "Matrix.h"

class Sorter
{
public:
    virtual void Sort(vector<Matrix*>& OutVectorOfMatrices) const = 0;
};

class QuickSorter : public Sorter
{
public:
    virtual void Sort(vector<Matrix*>& OutVectorOfMatrices) const override;
private:
    void Sort_Internal(vector<Matrix*>& OutVectorOfMatrices, const int Start, const int End) const;
};

class UsualSorter : public Sorter
{
public:
    virtual void Sort(vector<Matrix*>& OutVectorOfMatrices) const override;
};