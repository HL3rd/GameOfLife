// lifeboard.cpp
// Horacio Lopez, Section 02
// This is the implementation of the Life class

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstdlib>

#include "lifeboard.h"
using namespace std;

Life::Life()
{
	const int boardSize = 40;
	for (int y = 0; y < boardSize; y++) {
		for (int x = 0; x < boardSize; x++) {
				boardOne[y][x] = false;
		}
	}
}

Life::Life(char a, int x, int y)
{
	char action;
	action = a;
	x_coord = x;
	y_coord = y;
}

Life::~Life()
{ }

int Life::getCellX()
{
	return x_coord;
}

int Life::getCellY()
{
	return y_coord;
}

char Life::getAction()
{
	char action;
	return action;
}

void Life::setX_Coord(int x)
{
	x_coord = x;
}

void Life::setY_Coord(int y)
{
	y_coord = y;
}

void Life::setAction(char a)
{
	char action;
	action = a;
}

// called to print the board
void Life::printBoard()
{
	int boardSize  = 40;
	
	// top boarder
	for (int i = 0; i <= boardSize; i++) {
		cout << "-";
	}

	cout << endl;

	for (int y = 0; y < boardSize; y++) {
		cout << "|";
		for (int x = 0; x < boardSize; x++) {
			if (boardOne[y][x] == true) {
				cout << "X";
			} else {
				cout << " ";
			}
			
		}
		cout << "|" << endl;
	}

	// bottom border
	for (int i = 0; i <= boardSize; i++) {
		cout << "-";
	}
		
	cout << endl;
	
}

// adds cells of designated coordinates
void Life::add()
{
	int n, x, y;
	cout << "Enter the number of cells to activate: ";
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cout << "Enter the coordinates of the cell to add (0 to 39): ";
		cin >> x >> y;
		boardOne[y][x] = true;
		printBoard();
	}
}

void Life::autoAdd(ifstream &ifs)
{
	int x, y;
	ifs >> x;
	ifs >> y;
	boardOne[y][x] = true;
}

// removes cell of designated coordinates
void Life::remove()
{
	int n, x, y;
	cout << "Enter the number of cells to kill: ";
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cout << "Enter the coordinates of the cell to kill (0 to 39): ";
		cin >> x >> y;
		boardOne[y][x] = false;
		printBoard();
	}
}

void Life::next()
{
	const int boardSize = 40;
	bool boardTwo[boardSize][boardSize];

	for(int y = 0; y < boardSize; y++) {
		for(int x = 0; x < boardSize; x++) {
			boardTwo[y][x] = boardOne[y][x];
		}
	}
	

	for (int y = 0; y < boardSize; y++) {
		for (int x = 0; x < boardSize; x++) {
			int alive = 0; // intial count of alive cells always starts at 0
			
			// checking inner-loop is below
			// checks in order: low left, below, low right; left, skip, right; 
			// then upper right, up, and upper right
			for (int c = -1; c < 2; c++) {
				for (int d = -1; d < 2; d++) {
					if (!(c == 0 && d == 0)) {
						if (boardTwo[(y+c+39)%39][(x+d+39)%39]) {
							// loops around to check edges, +39 and mod 39 intentionally
							// added for this purpose
							++alive;
						}
					}
				}
			}

			
			
			if (boardTwo[y][x] == true && (alive == 2 || alive == 3)) {
				boardOne[y][x] = true;
			} else if (alive == 3 && boardTwo[y][x] == false) {
				boardOne[y][x] = true;
			} else {
				boardOne[y][x] = false; // if alive < 2 or alive > 3 then it dies
			}
		}
	}
	
	printBoard();
	usleep(250000);
	system("clear");
}

// option to quit
void Life::quit()
{
	cout << "Thanks for playing The Game of Life!" << endl;
}

ostream& operator << (ostream &os, Life r)
{
	int x_coord, y_coord;

	os << r.x_coord << r.y_coord << endl;
	return os;
}

istream& operator >> (istream &is, Life &r)
{
	int x_coord, y_coord;

	is >> x_coord >> y_coord;

	r.setX_Coord(x_coord);
	r.setY_Coord(y_coord);

	return is;
}
