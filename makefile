hepsi:derle calistir

derle:
	g++ -I ./include/ -o ./lib/DisplayAtCmd.o -c ./src/DisplayAtCmd.cpp
	g++ -I ./include/ -o ./lib/Exception.o -c ./src/Exception.cpp
	g++ -I ./include/ -o ./lib/OkumaEkleme.o -c ./src/OkumaEkleme.cpp
	g++ -I ./include/ -o ./lib/SatirListesi.o -c ./src/SatirListesi.cpp
	g++ -I ./include/ -o ./lib/SatirListesiNode.o -c ./src/SatirListesiNode.cpp
	g++ -I ./include/ -o ./lib/YoneticiListesi.o -c ./src/YoneticiListesi.cpp
	g++ -I ./include/ -o ./lib/YoneticiNode.o -c ./src/YoneticiNode.cpp
	
	g++ -I ./include/ -o ./bin/main ./lib/DisplayAtCmd.o ./lib/Exception.o ./lib/OkumaEkleme.o ./lib/SatirListesi.o ./lib/SatirListesiNode.o ./lib/YoneticiListesi.o ./lib/YoneticiNode.o ./src/main.cpp
	
calistir:
	./bin/main