#ifndef HABITAT_H
# define HABITAT_H
#include "CanliBagliListe.h"

struct HABITAT{
	CanliBagliListe canliListesi;
	
	void (*goruntule)(const struct HABITAT*);
	void (*dosyadanEkle)(struct HABITAT*, const char*);
	void (*katliam)(struct HABITAT*);
	void (*yoket)(struct HABITAT*);
};
typedef struct HABITAT *Habitat;

Habitat	HabitatOlustur();
void	HabitatDosyadanEkle(Habitat this, const char*);
void	HabitatGoruntule(const Habitat);
void	HabitatKatliam(Habitat);
void	HabitatYoket(const Habitat);

#endif