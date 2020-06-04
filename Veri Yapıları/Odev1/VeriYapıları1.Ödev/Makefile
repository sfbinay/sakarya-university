all:derle calistir

derle:
	g++ -I "./include" -o ./lib/Top.o -c ./src/Top.cpp
	g++ -I "./include" -o ./lib/Kova.o -c ./src/Kova.cpp
	g++ -I "./include" -o ./lib/KovaKontrol.o -c ./src/KovaKontrol.cpp
	g++ -I "./include" -o ./lib/Test.o -c ./src/Test.cpp
	g++ -I "./include" ./src/Top.cpp ./src/KovaKontrol.cpp ./src/Kova.cpp ./src/Test.cpp -o ./bin/Test

calistir:
	./bin/Test