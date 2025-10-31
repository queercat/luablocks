#ifndef COMMAND_H
#define COMMAND_H

struct Command {
  virtual ~Command() = default;

  virtual void Do() = 0;
  virtual void Undo() = 0;
};

#endif
