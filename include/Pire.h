#ifndef PIRE_H
# define PIRE_H
#include "Bocek.h"
struct PIRE{
	Bocek super;

	void (*yoket)(struct PIRE*);
};
typedef struct PIRE *Pire;

Pire	PireOlustur(int value, char character);
int 	PireDeger(const Canli);
char 	PireGorunum(const Canli);
bool 	PireSavas(const Canli, const Canli);
void 	PireGoruntule(const Canli);
bool 	PireYasiyorMu(const Canli);
Canli 	PireCanliyiGetir(const Pire);
void	PireYoket(const Pire);

#endif