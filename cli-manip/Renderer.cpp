#include "Renderer.h"
#include <Windows.h>
#include <iostream>

Renderer::Renderer(const std::size_t sz_buffer) : _buffer_size(sz_buffer)
{
    for (std::size_t i = 0; i < 256; i++)
    {
        vk_keys[i] = 0;
    }
}

// https://cplusplus.com/articles/4z18T05o/
void Renderer::clear()
{
    HANDLE hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;
    COORD homeCoords = {0, 0};

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE)
        return;

    /* Get the number of cells in the current buffer */
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi))
        return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    /* Fill the entire buffer with spaces */
    if (!FillConsoleOutputCharacter(hStdOut, (TCHAR)' ', cellCount, homeCoords, &count))
        return;

    /* Fill the entire buffer with the current colors and attributes */
    if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count))
        return;

    /* Move the cursor home */
    SetConsoleCursorPosition(hStdOut, homeCoords);
}

void Renderer::render(const char *buffer, const std::size_t sz_buffer)
{
    std::cout << buffer;
}

void Renderer::process_input(char *buffer)
{
    for (std::size_t i = 0; i < 256; i++)
    {
        buffer[i] = '0';

        if (GetKeyState(i) & 0x8000)
        {
            buffer[i] = '1';
        }
    }
}

void Renderer::swap_buffers(char *prev, char *current, const std::size_t sz_buffer)
{
    for (std::size_t i = 0; i < sz_buffer; i++)
    {
        prev[i] = current[i];
    }
}

bool Renderer::buffer_state_changed(const char *prev, const char *current, const std::size_t sz_buffer)
{
    for (std::size_t i = 0; i < sz_buffer; i++)
    {
        if (prev[i] != current[i])
        {
            return true;
        }
    }

    return false;
}
