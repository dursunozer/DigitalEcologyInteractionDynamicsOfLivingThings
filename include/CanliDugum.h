#ifndef CANLIDUGUM_H
# define CANLIDUGUM_H

#include "Canli.h"
#include "Bocek.h"
#include "Bitki.h"
#include "Pire.h"
#include "Sinek.h"

struct CANLIDUGUM{
	Canli canli;
	bool newLine;
	struct CANLIDUGUM *sonraki;

	void (*goruntule)(const struct CANLIDUGUM*);
	void (*yoket)(struct CANLIDUGUM*);
};
typedef struct CANLIDUGUM *CanliDugum;

CanliDugum	CanliDugumOlustur(int, bool);
void		CanliDugumGoruntule(const CanliDugum);
void		CanliDugumYoket(CanliDugum);

#endif