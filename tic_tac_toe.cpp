#include <iostream>
#include <cctype>
//declare functions
bool promptContinue();
//prompts user whether to continue program; returns true if yes, false otherwise
void outputBoard(char board[]);
//outputs a tic-tac-toe board stored in param board[] to the screen.
void playerTurn(char board[], char symbol);
//precondition: board is an array serving as a tic-tac-toe board, symbol is the player's symbol (i.e. X or O)
//postcondition: prompts player to pick a spot to place their symbol, and prompts them again if spot is invalid
bool checkWin(char board[], char symbol);
//precondition: board is an array serving as a tic-tac-toe board, symbol is the player's symbol (i.e. X or O)
//postcondition: checks if player corresponding to symbol has won the game; returns true if yes, false if no.
bool checkTie(char board[]);
//precondition: a winner has been checked for previously by checkWin(char board[], char symbol)
//postcondition: checks whether the board has any open spaces left; returns false if so, true if board is filled with symbols

//main
int main()
{
	//begin main program loop
	do
	{
		//initialize variables
		char tictactoe[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
		bool p1win = false, p2win = false, tie = false;
		//greet user
		std::cout << "Welcome to computer tic-tac-toe! Let's begin.\n";
		//run game while winner is undetermined
		while (!(p1win) && !(p2win) && !(tie))
		{
			//player 1's turn
			outputBoard(tictactoe);
			playerTurn(tictactoe, 'X');
			p1win = checkWin(tictactoe, 'X');
			tie = checkTie(tictactoe); //check for ties
			if (!(p1win) && !(tie)) //ensure game state is valid for player 2's turn
			{
				//player 2's turn
				outputBoard(tictactoe);
				playerTurn(tictactoe, 'O');
				p2win = checkWin(tictactoe, 'O');
			}
		}
		outputBoard(tictactoe);
		//output results
		if (p1win)
			std::cout << "Player X wins!\n";
		else if (p2win)
			std::cout << "Player O wins!\n";
		else //if tied
			std::cout << "It was a tie!\n";
	} while (promptContinue()); //prompt user to continue
	std::cout << "Goodbye!\n";
	return 0;
}

//define functions
//uses iostream
void outputBoard(char board[])
{
	int lineCounter = 0;
	for (int i = 0; i < 9; i++)
	{
		std::cout << board[i] << "  ";
		lineCounter++;
		if (lineCounter >= 3)
		{
			std::cout << std::endl;
			lineCounter = 0;
		}
	}
	return;
}
//uses iostream and cctype
void playerTurn(char board[], char symbol)
{
	using namespace std;
	int position;
	bool legalMove = false;
	cout << "it is player " << symbol << "'s turn\n";
	while (!(legalMove))
	{
		cout << "Enter the position you would like to place your next piece and hit enter.\n";
		cin >> position;
		if (position >= 0 && position <= 9 && isdigit(board[position - 1]))
		{
			board[position - 1] = symbol;
			return;
		}
		else //if illegal move
			cout << "That spot is already taken! pick another.\n";
	}
	return;
}
bool checkWin(char board[], char symbol)
{
	//check horizontals
	for (int i = 0; i < 9; i += 3)
	{
		if (board[i] == symbol && board[i + 1] == symbol && board[i + 2] == symbol)
			return true;
	}
	//check verticals
	for (int i = 0; i < 3; i++)
	{
		if (board[i] == symbol && board[i + 3] == symbol && board[i + 6] == symbol)
			return true;
	}
	//check diagonals
	if (board[0] == symbol && board[4] == symbol && board[8] == symbol)
		return true;
	else if (board[2] == symbol && board[4] == symbol && board[6] == symbol)
		return true;
	else //no winning combos
		return false;
}
bool checkTie(char board[])
{
	for (int i = 0; i < 9; i++)
	{
		if (isdigit(board[i]))
			return false;
	}
	return true;
}
//uses iostream
bool promptContinue()
{
	using namespace std;
	char prompt;
	cout << "Would you like to continue? Y to continue, N to end\n";
	cin >> prompt;
	if (prompt == 'Y' || prompt == 'y')
		return true;
	else
		return false;
}
