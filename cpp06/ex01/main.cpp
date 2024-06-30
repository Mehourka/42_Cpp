#include "Common.hpp"
#include "Data.hpp"
#include <stdint.h>

uintptr_t serialize(Data* ptr)
{
  return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
  return reinterpret_cast<Data*>(raw);
}

void print_data(Data &data)
{
  std::cout 
    << "Data struct:"\
    << "\nTitle: " << data.title\
    << "\nYear: " << data.year\
    << "\nGenre: " << data.genre\
    <<std::endl;
}

int main(int argc, char **argv) 
{
  Log("Initial Data:");
  Data movie_1 = {};
  movie_1.title = "Star Wars";
  movie_1.year = 1978;
  movie_1.genre = "Science fiction";

  print_data(movie_1);

  Log("\nSerialization ...");
  uintptr_t raw_ptr = serialize(&movie_1);
  std::cout << "raw_ptr : " << raw_ptr << std::endl;

  Log("\nDeserialization ...");
  Data *deserialized_ptr = deserialize(raw_ptr);
  std::cout << "deserialized_ptr : " << deserialized_ptr << std::endl;

  Log("\nRetreived Data:");
  print_data(*deserialized_ptr);
}
