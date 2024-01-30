#include <Windows.h>
#include <cstddef>
#include <iostream>

// https://cplusplus.com/articles/4z18T05o/
void clear()
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

void render(const char *buffer, const std::size_t sz_buffer)
{
    std::cout << buffer;
}

void process_input(char *buffer)
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

void swap_buffers(char *prev, char *current, std::size_t sz_buffer)
{
    for (std::size_t i = 0; i < sz_buffer; i++)
    {
        prev[i] = current[i];
    }
}

bool buffer_state_changed(const char *prev, const char *current, std::size_t sz_buffer)
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

int main()
{
    const std::size_t sz_buffer = 257;
    char buffer[sz_buffer];
    char prev_buffer[sz_buffer];
    buffer[sz_buffer - 1] = '\0';
    prev_buffer[sz_buffer - 1] = '\0';

    // press Left Shift key to end program
    while (!(GetKeyState(VK_ESCAPE) & 0x8000))
    {
        // only clear and render when buffer state changes
        if (buffer_state_changed(prev_buffer, buffer, sz_buffer))
        {
            clear();
            render(buffer, sz_buffer);
            swap_buffers(prev_buffer, buffer, sz_buffer);
        }

        process_input(buffer);
    }

    return 0;
}
