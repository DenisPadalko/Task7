#pragma once
#include "Matrix.h"

template <typename T>
class Sorter
{
public:
    virtual void Sort(vector<T>& DataToSort) const = 0;
};

template <typename T>
class QuickSorter : public Sorter<T>
{
public:
    virtual void Sort(vector<T>& DataToSort) const override;
private:
    void Sort_Internal(vector<T>& DataToSort, const int Start, const int End) const;
};

template <typename T>
class UsualSorter : public Sorter<T>
{
public:
    virtual void Sort(vector<T>& DataToSort) const override;
private:
    void SortWithPredicate(vector<T>& DataToSort) const;
};