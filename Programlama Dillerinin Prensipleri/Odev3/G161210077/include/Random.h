#ifndef RANDOM_H
#define RANDOM_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ZAMAN {
	unsigned zamanTutucu;
	unsigned millitm;
	unsigned ftime;
	int(*rastgeleSayi)(struct ZAMAN *);
};

typedef struct ZAMAN* Zaman;
int rastgeleSayi(Zaman);
Zaman zamanOlustur();
void zamanYoket(Zaman);

#endif
