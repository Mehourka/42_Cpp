#include "Common.hpp"
#include "Data.hpp"

uintptr_t serialize(Data* ptr);

Data* deserialize(uintptr_t raw);

void print_data(Data &data)
{
  std::cout 
    << "Data struct:\n"\
    << "Title: " << data.name\
    << "Year: " << data.year\
    << "Genre: " << data.genre\
    <<std::endl;
}

int main(int argc, char **argv) 
{
}
