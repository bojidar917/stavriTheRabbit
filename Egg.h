#pragma once
#include <iostream>

class Egg
{
public:
    Egg();
    Egg(const char* name, size_t size);
    Egg(const Egg& other);
    Egg& operator=(const Egg& other);
    ~Egg();

    static void Count();
    void setUid();

    bool isName(const char* name) const;

    const char* getName() const {return this->name;} 
    void setName(const char* name);

    void setSize(const int size);
    size_t getSize() const {return this->size; }

    void setUid(const int uuid);
    size_t getUid() const {return this->uid;}

    void saveToFile(std::ostream &out) const;
    void readfromFile(std::istream &in);

    void print() const;

private:
    char *name;
    size_t size;
    size_t uid;
    static size_t count;

    void clear();
    void copy(const Egg& other);
};