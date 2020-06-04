#include "RastgeleKarakter.h"

int main()
{
	RastgeleKarakter random = RastgeleKarOlustur();
	//Rastgele Karakter:
	printf("Rastgele Karakter:%c\n", random->rastgeleHarf(random));
	printf("Rastgele Karakter:%c\n", random->rastgeleHarf(random));

	printf("\n");
	
	//Rastgele x Karakter: (parametre olarak girilen x de�eri kadar harf ��kar�r)
	random->miktarliRastgeleHarf(random, 5);
	random->miktarliRastgeleHarf(random, 3);

	printf("\n");

	//Verilen iki karakter(a,k,adet): (parametre olarak girilen iki harf aras�ndan rastgele adet kadar harf ��kar�r)
	random->ikiHarfArasi(random, 'a', 'k', 1);        //B�y�k-k���k harfler kendi aralar�nda ayr� ayr� d���n�ld�.
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