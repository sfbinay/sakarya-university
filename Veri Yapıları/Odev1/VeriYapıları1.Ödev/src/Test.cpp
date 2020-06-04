/**
*@file             /Test.cpp
*@description      /Menü yazdırılıyor ve menünün kontrolü sağlanıyor. Ayrıca kova sayisi burada aliniyor.
                   /Alinan kova sayiyisi KovaKontrol sinifinin kurucu fonksiyonu ile private elemanı olan kovaSayisi'na ataniyor.				 
*@course           /2.öğretim C grubu
*@assignment       /1
*@date             /30.10.2019
*@author           /Süleyman Furkan BİNAY -> suleyman.binay@ogr.sakarya.edu.tr | Yasin OK ->yasin.ok1@ogr.sakarya.edu.tr
*/
#include<iostream>
#include"KovaKontrol.hpp"
using namespace std;

void menu()
{
	cout << "[1]Toplari Yerlestir" << endl << "[2]Toplari Yoket" << endl << "[3]Kova Degistir" << endl << "[4]Top Degistir"
		<< endl << "[5]Kovalari Tersten Yerlestir" << endl << "[6]Toplari Tersten Yerlestir" << endl << "[7]Cikis"
		<< endl << ">>";
}

int main()
{
	int kovaSayisi, menuSecenek;	
	cout << "Kova Sayisi:"; cin >> kovaSayisi;

	KovaKontrol kontrol(kovaSayisi);
	kontrol.kovalariOlustur();

	while (true)
	{
		kontrol.kovalariEkranaBas();
		menu();
		cin >> menuSecenek;
		////////////////////////////////////////////////// kovalari yerlestir
		if (menuSecenek == 1) kontrol.toplariYerlestir(); 
		////////////////////////////////////////////////// kovalari yoket
		else if (menuSecenek == 2) kontrol.toplariYokEt();
		//////////////////////////////////////////////////	kova degistir
		else if (menuSecenek == 3)
		{
			int kova1, kova2;
			cout << "Hangi Kova:";      cin >> kova1;
			cout << "Hangi Kova ile :"; cin >> kova2;
			kontrol.kovaDegistir(kova1, kova2);
		}
		////////////////////////////////////////////////// top degistir
		else if (menuSecenek == 4)
		{
			int top1, top2;
			cout << "Hangi Top:";      cin >> top1;
			cout << "Hangi Top ile :"; cin >> top2;
			kontrol.topDegistir(top1, top2);
		}
		////////////////////////////////////////////////////////////// kovalari tersten yerlestir
		else if (menuSecenek == 5) kontrol.kovalariTerstenYerlestir();
		////////////////////////////////////////////////////////////// toplari tersten yerlestir
		else if (menuSecenek == 6) kontrol.toplariTerstenYerlestir();
		//////////////////////////////////////////////////////////////
		else if (menuSecenek == 7) break;
		/////////////////////////////////
		else
		{
			cout << endl << " Hatali Secenek..." << endl << endl;
		}
	}
	kontrol.copleriSil();
	return 0;
}

