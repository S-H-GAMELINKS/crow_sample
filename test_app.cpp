#include "crow.h"
#include "fstream"
#include <sstream>
#include <string>

std::string loadView(const std::string& path){
  std::ifstream file(path.c_str());
  std::stringstream strstream;
  
  strstream << file.rdbuf();
  file.close();

  std::string data( strstream.str() );
  
  return data;
}

int main() {
  crow::SimpleApp app;

  CROW_ROUTE(app, "/")([](){
    return loadView("index.html");
  });

  app.port(3000).multithreaded().run();
}