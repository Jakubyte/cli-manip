#include <cstddef>
#include <map>
#include <memory>
#include <string>

#pragma once
class Scene
{
  public:
    struct SceneInfo
    {
        std::unique_ptr<std::string *> scene;
        std::size_t size;
    };

    Scene();
    ~Scene();
    void add(std::string, std::string *, std::size_t);
    void remove(std::string);
    void show_scene(std::string);
    void update_scene(std::string);
    SceneInfo *get_scene(std::string);

  private:
    std::size_t no_scenes;
    std::map<std::string, SceneInfo *> _scenes;
};
