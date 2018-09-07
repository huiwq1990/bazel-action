#include "lib/hello-time.h"
#include "main/hello-greet.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>


int main(int argc, char** argv) {

  std::string who = "world2";
  if (argc > 1) {
    who = argv[1];
  }
  std::cout << get_greet(who) << std::endl;
  print_localtime();
  int i = 0;
  for(i=0;i<10;i++){
    std::cout << "hi" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
  return 0;
}
