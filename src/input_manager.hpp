#ifndef INPUT_MANAGER_HPP_H
#define INPUT_MANAGER_HPP_H

#include "input_state.hpp"
#include "node.hpp"
#include <vector>

#define PRIMARY 1
#define SECONDARY 2

extern std::vector<Node *> nodes;

class InputManager {
private:
  static InputManager *_InputManager;
  InputState *state;
  std::vector<Node *> dragged_nodes;

  InputManager();

  void HandleClick();
  void HandleUnclick();
  void HandleMove();

public:
  static InputManager *GetInstance();
  Node *GetNodeUnderCursor();

  void Update();
};

#endif // INPUT_MANAGER_HPP_H
