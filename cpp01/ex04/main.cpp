#include "Common.hpp"

void print_usage()
{
    std::cout << "mySed usage: ./mySed [input_file] [str1] [str2]" << std::endl;
}

bool ft_replace(string &str, const string target, const string rep)
{
    std::size_t pos = str.find(target);
    if (pos == string::npos)
    {
        return false;
    }
   
    str.erase(pos, target.size());
    str.insert(pos, rep);
    return true;
}

void ft_replace_all(string &str, std::size_t start, const string target, const string rep)
{
    std::size_t pos = str.find(target, start);
    if (pos == string::npos)
    {
        return;
    }
   
    str.erase(pos, target.size());
    str.insert(pos, rep);
    std::size_t new_start = pos + rep.size();
    
    ft_replace_all(str, new_start, target, rep);
}

int main(int argc, char **argv)
{

	// Check arguments
    if (argc != 4)
    {
        print_usage();
        return (0);
    }

    string infile_path = argv[1];
    string str1 = argv[2];
    string str2 = argv[3];

    // Open a file  
    std::ifstream infile(infile_path.data());
    if (!infile.is_open())
    {
        std::cout << "Cannot Open input file" << std::endl;
        return (0);
    }

    // Write to outfile
    string outfile_path = infile_path + ".replace";
    std::ofstream outfile(outfile_path.c_str());

	// Read, replace ans write 
    string line;
    while (!infile.eof())
    {
        std::getline(infile, line);
        ft_replace_all(line,0, str1, str2);    
        outfile << line;
    }

    std::cout << "Operation complete: " << outfile_path << " Created" << std::endl;
}
