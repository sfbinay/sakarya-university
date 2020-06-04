
#ifndef LISTE_HPP
#define LISTE_HPP
#include <iostream>
#include <string>
#include <fstream>
#include "Dugum.hpp"

using namespace std;
class Liste
{
 private:
    int boyut;
    Dugum* ilkEleman;
    string tumVeri;
 public:
    Liste();
    Dugum* getir(int);
    void yazdir();
    int kacByteKazanc();
};
#endif
