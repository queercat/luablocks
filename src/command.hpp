#ifndef COMMAND_H
#define COMMAND_H

struct Command {
  virtual void Do();
  virtual void Undo();
};

#endif
