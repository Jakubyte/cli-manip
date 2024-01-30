#include <cstddef>
#include <memory>

#pragma once
class Renderer
{
  public:
    Renderer(const std::size_t);
    void clear();
    void render(const char *, const std::size_t);
    void process_input(char *);

  private:
    std::size_t _buffer_size;
    std::unique_ptr<char> ptr_buffer;
    std::unique_ptr<char> ptr_prev_buffer;
    unsigned char vk_keys[256];
    void swap_buffers(char *, char *, const std::size_t);
    bool buffer_state_changed(const char *, const char *, const std::size_t);
};
