/**
*@file             /Kova.cpp
*@description      /Kova sınıfı nesneleri için top olusturuluyor, rastgele harf üretiliyor, adresler tutuluyor ve metotlar ile private değerler döndürülüyor.
*@course           /2.öğretim C grubu
*@assignment       /1
*@date             /30.10.2019
*@author           /Süleyman Furkan BİNAY -> suleyman.binay@ogr.sakarya.edu.tr | Yasin OK -> yasin1.ok1@ogr.sakarya.edu.tr
*/
#include"Kova.hpp"
#include<iostream>
#include<ctime>

void Kova::kovaOlustur(int adres,int renkParametresi)
{
	srand(time(0));
	for (int i = 0; i < renkParametresi+1; i++) //rastgele kovaRengi değeri üreten döngü
	{
		kovaRengi = kovaRengi + rand();
	}
	
	kovaRengi = (kovaRengi%14)+1; //Rastgele elde edilen değeri windows.h kütüphanesi kullanarak renk parametresi olarak kullanmak için uygun aralığa indirgeniyor.
	kovaAdresi = adres; //Adres integer olarak saklanıyor. Yazdırılırken hexadecimale çevriliyor.
}

int Kova::kovaAdresiDondur()
{
	return kovaAdresi;
}

int Kova::kovaRengiDondur()
{
	return kovaRengi;
}

void Kova::kovadaTopOlustur()
{
	top = new Top();
}
void Kova::kovadaTopSil()
{
	Top *yedek = new Top();

	yedek = top;
	top = NULL;
	top = nullptr;

	delete top;
	delete yedek;
}

