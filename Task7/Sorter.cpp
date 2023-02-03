#include "Sorter.h"

#include <algorithm>

double CalculateSumOfElementsInDiagonals(const Matrix* SomeMatrix)
{
    double Result = 0;
    double** MatrixElements = SomeMatrix->GetMatrix();
    for(int i = 0; i < SomeMatrix->GetRows(); ++i)
    {
        Result += MatrixElements[i][i];
    }
    for(int i = SomeMatrix->GetRows() - 1; i > 0; --i)
    {
        Result += MatrixElements[i][i];
    }
    MatrixElements = nullptr;
    delete[] MatrixElements;
    return Result;
}

double CalculateTraceOfTheMatrix(const Matrix* SomeMatrix)
{
    double Result = 0;
    double** MatrixElements = SomeMatrix->GetMatrix();
    for(size_t i = 0; i < SomeMatrix->GetRows(); ++i)
    {
        Result += MatrixElements[i][i];
    }
    return Result;
}

bool Compare(const void* FirstMatrix, const void* SecondMatrix)
{
    double FirstResult = CalculateSumOfElementsInDiagonals(static_cast<const Matrix*>(FirstMatrix));
    double SecondResult = CalculateSumOfElementsInDiagonals(static_cast<const Matrix*>(SecondMatrix));
    if(FirstResult == SecondResult)
    {
        FirstResult = CalculateTraceOfTheMatrix(static_cast<const Matrix*>(FirstMatrix));
        SecondResult = CalculateTraceOfTheMatrix(static_cast<const Matrix*>(SecondMatrix));
        if(FirstResult < SecondResult) return false;
        else return true;
    }
    else if(FirstResult < SecondResult) return false;
    else return true;
}

int Partition(vector<Matrix*>& OutVectorOfMatrices, const int Start, const int End)
{
    Matrix* PivotMatrix = OutVectorOfMatrices[Start + (End - Start) / 2];
    int i = Start;
    int j = End;
    while(i <= j)
    {
        while(Compare(PivotMatrix, OutVectorOfMatrices[i])) ++i;
        while(Compare(OutVectorOfMatrices[j], PivotMatrix)) --j;
        if(i <= j)
        {
            swap(OutVectorOfMatrices[i], OutVectorOfMatrices[j]);
            ++i;
            --j;
        }
    }
    return i;
}

void QuickSorter::Sort(vector<Matrix*>& OutVectorOfMatrices, const int Start, const int End) const
{
    if(OutVectorOfMatrices.size() == 1) return;
    if(Start < End)
    {
        int PivotIndex = Partition(OutVectorOfMatrices, Start, End);
        Sort(OutVectorOfMatrices, Start, PivotIndex - 1);
        Sort(OutVectorOfMatrices, PivotIndex, End);
    }
}

void UsualSorter::Sort(vector<Matrix*>& OutVectorOfMatrices, const int, const int) const
{
    sort(OutVectorOfMatrices.begin(), OutVectorOfMatrices.end(), Compare);
}
