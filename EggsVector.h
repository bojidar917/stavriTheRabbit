#pragma once

#include "Egg.h"

class EggsVector
{
public:
    EggsVector();
    EggsVector(const EggsVector& other);
    EggsVector& operator=(const EggsVector& other);
    ~EggsVector();

    void addEgg(const Egg& egg);
    void removeEgg(const char* name);
    void serialize(std::ostream& out) const;
    void deserialize(std::istream& in); 
    
    int geetCount() const {return this->count; }

    void print() const; 

private:
    Egg* eggs;
    int capacity;
    int count;

    void resize();
    void clear();
    void copy(const EggsVector& other);
    void createNewTemp(int size);
    bool checkName(const char* name);
    void append();
};