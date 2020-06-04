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
#include"BST.h"

BSTDugum::BSTDugum(int yeniSayi)
{
	pSol = pSag = NULL;
	this->sayi = yeniSayi;
}

void BSTDugum::ekle(int yeniSayi)
{
	if (sayi > yeniSayi)
	{
		if (pSol)
			return pSol->ekle(yeniSayi);

		BSTDugum* pYeni = new BSTDugum(yeniSayi);
		pSol = pYeni;
	}
	else if (sayi < yeniSayi)
	{
		if (pSag)
			return pSag->ekle(yeniSayi);

		BSTDugum* pYeni = new BSTDugum(yeniSayi);
		pSag = pYeni;
	}
}

void BSTDugum::cikar(int cikacakSayi, BSTDugum * ebeveyn)
{
	if (sayi > cikacakSayi)
	{
		if (pSol)
			return pSol->cikar(cikacakSayi, this);
		else
			return;
	}
	else if (sayi < cikacakSayi)
	{
		if (pSag)
			return pSag->cikar(cikacakSayi, this);
		else
			return;
	}

	if (pSag == NULL && pSol == NULL)//hiç çocuk yoksa
	{
		if (ebeveyn->pSol == this)
			ebeveyn->pSol = NULL;
		else
			ebeveyn->pSag = NULL;
	}
	else if (pSag && pSol)//2 çocuk varsa
	{
		if (ebeveyn == NULL)//kök düğüm silinecek düğüm ise ebeveyn adresi dışarıdan NULL geliyor..
		{
			sayi = pSol->enBuyukGetir();
			return pSol->cikar(sayi, this);
		}
		else
		{
			sayi = pSol->enBuyukGetir();//solun en büyüğü getiriliyor.
			return pSol->cikar(sayi, this);
		}
	}
	else if (pSag)//sadece sağda çocuk varsa
	{
		if (ebeveyn == NULL)//kök düğüm silinecek düğüm ise ebeveyn adresi dışarıdan NULL geliyor..
		{
			sayi = pSag->sayi;
			return pSag->cikar(sayi, this);
		}
		else
		{
			if (ebeveyn->pSol == this)
				ebeveyn->pSol = pSag;
			else
				ebeveyn->pSag = pSag;
		}
	}
	else//sadece solda çocuk varsa	
	{
		if (ebeveyn == NULL)//kök düğüm silinecek düğüm ise ebeveyn adresi dışarıdan NULL geliyor..
		{
			sayi = pSol->sayi;
			return pSol->cikar(sayi,this);
		}
		else
		{
			if (ebeveyn->pSol == this)
				ebeveyn->pSol = pSol;
			else
				ebeveyn->pSag = pSol;
		}
	}
	delete this;
}

int BSTDugum::enBuyukGetir()//bulunduğu düğümden sürekli sağa giderek en büyük değeri getiriyor.
{
	if (pSag)
	{
		return pSag->enBuyukGetir();
	}
	return sayi;
}



