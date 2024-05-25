#include "Canli.h"

Canli CanliOlustur(int value, char character)
{
	Canli canli;
	canli = (Canli)malloc(sizeof(struct CANLI));
	if (!canli)
	{
		fprintf(stderr, "Bellek ayrilamadi\n");
		exit(EXIT_FAILURE);
	}
	canli->value = value;
	canli->character = character;	
	canli->is_alive = true;
	canli->yoket = &CanliYoket;
	return canli;
}

void CanliYoket(const Canli canli)
{
	if (canli == NULL)
		return ;
	free(canli);
}