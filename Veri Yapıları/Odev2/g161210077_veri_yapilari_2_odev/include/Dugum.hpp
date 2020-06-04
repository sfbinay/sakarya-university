
#ifndef DUGUM_HPP
#define DUGUM_HPP
#include <iostream>
using namespace std;

class Dugum
{
private:
	Dugum* ileri;
	Dugum* geri;
	string icerik;
	int yonlendirme;
public:
	Dugum(string);
	Dugum* ileriGetir();
	void ileriAta(Dugum*);
	Dugum* geriGetir();
	void geriAta(Dugum*);
	string icerikGetir();
	void icerikAta(string);
	int yonlendirmeGetir();
	void yonlendirmeAta(int);
};
#endif
