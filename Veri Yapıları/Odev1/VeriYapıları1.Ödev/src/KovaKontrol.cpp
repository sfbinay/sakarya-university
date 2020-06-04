/**
*@file             /KovaKontrol.cpp
*@description      /Ödevde verilen menü işlemleri fonksiyonlar ile yapılıyor. Ayrıca kovalarin ici dolu mu bos mu bunun kontrolü yapılıyor.
                   /Olusan copler siliniyor. Kova sekilleri ve adresleri ekrana yazdiriliyor, renk için windows.h kullanıldı.
*@course           /2.öğretim C grubu
*@assignment       /1
*@date             /31.10.2019
*@author           /Süleyman Furkan BİNAY -> suleyman.binay@ogr.sakarya.edu.tr | Yasin OK ->yasin1.ok@ogr.sakarya.edu.tr
*/
#include<iostream>
#include"windows.h"
#include"KovaKontrol.hpp"

using namespace std;

KovaKontrol::KovaKontrol(int parametreKovaSayisi)
{
	kovaSayisi = parametreKovaSayisi;
}

void KovaKontrol::kovalariOlustur()
{
	kovaDizisi = new Kova[kovaSayisi]; //Girilen kova sayisi kadar heap de kova dizisi oluşturuldu.
	Kova *nesne;
	
	for (int i = 0; i < kovaSayisi; i++)
	{
		nesne = new Kova();
		kovaDizisi[i] = *nesne;
		kovaDizisi[i].kovaOlustur(int(&kovaDizisi[i]),i);
	}
}

void KovaKontrol::kovalariEkranaBas()
{
	for (int i = 0; i < kovaSayisi; i++)
	{
		cout << i + 1 << ".ci Kova" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kovaDizisi[i].kovaRengiDondur() + 1);
		cout << "  .|." << endl << " .   ." << endl << ".     ." << endl << "#     #" << endl
			<< "#  " << topHarfiCagir(i) << "  #" << endl << "#     #" << endl << "#######" << endl;
		cout << "Kova Adresi:0x" << hex << kovaDizisi[i].kovaAdresiDondur() << dec << endl;
		cout << "Topun Adresi:"<<hex;
		topAdresiCagir(i);
		cout << dec << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << endl;
	}
}

bool KovaKontrol::kovadaTopVarMi()
{
	if (kovaDizisi[0].top == nullptr) //Kova da top yoksa FALSE dönüyor.
		return false;
	else
		return true; //Kova da top varsa TRUE dönüyor.
}

void KovaKontrol::toplariYerlestir()
{
	if (kovadaTopVarMi() == false)
	{
		for (int i = 0; i < kovaSayisi; i++) //Kova nesnelerinde top nesneleri oluşturuluyor.
			kovaDizisi[i].kovadaTopOlustur();

		for (int i = 0; i < kovaSayisi; i++) //Oluşturulan top nesnelerine harf ve adres atamaları yapılıyor.
			kovaDizisi[i].top->topOlustur(int(kovaDizisi[i].top), i);
	}
	else
		cout << endl << "Kovada top var..." << endl;
}

void KovaKontrol::toplariYokEt()
{
	if (kovadaTopVarMi() == true)
	{
		for (int i = 0; i < kovaSayisi; i++)
		{
			kovaDizisi[i].kovadaTopSil();
		}
	}
	else
		cout << endl << "Kovada top yok..." << endl;
}

void KovaKontrol::topAdresiCagir(int parametre)
{
	if (kovadaTopVarMi() == true) //Kovada top varsa topun adresi döndürülüyor.
		cout << "0x" << kovaDizisi[parametre].top->topAdresiDondur();
	else
		cout << "NULL"; //Kovada top yoksa NULL yazdiriliyor.
}

char KovaKontrol::topHarfiCagir(int parametre)
{
	if (kovadaTopVarMi() == true) //Kovada top varsa topun harfi döndürülüyor.
		return kovaDizisi[parametre].top->harfDondur();
	else
		return '-';	//Kovada top yoksa bu işaret döndürülüyor.
}

