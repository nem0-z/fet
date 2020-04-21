#include "ToDoTask.hpp"

std::ostream& operator<<(std::ostream& stream, const ToDoTask& task) {
  stream << "Task id:";
  stream << task.id_ << std::endl;
  stream << "Naslov id:";
  stream << task.taskTitle_ << std::endl;
  stream << "Task description:";
  stream << task.taskDescription_ << std::endl;
  stream << "Task priority:";
  stream << task.priority_ << std::endl;
  stream << '\n';
  return stream;
}
