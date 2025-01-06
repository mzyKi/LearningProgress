#include <iostream>
#include <thread>

void open_document_and_display_gui(std::string const &filename);
bool done_editing();

enum Mode { open_new_document, open_else };

struct user_command {
public:
  Mode type;
};

user_command get_user_input();
std::string get_filename_from_user();
void process_user_input(const user_command &cmd);

void edit_document(std::string const &filename) {
  open_document_and_display_gui(filename);
  while (!done_editing()) {
    user_command cmd = get_user_input();
    if (cmd.type == open_new_document) {
      std::string const new_name = get_filename_from_user();
      std::thread t(edit_document, new_name);
      t.detach();
    } else {
      process_user_input(cmd);
    }
  }
}