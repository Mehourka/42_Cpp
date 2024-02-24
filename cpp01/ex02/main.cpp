#include <iostream>
#include <string>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    (void) str;
    (void) stringPTR;
    (void) stringREF;

    // Address de la string en Mémoir
    std::cout   << "\nAddresse de la string (type): "
                << &str << std::endl;
    std::cout   << "Addresse de la string (literal): "
                << static_cast<const void*>(str.data()) << std::endl;

    // Addresse stockée dans stringPTR
    std::cout   << "\nAddresse de stringPTR: "
                << stringPTR << std::endl;
    
    // Addresse stockée dans stringRef
    std::cout   << "Addresse de stringREF: " 
                << &stringREF << std::endl;
    
    // Valeurs:
    std::cout   << "\nValeur de la string (type): "
                << str << std::endl;
    std::cout   << "Valeur de la string (literal): "
                << str.data() << std::endl;
    std::cout   << "\nValeur de stringPTR: "
                << *stringPTR << std::endl;
    std::cout   << "Valeur de stringREF: " 
                <<  stringREF << std::endl;
}

