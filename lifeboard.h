// lifeboard.h
// Horacio Lopez, Section 02
// This is the header file for the Life class

#include <iostream>
using namespace std;

class Life {
	friend ostream& operator << (ostream &, Life);
	friend istream& operator >> (istream &, Life&);

	public:
		Life();
		Life(char, int, int);
		~Life();
		int getCellX();
		int getCellY();
		char getAction();
		void setX_Coord(int);
		void setY_Coord(int);
		void setAction(char);
		void printBoard(); // prints board whenever needed
		// below are the separate actions activated by chars
		void add(); // this and all others are used in interactive
		void autoAdd(ifstream&); // used for batch
		void remove();
		void next();
		void quit();
	private:
		int x_coord;
		int y_coord;
		bool boardOne[40][40];
		bool boardTwo[40][40];
};
