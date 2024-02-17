#include <iostream>
#include <string>
#include <cctype>

void ft_transform(
	std::string::iterator it,
	std::string::iterator last,
	std::string::iterator dest,
	int (*func)(int))
{
	while(it != last)
	{
		*dest++ = func(*it++);
	}
}

int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	std::string s;

    if (argc == 1)
    {
        std::cout <<  "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
	else for(int i = 1; i < argc; i++)
	{
		s = argv[i];
		ft_transform(s.begin(), s.end(), s.begin(), toupper);
		std::cout << s;
	}

	std::cout << std::endl;
	return (0);
}

