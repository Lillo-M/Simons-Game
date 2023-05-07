Jogo: Game.o main.o Ground.o EventsManager.o Player.o PlayerInputManager.o Entity.o CollisionManager.o
	g++ *.o -o Jogo -LC:/SFML-2.5.1/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows 

main.o: main.cpp
	g++ -c main.cpp -IC:/SFML-2.5.1/include -DSFML_STATIC

Game.o: src/Game.cpp include/Game.h
	g++ -c src/Game.cpp -IC:/SFML-2.5.1/include -DSFML_STATIC

Ground.o: src/Ground.cpp include/Entities/Ground.h
	g++ -c src/Ground.cpp -IC:/SFML-2.5.1/include -DSFML_STATIC

EventsManager.o: src/EventsManager.cpp include/Managers/EventsManager.h
	g++ -c src/EventsManager.cpp -IC:/SFML-2.5.1/include -DSFML_STATIC

Player.o: src/Player.cpp include/Entities/Player.h
	g++ -c src/Player.cpp -IC:/SFML-2.5.1/include -DSFML_STATIC

PlayerInputManager.o: src/PlayerInputManager.cpp include/Managers/PlayerInputManager.h
	g++ -c src/PlayerInputManager.cpp -IC:/SFML-2.5.1/include -DSFML_STATIC

Entity.o: src/Entity.cpp include/Entities/Entity.h
	g++ -c src/Entity.cpp -IC:/SFML-2.5.1/include -DSFML_STATIC

CollisionManager.o: src/CollisionManager.cpp include/Managers/CollisionManager.h
	g++ -c src/CollisionManager.cpp -IC:/SFML-2.5.1/include -DSFML_STATIC

clean:
	rm ./*.o ./Jogo.exe