#include "displaymanager.hpp"
#include <raylib.h>

DisplayManager::DisplayManager(
    const int screenWidth,
    const int screenHeight,
    const std::string title,
    const int targetFPS,
    const std::string profile
){
  InitWindow(screenWidth, screenHeight, title.data());
  SetTargetFPS(targetFPS);

  this->profile = profile;
  this->screenWidth = screenWidth;
  this->screenHeight = screenHeight;

  switchProfile(profile);
}

void DisplayManager::switchProfile(std::string profile){
  if (!profiles.contains(profile))
    profiles[profile] = {};

  this->profile = profile;

  this->profileRef = &profiles[profile];
}

void DisplayManager::attachShape(Object* shape){
  profileRef->push_back(shape);
}

void DisplayManager::removeShape(Object* shape){
  for (size_t i = 0; i < profileRef->size(); i++){
    if (profileRef->at(i) == shape){
      profileRef->erase(profileRef->begin()+i);
      return;
    }
  }
}

void DisplayManager::drawShape() const{
  BeginDrawing();
  ClearBackground(RAYWHITE);
  for (Object* i : *profileRef)
    i->draw();
  EndDrawing();
}

void DisplayManager::closeScreen() const{
  CloseWindow();
}

void DisplayManager::clear(){
  profileRef->clear();
}

std::vector<Object*> DisplayManager::exposeShapes(std::string profile) const{
  return profiles.at(profile);
}
