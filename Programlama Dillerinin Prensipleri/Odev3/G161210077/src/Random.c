#include "Random.h"

int rastgeleSayi(Zaman this)
{
	for (int i = 0; i < 8000000; i++)//belirgin zaman farki olmasi icin sisteme bos is yaptiriliyor.
	{
		printf("");
	}

	ftime(this);
	int sayi;
	sayi = this->millitm % 26;
	return sayi;
}

Zaman zamanOlustur() {
	Zaman this;
	this = (Zaman)malloc(sizeof(struct ZAMAN));
	this->rastgeleSayi = &rastgeleSayi;
	return this;
}

void zamanYoket(Zaman this) {
	free(this);
}
