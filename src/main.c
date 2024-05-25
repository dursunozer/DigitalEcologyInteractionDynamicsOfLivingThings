#include "Habitat.h"
/*
Bitki: 1-9
Böcek: 10-20
Sinek: 21-50
Pire: 51-99
*/

int main()
{
	
	Habitat habitat = HabitatOlustur();
	habitat->dosyadanEkle(habitat, "Veri.txt");
	habitat->katliam(habitat);
	return (0);
}
