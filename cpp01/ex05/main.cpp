#include "Harl.hpp"

int main(void)
{
    Harl harl;

    // Valid Commands
    harl.complain("ERROR");
    harl.complain("warning");
    harl.complain("info");
    harl.complain("debug");

    // Invalid Commands
    harl.complain("nope");
    harl.complain("");

}
