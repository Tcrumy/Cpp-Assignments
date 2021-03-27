// iostream  will be used to handle I\O operations
#include <iostream>

// cstdlib will be used to generate random numbers in computer_turn function
#include <cstdlib>

// ctime will be used to seed srand in cpmputer_turn function
#include <ctime>

using namespace std;

// Prototype for initialize
void initialize(char[3][3]);

// Prototype for draw_board
void draw_board(char[3][3]);

// Prototype for player turn
void player_turn(char[3][3], char);

// Prototype for computer_turn
void computer_turn(char[3][3], char);

// Prototype for check_winner
bool check_winner(char[3][3], char);

// Prototype for display_overall_winner
void display_overall_winner(int[2][10], int);

// Program begins here
int main()
{
	// Declare and initialize variables needed in main
	const char PLAYER_MARK{ 'X' }, COMPUTER_MARK{ 'O' };
	char the_board[3][3], play_again{};
	int score_board[2][10]{ {0},{0} }, rounds_played{ 0 };


	// Begin a do-while loop that will execute for as long as the player wishes to play the game
	// Turns must be intialized to 0 at the beginning of every game
	// because the program will base whether or not it is the player
	// or computers turn based on this number
	do
	{

		int player_turns{ 0 }, cpu_turns{ 0 };

		// Set every element of the board to an empty space and display the board
		initialize(the_board);
		draw_board(the_board);

		// This loop will continue as long as there is no winner and the score_board is not full, if there are
		// more than 10 rounds, the program is at risk of crashing because there is no space left in the
		// score_board array.
		while (!(check_winner(the_board, PLAYER_MARK) || check_winner(the_board, COMPUTER_MARK)) && player_turns + cpu_turns < 9 && rounds_played < 10)
		{

			// If sum of turns is evenly divizable by 2, then it is the players turn
			// Call and execute the player_turn and draw_board functions, and increment turns by 1
			if ((player_turns + cpu_turns) % 2 == 0)
			{
				player_turn(the_board, PLAYER_MARK);
				draw_board(the_board);
				player_turns++;
			}

			// If sum of turns is not eveny divisable by 2, then it is the computers turn
			// Call and execute the computer_turn and draw_board functions, and increment turns by 1
			else
			{
				computer_turn(the_board, COMPUTER_MARK);
				draw_board(the_board);
				cpu_turns++;
			}
		}
		// While loop ends here

		//If sum of turns is evenly divisable by two, the computer had the last turn before
		// exiting the while loop, and the check_winner function can be used with
		// COMPUTER_MARK as an argument
		if ((player_turns + cpu_turns) % 2 == 0 && check_winner(the_board, COMPUTER_MARK))
		{
			cout << "You were beaten by a computer in " << cpu_turns << " turns." << endl;

			// The score board will be updated to record that player 2, which is the computer
			// has won, and the amount of turns taken to win. rounds_played will be incremented by 1
			score_board[0][rounds_played] = 2;
			score_board[1][rounds_played] = cpu_turns;
			rounds_played++;
		}

		// If sum of turns is not evenly divisable by two, the player had the last turn before
		// exiting the while loop, and the check_winner function can be used with
		// PLAYER_MARK as an argument
		else if ((player_turns + cpu_turns) % 2 != 0 && check_winner(the_board, PLAYER_MARK))
		{
			cout << "\nCongratulations, you won in " << player_turns << " turns" << endl;

			// The score board will be updated to record that player 1, which is the user
			// has won, and the amount of turns taken to win. rounds_played will be incremented by 1
			score_board[0][rounds_played] = 1;
			score_board[1][rounds_played] = player_turns;
			rounds_played++;
		}


		// If the rounds_played has not reached the maximum scoreboard  
		// size, ask the user if they want to play again.
		if (rounds_played < 10)
		{
			cout << "\nDo you want to play again (Y/N): ";
			cin >> play_again;
		}

		// If you have met this condition, the scoreboard is full, 
		// and the game must be stopped to prevent crashing
		else
			play_again = 'n';

	} while (play_again == 'Y' || play_again == 'y');
	// Do-While ends here

	display_overall_winner(score_board, rounds_played);

	return 0;
}




// Definition for initilize function
// intialize will accept an array parameter
// for marker locations and initialized each 
// element to a whitespace character
void initialize(char board[3][3])
{
	// User a nested for loop to set every element of the board array to a whitespace character
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			board[row][column] = ' ';
		}
	}
}


