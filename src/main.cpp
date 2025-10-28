#include "raylib.h"

#include "command.hpp"
#include "input_manager.hpp"
#include "node.hpp"

#include <queue>
#include <vector>

#define WIDTH 800
#define HEIGHT 800

std::vector<Node *> nodes = {};
std::queue<Command *> commands = {};

int main() {
  SetTargetFPS(60);

  InitWindow(WIDTH, HEIGHT, "luablocks");

  auto input_manager = InputManager::GetInstance();

  nodes.push_back(new Node(0, 0, WIDTH / 2, HEIGHT / 2, LIGHTGRAY, "h"));

  while (!WindowShouldClose()) {
    input_manager->Update();

    BeginDrawing();
    ClearBackground(RAYWHITE);

    for (Node *node : nodes) {
      Vector2 center = node->get_center();
      DrawRectangle(node->x, node->y, node->w, node->h, node->color);
      DrawText(node->symbol, center.x, center.y, 12, BLACK);
    }

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
