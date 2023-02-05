#pragma once
#include "Matrix.h"

class Loader
{
public:
    virtual const vector<string>& Load() const = 0;
};

class ConsoleLoader : public Loader
{
public:
    virtual const vector<string>& Load() const override;
};

class FileLoader : public Loader
{
public:
    virtual const vector<string>& Load() const override;
};