#include "mcpp.hpp"
#include "entity.hpp"
#include <boost/algorithm/string/join.hpp>
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

std::string mcpp::generate_mcmeta()
{
    json j = {
        {"pack",
         {{"pack_format", dp_version},
          {"description", dp_description}}}};
    return j.dump(4);
}

std::string mcpp::generate_function_tag(std::string function)
{
    json j = {
        {"values",
         {dp_namespace + ":" + function}}};
    return j.dump(4);
}

void mcpp::init()
{
    std::filesystem::create_directory(dp_namespace);
    std::ofstream mcmeta(dp_namespace + "/pack.mcmeta");
    mcmeta << generate_mcmeta();
    mcmeta.close();
    std::filesystem::create_directories(dp_namespace + "/data/minecraft/tags/functions");
    // tick and load jsons
    std::ofstream tick(dp_namespace + "/data/minecraft/tags/functions/tick.json");
    tick << generate_function_tag("tick");
    tick.close();
    std::ofstream load(dp_namespace + "/data/minecraft/tags/functions/load.json");
    load << generate_function_tag("load");
    load.close();
    std::filesystem::create_directories(dp_namespace + "/data/" + dp_namespace + "/functions");
}

void mcpp::func(std::string name, std::vector<std::string> body)
{
    std::ofstream output(dp_namespace + "/data/" + dp_namespace + "/functions/" + name + ".mcfunction");
    output << boost::algorithm::join(body, "\n");
    output.close();
}
