#pragma once

#include "Egg.h"
#include "EggsVector.h"

class Basket
{
public:
    Basket();
    Basket(const char* name, const EggsVector eggs, const size_t size);
    Basket(const Basket& other);
    Basket& operator=(const Basket& other);
    ~Basket();

    bool checkName(const char* name);
    void addEgg(const Egg& newEgg);
    void removeEgg(const char* name);

    void serialize(std::ostream& out); //const or no const
    void deserialize(std::istream& in); 

    void print() const;

private:
    char* name;
    EggsVector eggs; //какво го правим като не е динамично ???
    size_t size;

    void clear();
    void copy(const Basket& other);
};

//write Egg in file
//read Egg from file

//TODO: write in file EggVEctor and Basket (bin file)
//TODO: read from file EggVector and Basket (bin file)

//TODO: make the uuid unique for the day
//TODO: generate report for each basket (text file)