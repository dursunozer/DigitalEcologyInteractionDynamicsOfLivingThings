#include "CanliBagliListe.h"

CanliBagliListe CanliBagliListeOlustur(){
	CanliBagliListe this;
	this = (CanliBagliListe)malloc(sizeof(struct CANLIBAGLILISTE));
	if (!this){
		fprintf(stderr, "Bellek ayrilamadi\n");
		exit(EXIT_FAILURE);
	}
	this->bas = NULL;
	this->son = NULL;
	this->elemanEkle = &CanliBagliListeElemanEkle;
	this->goruntule = &CanliBagliListeGoruntule;
	this->savasHazirla = &CanliBagliListeSavasHazirla;
	this->savas = &CanliBagliListeSavas;
	this->kazananGoruntule = &CanliBagliListeKazananGoruntule;
	this->yoket = &CanliBagliListeYoket;
	return this;
}

void CanliBagliListeElemanEkle(CanliBagliListe this, CanliDugum canliDugum){
	if (this->bas == NULL)
	{
		this->bas = canliDugum;
		this->son = canliDugum;
	}
	else
	{
		this->son->sonraki = canliDugum;
		this->son = canliDugum;
	}
}

void CanliBagliListeGoruntule(const CanliBagliListe this){
	CanliDugum iter = this->bas;
	while (iter != NULL)
	{
		iter->goruntule(iter);
		iter = iter->sonraki;
	}
}

void CanliBagliListeSavasHazirla(CanliBagliListe this){
	if (this->bas == NULL || this->bas->sonraki == NULL)
	{
		fprintf(stderr, "Savas icin en az iki canli olmali\n");
		exit(EXIT_FAILURE);
	}
	this->ilkCanli = this->bas;
	this->ikinciCanli = this->bas->sonraki;
}

void CanliBagliListeSavas(CanliBagliListe this){
	
	//printf("ilk canli: %d\n", this->ilkCanli->canli->value);
	//printf("ikinci canli: %d\n", this->ikinciCanli->canli->value);
	if (this->ilkCanli->canli->savas(this->ilkCanli->canli, this->ikinciCanli->canli))
	{
		this->ikinciCanli = this->ikinciCanli->sonraki;
	}
	else
	{
		this->ilkCanli = this->ikinciCanli;
		this->ikinciCanli = this->ikinciCanli->sonraki;
	}
}

void CanliBagliListeKazananGoruntule(CanliBagliListe this){
	if (this->ilkCanli != NULL)
	{
		int x = 0;
		int y = 0;
		CanliDugum iter = this->bas;
		while (!iter->canli->yasiyorMu(iter->canli))
		{
			x++;
			if (iter->newLine && iter->sonraki != NULL)
			{x = 0; y++;}
			iter = iter->sonraki;
		}
		printf("\033c");
		printf("Kazanan: %c (%d,%d)\n", this->ilkCanli->canli->gorunum(this->ilkCanli->canli), y, x);
	}
	else
	{
		printf("Kazanan yok\n");
	}
}

void CanliBagliListeYoket(CanliBagliListe this){
	CanliDugum temp;
	while (this->bas != NULL)
	{
		temp = this->bas;
		this->bas = this->bas->sonraki;
		temp->yoket(temp);
	}
	free(this);
}