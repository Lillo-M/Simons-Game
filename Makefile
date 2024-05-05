#Compilador
CC = g++
#Nome do diretorio para os *.o
ODIR=obj
#*.o necessarios para a compilacao
OBJ = obj/main.o $(patsubst src/%.cpp,$(ODIR)/%.o,$(wildcard src/*.cpp))

#diretorio de include
IDIR = -Iinclude -Iinclude/Entities -Iinclude/Entities/Characters -Iinclude/Entities/Characters/Enemies -Iinclude/Managers -Iinclude/Math -Iinclude/Defines
#includes ------------------------- Colocar diretorio da bilioteca SFML -----------------------------------
CFLAGS= $(IDIR) -ISFML-2.5.1/include
#diretorio das libraries usadas
#includes ------------------------- Colocar diretorio da bilioteca SFML -----------------------------------
LDIR =-LSFML-2.5.1/lib
#libraries usadas
LIBS=-lsfml-graphics-s -lsfml-window-s -lsfml-system -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows


Jogo: $(OBJ)
	$(CC) obj/*.o -o Jogo $(LDIR) $(LIBS)
	@echo '===================================COMPILE COMPLETE==========================================='
	@echo ''

$(ODIR)/main.o: src/main.cpp
	if test -d obj; then echo ; else mkdir obj; fi
	@echo '======================================COMPILING==============================================='
	$(CC) -c -o $@ $< -IC:/SFML-2.5.1/include -DSFML_STATIC $(CFLAGS) 

$(ODIR)/Game.o: src/Game.cpp include/Game.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/Math.o: src/Math.cpp include/Math/Math.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/Being.o: src/Being.cpp include/Being.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/Ground.o: src/Ground.cpp include/Entities/Obstacles/Ground.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/EventsManager.o: src/EventsManager.cpp include/Managers/EventsManager.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/Player.o: src/Player.cpp include/Entities/Characters/Player.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/PlayerInputManager.o: src/PlayerInputManager.cpp include/Observers/PlayerInputManager.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/Entity.o: src/Entity.cpp include/Entities/Entity.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/CollisionManager.o: src/CollisionManager.cpp include/Managers/CollisionManager.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/Character.o: src/Character.cpp include/Entities/Characters/Character.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/Enemy.o: src/Enemy.cpp include/Entities/Characters/Enemies/Enemy.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/Warrior.o: src/Warrior.cpp include/Entities/Characters/Enemies/Warrior.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/GraphicManager.o: src/GraphicManager.cpp include/Managers/GraphicManager.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/Obstacle.o: src/Obstacle.cpp include/Entities/Obstacles/Obstacle.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/Level.o: src/Level.cpp include/Levels/Level.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/Alaska.o: src/Alaska.cpp include/Levels/Alaska.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/Vulcano.o: src/Vulcano.cpp include/Levels/Vulcano.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/Projectile.o: src/Projectile.cpp include/Entities/Projectiles/Projectile.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/State.o: src/State.cpp include/States/State.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/StateMachine.o: src/StateMachine.cpp include/States/StateMachine.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/Observer.o: src/Observer.cpp include/Observers/Observer.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/InputManager.o: src/InputManager.cpp include/Managers/InputManager.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/EntityList.o: src/EntityList.cpp include/Math/EntityList.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/Button.o: src/Button.cpp include/GraphicElements/Button.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/Menu.o: src/Menu.cpp include/Menus/Menu.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/MainMenu.o: src/MainMenu.cpp include/Menus/MainMenu.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/PauseMenu.o: src/PauseMenu.cpp include/Menus/PauseMenu.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/MenuObserver.o: src/MenuObserver.cpp include/Observers/MenuObserver.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/LoadGameState.o: src/LoadGameState.cpp include/States/LoadGameState.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/NewGameMenu.o: src/NewGameMenu.cpp include/Menus/NewGameMenu.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/Animation.o: src/Animation.cpp include/GraphicElements/Animation.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/SimpleAnimation.o: src/SimpleAnimation.cpp include/GraphicElements/SimpleAnimation.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/ComplexAnimation.o: src/ComplexAnimation.cpp include/GraphicElements/ComplexAnimation.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/SimpleSprite.o: src/SimpleSprite.cpp include/GraphicElements/SimpleSprite.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/Archer.o: src/Archer.cpp include/Entities/Characters/Enemies/Archer.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/Arrow.o: src/Arrow.cpp include/Entities/Projectiles/Arrow.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/PlayerProjectile.o: src/PlayerProjectile.cpp include/Entities/Projectiles/PlayerProjectile.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/Lava.o: src/Lava.cpp include/Entities/Obstacles/Lava.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/Horse.o: src/Horse.cpp include/Entities/Characters/Enemies/Horse.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/Ice.o: src/Ice.cpp include/Entities/Obstacles/Ice.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/LeaderBoard.o: src/LeaderBoard.cpp include/Menus/LeaderBoard.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/TextInputObserver.o: src/TextInputObserver.cpp include/Observers/TextInputObserver.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/GameOverState.o: src/GameOverState.cpp include/States/GameOverState.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

$(ODIR)/Skull.o: src/Skull.cpp include/Entities/Projectiles/Skull.h
	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC

#$(ODIR)/nome.o: src/nome.cpp include/ ... .h // lembrar de por .o em OBJ
#	$(CC) -c -o $@ $< $(CFLAGS) -DSFML_STATIC


clean:
	rm obj/*.o ./*.exe 
	@echo '================================DELETED ALL *.o FILES========================================='
	@echo ''