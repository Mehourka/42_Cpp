#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    (void) argc;
    std::string s;

    if (argc == 1)
    {
        std::cout <<  "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }

    for (int i = 1; argv[i]; i++)
    {
        s = argv[i];
        std::transform(s.begin(), s.end(), s.begin(), std::ptr_fun<int, int>(std::toupper));
        std::cout << s;
    }
    std::cout << std::endl;

    return (0);
}