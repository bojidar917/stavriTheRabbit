#include "Egg.h"
#include <cstring>

size_t Egg::count = 0;

Egg::Egg() : name(nullptr), size(0)
{
}

Egg::Egg(const char *name, size_t size)
{
    this->size = size;

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Egg::Egg(const Egg &other)
{
    copy(other);
}

Egg &Egg::operator=(const Egg &other)
{
    if(this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}

Egg::~Egg()
{
    clear();
}

void Egg::Count()
{
    Egg::count++;
}

void Egg::setUid()
{
    Egg::count++;
}

bool Egg::isName(const char *name) const
{
    return strcmp(this->name, name) == 0;
}

void Egg::setName(const char *name)
{
    if(name != nullptr)
    {
        char* newName = new char[strlen(name) + 1];
        if(!newName)
        {
            //TODO: handle the error here
            throw std::runtime_error("Error allocating memiry");
        }

        strcpy(newName, name);
        delete[] this->name;
        this->name = newName;
    }
    else
    {
        std::cout << "cannot set name" << std::endl;
    }
}

void Egg::setSize(const int size)
{
    if(size >= 0)
        this->size = size;
    else
        std::cout << "cannot set size" << std::endl;
}

void Egg::setUid(const int uuid)
{
    if(uuid >= 0)
        this->uid = uuid;
    else
        std::cout << "cannot set negative uid" << std::endl;
}

void Egg::saveToFile(std::ostream &out) const
{
    if(!out)
        std::cout << "Error with the file" << std::endl;
    else
    {
        size_t size = strlen(this->name) + 1;
        out.write(reinterpret_cast<char*>(&size), sizeof(size));
        out.write(reinterpret_cast<char*>(this->name), size);
        out.write(reinterpret_cast<const char*>(&this->size), sizeof(this->size));
        out.write(reinterpret_cast<const char*>(&this->uid), sizeof(this->uid));
    }
}

void Egg::readfromFile(std::istream &in)
{
    if(!in) std::cout << "Error reding from file" <<  std::endl;
    else
    {
        size_t size = 0;
        in.read(reinterpret_cast<char*>(&size), sizeof(size));
        delete[] this->name;
        this->name = new(std::nothrow) char[size];
        in.read(reinterpret_cast<char*>(this->name), size);
        in.read(reinterpret_cast<char*>(&this->size), sizeof(this->size));
        in.read(reinterpret_cast<char*>(&this->uid), sizeof(this->uid));
    }
}

void Egg::print() const
{
    std::cout << this->name << std::endl;
}

void Egg::clear()
{
    delete [] this->name;
}

void Egg::copy(const Egg &other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->size = other.size;
    this->uid = other.uid;
}
