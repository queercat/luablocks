#include "raylib.h"

#ifndef NODE_HPP_H
#define NODE_HPP_H

struct Node {
  int x, y, w, h;
  Color color;
  const char *symbol;

  Vector2 get_center() { return Vector2{(float)x + w / 2, (float)y + h / 2}; }

  Node(int x, int y, int w, int h, Color color = WHITE,
       const char *symbol = "0")
      : x(x), y(y), w(w), h(h), color(color), symbol(symbol) {}
};

#endif // NODE_HPP_H
