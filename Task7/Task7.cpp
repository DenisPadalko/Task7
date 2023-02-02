#include "Matrix.h"
#include "Loader.h"
#include "Sorter.h"
#include "Exceptions.h"

int main(int argc, char* argv[])
{
    FileLoader LoaderFromFile;
    Matrix MatrixFromFile = LoaderFromFile.Load();
    cout << "Matrix read from the file: " << endl;
    for(size_t i = 0; i < MatrixFromFile.GetLines(); ++i)
    {
        for(size_t j = 0; j < MatrixFromFile.GetColumns(); ++j)
        {
            cout << MatrixFromFile.GetMatrix()[i][j] << " ";
        }
        cout << endl;
    }
    ConsoleLoader LoaderFromConsole;
    Matrix MatrixFromConsole = LoaderFromConsole.Load();
    cout << "Matrix read from the console" << endl;
    for(size_t i = 0; i < MatrixFromConsole.GetLines(); ++i)
    {
        for(size_t j = 0; j < MatrixFromConsole.GetColumns(); ++j)
        {
            cout << MatrixFromConsole.GetMatrix()[i][j] << " ";
        }
        cout << endl;
    }
    vector<Matrix*> Vec;
    Vec.push_back(&MatrixFromFile);
    Vec.push_back(&MatrixFromConsole);
    QuickSorter Sorter;
    Sorter.Sort(Vec);
    cout << endl << "Sorted matrices: " << endl;
    for(size_t i = 0; i < Vec[0]->GetLines(); ++i)
    {
        for(size_t j = 0; j < Vec[0]->GetColumns(); ++j)
        {
            cout << Vec[0]->GetMatrix()[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(size_t i = 0; i < Vec[1]->GetLines(); ++i)
    {
        for(size_t j = 0; j < Vec[1]->GetColumns(); ++j)
        {
            cout << Vec[1]->GetMatrix()[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
