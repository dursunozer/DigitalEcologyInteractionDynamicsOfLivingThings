#include "Bocek.h"

Bocek BocekOlustur(int value, char character)
{
	Bocek bocek;
	bocek = (Bocek)malloc(sizeof(struct BOCEK));
	if (!bocek)
	{
		fprintf(stderr, "Bellek ayrilamadi\n");
		exit(EXIT_FAILURE);
	}
	bocek->super = CanliOlustur(value, character);
	bocek->super->deger = &BocekDeger;
	bocek->super->gorunum = &BocekGorunum;
	bocek->super->savas = &BocekSavas;
	bocek->super->goruntule = &BocekGoruntule;
	bocek->super->yasiyorMu = &BocekYasiyorMu;
	bocek->super->canliyiGetir = &BocekCanliyiGetir;
	bocek->yoket = &BocekYoket;
	return bocek;
}

int BocekDeger(const Canli canli)
{
	return canli->value;
}

char BocekGorunum(const Canli canli)
{
	if (canli->yasiyorMu(canli))
		return canli->character;
	return 'X';
}

bool BocekSavas(Canli bocek, Canli canli)
{
	if (canli->value >= 1 && canli->value <= 9)
		return (canli->is_alive = false,  true);
	else if (canli->value >= 51 && canli->value <= 99)
		return (canli->is_alive = false, true);
	else if (canli->value >= 21 && canli->value <= 50)
		return (bocek->is_alive = false, false);
	else if (bocek->value < canli->value)
		return (bocek->is_alive = false, false);
	else if (bocek->value >= canli->value)
		return (canli->is_alive = false, true);
	else
	{
		fprintf(stderr, "BocekSavas > Hatali deger girdisi\n");
		exit(EXIT_FAILURE);
	}
}

void BocekGoruntule(const Canli canli)
{
	printf("%c ", canli->gorunum(canli));
}

bool BocekYasiyorMu(const Canli canli)
{
	return canli->is_alive;
}

Canli BocekCanliyiGetir(const Bocek bocek)
{
	Canli canli = bocek->super;
	free(bocek);
	return canli;
}

void BocekYoket(const Bocek bocek)
{
	if (bocek == NULL)
		return ;
	bocek->super->yoket(bocek->super);
	free(bocek);
}