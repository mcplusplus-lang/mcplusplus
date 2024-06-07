#include "entity.hpp"
#include "mcpp.hpp"
#define DP_VERSION 41
#define DP_DESCRIPTION "A datapack to test mcpp's capabilities"
#define DP_NAMESPACE "test-datapack"

using namespace mcpp;

int main(int argc, char **argv)
{
    dp_namespace = DP_NAMESPACE;
    dp_version = DP_VERSION;
    dp_description = DP_DESCRIPTION;
    init();
    func("load",
         {
             say("hello world!"),
             tellraw(
                 Entity(Entity::A, {.sort = Entity::FURTHEST, .distance = Range{.min = -1, .max = 560}}),
                 "hello world!"),
         });
    return 0;
}
