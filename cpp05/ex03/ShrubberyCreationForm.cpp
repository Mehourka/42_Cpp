#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery creation form", 150, 137)
{
    Log("[ ShrubberyCreationForm ] Default Constructor");
}

ShrubberyCreationForm::ShrubberyCreationForm(const string &target)
    : AForm("Shrubbery creation form", 150, 137)
{
    Log("[ ShrubberyCreationForm ] Default Constructor");
    setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm("Shrubbery creation form", 150, 137)
{
    Log("[ ShrubberyCreationForm ] Copy Constructor");
    *this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    Log("[ ShrubberyCreationForm ] Assigment Operator");
    // Grades and name are const
    this->setTarget(other.getTarget());
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    Log("[ ShrubberyCreationForm ] Default Destructor");
}

void ShrubberyCreationForm::formAction() const
{
    std::string outfile_path = getTarget() + "_shrubbery";

    // Replace filename blanks
    std::string::size_type pos = 0;
    while ((pos = outfile_path.find(' ', pos)) != std::string::npos)
    {
        outfile_path.replace(pos, 1, "_");
        pos++;
    }

    std::ofstream outfile(outfile_path.data());
    if (!outfile.is_open())
    {
        outfile.close();
        throw std::exception();
    }

    outfile << "      ^\n\
     / \\\n\
    /   \\\n\
   /     \\\n\
  /       \\\n\
 /         \\\n\
/___________\\\n\
     |||\n\
     |||\n";

    std::cout << outfile_path << " has been planted 🌲" << std::endl;
}
