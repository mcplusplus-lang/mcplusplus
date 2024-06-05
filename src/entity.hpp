#include <string>

namespace minecraft::Entity {
  std::string self();
  std::string nearest();
  std::string any();
  class Properties {
    public:
      enum Sort {
        NEAREST,
        FARTHEST,
      };
      Sort sort;
      std::string unpack();
  };
};

namespace minecraft::Entity::Player {
  std::string nearest();
  std::string any();
  std::string any(minecraft::Entity::Properties properties);
  std::string random();
};