// Definition for the draw_board function
// draw_board will accept an array for marker
// locations and display a tic-tac-tow board
// to the console
void draw_board(char board[3][3])
{
	system("cls");

	// Draw the top of the board
	cout << "|----|----|----|\n";

	// Use a nested for loop to display the rest of the board to the console
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			cout << "|  " << board[row][column] << " ";
		}

		// Display horizontal bars and footer to the console
		cout << "|\n|----|----|----|\n";
	}
}


// Definition for player_turn function
// player_turn will accept an array for marker locations
// which will be updated to reflect the users choice for 
// their row/column selections
void player_turn(char board[3][3], char mark)
{
	bool turn_done = false;

	int row, column;

	// This loop will validate user selection for
	// row/column marker location and terminate once
	// the input is accepted
	while (!turn_done)
	{
		cout << "Enter your move's cell row and column: ";
		cin >> row >> column;

		// Test that the row and column are in range
		if (row >= 0 && row <= 2 && column >= 0 && column <= 2)
		{
			// Test to see if the users choice is occupied
			if (board[row][column] == ' ')
			{
				board[row][column] = mark;

				turn_done = true;
			}
		}
	}
}

// Definition for computer turn
// computer__turn will accept an array for marker locations
// and cpu marke, then it will seed srand and use rand
// to generate a row/column number for the computers
// marker placement then update the board accordingly
void computer_turn(char board[3][3], char cpu_mark)
{
	int row, column;

	srand(time(0));

	bool turn_done = false;

	// This loop will execute until the random numbers
	// generated match an empty space on the board
	while (!turn_done)
	{
		row = rand() % 3;
		column = rand() % 3;

		// Check that the space is not occupied
		// then update the boards row and column
		if (board[row][column] == ' ')
		{
			board[row][column] = cpu_mark;
			turn_done = true;
		}
	}
}



// Definition for check_winner function
// check_winner will accept an array for marker locations
// and either the player mark or computer marl, and
// will return true if a winning pattern is found
bool check_winner(char board[3][3], char mark)
{

	bool result{ false };

	// Test to see if there is a winning pattern
	// and update result if one is found
	if ((board[0][0] == mark && board[0][1] == mark && board[0][2] == mark) ||
		(board[1][0] == mark && board[1][1] == mark && board[1][2] == mark) ||
		(board[2][0] == mark && board[2][1] == mark && board[2][2] == mark) ||
		(board[0][0] == mark && board[1][0] == mark && board[2][0] == mark) ||
		(board[0][1] == mark && board[1][1] == mark && board[2][1] == mark) ||
		(board[0][2] == mark && board[1][2] == mark && board[2][2] == mark) ||
		(board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
		(board[0][2] == mark && board[1][1] == mark && board[2][0] == mark))
	{
		result = true;
	}

	return result;
}

// Definition for display_overall_winner
// display_overall_winner will accept an array for the scoreboard and 
// integer for rounds. Rounds will be used to set a limit on the amount
// of columns that are checked within the scoreboard. Once an overall winner
// is determined, the wins for each player user/cpu will be desplayed
// along with a message stating who the overall winner is, and the 
// minimum number of turns taken during the game
void display_overall_winner(int score_board[2][10], int rounds)
{

	int player_wins{ 0 }, computer_wins{ 0 }, min_player_turns{ 9 }, min_cpu_turns{ 9 };


	for (int column = 0; column < rounds; column++)
	{
		// Test if the winner row matches the user
		if (score_board[0][column] == 1)
		{
			player_wins++;

			// Test if the coresponding turns row is less than the current value in min_player_turns
			if (score_board[1][column] < min_player_turns)
			{
				min_player_turns = score_board[1][column];
			}
		}
		// Test if the winner row matches the computer
		else if (score_board[0][column] == 2)
		{
			computer_wins++;

			// Test if the coresponding turns row is less than the current value in min_cpu_turns
			if (score_board[1][column] < min_cpu_turns)
			{
				min_cpu_turns = score_board[1][column];
			}
		}
	}

	cout << "\nPlayer wins: " << player_wins << "\tComputer wins: " << computer_wins << endl;

	// Test to see if player has more overall wins
	if (min_cpu_turns > min_player_turns)
	{
		cout << "\nPlayer has won with a minimum of " << min_player_turns << " turns." << endl;
	}

	// Test to see if the computer has more overall wins
	else if (min_player_turns > min_cpu_turns)
	{
		cout << "\nComputer has won with a minimum of " << min_cpu_turns << " turns." << endl;
	}

	// The draw condition is met
	else
	{
		cout << "\nThere is no overall winner. This game is a draw." << endl;
	}

}
