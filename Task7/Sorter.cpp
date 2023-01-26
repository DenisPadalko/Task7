#include "Sorter.h"

#include <algorithm>

const double CalculateSumOfElementsInDiagonals(const Matrix& SomeMatrix)
{
    double Result = 0;
    double** MatrixElements = SomeMatrix.GetMatrix();
    for(int i = 0; i < SomeMatrix.GetLines(); ++i)
    {
        Result += MatrixElements[i][i];
    }
    for(int i = SomeMatrix.GetLines(); i > 0; --i)
    {
        Result += MatrixElements[i][i];
    }
    for(int i = 0; i < SomeMatrix.GetLines(); ++i)
    {
        delete[] MatrixElements[i];
    }
    delete[] MatrixElements;
    return Result;
}

const double CalculateTraceOfTheMatrix(const Matrix& SomeMatrix)
{
    double Result = 0;
    double** MatrixElements = SomeMatrix.GetMatrix();
    for(size_t i = 0; i < SomeMatrix.GetLines(); ++i)
    {
        Result += MatrixElements[i][i];
    }
    return Result;
}

int Compare(const void* FirstMatrix, const void* SecondMatrix)
{
    double FirstResult = CalculateSumOfElementsInDiagonals(*(Matrix*)FirstMatrix);
    double SecondResult = CalculateSumOfElementsInDiagonals(*(Matrix*)SecondMatrix);
    if(FirstResult == SecondResult)
    {
        FirstResult = CalculateTraceOfTheMatrix(*(Matrix*)FirstMatrix);
        SecondResult = CalculateTraceOfTheMatrix(*(Matrix*)SecondMatrix);
        if(FirstResult < SecondResult) return -1;
        else return 1;
    }
    else if(FirstResult < SecondResult) return -1;
    else return 1;
}

void Sorter::QuickSort(vector<Matrix*> Vec)
{
    qsort(Vec.data(), Vec.size(), sizeof(Matrix*), Compare);
}

void Sorter::UsualSort(vector<Matrix*> Vec)
{
    sort(Vec.begin(), Vec.end(), Compare);
}
