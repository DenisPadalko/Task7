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
void QuickSorter<T>::Sort(vector<T>& DataToSort) const
{
    Sort_Internal(DataToSort, 0, DataToSort.size() - 1);
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
bool Compare(T& Left, T& Right)
{
    bool Result = Left < Right;
    return Result;
}

template <typename T>
void UsualSorter<T>::Sort(vector<T>& DataToSort) const
{
    SortWithPredicate(DataToSort);
}


template <typename T>
void UsualSorter<T>::SortWithPredicate(vector<T>& DataToSort) const
{
    sort(DataToSort.begin(), DataToSort.end(), Compare<T>);
}
