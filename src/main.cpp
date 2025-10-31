#include "raylib.h"

#include "command.hpp"
#include "input_manager.hpp"
#include "node.hpp"

#include <queue>
#include <vector>

#define WIDTH 800
#define HEIGHT 800

std::deque<Node *> nodes = {};
std::deque<Command *> commands = {};

int main() {
  SetTargetFPS(60);

  InitWindow(WIDTH, HEIGHT, "luablocks");

  auto input_manager = InputManager::GetInstance();
  nodes.push_back(new Node(0, 0, WIDTH / 2, HEIGHT / 2, RED, "h"));

  while (!WindowShouldClose()) {
    input_manager->Update();

    BeginDrawing();
    ClearBackground(RAYWHITE);

    for (Node *node : nodes) {
        node->Draw();
    }

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
