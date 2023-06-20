
all : bin/juego.exe 


bin/juego.exe : src/main.cpp
	g++ -o bin/juego.exe -Iinclude src/main.cpp

run : bin/juego.exe
	./bin/juego.exe

build-test : test/RPG/armas/Espadon.test.cpp
	g++ -o bin/test/Espadon ./test/RPG/armas/Espadon.test.cpp -Iinclude

run-test : build-test

bin/test_sdl : src/main.cpp
	g++ -o bin/test_sdl test/sdl_test.cpp -Iinclude
