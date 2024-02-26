#include "Harl.hpp"

void print_usage(string prog_name)
{
    std::cout
        << "Usage: " << prog_name
        << " [ Error | Warning | Info | Debug ]"
        << std::endl;
}

int main(int argc, char **argv)
{
    string level;

    if (argc != 2)
    {
        print_usage(argv[0]);
        return (0);
    }

    level = argv[1];

    Harl harl(level);
    harl.complain();

    // Harl harl;
    // harl.complain(level);

}
