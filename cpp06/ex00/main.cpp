#include "Converter.hpp"

void check_arguments(int argc, char **argv)
{
	if (!argv)
	{
		std::cerr << "Unexpecter Error!" << std::endl;
		exit(EXIT_FAILURE);
	}

	if (argc != 2)
	{
		std::cerr << "Wrong number of Arguments.\n"
			<< "Usage:\n"
			<< argv[0] << "[literal int|char|double|float]" << std::endl;
		exit(EXIT_FAILURE);
	}
}


int main(int argc, char **argv) 
{
	check_arguments(argc, argv);

	// Converter conv(argv[1]);
	std::string _str = argv[1];
	Converter conv(argv[1]);
	/* conv.print(); */
}
