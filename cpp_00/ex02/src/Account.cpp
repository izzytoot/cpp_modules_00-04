/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:03:17 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/01 18:06:51 by icunha-t         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

/*******************************************************************/
/*                      Variable initiation                        */
/*******************************************************************/

//initializing static vars outside class
//vars regarding the whole system
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/*******************************************************************/
/*                    Static public functions                      */
/*******************************************************************/

//implement static functions:
int Account::getNbAccounts(){
	return _nbAccounts;
}

int Account::getTotalAmount(){
	return _totalAmount;
}

int Account::getNbDeposits(){
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(){
	return _totalNbDeposits;
}

void Account::displayAccountsInfos(){
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

/*******************************************************************/
/*                 Constructor and Destructor                      */
/*******************************************************************/

Account:: Account(int initial_deposit): 
	_accountIndex(_nbAccounts++),
	_amount(initial_deposit), 
	_nbDeposits(0), 
	_nbWithdrawals(0){
		_totalAmount += initial_deposit;
		_displayTimestamp();
		std::cout <<" index:" 
				  << _accountIndex 
				  << ";amount:" << initial_deposit 
				  << ";created" << std::endl;
}

Account:: ~Account(){
	_displayTimestamp();
	std::cout <<" index:" 
			  << _accountIndex 
			  << ";amount:" << _amount
			  << ";closed" << std::endl;
}

/*******************************************************************/
/*            Member public functions (per instance)               */
/*******************************************************************/

void Account::makeDeposit(int deposit){
	_totalAmount += deposit; //update total amount
	_totalNbDeposits++; //update total nb of deposits

	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << ";p_amount:" << _amount //before deposit
			  << ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	std::cout <<";amount:" << _amount //after deposit
			  << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal){
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << ";p_amount:" << _amount;
	int diff = _amount - withdrawal;
	if (diff > 0){
		_totalAmount -= withdrawal;
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;

		std::cout << ";withdrawal:" <<withdrawal
				  << ";amount:" << _amount
				  << ";nb_withdrawls:" << _nbWithdrawals << std::endl;
		return true;
	}
	else{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	
}

int Account::checkAmount() const{
	return _amount;
}

void Account::displayStatus() const{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawls:" << _nbWithdrawals << std::endl;
}

/*******************************************************************/
/*                       Static prvate function                     */
/*******************************************************************/

void Account::_displayTimestamp(){
	std::time_t time_in_secs = std::time(NULL);
	std::tm *time = std::localtime(&time_in_secs);

	char buffer[18];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", time);
	std::cout << buffer;
}
