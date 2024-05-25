#include "Bitki.h"

Bitki BitkiOlustur(int value, char character)
{
	Bitki bitki;
	bitki = (Bitki)malloc(sizeof(struct BITKI));
	if (!bitki)
	{
		fprintf(stderr, "Bellek ayrilamadi\n");
		exit(EXIT_FAILURE);
	}
	bitki->super = CanliOlustur(value, character);
	bitki->super->deger = &BitkiDeger;
	bitki->super->gorunum = &BitkiGorunum;
	bitki->super->savas = &BitkiSavas;
	bitki->super->goruntule = &BitkiGoruntule;
	bitki->super->yasiyorMu = &BitkiYasiyorMu;
	bitki->super->canliyiGetir = &BitkiCanliyiGetir;
	bitki->yoket = &BitkiYoket;
	return bitki;
}

int BitkiDeger(const Canli canli)
{
	return canli->value;
}

char BitkiGorunum(const Canli canli)
{
	if (canli->yasiyorMu(canli))
		return canli->character;
	return 'X';
}

bool BitkiSavas(const Canli bitki, const Canli canli)
{
	if (canli->value >= 51 && canli->value <= 99)
		return (canli->is_alive = false, true);
	else if (canli->value >= 21 && canli->value <= 50)
		return (canli->is_alive = false, true);
	else if (canli->value >= 10 && canli->value <= 20)
		return (bitki->is_alive = false, false);
	else if (bitki->value < canli->value)
		return (bitki->is_alive = false, false);
	else if (bitki->value >= canli->value)
		return (canli->is_alive = false, true);
	else
	{
		fprintf(stderr, "BitkiSaldir > Hatali deger girisi\n");
		exit(EXIT_FAILURE);
	}
}

void BitkiGoruntule(const Canli canli)
{
	printf("%c ", canli->gorunum(canli));
}

bool BitkiYasiyorMu(const Canli canli)
{
	return canli->is_alive;
}

Canli BitkiCanliyiGetir(const Bitki bitki)
{
	Canli canli = bitki->super;
	free(bitki);
	return canli;
}

void BitkiYoket(const Bitki bitki)
{
	if (bitki == NULL)
		return ;
	bitki->super->yoket(bitki->super);
	free(bitki);
}