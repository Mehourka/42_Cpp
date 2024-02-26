#include "Harl.hpp"

int main(void)
{
    Harl harl;

    harl.complain("error");
    harl.complain("warn");
    harl.complain("info");
    harl.complain("debug");

    harl.complain("nope");
    harl.complain("");

}
