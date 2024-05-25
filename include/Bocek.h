#ifndef BOCEK_H
# define BOCEK_H
#include "Canli.h"
struct BOCEK{
	Canli super;

	void (*yoket)(struct BOCEK*);
};
typedef struct BOCEK *Bocek;

Bocek	BocekOlustur(int value, char character);
int		BocekDeger(const Canli);
char	BocekGorunum(const Canli);
bool	BocekSavas(const Canli, const Canli);
void	BocekGoruntule(const Canli);
bool	BocekYasiyorMu(const Canli);
Canli	BocekCanliyiGetir(const Bocek);
void	BocekYoket(const Bocek);

#endif