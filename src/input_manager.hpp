#ifndef INPUT_MANAGER_HPP_H
#define INPUT_MANAGER_HPP_H

#include "input_state/input_state.hpp"
#include "node.hpp"
#include <vector>
#include <deque>

#define PRIMARY 1
#define SECONDARY 2

extern std::deque<Node *> nodes;

class InputManager {
private:
  static InputManager *_InputManager;
  InputManager();
  InputState *state;

public:
  static InputManager *GetInstance();
  Node *GetNodeUnderCursor();
  std::vector<Node *> selected_nodes;
  void Transition(InputState *new_state);
  void Update();
};

#endif // INPUT_MANAGER_HPP_H
