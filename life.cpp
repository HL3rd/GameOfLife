// life.cpp
// Horacio Lopez, Section 02
// This is the main driver for the Life class.

#include <iostream>
#include <unistd.h>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

#include "lifeboard.h"

int main(int argc, char *argv[])
{
	Life board; // creating the life object board
	const int boardSize = 40; // global for easy change

	bool boardOne[boardSize][boardSize]; // set as board of bools for easier X placement
	bool boardTwo[boardSize][boardSize];
	char start;

	char mode;
	
	char choice; // used in vector and while loop

	
	if (argc == 2) {
		ifstream ifs;
		char action; // the char actions to be streamed in
		Life ac; // to become a vector object

		ifs.open(argv[1]); // opens user file name

		if (!ifs) {
			cout << "error, enter a valid file name" << endl;
			return 1;
		}

		while (ifs.peek() != EOF) {
			ifs >> action; // streams in each variable action

			switch (action) {
				case 'a':
					board.autoAdd(ifs);
					break;
				case 'r':
					board.remove();
					break;
				case 'n':
					board.next();
					break;
				case 'q':
					board.quit();
					break;
				case 'p':
					while (action == 'p') {
						board.next();
					}
					break;
				default:
					cout << "Error, unidentified char in textfile." << endl;
					break;

			}
		}
	}

	if (argc == 1) {
		cout << "Welcome to Conway's Game of Life!" << endl;
		while (choice != 'q') {
			cout << "Make a choice to begin: " << endl;
			cout << "-> a: add a new live cell." << endl;
			cout << "-> r: remove a cell." << endl;
			cout << "-> n: advance to the next iteration of the board." << endl;
			cout << "-> q: quit the program." << endl;
			cout << "-> p: play the game continuously." << endl << endl;

			cout << "Your choice: ";
			cin >> choice;

			switch (choice) {
				case 'a':
					board.printBoard();
					board.add();
					break;
				case 'r':
					board.printBoard();
					board.remove();
					break;
				case 'n':
					board.next();
					break;
				case 'q':
					board.quit();
					break;
				case 'p':
					while (choice == 'p') {
						board.next();
					}
					break;
				default:
					cout << "Sorry, enter a valid choice" << endl;
					break;
			}
		}
	}

	if (argc > 2) {
		cout << "Sorry, enter a valid filename." << endl;
		return 1;
	}

}

