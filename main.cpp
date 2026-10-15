#include <cstddef>
#include <iostream>
#include <string>
#include <utility>

int main()
{
    std::string text;

    // Read an entire line of input, including spaces.
    std::cout << "Enter the text: ";
    std::getline(std::cin, text);

    // Process the text in blocks of four characters.
    for (std::size_t i = 0; i + 2 < text.size(); i += 4)
    {
        // Swap the first and third characters of the current block.
        std::swap(text[i], text[i + 2]);

        // Swap the second and fourth characters when the fourth exists.
        if (i + 3 < text.size())
        {
            std::swap(text[i + 1], text[i + 3]);
        }
    }

    // Print the transformed text.
    std::cout << text << '\n';

    return 0;
}
