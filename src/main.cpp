#include "app-window.h"

#include <filesystem>
#include <fstream>
#include <iostream>

#ifdef __ANDROID__
extern "C" void slint_main()
#else
int main(int argc, char **argv)
#endif

{
  std::filesystem::path fileName = ".firstrun";
  bool firstRun = !std::filesystem::exists(fileName); // reverses so if its NOT found, then false instead of true
  if (firstRun) {
    std::ofstream file(fileName);
    file.close();
  }

  auto ui = AppWindow::create();
  ui->run();

  return 0;
}