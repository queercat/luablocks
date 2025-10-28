#ifndef IDLE_STATE_HPP_H
#define IDLE_STATE_HPP_H

#include "input_state.hpp"

class IdleState : public InputState {
  void Enter(InputManager &manager) override;
  void Exit(InputManager &manager) override;

  void HandleClick(InputManager &manager) override;
  void HandleUnclick(InputManager &manager) override;
  void HandleMove(InputManager &manager) override;
};

#endif // IDLE_STATE_HPP_H
