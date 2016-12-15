#include <emscripten/val.h>
#include <stdio.h>
#include <string>

using namespace emscripten;

int main() {
  val document = val::global("document");
  document["body"]["style"].set("backgroundColor", "SteelBlue");
}
