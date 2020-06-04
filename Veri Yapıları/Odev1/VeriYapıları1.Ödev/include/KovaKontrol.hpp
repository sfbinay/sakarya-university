#pragma once
#include"Kova.hpp"
class KovaKontrol
{
public:
	Kova *kovaDizisi;
	
	void kovalariOlustur();
	void kovalariEkranaBas();
	
	bool kovadaTopVarMi();
	
	char topHarfiCagir(int);
	void topAdresiCagir(int);
	
	void toplariYerlestir();         //1
	void toplariYokEt();             //2
	void kovaDegistir(int,int);      //3
	void topDegistir(int,int);       //4
	void kovalariTerstenYerlestir(); //5
	void toplariTerstenYerlestir();  //6

	void copleriSil();

	KovaKontrol(int); //Kova Sayisi Test programından alınıyor. KovaKontrol sınıfının private elamanı olan kovaSayisi'na ataniyor.

private:
	int kovaSayisi;
};
