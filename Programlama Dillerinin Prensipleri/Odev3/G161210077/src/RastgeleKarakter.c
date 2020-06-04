#include "RastgeleKarakter.h"

RastgeleKarakter RastgeleKarOlustur() {

	RastgeleKarakter this = (RastgeleKarakter)malloc(sizeof(struct RASTGELEKARAKTER));
	this->rastgeleHarf = &rastgeleHarf;
	this->miktarliRastgeleHarf = &miktarliRastgeleHarf;
	this->ikiHarfArasi = &ikiHarfArasi;
	this->belirtilenHarfler = &belirtilenHarfler;
	this->cumle = &cumle;
	return this;
}

char rastgeleHarf(RastgeleKarakter this)
{
	Zaman zaman = zamanOlustur();

	int tekCift = zaman->rastgeleSayi(zaman);//random degerin tek veya cift olma durumuna göre büyük yada küçük yazdýrýlýyor.
	
	if (tekCift % 2 == 1)
	{
		int sayi = zaman->rastgeleSayi(zaman);
		sayi = sayi + 97;
		char karakter = (char)sayi;
		zamanYoket(zaman);
		return karakter;
	}
	else
	{
		int sayi = zaman->rastgeleSayi(zaman);
		sayi = sayi + 65;
		char karakter = (char)sayi;
		zamanYoket(zaman);
		return karakter;
	}

}

//char rastgeleHarf son.

void miktarliRastgeleHarf(RastgeleKarakter this, int adet)
{
	printf("Rastgele %d Karakter:",adet);
	for (int i = 0; i < adet; i++)
	{
		printf("%c", this->rastgeleHarf(this));
	}
	printf("\n");
}//void MiktarlýRastgeleHarf son.

void ikiHarfArasi(RastgeleKarakter this, char harf1, char harf2, int adet)
{
	printf("Verilen iki karakter(%c,%c):", harf1, harf2);
	
	int deger1 = (int)harf1;//harf1 ve harf2 ASCII karþýlýðýnýn bulunmasý için integer a çevriliyor
	int deger2 = (int)harf2;

	for (int i = 0; i < adet; i++)
	{
		while (1)//ara harf bulunana kadar döngü devam etmesi için.
		{	
			if (deger1 > 96 && deger1 < 123 && deger2>96 && deger2 < 123)//ASCII'ye göre küçük harflerler arasýný bulma
			{
				char harf = this->rastgeleHarf(this);
				
				if (deger1 < (int)harf && (int)harf < deger2)
				{
					printf("%c", harf);
					break;//ara harf bulununca while döngüsünden çýkýlýyor
				}
			}
			
			else if (deger1 > 64 && deger1 < 91 && deger2>64 && deger2 < 91)//ASCII'ye göre büyük harfler arasýný bulma
			{
				char harf = this->rastgeleHarf(this);

				if (deger1 < (int)harf && (int)harf < deger2)
				{
					printf("%c", harf);
					break;//ara harf bulununca while döngüsünden çýkýlýyor
				}

			}
		}
	}
	printf("\n");
}//void ikiHarfArasi son.

void belirtilenHarfler(RastgeleKarakter this, char harf1, char harf2, char harf3, char harf4, char harf5, char harf6, int adet)
{
	printf("Belirtilen Karakterler(%c,%c,%c,%c,%c,%c):", harf1, harf2, harf3, harf4, harf5, harf6);
	int deger1 = (int)harf1;
	int deger2 = (int)harf2;
	int deger3 = (int)harf3;
	int deger4 = (int)harf4;
	int deger5 = (int)harf5;
	int deger6 = (int)harf6;

	for (int i = 0; i < adet; i++)
	{
		while (1)
		{
			char harf = this->rastgeleHarf(this);

			if ((int)harf == deger1 || (int)harf == deger2 || (int)harf == deger3 ||
				(int)harf == deger4 || (int)harf == deger5 || (int)harf == deger6)
			{
				printf("%c", harf);
				break;
			}

		}
	}
	printf("\n");
}//void belirtilenHarfler son.

void cumle(RastgeleKarakter this)
{
	printf("Rastgele Cumle:");
	
	Zaman zaman = zamanOlustur();

	int kelimeSayisi = (zaman->rastgeleSayi(zaman) % 7) + 1;//Cumledeki kelime sayisi belirleniyor en fazla 7 kelimeden oluþacaðý düþünüldü.

	for (int i = 0; i < kelimeSayisi; i++)
	{
		int kelimeHarfSayisi = (zaman->rastgeleSayi(zaman) % 9) + 1;//bir kelimede en fazla 9 harf olacaðý düþünüldü.

		if (i == 0)//Cumlede ilk kelimenin ilk harfi buyuk olmalýdýr bu yüzden o ayrýca çýkarýlýyor.
		{
			char ilkHarf = (char)(zaman->rastgeleSayi(zaman) % 26 + 65);//Rastgele sayý fonksiyonundan gelen sayý ASCII karþýlýðýna göre büyük harfe çeviriliyor
			printf("%c",ilkHarf);

			if (kelimeSayisi == 0 && kelimeHarfSayisi == 0)
			{
				printf("!.");
				break;
			}
		}

		for (int j = 0; j < kelimeHarfSayisi; j++)
		{
			if (i == 0 && 1 < kelimeHarfSayisi)
			{
				j++;
			}
			char ilkHarf = (char)(zaman->rastgeleSayi(zaman) % 26 + 97);//Rastgele sayý fonksiyonundan gelen sayý ASCII karþýlýðýna göre küçük harfe çeviriliyor
			printf("%c",ilkHarf);
		}

		if (i + 1 == kelimeSayisi)//Son kelimenin sonuna boþluk býrakýlmadan nokta konulmasý için.
		{
			break;
		}
		printf(" ");

	}
	printf(".\n");
	free(zaman);
}//void cumle son.

RastgeleKarYoket(RastgeleKarakter this) {
	free(this);
}