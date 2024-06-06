#include "entity.hpp"
#include "minecraft.hpp"
#include <fstream>
#include <optional>

using namespace minecraft;

int main(int argc, char **argv)
{
    std::ofstream load;
    load.open("load.mcfunction");
    load << say("hello world!");
    load << tellraw(entity::player::any({.sort = entity::NEAREST, .distance = {std::nullopt, 5}}), "hello world!");
    load.close();
    return 0;
}
