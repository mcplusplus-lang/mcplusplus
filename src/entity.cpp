#include "entity.hpp"

std::string minecraft::Entity::Properties::unpack() {
  std::string result;
  switch (sort) {
    case NEAREST:
      result += "sort: nearest";
      break;
    case FARTHEST:
      result += "sort: farthest";
      break;
  };
  return result;
}

std::string minecraft::Entity::self() {
  return "@s";
};

std::string minecraft::Entity::nearest() {
  return "@n";
};

std::string minecraft::Entity::any() {
  return "@e";
};

std::string minecraft::Entity::Player::any()
{
  return "@a";
};

std::string minecraft::Entity::Player::any(minecraft::Entity::Properties properties)
{
  return std::string("@a[") + properties.unpack() + std::string("]");
};
