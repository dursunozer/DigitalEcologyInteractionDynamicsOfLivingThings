#ifndef CANLIBAGLILISTE_H
# define CANLIBAGLILISTE_H

#include "CanliDugum.h"

struct CANLIBAGLILISTE{
	CanliDugum bas;
	CanliDugum son;
	CanliDugum ilkCanli;
	CanliDugum ikinciCanli;

	void (*elemanEkle)(struct CANLIBAGLILISTE*, CanliDugum);
	void (*goruntule)(struct CANLIBAGLILISTE*);
	void (*savasHazirla)(struct CANLIBAGLILISTE*);
	void (*savas)(struct CANLIBAGLILISTE*);
	void (*kazananGoruntule)(struct CANLIBAGLILISTE*);
	void (*yoket)(struct CANLIBAGLILISTE*);
};
typedef struct CANLIBAGLILISTE *CanliBagliListe;

CanliBagliListe	CanliBagliListeOlustur();
void			CanliBagliListeElemanEkle(CanliBagliListe, CanliDugum);
void			CanliBagliListeGoruntule(const CanliBagliListe);
void			CanliBagliListeSavasHazirla(CanliBagliListe);
void			CanliBagliListeSavas(CanliBagliListe);
void			CanliBagliListeKazananGoruntule(CanliBagliListe);
void			CanliBagliListeYoket(CanliBagliListe);

#endif