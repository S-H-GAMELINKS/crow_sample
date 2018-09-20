#include "crow.h"

int main() {
  crow::SimpleApp app;

  CROW_ROUTE(app, "/")([](){
      return "<h1>Hello, World!</h1>";
  });

  app.port(3000).multithreaded().run();
}
