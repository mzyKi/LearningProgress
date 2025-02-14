#include <memory>
#include <mutex>

class some_resource {
public:
  void do_something();
};

std::shared_ptr<some_resource> resource_ptr;
std::once_flag resource_flag; // 1

void init_resource() { resource_ptr.reset(new some_resource); }

void foo() {
  std::call_once(resource_flag, init_resource);
  resource_ptr->do_something();
}

class X {
private:
  connection_info connection_details;
  connection_handle connection;
  std::once_flag connection_init_flag;

  void open_connection() {
    connection = connection_manager.open(connection_details);
  }

public:
  X(connection_info const &connection_details_)
      : connection_details(connection_details_) {}
  void send_data(data_packet const &data) // 1
  {
    std::call_once(connection_init_flag, &X::open_connection, this); // 2
    connection.send_data(data);
  }
  data_packet receive_data() // 3
  {
    std::call_once(connection_init_flag, &X::open_connection, this); // 2
    return connection.receive_data();
  }
};