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
    for (auto& i : MatricesFromFile)
    {
        Vec.push_back(i);
    }
    for(auto& i : MatricesFromConsole)
    {
        Vec.push_back(i);
    }
    UsualSorter<Matrix> Sorter;
    Sorter.Sort(Vec);
    cout << endl << "Sorted matrices: " << endl;
    for(auto& k : Vec)
    {
        for(size_t i = 0; i < k.GetRows(); ++i)
        {
            for(size_t j = 0; j < k.GetColumns(); ++j)
            {
                cout << k.GetMatrix()[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
