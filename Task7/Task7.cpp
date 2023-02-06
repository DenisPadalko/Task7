#include "Matrix.h"
#include "Loader.h"
#include "Sorter.h"
#include "Sorter.cpp"
#include "Exceptions.h"

int main(int argc, char* argv[])
{
    FileLoader LoaderFromFile;
    vector<string> InputFromFile = LoaderFromFile.Load();
    vector<Matrix> MatricesFromFile;
    for (auto& k : InputFromFile)
    {
        MatricesFromFile.push_back(k.c_str());
        
    }
    for (auto& k : MatricesFromFile)
    {
        cout << "Matrix read from the file: " << endl;
        for(size_t i = 0; i < k.GetRows(); ++i)
        {
            for(size_t j = 0; j < k.GetColumns(); ++j)
            {
                cout << k.GetMatrix()[i][j] << " ";
            }
            cout << endl;
        }
    }
    ConsoleLoader LoaderFromConsole;
    vector<string> InputFromConsole = LoaderFromConsole.Load();
    vector<Matrix> MatricesFromConsole;
    for(auto& k : InputFromConsole)
    {
        MatricesFromConsole.push_back(InputFromConsole[0].c_str());
    }
    for(auto& k : MatricesFromConsole)
    {
        cout << "Matrix read from the console" << endl;
        for(size_t i = 0; i < k.GetRows(); ++i)
        {
            for(size_t j = 0; j < k.GetColumns(); ++j)
            {
                cout << k.GetMatrix()[i][j] << " ";
            }
            cout << endl;
        }
    }
    vector<Matrix> Vec;
    for(int i = 0; i < MatricesFromFile.size(); ++i)
    {
        Vec.push_back(MatricesFromFile[i]);
    }
    for(int i = 0; i < MatricesFromConsole.size(); ++i)
    {
        Vec.push_back(MatricesFromConsole[i]);
    }
    QuickSorter<Matrix> Sorter;
    Sorter.Sort(Vec);
    cout << endl << "Sorted matrices: " << endl;
    for(int k = 0; k < Vec.size(); ++k)
    {
        for(size_t i = 0; i < Vec[k].GetRows(); ++i)
        {
            for(size_t j = 0; j < Vec[k].GetColumns(); ++j)
            {
                cout << Vec[k].GetMatrix()[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
