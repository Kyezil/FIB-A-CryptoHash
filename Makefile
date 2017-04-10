program.exe: sha256.o main.o
	g++ -o cryptohash.exe sha256.o main.o
	rm *.o

sha256.o:
	g++ -c sources/sha256.cc

main.o:
	g++ -c sources/main.cc