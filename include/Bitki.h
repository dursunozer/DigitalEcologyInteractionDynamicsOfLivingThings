#ifndef BITKI_H
# define BITKI_H
#include "Canli.h"
struct BITKI{
	Canli super;

	void (*yoket)(struct BITKI*);
};
typedef struct BITKI *Bitki;

Bitki	BitkiOlustur(int value, char character);
int		BitkiDeger(const Canli);
char	BitkiGorunum(const Canli);
bool	BitkiSavas(const Canli, const Canli);
void	BitkiGoruntule(const Canli);
bool	BitkiYasiyorMu(const Canli);
Canli	BitkiCanliyiGetir(const Bitki);
void	BitkiYoket(const Bitki);

#endif