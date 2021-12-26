#pragma once
#include <raylib.h>
#include <vector>
#include <map>
#include <string>
#include "object.hpp"

class DisplayManager{
private:
  int screenWidth, screenHeight;
  std::string profile;
  std::vector<Object*>* profileRef = nullptr;
  std::map<std::string, std::vector<Object*>> profiles;

public:
  DisplayManager(const int width, const int height, const std::string title, const int fps, const std::string profile = "main");
  void switchProfile(const std::string profile);
  std::string getProfile() const {return this->profile;};

  void attachShape(Object* shape);
  void removeShape(Object* shape);

  void clear();

  void drawShape() const;
  void closeScreen() const;

  std::vector<Object*> exposeShapes(std::string profile) const;
};
