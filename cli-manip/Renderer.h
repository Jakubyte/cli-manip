#include <cstddef>
#include <memory>

#include "Scene.h"

#pragma once
class Renderer
{
  public:
    Renderer(Scene *, std::size_t);
    ~Renderer();
    void clear();
    void draw(std::string, bool = true);
    // void render();
    // void process_input(char *);

  private:
    std::unique_ptr<Scene> _scene_holder;
    std::string current_scene;
    std::size_t _ticks;
    // void swap_buffers(char *, char *, const std::size_t);
    // bool buffer_state_changed(const char *, const char *, const std::size_t);
};
