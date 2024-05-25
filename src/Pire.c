#include "Pire.h"

Pire PireOlustur(int value, char character){
	Pire pire = (Pire)malloc(sizeof(struct PIRE));
	if (!pire){
		fprintf(stderr, "Bellek ayrilamadi\n");
		exit(EXIT_FAILURE);
	}
	pire->super = BocekOlustur(value, character);
	pire->super->super->deger = &PireDeger;
	pire->super->super->gorunum = &PireGorunum;
	pire->super->super->savas = &PireSavas;
	pire->super->super->goruntule = &PireGoruntule;
	pire->super->super->yasiyorMu = &PireYasiyorMu;
	pire->super->super->canliyiGetir = &PireCanliyiGetir;
	pire->yoket = &PireYoket;
	return pire;
}

int PireDeger(const Canli canli){
	return canli->value;
}

char PireGorunum(const Canli canli){
	if (canli->yasiyorMu(canli))
		return canli->character;
	return 'X';
}

bool PireSavas(Canli pire, Canli canli){
	pire->is_alive = false;
	return (false);
}

void PireGoruntule(const Canli canli){
	printf("%c ", canli->gorunum(canli));
}

bool PireYasiyorMu(const Canli canli){
	return canli->is_alive;
}

Canli PireCanliyiGetir(const Pire pire){
	Canli canli = pire->super->super;
	free(pire->super);
	free(pire);
	return canli;
}

void PireYoket(const Pire pire){
	if (pire == NULL)
		return ;
	pire->super->yoket(pire->super);
	free(pire);
}