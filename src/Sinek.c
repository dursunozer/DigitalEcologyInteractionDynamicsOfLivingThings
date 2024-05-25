#include "Sinek.h"

Sinek SinekOlustur(int value, char character){
	Sinek sinek;
	sinek = (Sinek)malloc(sizeof(struct SINEK));
	if (!sinek)
	{
		fprintf(stderr, "Bellek ayrilamadi\n");
		exit(EXIT_FAILURE);
	}
	sinek->super = BocekOlustur(value, character);
	sinek->super->super->deger = &SinekDeger;
	sinek->super->super->gorunum = &SinekGorunum;
	sinek->super->super->savas = &SinekSavas;
	sinek->super->super->goruntule = &SinekGoruntule;
	sinek->super->super->yasiyorMu = &SinekYasiyorMu;
	sinek->super->super->canliyiGetir = &SinekCanliyiGetir;
	sinek->yoket = &SinekYoket;
	return sinek;
}

int SinekDeger(const Canli canli){
	return canli->value;
}

char SinekGorunum(const Canli canli){
	if (canli->yasiyorMu(canli))
		return canli->character;
	return 'X';
}

bool SinekSavas(Canli sinek, Canli canli){
	if (canli->value >= 51 && canli->value <= 99)
		return (canli->is_alive = false, true);
	else if (canli->value >= 10 && canli->value <= 20)
		return (canli->is_alive = false, true);
	else if (canli->value >= 1 && canli->value <= 9)
		return (sinek->is_alive = false, false);
	else if (sinek->value < canli->value)
		return (sinek->is_alive = false, false);
	else if (sinek->value >= canli->value)
		return (canli->is_alive = false, true);
	else{
		fprintf(stderr, "SinekSavas > Hatali deger girdisi\n");
		exit(EXIT_FAILURE);
	}
}

void SinekGoruntule(const Canli canli){
	printf("%c ", canli->gorunum(canli));
}

bool SinekYasiyorMu(const Canli canli){
	return canli->is_alive;
}

Canli SinekCanliyiGetir(const Sinek sinek){
	Canli canli = sinek->super->super;
	free(sinek->super);
	free(sinek);
	return canli;
}

void SinekYoket(const Sinek sinek){
	if (sinek == NULL)
		return ;
	sinek->super->yoket(sinek->super);
	free(sinek);
}