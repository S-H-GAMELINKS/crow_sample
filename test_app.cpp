#include "crow.h"
#include "fstream"
#include <sstream>
#include <string>

int main() {
  crow::SimpleApp app;

  CROW_ROUTE(app, "/")([](){
      std::ifstream file("index.html");
      std::stringstream strstream;
      strstream << file.rdbuf();
      file.close();

      //ファイルの内容をstringに入れる
      std::string data( strstream.str() );
      return data;
  });

  app.port(3000).multithreaded().run();
}
