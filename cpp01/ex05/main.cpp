#include "Harl.hpp"

int main(void)
{
    Harl harl;

    harl.complain("ERROR");
    harl.complain("warning");
    harl.complain("info");
    harl.complain("debug");

    harl.complain("nope");
    harl.complain("");

}
