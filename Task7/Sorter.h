#pragma once
#include "Matrix.h"
#include <functional>

template <typename T>
class Sorter
{
public:
    using PredicateType = function<bool(const T& left, const T& right)>;
    virtual void Sort(vector<T>& DataToSort) const = 0;
    virtual void SortWithPredicate(vector<T>& DataToSort, const Sorter<T>::PredicateType& Predicate) const = 0;
};

template <typename T>
class QuickSorter : public Sorter<T>
{
public:
    virtual void Sort(vector<T>& DataToSort) const override;
    virtual void SortWithPredicate(vector<T>& DataToSort, const Sorter<T>::PredicateType& Predicate) const override;
private:
    void Sort_Internal(vector<T>& DataToSort, const int Start, const int End) const;
    void Sort_Internal_WithPredicate(vector<T>& DataToSort, const int Start, const int End,
        const Sorter<T>::PredicateType& Predicate) const;
};

template <typename T>
class UsualSorter : public Sorter<T>
{
public:
    virtual void Sort(vector<T>& DataToSort) const override;
    virtual void SortWithPredicate(vector<T>& DataToSort, const Sorter<T>::PredicateType& Predicate) const override;
};