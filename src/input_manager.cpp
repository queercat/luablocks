#include "input_manager.hpp"
#include "idle_state.hpp"
#include "raylib.h"
#include <cstdio>

InputManager *InputManager::_InputManager = nullptr;

InputManager::InputManager() { state = new IdleState(); }

InputManager *InputManager::GetInstance() {
  if (_InputManager == nullptr) {
    _InputManager = new InputManager();
  }
  return _InputManager;
}

Node *InputManager::GetNodeUnderCursor() {
  Vector2 position = GetMousePosition();

  for (auto node : nodes) {
    auto left = node->x;
    auto right = node->x + node->w;
    auto bottom = node->y;
    auto top = node->y + node->h;

    if (left <= position.x && position.x <= right && bottom <= position.y &&
        position.y <= top) {
      return node;
    }
  }

  return nullptr;
}

void InputManager::Update() {
  Vector2 position = GetMousePosition();
  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    state->HandleClick(*this);
  } else if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
    state->HandleUnclick(*this);
  }

  state->HandleMove(*this);
}
