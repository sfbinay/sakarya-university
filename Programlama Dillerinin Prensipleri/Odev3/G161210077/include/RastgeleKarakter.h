#ifndef RASTGELEKARAKTER_H
#define RASTGELEKARAKTER_H

#include "Random.h"

struct RASTGELEKARAKTER {

	char(*rastgeleHarf)(struct RASTGELEKARAKTER *);
	void(*miktarliRastgeleHarf)(struct RASTGELEKARAKTER *, int);
	void(*ikiHarfArasi)(struct RASTGELEKARAKTER *, char, char, int);
	void(*belirtilenHarfler)(struct RASTGELEKARAKTER *, char, char, char, char, char, char, int);
	void(*cumle)(struct RASTGELEKARAKTER *);
};
typedef struct RASTGELEKARAKTER* RastgeleKarakter;

RastgeleKarakter RastgeleKarOlustur();
char rastgeleHarf(RastgeleKarakter);
void miktarliRastgeleHarf(RastgeleKarakter, int adet);
void ikiHarfArasi(RastgeleKarakter, char harf1, char harf2, int adet);
void belirtilenHarfler(RastgeleKarakter, char harf1, char harf2, char harf3, char harf4, char harf5, char harf6, int adet);
void cumle(RastgeleKarakter);
RastgeleKarYoket(RastgeleKarakter);

#endif