void KovaKontrol::kovaDegistir(int kova1, int kova2)
{
	if (kova1 < kovaSayisi + 1 && kova1 > 0 &&
		kova2 < kovaSayisi + 1 && kova2 > 0)
	{
		kova1 = kova1 - 1;
		kova2 = kova2 - 1;
		Kova *geciciDizi = new Kova[kovaSayisi];

		for (int i = 0; i < kovaSayisi; i++)
		{
			if (i == kova1)
			{
				geciciDizi[0] = kovaDizisi[i];
			}
			if (i == kova2)
			{
				geciciDizi[1] = kovaDizisi[i];
			}
		}

		for (int i = 0; i < kovaSayisi; i++)
		{
			if (i == kova1)
			{
				kovaDizisi[i] = geciciDizi[1];
			}
			if (i == kova2)
			{
				kovaDizisi[i] = geciciDizi[0];
			}
		}

		delete[] geciciDizi;
	}
	else
		cout << endl << "Gecersiz degerler girildi, tekrar deneyin..." << endl;
}

void KovaKontrol::topDegistir(int top1,int top2)
{
	if (top1 < kovaSayisi + 1 && top1 > 0 &&
		top2 < kovaSayisi + 1 && top2 > 0 && kovadaTopVarMi() == true) //Kovada top var ve girilen değerler geçerliyse işlem yapılıyor.
	{
		top1 = top1 - 1;
		top2 = top2 - 1;
		Kova *geciciDizi = new Kova[kovaSayisi];

		for (int i = 0; i < kovaSayisi; i++)
		{
			if (i == top1)
			{
				geciciDizi[0].top = kovaDizisi[i].top;
			}
			if (i == top2)
			{
				geciciDizi[1].top = kovaDizisi[i].top;
			}
		}

		for (int i = 0; i < kovaSayisi; i++)
		{
			if (i == top1)
			{
				kovaDizisi[i].top = geciciDizi[1].top;
			}
			if (i == top2)
			{
				kovaDizisi[i].top = geciciDizi[0].top;
			}
		}

		delete geciciDizi;
	}
	else
		cout << endl << "Gecersiz degerler girildi, tekrar deneyin..." << endl;
}

void KovaKontrol::kovalariTerstenYerlestir()
{
	Kova *geciciDizi = new Kova[kovaSayisi];

	for (int i = 0; i < kovaSayisi; i++)
	{
		geciciDizi[i] = kovaDizisi[i];
	}

	int sayac = kovaSayisi;

	for (int i = 0; i < kovaSayisi; i++)
	{
		kovaDizisi[i] = geciciDizi[sayac - 1];
		sayac--;
	}

	delete[] geciciDizi;
}

void KovaKontrol::toplariTerstenYerlestir()
{
	if (kovadaTopVarMi() == true)
	{
		Kova *geciciDizi = new Kova[kovaSayisi];

		for (int i = 0; i < kovaSayisi; i++)
		{
			geciciDizi[i].top = kovaDizisi[i].top;
		}

		int sayac = kovaSayisi;

		for (int i = 0; i < kovaSayisi; i++)
		{
			kovaDizisi[i].top = geciciDizi[sayac - 1].top;
			sayac--;
		}
		delete[] geciciDizi;
	}
	else
		cout << endl << "Kovada top yok..." << endl;
}

void KovaKontrol::copleriSil()
{
	if (kovadaTopVarMi() == true) //Kovada top varsa önce toplar siliniyor daha sonra kovalar siliniyor.
	{
		for (int i = 0; i < kovaSayisi; i++)
		{
			kovaDizisi[i].kovadaTopSil();
		}
		delete[] kovaDizisi;
	}
	else // Kovada top yoksa kovalar siliniyor.
		delete[] kovaDizisi;
}