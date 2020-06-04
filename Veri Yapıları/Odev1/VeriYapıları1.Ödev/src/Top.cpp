/**
*@file             /Top.cpp
*@description      /Top sınıfı nesneleri için rastgele harf üretiliyor, adresler tutuluyor ve metotlar ile private değerler döndürülüyor
*@course           /2.öğretim C grubu
*@assignment       /1
*@date             /30.10.2019
*@author           /Süleyman Furkan BİNAY -> suleyman.binay@ogr.sakarya.edu.tr | Yasin OK -> yasin1.ok@ogr.sakarya.edu.tr
*/
#include"Top.hpp"
#include<iostream>
#include<ctime>

void Top::topOlustur(int adres,int parametreDeger)
{
	int sayi=0;

	srand(time(0));
	for (int i = 0; i < parametreDeger + 1; i++) //rastgele kovaRengi değeri üreten döngü
	{
		sayi = sayi + rand();
	}
	harf = (sayi % 26) + 65; //Harflerin rastgele oluşması için rastgele alınan heap adresleri integera çevirilip ASCII karşılığı veriliyor.
	topAdresi = adres;//Adres integer olarak saklanıyor. Yazdırılırken hexadecimale çevriliyor.
}

char Top::harfDondur()
{
	return harf;
}

int Top::topAdresiDondur()
{
	return topAdresi;
}
