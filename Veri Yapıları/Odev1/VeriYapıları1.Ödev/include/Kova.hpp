#pragma once
#include"Top.hpp"
class Kova
{
public:
	Top *top;

	void kovaOlustur(int,int);
	void kovadaTopOlustur();
	void kovadaTopSil();
	int kovaRengiDondur();
	int kovaAdresiDondur();

private:
	int kovaRengi; //Kova rengi integer olarak temsil ediliyor. windows.h kullanılarak renk yansıtılıyor.
	int kovaAdresi;
};

