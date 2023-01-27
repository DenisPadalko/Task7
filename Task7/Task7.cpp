#include "Matrix.h"
#include "Loader.h"
#include "Sorter.h"
#include "Exceptions.h"

int main(int argc, char* argv[])
{
    Matrix** MatrixArray = new Matrix*[2];
    MatrixArray[0] = new Matrix(Loader::FileLoader());
    cout << "Matrix read from the file: " << endl;
    for(size_t i = 0; i < MatrixArray[0]->GetLines(); ++i)
    {
        for(size_t j = 0; j < MatrixArray[0]->GetColumns(); ++j)
        {
            cout << MatrixArray[0]->GetMatrix()[i][j] << " ";
        }
        cout << endl;
    }
    MatrixArray[1] = Loader::ConsoleLoader();
    cout << "Matrix read from the console" << endl;
    for(size_t i = 0; i < MatrixArray[1]->GetLines(); ++i)
    {
        for(size_t j = 0; j < MatrixArray[1]->GetColumns(); ++j)
        {
            cout << MatrixArray[1]->GetMatrix()[i][j] << " ";
        }
        cout << endl;
    }
    Sorter::QuickSort(const_cast<const Matrix**>(MatrixArray), 2);
    for(size_t i = 0; i < MatrixArray[0]->GetLines(); ++i)
    {
        for(size_t j = 0; j < MatrixArray[0]->GetColumns(); ++j)
        {
            cout << MatrixArray[0]->GetMatrix()[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl << endl;
    for(size_t i = 0; i < MatrixArray[1]->GetLines(); ++i)
    {
        for(size_t j = 0; j < MatrixArray[1]->GetColumns(); ++j)
        {
            cout << MatrixArray[1]->GetMatrix()[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
