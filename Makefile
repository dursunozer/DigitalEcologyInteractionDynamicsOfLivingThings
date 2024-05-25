hepsi: derle calistir

derle:
	gcc -I ./include/ -o ./lib/Bitki.o -c ./src/Bitki.c
	gcc -I ./include/ -o ./lib/Bocek.o -c ./src/Bocek.c
	gcc -I ./include/ -o ./lib/Canli.o -c ./src/Canli.c
	gcc -I ./include/ -o ./lib/Pire.o -c ./src/Pire.c
	gcc -I ./include/ -o ./lib/Sinek.o -c ./src/Sinek.c
	gcc -I ./include/ -o ./lib/CanliDugum.o -c ./src/CanliDugum.c
	gcc -I ./include/ -o ./lib/CanliBagliListe.o -c ./src/CanliBagliListe.c
	gcc -I ./include/ -o ./lib/Habitat.o -c ./src/Habitat.c
	gcc -I ./include/ -o ./bin/odev2 ./lib/Habitat.o ./lib/CanliBagliListe.o ./lib/CanliDugum.o ./lib/Canli.o ./lib/Bocek.o ./lib/Pire.o ./lib/Sinek.o ./lib/Bitki.o  ./src/main.c

calistir:
	./bin/odev2


##