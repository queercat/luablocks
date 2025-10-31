#include "input_manager.hpp"
#include "input_state/idle_state.hpp"

InputManager *InputManager::_InputManager = nullptr;

InputManager::InputManager() { state = nullptr; Transition(new IdleState()); }

InputManager *InputManager::GetInstance() {
  if (_InputManager == nullptr) {
    _InputManager = new InputManager();
  }
  return _InputManager;
}

Node *InputManager::GetNodeUnderCursor() {
  Vector2 position = GetMousePosition();

  for (auto node : nodes) {
    auto left = node->position.x;
    auto right = node->position.x + node->size.x;
    auto bottom = node->position.y;
    auto top = node->position.y + node->size.y;

    if (left <= position.x && position.x <= right && bottom <= position.y &&
        position.y <= top) {
      return node;
    }
  }

  return nullptr;
}

void InputManager::Transition(InputState *new_state) {
  if (state != nullptr) {
    state->Exit(*this);
  }

  if (new_state != nullptr) {
    delete state;
    new_state->Enter(*this);
    state = new_state;
  }
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
