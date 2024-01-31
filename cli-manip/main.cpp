#include "Renderer.h"
#include <Windows.h>

int main()
{
    // const std::size_t sz_buffer = 257;
    // char buffer[sz_buffer];
    // char prev_buffer[sz_buffer];
    // buffer[sz_buffer - 1] = '\0';
    // prev_buffer[sz_buffer - 1] = '\0';

    //// press Left Shift key to end program
    // while (!(GetKeyState(VK_ESCAPE) & 0x8000))
    //{
    //     // only clear and render when buffer state changes
    //     if (buffer_state_changed(prev_buffer, buffer, sz_buffer))
    //     {
    //         clear();
    //         render(buffer, sz_buffer);
    //         swap_buffers(prev_buffer, buffer, sz_buffer);
    //     }

    //    process_input(buffer);
    //}

    std::string main = "___---===+++ JAKUB +++===---___\n          ~~~Main Menu~~~          \n";
    std::string sub = "+------------+\n|  sub menu  |\n+------------+";

    Scene scene_holder;
    scene_holder.add("Main", &main, 69);
    scene_holder.add("Sub", &sub, 45);

    Renderer renderer(&scene_holder, 60);
    renderer.draw("Main", true);

    //// press Left Shift key to end program
    while (!(GetKeyState(VK_ESCAPE) & 0x8000))
    {
        if (GetKeyState(VK_LEFT) & 0x8000)
        {
            renderer.draw("Main");
        }

        if (GetKeyState(VK_RIGHT) & 0x8000)
        {
            renderer.draw("Sub");
        }

        if (GetKeyState(VK_ADD) & 0x8000)
        {
            main = "___---===+++ JAKUB +++===---___\n          ~~~Changed :D~~~          \n";
        }
    }

    return 0;
}
