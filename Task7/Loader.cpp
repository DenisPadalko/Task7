#include "Loader.h"
#include <fstream>

const Matrix& Loader::ConsoleLoader()
{
    cout << "Enter matrix lines: ";
    int Lines;
    cin >> Lines;
    cout << "Enter matrix columns: ";
    int Columns;
    cin >> Columns;
    double** NewArray = new double*[Lines];
    for(int i = 0; i < Lines; ++i)
    {
        NewArray[i] = new double[Columns];
        cout << endl << endl << "Line number " << i+1 << endl << endl;
        for(int j = 0; j < Columns; ++j)
        {
            cout << "Enter next element: ";
            cin >> NewArray[i][j];
        }
    }
    Matrix* NewMatrix = new Matrix((const double**)NewArray, Lines, Columns);
    for(int i = 0; i < Lines; ++i)
    {
        delete[] NewArray[i];
    }
    delete[] NewArray;
    return *NewMatrix;
}

const Matrix& Loader::FileLoader()
{
    ifstream input;
    input.open("Input.txt", ios::in);
    if(!input)
    {
        
    }
    input.close();
}
