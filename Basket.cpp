#include "Basket.h"
#include <cstring>

Basket::Basket() : name(nullptr), size(0)
{
}

Basket::Basket(const char *name, const EggsVector eggs, const size_t size) : size(size)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->eggs = eggs;
}

Basket::Basket(const Basket &other)
{
    copy(other);
}

Basket &Basket::operator=(const Basket &other)
{
    if(this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}

Basket::~Basket()
{
    clear();
}

bool Basket::checkName(const char* name)
{
    if(strcmp(this->name, name) == 0)
        return true;
    return false;
}

void Basket::addEgg(const Egg &newEgg)
{
    this->eggs.addEgg(newEgg);
}

void Basket::removeEgg(const char *name)
{
    this->eggs.removeEgg(name);
}

void Basket::serialize(std::ostream &out)
{
    if(!out)
    {
        std::cout << "Somethong went wrong!" << std::endl;
    }
    else
    {
        int nameSize = strlen(this->name)+1;
        out.write(reinterpret_cast<char*>(&nameSize), sizeof(nameSize)); //wrtie size of the name
        out.write(reinterpret_cast<char*>(this->name), nameSize); //write the name
        eggs.serialize(out);

    }
}

void Basket::deserialize(std::istream &in)
{
    if(!in)
    {
        std::cout << "Somethong went wrong!" << std::endl;
    }
    else
    {
        int nameSize = 0;
        in.read(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));
        char* n = new char[nameSize];
        in.read(reinterpret_cast<char*>(n), nameSize);
        
        delete[] this->name;
        this->name = new char[nameSize];
        strcpy(this->name, n);

        eggs.deserialize(in);
    }
}

void Basket::print() const
{
    std::cout << "printing basket " << this->name << std::endl;
    eggs.print();
}

void Basket::clear()
{
    delete[] name;
}

void Basket::copy(const Basket &other)
{
    this->size = other.size;

    delete[] name;
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->eggs = other.eggs;
}
