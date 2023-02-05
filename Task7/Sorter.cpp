#include "Sorter.h"
#include <algorithm>

template <typename T>
int Partition(vector<T>& DataToSort, const int Start, const int End)
{
    T PivotMatrix = DataToSort[Start + (End - Start) / 2];
    int i = Start;
    int j = End;
    while(i <= j)
    {
        while(PivotMatrix < DataToSort[i]) ++i;
        while(DataToSort[j] < PivotMatrix) --j;
        if(i <= j)
        {
            swap(DataToSort[i], DataToSort[j]);
            ++i;
            --j;
        }
    }
    return i;
}

template <typename T>
int PartitionWithPredicate(vector<T>& DataToSort, const int Start, const int End, const Sorter<T>::PredicateType& Predicate)
{
    T PivotMatrix = DataToSort[Start + (End - Start) / 2];
    int i = Start;
    int j = End;
    while(i <= j)
    {
        while(Predicate(PivotMatrix, DataToSort[i])) ++i;
        while(Predicate(DataToSort[j], PivotMatrix)) --j;
        if(i <= j)
        {
            swap(DataToSort[i], DataToSort[j]);
            ++i;
            --j;
        }
    }
    return i;
}

template <typename T>
void QuickSorter<T>::Sort(vector<T>& DataToSort) const
{
    Sort_Internal(DataToSort, 0, DataToSort.size() - 1);
}

template <typename T>
void QuickSorter<T>::SortWithPredicate(vector<T>& DataToSort, const typename Sorter<T>::PredicateType& Predicate) const
{
    Sort_Internal_WithPredicate(DataToSort, 0, DataToSort.size() - 1, Predicate);
}


template <typename T>
void QuickSorter<T>::Sort_Internal(vector<T>& DataToSort, const int Start, const int End) const
{
    if(DataToSort.size() == 1) return;
    if(Start < End)
    {
        int PivotIndex = Partition(DataToSort, Start, End);
        Sort_Internal(DataToSort, Start, PivotIndex - 1);
        Sort_Internal(DataToSort, PivotIndex, End);
    }
}

template <typename T>
void QuickSorter<T>::Sort_Internal_WithPredicate(vector<T>& DataToSort, const int Start, const int End,
    const Sorter<T>::PredicateType& Predicate) const
{
    if(DataToSort.size() == 1) return;
    if(Start < End)
    {
        int PivotIndex = PartitionWithPredicate(DataToSort, Start, End);
        Sort_Internal_WithPredicate(DataToSort, Start, PivotIndex - 1);
        Sort_Internal_WithPredicate(DataToSort, PivotIndex, End);
    }
}


template <typename T>
void UsualSorter<T>::Sort(vector<T>& DataToSort) const
{
    sort(DataToSort.begin(), DataToSort.end());
}


template <typename T>
void UsualSorter<T>::SortWithPredicate(vector<T>& DataToSort, const Sorter<T>::PredicateType& Predicate) const
{
    sort(DataToSort.begin(), DataToSort.end(), Predicate);
}
