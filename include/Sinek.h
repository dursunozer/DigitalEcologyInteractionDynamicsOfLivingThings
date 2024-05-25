#ifndef SINEK_H
# define SINEK_H

#include "Bocek.h"

struct SINEK{
	Bocek super;

	void (*yoket)(struct SINEK*);
};
typedef struct SINEK *Sinek;

Sinek	SinekOlustur(int value, char character);
int		SinekDeger(const Canli);
char	SinekGorunum(const Canli);
bool	SinekSavas(const Canli, const Canli);
void	SinekGoruntule(const Canli);
bool	SinekYasiyorMu(const Canli);
Canli	SinekCanliyiGetir(const Sinek);
void	SinekYoket(const Sinek);

#endif