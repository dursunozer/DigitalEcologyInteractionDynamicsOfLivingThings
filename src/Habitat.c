#include "Habitat.h"

Habitat HabitatOlustur(){
	Habitat this;
	this = (Habitat)malloc(sizeof(struct HABITAT));
	if (!this){
		fprintf(stderr, "Bellek ayrilamadi\n");
		exit(EXIT_FAILURE);
	}
	this->canliListesi = CanliBagliListeOlustur();
	this->dosyadanEkle = &HabitatDosyadanEkle;
	this->goruntule = &HabitatGoruntule;
	this->katliam = &HabitatKatliam;
	this->yoket = &HabitatYoket;
	return this;
}

void HabitatDosyadanEkle(Habitat this, const char* dosyaAdi)
{
	FILE* file = fopen(dosyaAdi, "r");
	if (file == NULL){
		fprintf(stderr, "Dosya acilamadi\n");
		exit(EXIT_FAILURE);
	}
	int i;
	while (fscanf(file, "%d", &i) != EOF){
		CanliDugum canliDugum;
		if (fgetc(file) == '\n')
			canliDugum = CanliDugumOlustur(i, true);
		else
			canliDugum = CanliDugumOlustur(i, false);
		this->canliListesi->elemanEkle(this->canliListesi, canliDugum);
	}
	fclose(file);
}

void HabitatGoruntule(const Habitat this){
	this->canliListesi->goruntule(this->canliListesi);
	printf("\n");
}

void HabitatKatliam(Habitat this){
	this->canliListesi->savasHazirla(this->canliListesi);
	printf("\033c");
	this->goruntule(this);
	printf("Press any key to continue...\n");
	getchar();
	while (this->canliListesi->ikinciCanli != NULL)
	{
		this->canliListesi->savas(this->canliListesi);
		printf("\033c");
		this->goruntule(this);
		//getchar();
	}
	this->canliListesi->kazananGoruntule(this->canliListesi);
}

void HabitatYoket(const Habitat this){
	if (this == NULL)
		return ;
	this->canliListesi->yoket(this->canliListesi);
	free(this);
}