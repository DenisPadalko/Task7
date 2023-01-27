#include "Sorter.h"

#include <algorithm>

const double CalculateSumOfElementsInDiagonals(const Matrix* SomeMatrix)
{
    double Result = 0;
    double** MatrixElements = SomeMatrix->GetMatrix();
    for(int i = 0; i < SomeMatrix->GetLines(); ++i)
    {
        Result += MatrixElements[i][i];
    }
    for(int i = SomeMatrix->GetLines() - 1; i > 0; --i)
    {
        Result += MatrixElements[i][i];
    }
    MatrixElements = nullptr;
    delete[] MatrixElements;
    return Result;
}

const double CalculateTraceOfTheMatrix(const Matrix* SomeMatrix)
{
    double Result = 0;
    double** MatrixElements = SomeMatrix->GetMatrix();
    for(size_t i = 0; i < SomeMatrix->GetLines(); ++i)
    {
        Result += MatrixElements[i][i];
    }
    return Result;
}

int Compare(const void* FirstMatrix, const void* SecondMatrix)
{
    double FirstResult = CalculateSumOfElementsInDiagonals(static_cast<const Matrix*>(FirstMatrix));
    double SecondResult = CalculateSumOfElementsInDiagonals(static_cast<const Matrix*>(SecondMatrix));
    if(FirstResult == SecondResult)
    {
        FirstResult = CalculateTraceOfTheMatrix(static_cast<const Matrix*>(FirstMatrix));
        SecondResult = CalculateTraceOfTheMatrix(static_cast<const Matrix*>(SecondMatrix));
        if(FirstResult < SecondResult) return 0;
        else return 1;
    }
    else if(FirstResult < SecondResult) return 0;
    else return 1;
}

void Sorter::QuickSort(const Matrix** MatrixArray, const size_t Size)
{
    qsort(MatrixArray, Size, sizeof(Matrix), Compare);
}

void Sorter::UsualSort(const Matrix** MatrixArray, const size_t Size)
{
    sort(MatrixArray, MatrixArray + Size, Compare);
}
