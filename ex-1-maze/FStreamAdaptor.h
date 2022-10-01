#pragma once
#include "FileIOInterface.h"
#include <fstream>

class FStreamAdaptor :
    public FileIOInterface {
public:
    FStreamAdaptor(std::string _filePath);
    ~FStreamAdaptor();
    // Inherited via FileIOInterface
    virtual std::string read() override;
    virtual bool write(std::string line) override;

private:
    std::fstream fileStream;
    int currentPosition;
};

