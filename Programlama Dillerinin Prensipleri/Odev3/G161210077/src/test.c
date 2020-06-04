#include "RastgeleKarakter.h"

int main()
{
	RastgeleKarakter random = RastgeleKarOlustur();
	//Rastgele Karakter:
	printf("Rastgele Karakter:%c\n", random->rastgeleHarf(random));
	printf("Rastgele Karakter:%c\n", random->rastgeleHarf(random));

	printf("\n");
	
	//Rastgele x Karakter: (parametre olarak girilen x deðeri kadar harf çýkarýr)
	random->miktarliRastgeleHarf(random, 5);
	random->miktarliRastgeleHarf(random, 3);

	printf("\n");

	//Verilen iki karakter(a,k,adet): (parametre olarak girilen iki harf arasýndan rastgele adet kadar harf çýkarýr)
	random->ikiHarfArasi(random, 'a', 'k', 1);        //Büyük-küçük harfler kendi aralarýnda ayrý ayrý düþünüldü.
	random->ikiHarfArasi(random, 'A', 'K', 2);

	printf("\n");

	//Belirtilen Karakterler(x,y,z,k,l,m,adet):
	random->belirtilenHarfler(random, 'g', 'y', 'u', 'c', 'n', 'e', 1);
	random->belirtilenHarfler(random, 'g', 'y', 'u', 'c', 'n', 'e', 1);
	random->belirtilenHarfler(random, 'g', 'y', 'u', 'c', 'n', 'e', 2);

	printf("\n");
	
	//Rastgele Cumle
	random->cumle(random);

	printf("\n");
	free(random);
	system("pause");
}