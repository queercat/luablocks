#ifndef LUABLOCKS_DRAGGING_STATE_HPP_H
#define LUABLOCKS_DRAGGING_STATE_HPP_H

#include "input_state.hpp"

class DraggingState : public InputState {
public:
    void Enter(InputManager &manager) override;
    void Exit(InputManager &manager) override;
    void HandleClick(InputManager &manager) override;
    void HandleUnclick(InputManager &manager) override;
    void HandleMove(InputManager &manager) override;
};

#endif