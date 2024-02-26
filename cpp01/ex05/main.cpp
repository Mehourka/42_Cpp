#include "Harl.hpp"

int main(void)
{
    Harl harl;

    initHarl();
    harl.SetLevel(Harl::HarlLevelWarning);
    harl.Error("Hey there,");
    harl.Warn("Space Cowbo!");
    harl.Info("... To be continued");
}
