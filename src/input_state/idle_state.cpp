#include "idle_state.hpp"

#include "dragging_state.hpp"
#include "selecting_state.hpp"
#include "../input_manager.hpp"

void IdleState::Enter(InputManager &manager) {}

void IdleState::Exit(InputManager &manager) {
}

void IdleState::HandleClick(InputManager &manager) {
  auto node = manager.GetNodeUnderCursor();

  if (node != nullptr) {
    manager.selected_nodes.push_back(node);
    manager.Transition(new DraggingState());
  } else {
    manager.selected_nodes.clear();
    manager.Transition(new SelectingState());
  }
}

void IdleState::HandleUnclick(InputManager &manager) {
  manager.selected_nodes.clear();
}

void IdleState::HandleMove(InputManager &manager) {}
