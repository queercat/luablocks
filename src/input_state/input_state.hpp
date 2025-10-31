#ifndef INPUT_STATE_HPP_H
#define INPUT_STATE_HPP_H

class InputManager;

class InputState {
public:
  virtual ~InputState() = default;

  virtual void Enter(InputManager &manager) = 0;
  virtual void Exit(InputManager &manager) = 0;
  virtual void HandleClick(InputManager &manager) = 0;
  virtual void HandleUnclick(InputManager &manager) = 0;
  virtual void HandleMove(InputManager &manager) = 0;
};

#endif // INPUT_STATE_HPP_H
