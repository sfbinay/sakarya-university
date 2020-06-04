/**************************************************************************** 
 **							SAKARYA UNIVERSITY 
 **					  BILGISAYAR MUHENDISLIGI BOLUMU 
 **					  	VERI YAPILARI DERSI 2.ODEV
 **     
 **				OGRENCI ISMI.....: Süleyman Furkan BİNAY , Yasin OK
 **				OGRENCI NUMARASI.: G161210077 , B181210506
 **             OGRENCI GRUBU....:  2 - C
 **             MAIL ADRESLERI...: suleyman.binay@ogr.sakarya.edu.tr , yasin.ok1@ogr.sakarya.edu.tr
 ****************************************************************************/
#include<iostream>
#include<cstdlib>
#include<fstream>
#include"BST.h"
using namespace std;

int soySayisiHesapla(BSTDugum *dugum)//rekürsif şekilde işaret edilen düğümle beraber altındaki düğümleri sayısnı buluyor.
{
	if (dugum == NULL)
	{
		return 0;
	}
	else
	{
		return soySayisiHesapla(dugum->pSag) + 1 + soySayisiHesapla(dugum->pSol);
	}
}

void postorderSirala(BSTDugum *dugum)
{
	if (dugum == NULL)
		return;

	postorderSirala(dugum->pSol);
	postorderSirala(dugum->pSag);

	cout <<"<"<<dugum->sayi <<","<<dugum->soy_sayisi<<">" <<" ";
}

void soySayilariniAta(BSTDugum *dugum)//tüm ağacın soy_sayısı'nı atıyor.
{
	if (dugum == NULL)
		return;

	dugum->soy_sayisi = soySayisiHesapla(dugum)-1;
	soySayilariniAta(dugum->pSag);
	soySayilariniAta(dugum->pSol);
}

int toplamSoySayisi(BSTDugum *dugum)
{
	int toplam;
	
	if (dugum == NULL)
		return 0;

	toplam = dugum->soy_sayisi + toplamSoySayisi(dugum->pSag) + toplamSoySayisi(dugum->pSol);

	return toplam;
}


int main()
{
	int sayi;//baslangicta dosyadan okunan sayilari tutan değişken.

	ifstream benimtxt("benim.txt");
	if (!benimtxt.is_open())//benim.txt bulunamaz ise program sonlaniyor.
	{
		cout << "benim.txt dosyasi bulunamadi..." << endl;
		system("pause");
		exit(0);
	}

	benimtxt >> sayi;
	BSTDugum* benimAgac = new BSTDugum(sayi);

	while (benimtxt >> sayi)
	{
		benimAgac->ekle(sayi);
	}
	benimtxt.close();
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	ifstream rakiptxt("rakip.txt");
	if (!rakiptxt.is_open())//rakip.txt bulunamaz ise program sonlaniyor.
	{
		cout << "rakip.txt dosyasi bulunamadi..." << endl;
		system("pause");
		exit(0);
	}

	rakiptxt >> sayi;
	BSTDugum* rakipAgac = new BSTDugum(sayi);

	while (rakiptxt >> sayi)
	{
		rakipAgac->ekle(sayi);
	}
	rakiptxt.close();
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	int benim = 0, rakip = 0, turKontrol = 0;//skorlari tutmak için ve 5 tur koşulunu kontrol etmek için..

	for (int i = 0; i < 20; i++)//20 turun sonu koşulu için en fazla 20 dönen bir for dönügüsü
	{
		soySayilariniAta(benimAgac);
		soySayilariniAta(rakipAgac);

		cout << "Benim Agac Postorder :" << endl;
		postorderSirala(benimAgac);
		cout << endl << "Benim Agac Toplam Soy Sayisi : " << toplamSoySayisi(benimAgac);
		cout << endl << "---------------------------------" << endl << endl;
		cout << "Rakip Agac Postorder :" << endl;
		postorderSirala(rakipAgac);
		cout << endl << "Rakip Agac Toplam Soy Sayisi : " << toplamSoySayisi(rakipAgac) << endl;
		
		if (toplamSoySayisi(benimAgac) < toplamSoySayisi(rakipAgac))//benim agacın turu kazanma durumu
		{
			benim++;
			benimAgac->ekle(rakipAgac->enBuyukGetir());
			rakipAgac->cikar(rakipAgac->enBuyukGetir(),NULL);
			rakipAgac->ekle(benimAgac->sayi);
			benimAgac->cikar(benimAgac->sayi,NULL);

			cout << endl << endl << "-- TEBRIKLER TURU KAZANDINIZ --" << endl << endl;
			cout << "SKOR" << endl << "Benim : " << benim << endl << "Rakip : " << rakip << endl;
			if (benim == 5)
				break;
		}
		
		else if (toplamSoySayisi(benimAgac) > toplamSoySayisi(rakipAgac))//rakip agacın turu kazanma durumu
		{
			rakip++;
			rakipAgac->ekle(benimAgac->enBuyukGetir());
			benimAgac->cikar(benimAgac->enBuyukGetir(),NULL);
			benimAgac->ekle(rakipAgac->sayi);
			rakipAgac->cikar(rakipAgac->sayi, NULL);

			cout << endl << endl << "-- MALESEF TURU KAYBETTINIZ --" << endl << endl;
			cout << "SKOR" << endl << "Benim : " << benim << endl << "Rakip : " << rakip << endl;
			if (rakip == 5)
				break;
		}
		
		else//beraberlik durumu
		{
			int benimKok, rakipKok;
			benimKok = benimAgac->sayi;
			rakipKok = rakipAgac->sayi;
			
			benimAgac->cikar(benimKok, NULL);
			rakipAgac->cikar(rakipKok, NULL);
			benimAgac->ekle(rakipKok);
			rakipAgac->ekle(benimKok);
			
			cout << endl << endl << "-- BERABERE --" << endl << endl;
			cout << "SKOR" << endl << "Benim : " << benim << endl << "Rakip : " << rakip << endl;
		}

		cout << endl;
		system("pause");
		cout << endl;
	}
	delete benimAgac;
	delete rakipAgac;

	system("pause");

	return 0;
}