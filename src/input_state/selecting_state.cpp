#include "selecting_state.hpp"

#include <algorithm>

#include "idle_state.hpp"
#include "../input_manager.hpp"

void SelectingState::Enter(InputManager &manager) {
    auto mouse_position = GetMousePosition();
    selection_box = new Rectangle(mouse_position.x, mouse_position.y, 0, 0);

}

void SelectingState::Exit(InputManager &manager) {
    delete selection_box;
    selection_box = nullptr;
}

void SelectingState::HandleClick(InputManager &manager) {

}

void SelectingState::HandleUnclick(InputManager &manager) {
    manager.Transition(new IdleState());
}

void SelectingState::HandleMove(InputManager &manager) {
    auto mouse_position = GetMousePosition();

    auto width = mouse_position.x - selection_box->x;
    auto height = mouse_position.y - selection_box->y;

    selection_box->width = width;
    selection_box->height = height;

    DrawRectangleRec(*selection_box, Color { BLUE.r, BLUE.g, BLUE.b, 128 });
}