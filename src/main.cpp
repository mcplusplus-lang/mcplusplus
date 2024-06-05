#include "minecraft.hpp"
#include <fstream>

using namespace minecraft;

int main(int argc, char** argv) {
    std::ofstream load;
    load.open("load.mcfunction");
    load << say("hello world!" + Entity::Player::any(Entity::Properties{sort: Entity::Properties::NEAREST}));
    load << "test";
    load.close();
    return 0;
}
