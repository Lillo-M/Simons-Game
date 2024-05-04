cmake_minimum_required(VERSION 3.15)

project(TheWizard VERSION 1.0 LANGUAGES CXX)

set(cpp_source_files  src/Alaska.cpp src/Animation.cpp src/Archer.cpp src/Arrow.cpp src/Being.cpp
 src/Button.cpp src/Character.cpp src/CollisionManager.cpp src/ComplexAnimation.cpp src/Enemy.cpp
 src/Entity.cpp src/EntityList.cpp src/EventsManager.cpp src/Game.cpp src/GameOverState.cpp 
 src/GraphicManager.cpp src/Ground.cpp src/Horse.cpp src/Ice.cpp src/InputManager.cpp src/Lava.cpp 
 src/LeaderBoard.cpp src/Level.cpp src/LoadGameState.cpp src/main.cpp src/MainMenu.cpp src/Math.cpp 
 src/Menu.cpp src/MenuObserver.cpp src/NewGameMenu.cpp src/Observer.cpp src/Obstacle.cpp src/PauseMenu.cpp 
 src/Player.cpp src/PlayerInputManager.cpp src/PlayerProjectile.cpp src/Projectile.cpp src/SimpleAnimation.cpp 
 src/SimpleSprite.cpp src/Skull.cpp src/State.cpp src/StateMachine.cpp src/TextInputObserver.cpp src/Vulcano.cpp 
 src/Warrior.cpp)

set(THE_WIZARD_PATH ${PROJECT_SOURCE_DIR})

add_executable(TheWizard ${cpp_source_files})

include_directories("${PROJECT_SOURCE_DIR}/SFML-2.5.1/include/SFML" "${PROJECT_SOURCE_DIR}/SFML-2.5.1/include/" 
"${PROJECT_SOURCE_DIR}/include" "${PROJECT_SOURCE_DIR}/include/Entities" "${PROJECT_SOURCE_DIR}/include/Entities/Characters"
"${PROJECT_SOURCE_DIR}/include/Entities/Obstacles" "${PROJECT_SOURCE_DIR}/include/Entities/Projectiles" 
"${PROJECT_SOURCE_DIR}/include/Entities/Characters/Enemies" "${PROJECT_SOURCE_DIR}/include/Math"
"${PROJECT_SOURCE_DIR}/include/Managers" "${PROJECT_SOURCE_DIR}/include/States" "${PROJECT_SOURCE_DIR}/include/Levels" 
"${PROJECT_SOURCE_DIR}/include/Menus" "${PROJECT_SOURCE_DIR}/include/Observers" "${PROJECT_SOURCE_DIR}/include/Defines")

configure_file(${PROJECT_SOURCE_DIR}/include/Defines/SOURCEDIR.h.in ${PROJECT_SOURCE_DIR}/include/Defines/SOURCEDIR.h)

target_link_libraries(TheWizard PUBLIC ${PROJECT_SOURCE_DIR}/SFML-2.5.1/lib/libsfml-graphics-d.a)
target_link_libraries(TheWizard PUBLIC ${PROJECT_SOURCE_DIR}/SFML-2.5.1/lib/libsfml-window-d.a)
target_link_libraries(TheWizard PUBLIC ${PROJECT_SOURCE_DIR}/SFML-2.5.1/lib/libsfml-system-d.a)

#install(TARGETS TheWizard DESTINATION ${PROJECT_SOURCE_DIR}/TheWizard_Build/bin)
#install(FILES "${PROJECT_BINARY_DIR}/include/Defines/SOURCEDIR.h" DESTINATION ${PROJECT_SOURCE_DIR}/TheWizard_Build/include)