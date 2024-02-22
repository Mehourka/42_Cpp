#include <iostream>

#include <ctime>

 
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
    _amount = initial_deposit;
    _totalAmount += _amount;
    _accountIndex = _nbAccounts++;
    _displayTimestamp();
    std::cout 
    << "index:" << _accountIndex << ";"
    << "amount:" << _amount << ";" 
    << "created" << std::endl;
    // std::cout << "Constructor" << std::endl;
}

Account::Account(void)
{

}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout 
    << "index:" << _accountIndex << ";"
    << "amount:" << _amount << ";" 
    << "closed" << std::endl;
    return;
}

int	Account::getNbAccounts( void )
{
    return (Account::_nbAccounts);
}

// int	Account::getTotalAmount( void )
// {
//     return (Account::_totalAmount);
// }

// int	Account::getNbDeposits( void )
// {
//     return (Account::_totalNbDeposits);
// }


// int	Account::getNbWithdrawals( void )
// {
//     return (Account::_totalNbWithdrawals);
// }

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout
    << "accounts:" << _nbAccounts << ";"
    << "total:" << _totalAmount << ";"
    << "deposits:" << _totalNbDeposits << ";"
    << "withdrawals:" << _totalNbWithdrawals << std::endl;
}


void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();

    int p_amount = _amount;
    
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;

    std::cout
    << "index:" << _accountIndex << ";"
    << "p_amount:" << p_amount << ";" 
    << "deposit:" << deposit << ";"
    << "amount:" << _amount << ";" 
    << "nb_deposits:" << _nbDeposits << std::endl;

}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    int p_amount = _amount;
    std::cout
    << "index:" << _accountIndex << ";"
    << "p_amount:" << p_amount << ";";
    
    if (withdrawal > _amount)
    {
        std::cout << "withdrawal:refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;

    std::cout
    << "withdrawal:" << withdrawal << ";"
    << "amount:" << _amount << ";" 
    << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;

}

int		Account::checkAmount( void ) const
{
    _displayTimestamp();
    std::cout << "checkAmount" << std::endl;
    return 0;

}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout
    << "index:" << _accountIndex << ";"
    << "amount:" << _amount << ";" 
    << "deposits:" << _nbDeposits << ";"
    << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
    std::time_t t = std::time(nullptr);
    char mbstr[100];
    std::string format = "%Y%m%d_%H%M%S";

    if (std::strftime(mbstr, sizeof(mbstr), format.data(), std::localtime(&t)))
        std::cout << "[" << mbstr << "] ";

}

