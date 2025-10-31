#include "dragging_state.hpp"

#include "idle_state.hpp"
#include "../input_manager.hpp"

#include "raymath.h"

void DraggingState::Enter(InputManager &manager) {

}

void DraggingState::Exit(InputManager &manager) {

}

void DraggingState::HandleClick(InputManager &manager) {
}

void DraggingState::HandleUnclick(InputManager &manager) {
    manager.selected_nodes.clear();
    manager.Transition(new IdleState());
}

void DraggingState::HandleMove(InputManager &manager) {
    auto delta = GetMouseDelta();

    for (auto selected_node : manager.selected_nodes) {
        selected_node->position = Vector2Add(delta, selected_node->position);
    }
}
