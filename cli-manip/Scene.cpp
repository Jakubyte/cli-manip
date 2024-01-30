#include "Scene.h"
#include <cassert>
#include <iostream>

Scene::Scene()
{
}

void Scene::add(std::string title, std::string scene, std::size_t sz_scene)
{
    no_scenes++;

    SceneInfo *scene_info = new SceneInfo{std::make_unique<std::string>(scene), sz_scene};
    std::pair<std::string, SceneInfo *> p = {title, scene_info};

    _scenes.insert(p);
}

void Scene::remove(std::string index)
{
    _scenes.erase(_scenes.find(index));
}

void Scene::show_scene(std::string index)
{
    // assert(index < no_scenes);
    for (std::string::iterator it = _scenes[index]->scene->begin(); it != _scenes[index]->scene->end(); it++)
    {
        std::cout << *it;
    }
}
