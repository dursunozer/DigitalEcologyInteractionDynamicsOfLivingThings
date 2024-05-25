#include "CanliDugum.h"

CanliDugum CanliDugumOlustur(int value, bool newLine)
{
	CanliDugum canliDugum = (CanliDugum)malloc(sizeof(struct CANLIDUGUM));
	if (!canliDugum)
	{
		fprintf(stderr, "Bellek ayrilamadi\n");
		exit(EXIT_FAILURE);
	}
	if (value >= 1 && value <= 9)
	{
		Bitki bitki = BitkiOlustur(value, 'B');
		canliDugum->canli = bitki->super->canliyiGetir(bitki);
	}
	else if (value >= 10 && value <= 20)
	{
		Bocek bocek = BocekOlustur(value, 'C');
		canliDugum->canli = bocek->super->canliyiGetir(bocek);
	}
	else if (value >= 21 && value <= 50)
	{
		Sinek sinek = SinekOlustur(value, 'S');
		canliDugum->canli = sinek->super->super->canliyiGetir(sinek);
	}
	else if (value >= 51 && value <= 99)
	{
		Pire pire = PireOlustur(value, 'P');
		canliDugum->canli = pire->super->super->canliyiGetir(pire);
	}
	else
	{
		fprintf(stderr, "Gecersiz deger\n");
		exit(EXIT_FAILURE);
	}
	canliDugum->newLine = newLine;
	canliDugum->sonraki = NULL;

	canliDugum->goruntule = &CanliDugumGoruntule;
	canliDugum->yoket = &CanliDugumYoket;
	return canliDugum;
}

void CanliDugumGoruntule(const CanliDugum canliDugum)
{
	canliDugum->canli->goruntule(canliDugum->canli);
	if (canliDugum->newLine)
		printf("\n");
}

void CanliDugumYoket(CanliDugum canliDugum)
{
	if (canliDugum == NULL)
		return;
	canliDugum->canli->yoket(canliDugum->canli);
	free(canliDugum);
}