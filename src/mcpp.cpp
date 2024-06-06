#include "mcpp.hpp"
#include "entity.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

using json = nlohmann::json;

std::string mcpp::say(std::string message)
{
    return "say " + message + "\n";
};

std::string mcpp::tellraw(mcpp::Entity target, std::string messageJson)
{
    return "tellraw " + target.pack() + " \"" + messageJson + "\"";
}

std::string mcpp::generate_mcmeta(int dp_version, std::string dp_description)
{
    json j = {
        {"pack", {{"pack_format", dp_version}, {"description", dp_description}}}};
    return j.dump(4);
}

void mcpp::init(int dp_version, std::string dp_description, std::string dp_namespace)
{
    std::ofstream mcmeta("pack.mcmeta");
    mcmeta << generate_mcmeta(dp_version, dp_description);
    mcmeta.close();
    if (not std::filesystem::is_directory("data"))
    {
        std::filesystem::create_directory("data");
    }
    if (not std::filesystem::is_directory("data/" + dp_namespace))
    {
        std::filesystem::create_directory("data/" + dp_namespace);
    }
}
