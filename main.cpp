#include <iostream>
#include <fstream>

#include "Egg.h"
#include "EggsVector.h"
#include "Basket.h"

int main()
{
    Egg egg1("Unufri", 5);
    Egg egg2("Gosho", 59);
    Egg egg3("Nafarforii", 1);
    Egg egg4("Ivan", 500);
    Egg egg5("Tosho", 500);
    Egg egg6("Denko", 500);

    EggsVector neweggv;
    neweggv.addEgg(egg1);
    neweggv.addEgg(egg2);
    neweggv.addEgg(egg3);
    neweggv.addEgg(egg4);
    // neweggv.addEgg(egg4);
    neweggv.removeEgg("Ivan");
    neweggv.removeEgg("Denko");

    neweggv.addEgg(egg5);
    neweggv.addEgg(egg6);

    // Egg egg5 = egg4;
    // egg5.print();

    // neweggv.print();

    //test to save egg to bin file ☑️
    // std::ofstream file("egg1.bin", std::ios::binary);
    // if (!file) {
    //     std::cout << "Something went wrong writing the file...";
    // } 
    // else 
    // {
    //     std::cout << "saving..." << std::endl;
    //     egg1.saveToFile(file);
    // }
    // file.close();

    // Egg newestEgg;
    // std::ifstream filen("egg1.bin", std::ios::binary);
    // if(!filen) std::cout << "Something is wrong here" << std::endl;
    // else
    // {
    //     std::cout << "reading..." << std::endl;
    //     newestEgg.readfromFile(filen);
    // }
    // filen.close();
    // newestEgg.print();

    //test to save EggVector ☑️
    // std::ofstream file("eggVector.bin", std::ios::binary);
    // if (!file) {
    //     std::cout << "Something went wrong writing the file...";
    // } 
    // else 
    // {
    //     std::cout << "saving..." << std::endl;
    //     neweggv.serialize(file);
    //     std::cout << "done saving..." << std::endl;
    // }
    // file.close();

    // EggsVector readEggsVector;
    // std::ifstream filen("eggVector.bin", std::ios::binary);
    // if(!filen) std::cout << "Something is wrong here" << std::endl;
    // else
    // {
    //     std::cout << "reading..." << std::endl;
    //     readEggsVector.deserialize(filen);
    // }
    // filen.close();
    // readEggsVector.print();

    //test to create, save and read Basket
    Basket testBasket("testBasket1", neweggv, 5);

    std::ofstream file("testBasket1.bin", std::ios::binary);
    if (!file) {
        std::cout << "Something went wrong writing the file...";
    } 
    else 
    {
        std::cout << "saving basket..." << std::endl;
        testBasket.serialize(file);
        std::cout << "done saving basket..." << std::endl;
    }
    file.close();

    Basket readTestBasket;
    std::ifstream filen("testBasket1.bin", std::ios::binary);
    if(!filen) std::cout << "Something is wrong here" << std::endl;
    else
    {
        std::cout << "reading basket..." << std::endl;
        readTestBasket.deserialize(filen);
    }
    filen.close();

    std::cout << "printing basket..." << std::endl;
    readTestBasket.print();

}