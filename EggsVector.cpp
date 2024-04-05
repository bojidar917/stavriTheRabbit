#include "EggsVector.h"
#include <iostream>
#include <cstring>

EggsVector::EggsVector() : eggs(nullptr), capacity(0), count(0)
{
}

EggsVector::EggsVector(const EggsVector &other)
{
    copy(other);
}

EggsVector &EggsVector::operator=(const EggsVector &other)
{
    if(this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}

EggsVector::~EggsVector()
{
    clear();
}

void EggsVector::addEgg(const Egg &egg)
{
    if(checkName(egg.getName()))
    {
        resize();
        this->eggs[this->count] = egg;
        this->count++;
    }
}

void EggsVector::removeEgg(const char *name)
{
    // this->count -= 1;
    // this->capacity = this->count * 2;
    // Egg* temp = new Egg[this->capacity];
    // int tempCounter = 0;
    // for (int i = 0; i < this->count+1; i++)
    // {
    //     if(!this->eggs[i].isName(name))
    //         temp[tempCounter] = this->eggs[i];
    //         tempCounter++;
    // }
    // delete[] this->eggs;
    // this->eggs = temp;

    int index = -1;
    for (int i = 0; i < this->count; i++)
    {
        if (this->eggs[i].isName(name))
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        for (int i = index; i < this->count - 1; i++)
        {
            this->eggs[i] = this->eggs[i + 1];
        }
        this->count -= 1;
        this->capacity = this->count * 2;
        Egg *temp = new Egg[this->capacity];
        for (int i = 0; i < this->count; i++)
        {
            temp[i] = this->eggs[i];
        }
        delete[] this->eggs;
        this->eggs = temp;
    }
}

void EggsVector::serialize(std::ostream &out) const
{
    if(!out)
    {
        std::cout << "Somethong went wrong!" << std::endl;
    }
    else
    {
        out.write(reinterpret_cast<const char*>(&this->count), sizeof(this->count)); //wrtie the count of all eggs in the vector
        
        for (int i = 0; i < this->count; i++)
        {
            this->eggs[i].saveToFile(out);
        }  
    }
}

void EggsVector::deserialize(std::istream &in)
{
    if (!in)
    {
        std::cout << "Error reading from file" << std::endl;
        return;
    }

    in.read(reinterpret_cast<char*>(&this->count), sizeof(this->count));
    this->capacity = this->count * 2;

    delete[] this->eggs;
    this->eggs = new Egg[this->capacity];

    for (int i = 0; i < this->count; i++)
    {
        Egg egg;
        egg.readfromFile(in);
        this->eggs[i] = egg;
    }
}

void EggsVector::print() const
{
    for (int i = 0; i < this->count; i++)
    {
        std::cout <<this->count << " " << this->capacity << " " ;
        this->eggs[i].print();
    }
    
}

void EggsVector::resize()
{
    int newCapacity = (this->count + 1) * 2;
    Egg* tempEggs = new Egg[newCapacity];
    for (int i = 0; i < this->count; i++)
    {
        tempEggs[i] = this->eggs[i];
        // tempEggs[i] = Egg(this->eggs[i]);
    }
    delete[] this->eggs;
    this->eggs = tempEggs;
    this->capacity = newCapacity;
}

void EggsVector::clear()
{
    delete[] eggs;
}

void EggsVector::copy(const EggsVector &other)
{
    this->count = other.count;
    this->capacity = other.capacity;
    eggs = new Egg[capacity];
    for (int i = 0; i < this->count; i++)
    {
        this->eggs[i] = other.eggs[i];
    }
    // never do eggs = other !!!
}

bool EggsVector::checkName(const char* name)
{
    for (int i = 0; i < this->count; i++)
    {
        if(this->eggs[i].isName(name))
        {
            // std::throw ("Could not add egg with existing name");
            std::cout << "Could not add egg with existing name" << std::endl;
            return false;
        }  
    }
    return true;
}

void EggsVector::append()
{
    
}
