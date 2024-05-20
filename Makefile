#Compilador
CC = g++
#Nome do diretorio para os *.o
ODIR=obj
#*.o necessarios para a compilacao
_OBJ = $(patsubst src/%.cpp,$(ODIR)/%.o,$(wildcard src/*.cpp))

#forcando o main.cpp ser o primeiro arquivo compilado
#adicionando na frente || substituindo o obj/main.o encontrado por uma string vazia ""
OBJ = $(ODIR)/main.o $(subst $(ODIR)/main.o,$(nullstring),$(_OBJ))

#diretorio de include
IDIR = -Iinclude -Iinclude/Entities -Iinclude/Entities/Characters -Iinclude/Entities/Characters/Enemies \
-Iinclude/Managers -Iinclude/Math -Iinclude/Defines -Iinclude/Entities/Obstacles -Iinclude/Entities/Projectiles \
-Iinclude/GraphicElements -Iinclude/Levels -Iinclude/Managers -Iinclude/Menus -Iinclude/Observers -Iinclude/States
#includes ------------------------- Colocar diretorio da bilioteca SFML -----------------------------------
CFLAGS= $(IDIR) -ISFML-2.5.1/include
#diretorio das libraries usadas
#libs ------------------------- Colocar diretorio da bilioteca SFML -----------------------------------
LDIR =-LSFML-2.5.1/lib
#libraries usadas
LIBS=-lsfml-graphics -lsfml-window -lsfml-system 

vpath %.h  $(patsubst -Iinclude%,include%,$(IDIR))

Jogo: $(OBJ)
	$(CC) $(DDEBUG) obj/*.o -o Jogo $(LDIR) $(LIBS)
	@echo '===================================COMPILE COMPLETE==========================================='
	@echo ''

$(ODIR)/main.o::
	if test -d obj; then echo ; else mkdir obj; fi

$(OBJ):: $(ODIR)/%.o: src/%.cpp %.h
	@echo '======================================COMPILING==============================================='
	$(CC) $(DDEBUG) -c -o $@ $< $(CFLAGS) -DSFML_STATIC 

Debug: DDEBUG :=-g
Debug: Jogo

clean:
	-rm obj/*.o ./*.exe 
	@echo '================================DELETED ALL *.o FILES========================================='
	@echo ''
