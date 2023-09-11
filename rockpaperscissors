#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string ComputerPlay()
{
	srand(time(NULL));
	int randomNumber = rand()%3;
	string computerChoice;
	
	if (randomNumber == 1)
	{
		computerChoice = "rock";
	}
	else if (randomNumber == 2)
	{
		computerChoice = "paper";
	}
	else
	{
		computerChoice = "scissor";
	}
	
	return computerChoice;
}

int CheckWin(string computerChoice, string userChoice)
{
	int result;           // Result of 1 means tie, Result of 2 means computer wins, Result of 3 means you win
	
	if (computerChoice == userChoice)
	{
		result = 1;
	}
	else if (computerChoice == "rock")
	{
		if (userChoice == "scissor")
		{
			result = 2;
		}
		else
		{
			result = 3;
		}
	}
	else if (computerChoice == "scissor")
	{
		if (userChoice == "paper")
		{
			result = 2;
		}
		else
		{
			result = 3;
		}
	}
	else
	{
		if (userChoice == "rock")
		{
			result = 2;
		}
		else
		{
			result = 3;
		}
	}
	
	return result;
}
	
	
int main()
{
	int roundNumber = 1;
	string userChoice;
	int userWins = 0;
	int gamesPlayed = 0;
	string computerChoice;
	int winner;
	
	while (userWins<3)
	{
		cout << "Please enter your choice (rock, paper, scissor, or q to quit): ";
		cin >> userChoice;
		
		if (userChoice=="q")
		{
			break;
		}
		
		cout << "Your choice: " << userChoice << endl;
		
		computerChoice = ComputerPlay();
		cout << "Computer choice: " << computerChoice << endl;
		
		winner = CheckWin(computerChoice, userChoice);
		
		if (winner == 2)
		{
			cout << "Result: Computer wins" << endl;
			gamesPlayed++;
		}
		else if (winner == 3)
		{
			cout << "Result: You win!" << endl;
			userWins++;
			gamesPlayed++;
		}
		else
		{
			cout << "Result: Draw" << endl;
		}
		
		cout << "Score: " << userWins << "/" << gamesPlayed << endl;
		
	}
	
	if (userWins > 2)
	{
		cout << "You are the grand champion!" << endl;
	}
	
	cout << "Thanks for playing!" << endl;
	
	return 0;
}
