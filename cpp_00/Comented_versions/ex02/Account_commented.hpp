// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once //can only include once. substitutes ifndef...define...endif
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t; //t is an alias and will be used as Account::t

	//these are member static functions that operate on the class itself and not individual objects
	//info about the whole system (not per account)
	//access only static variables.
	//Used to track global stats for all Accounts.
	static int	getNbAccounts( void );
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );
	static void	displayAccountsInfos( void );

	//constructor and destructor
	Account( int initial_deposit );
	~Account( void );

	//functions per instance (account)
	void	makeDeposit( int deposit ); //adds money to account
	bool	makeWithdrawal( int withdrawal ); //removes money from account
	int		checkAmount( void ) const; // checks balance - const means they don't modify the object
	void	displayStatus( void ) const; //shows account info

//only the class has access
private:

	//these are global stats
	//they have to be declared and initialized at the beginning of .cpp
	static int	_nbAccounts; //total nb of accounts
	static int	_totalAmount; //total sum of money in the system
	static int	_totalNbDeposits; //total nb of deposits
	static int	_totalNbWithdrawals; //total nb of withdrawls

	//internal function used to show timestamp of logs
	static void	_displayTimestamp( void );

	//variables per instance
	int				_accountIndex; //account nb
	int				_amount; //amount in the account
	int				_nbDeposits; //nb of deposits in the account
	int				_nbWithdrawals; //nb of withdrawels from the account

	//disables the default constructor - forces users to provide an initial_deposit. Good for safety.

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
