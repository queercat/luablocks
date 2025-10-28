#include "idle_state.hpp"
#include "input_manager.hpp"

#include <cstdio>

void IdleState::Enter(InputManager &manager) {}
void IdleState::Exit(InputManager &manager) {}

void IdleState::HandleClick(InputManager &manager) {
  auto node = manager.GetNodeUnderCursor();

  if (node != nullptr) {
    printf("clicked on node!\n");
  } else {
    printf("did not click on node!\n");
  }
}

void IdleState::HandleUnclick(InputManager &manager) {}
void IdleState::HandleMove(InputManager &manager) {}
