#Define a versao minima do CMake para gerar a build
cmake_minimum_required(VERSION 3.15)
#Define nome do projeto e informacoes basicas do projeto como: versao, descricao, url, linguagens utilizadas, etc...
project(TheWizard VERSION 1.0)
#Construtura do projeto. (Em tutoriais mais antigos de CMake geralmente utilizam uma variavel para guardar
#os 'source_files', em CMake moderno abandonamos essa funcionalidade e utilizamos as funcoes 'Target')
add_executable(${PROJECT_NAME})


#- Metodo recomendado para projetos com mais de um Dev
#target_sources(${PROJECT_NAME} PRIVATE  src/Alaska.cpp src/Animation.cpp src/Archer.cpp src/Arrow.cpp src/Being.cpp
# src/Button.cpp src/Character.cpp src/CollisionManager.cpp src/ComplexAnimation.cpp src/Enemy.cpp
# src/Entity.cpp src/EntityList.cpp src/EventsManager.cpp src/Game.cpp src/GameOverState.cpp 
# src/GraphicManager.cpp src/Ground.cpp src/Horse.cpp src/Ice.cpp src/InputManager.cpp src/Lava.cpp 
# src/LeaderBoard.cpp src/Level.cpp src/LoadGameState.cpp src/main.cpp src/MainMenu.cpp src/Math.cpp 
# src/Menu.cpp src/MenuObserver.cpp src/NewGameMenu.cpp src/Observer.cpp src/Obstacle.cpp src/PauseMenu.cpp 
# src/Player.cpp src/PlayerInputManager.cpp src/PlayerProjectile.cpp src/Projectile.cpp src/SimpleAnimation.cpp 
# src/SimpleSprite.cpp src/Skull.cpp src/State.cpp src/StateMachine.cpp src/TextInputObserver.cpp src/Vulcano.cpp 
# src/Warrior.cpp)

#- Exemplo de file GLOB 
#- GLOB nao eh recomendado ja que o CMake eh um gerador de build, ou seja, ele nao eh conectado
# com o build em si. Portanto se for adicionado algum arquivo, *.cpp por exemplo, o build gerado nao ficara sabendo.

file(GLOB cpp_source_files ${PROJECT_SOURCE_DIR}/src/*.cpp)

target_sources(${PROJECT_NAME} PRIVATE ${cpp_source_files})

#end- Exemplo de file GLOB

#exemplo de variavel
set(THE_WIZARD_PATH ${PROJECT_SOURCE_DIR})

#define os diretorios de include
#Isso eh interessante pois faz com que nao seja necessario dar include no 'Relative_Path', ou seja,
#se um arquivo src/Foo.c quer incluir Bar.h inves de dar include em "../include/Bar.h"
#Foo.c pode incluir apenas "Bar.h" se "include" estiver definido como diretorio de include
target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/SFML-2.5.1/include/SFML" "${PROJECT_SOURCE_DIR}/SFML-2.5.1/include/" 
"${PROJECT_SOURCE_DIR}/include" "${PROJECT_SOURCE_DIR}/include/Entities" "${PROJECT_SOURCE_DIR}/include/Entities/Characters"
"${PROJECT_SOURCE_DIR}/include/Entities/Obstacles" "${PROJECT_SOURCE_DIR}/include/Entities/Projectiles" 
"${PROJECT_SOURCE_DIR}/include/Entities/Characters/Enemies" "${PROJECT_SOURCE_DIR}/include/Math"
"${PROJECT_SOURCE_DIR}/include/Managers" "${PROJECT_SOURCE_DIR}/include/States" "${PROJECT_SOURCE_DIR}/include/Levels" 
"${PROJECT_SOURCE_DIR}/include/Menus" "${PROJECT_SOURCE_DIR}/include/Observers" "${PROJECT_SOURCE_DIR}/include/Defines")


#Exemplo de passagem de variavel CMAKE para variavel do Codigo
configure_file(${PROJECT_SOURCE_DIR}/include/Defines/SOURCEDIR.h.in ${PROJECT_SOURCE_DIR}/include/Defines/SOURCEDIR.h)

#Exemplo de biblioteca de interface, uma biblioteca de interface eh uma biblioteca que nao tem
#especificacoes de construcao, elas tem apenas requisitos de uso.
add_library(SFML INTERFACE)

#exemplo de estrutura condicional
if(WIN32)
  #Define as Bibliotecas, Neste caso a biblioteca eh um arquivo lib do tipo lib**.a mas poderia ser lib**.so ou simplificar para
  # **.lib, ainda, bibliotecas podem ser arquivos .cxx, .cpp, etc...
  target_link_libraries(SFML INTERFACE ${PROJECT_SOURCE_DIR}/SFML-2.5.1/lib/libsfml-graphics-d.a)
  target_link_libraries(SFML INTERFACE ${PROJECT_SOURCE_DIR}/SFML-2.5.1/lib/libsfml-window-d.a)
  target_link_libraries(SFML INTERFACE ${PROJECT_SOURCE_DIR}/SFML-2.5.1/lib/libsfml-system-d.a)
else()
  #exemplo de uso de bibliotecas em 'Path Padrao'
  target_link_libraries(SFML INTERFACE sfml-graphics sfml-window sfml-system)
endif()

target_link_libraries(${PROJECT_NAME} PUBLIC SFML)