#ifndef RFIDDATA_H
#define RFIDDATA_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <iterator>

class rfiddata
{
public:
     rfiddata();
    ~rfiddata();

private:


public:
     std::vector<std::string> datablocks;
     std::vector<std::string> const &rdatablocks =datablocks;

};

#endif // RFIDDATA_H
