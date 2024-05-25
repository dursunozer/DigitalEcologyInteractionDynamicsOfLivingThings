#ifndef CANLI_H
# define CANLI_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
struct CANLI{
	int value;
	char character;
	bool is_alive;

	int  (*deger)(struct CANLI*);		//Canlinin degerini donduren fonksiyon
	char (*gorunum)(struct CANLI*);		//Canlinin gorunumunu donduren fonksiyon
	bool (*savas)(struct CANLI*, struct CANLI*);	//Canlinin savas fonksiyonu
	void (*goruntule)(struct CANLI*);	//Canlinin gorunumunu ekrana yazdiran fonksiyon
	bool (*yasiyorMu)(struct CANLI*);	//Canlinin yasiyor olup olmadigini donduren fonksiyon
	struct CANLI* (*canliyiGetir)();	//Üst klasları silip, Canliyi donduren fonksiyon
	void (*yoket)(struct CANLI*);		//Canliyi yok eden fonksiyon
};
typedef struct CANLI *Canli;

Canli	CanliOlustur(int deger, char karakter);
void	CanliYoket(const Canli);

#endif