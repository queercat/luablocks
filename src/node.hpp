#include "raylib.h"

#ifndef NODE_HPP_H
#define NODE_HPP_H

struct Node {
  Vector2 position;
  Vector2 size;
  Color color;
  const char *symbol;

  Vector2 get_center();

  Node(int x, int y, int w, int h, Color color = WHITE,
       const char *symbol = "0");

  void Draw();
};

#endif // NODE_HPP_H
