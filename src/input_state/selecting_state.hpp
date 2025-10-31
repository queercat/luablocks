#ifndef SELECTING_STATE_HPP_H
#define SELECTING_STATE_HPP_H

#include <raylib.h>

#include "input_state.hpp"

class SelectingState : public InputState {
	Rectangle *selection_box;
public:
	void HandleClick(InputManager &manager) override;
	void HandleUnclick(InputManager &manager) override;
	void HandleMove(InputManager &manager) override;

	void Enter(InputManager &manager) override;
	void Exit(InputManager &manager) override;
};
#endif
