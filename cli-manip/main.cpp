#include "Scene.h"

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

    char scene[] = {' ', ' ', ' ', '-', '-', '-', '=', '=',  '=', 'J', 'a', 'k', 'u', 'b', '=', '=',
                    '=', '-', '-', '-', ' ', ' ', ' ', '\n', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                    ' ', ' ', 'm', 'e', 'n', 'u', ' ', ' ',  ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'};

    Scene menus;
    menus.add("Main", scene, 48);
    menus.show_scene("Main");
    return 0;
}
