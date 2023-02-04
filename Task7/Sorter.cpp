#include "Sorter.h"
#include <algorithm>

int Partition(vector<Matrix*>& OutVectorOfMatrices, const int Start, const int End)
{
    Matrix* PivotMatrix = OutVectorOfMatrices[Start + (End - Start) / 2];
    int i = Start;
    int j = End;
    while(i <= j)
    {
        while(PivotMatrix < OutVectorOfMatrices[i]) ++i;
        while(OutVectorOfMatrices[j] < PivotMatrix) --j;
        if(i <= j)
        {
            swap(OutVectorOfMatrices[i], OutVectorOfMatrices[j]);
            ++i;
            --j;
        }
    }
    return i;
}

void QuickSorter::Sort(vector<Matrix*>& OutVectorOfMatrices) const
{
    Sort_Internal(OutVectorOfMatrices, 0, OutVectorOfMatrices.size() - 1);
}


void QuickSorter::Sort_Internal(vector<Matrix*>& OutVectorOfMatrices, const int Start, const int End) const
{
    if(OutVectorOfMatrices.size() == 1) return;
    if(Start < End)
    {
        int PivotIndex = Partition(OutVectorOfMatrices, Start, End);
        Sort_Internal(OutVectorOfMatrices, Start, PivotIndex - 1);
        Sort_Internal(OutVectorOfMatrices, PivotIndex, End);
    }
}

void UsualSorter::Sort(vector<Matrix*>& OutVectorOfMatrices) const
{
    sort(OutVectorOfMatrices.begin(), OutVectorOfMatrices.end(), Compare);
}
