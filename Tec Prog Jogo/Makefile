Jogo: Game.o main.o Ground.o EventsManager.o Player.o PlayerInputManager.o Entity.o CollisionManager.o
	g++ *.o -o Jogo -LC:/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp -IC:/SFML-2.5.1/include

Game.o: src/Game.cpp include/Game.h
	g++ -c src/Game.cpp -IC:/SFML-2.5.1/include

Ground.o: src/Ground.cpp include/Ground.h
	g++ -c src/Ground.cpp -IC:/SFML-2.5.1/include

EventsManager.o: src/EventsManager.cpp include/EventsManager.h
	g++ -c src/EventsManager.cpp -IC:/SFML-2.5.1/include

Player.o: src/Player.cpp include/Player.h
	g++ -c src/Player.cpp -IC:/SFML-2.5.1/include

PlayerInputManager.o: src/PlayerInputManager.cpp include/PlayerInputManager.h
	g++ -c src/PlayerInputManager.cpp -IC:/SFML-2.5.1/include

Entity.o: src/Entity.cpp include/Entity.h
	g++ -c src/Entity.cpp -IC:/SFML-2.5.1/include

CollisionManager.o: src/CollisionManager.cpp include/CollisionManager.h
	g++ -c src/CollisionManager.cpp -IC:/SFML-2.5.1/include

clean:
	rm *.o Jogo.exe