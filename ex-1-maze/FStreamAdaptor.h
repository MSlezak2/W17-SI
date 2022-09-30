#pragma once
#include "FileIOInterface.h"

class FStreamAdaptor :
    public FileIOInterface {
public:
    FStreamAdaptor(std::string _filePath) : filePath{ _filePath } {};
    // Inherited via FileIOInterface
    virtual std::string read() override;
    virtual bool write(std::string) override;

private:
    std::string filePath;

};

