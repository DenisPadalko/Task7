#include "Loader.h"
#include <fstream>

const Matrix& ConsoleLoader::Load() const
{
    cout << "Enter matrix Rows: ";
    int Rows;
    cin >> Rows;
    cout << "Enter matrix columns: ";
    int Columns;
    cin >> Columns;
    double** NewArray = new double*[Rows];
    for(int i = 0; i < Rows; ++i)
    {
        NewArray[i] = new double[Columns];
        cout << endl << endl << "Line number " << i+1 << endl << endl;
        for(int j = 0; j < Columns; ++j)
        {
            cout << "Enter next element: ";
            cin >> NewArray[i][j];
        }
    }
    Matrix* NewMatrix = new Matrix(const_cast<const double**>(NewArray), Rows, Columns);
    for(int i = 0; i < Rows; ++i)
    {
        delete[] NewArray[i];
    }
    delete[] NewArray;
    return *NewMatrix;
}

const Matrix& FileLoader::Load() const
{
    ifstream Input;
    Input.open("Input.txt", ios::in);
    if(!Input)
    {
        throw CannotOpenTheFileException("Error. File is not opened");
    }
    int Rows, Columns;
    Input >> Rows >> Columns;
    double** NewArray = new double*[Rows];
    for(int i = 0; i < Rows; ++i)
    {
        NewArray[i] = new double[Columns];
        for(int j = 0; j < Columns; ++j)
        {
            Input >> NewArray[i][j];
        }
    }
    Input.close();
    Matrix* NewMatrix = new Matrix(const_cast<const double**>(NewArray), Rows, Columns);
    return *NewMatrix;
}
