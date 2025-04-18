#include <MyTemplate/StdName/Name_memory.hpp>
#include <MyTemplate/StdName/Name_vector.hpp>
#include <iostream>

using namespace Smkz;

int main() {
  std::cout << type_name<std::unique_ptr<int>>().Data() << std::endl;
  std::cout << type_name<std::vector<int>>().Data() << std::endl;
}
