#include <iostream>
#include <fstream>

using std::ifstream;
using std::cout;
using std::cin;
using std::endl;

// check if current board state is valid, no constraints broken
bool isValid(int b[][9]) {
   for (int R = 0; R < 9; R++) {
      for (int C = 0; C < 9; C++) {

	 // we don't check cells filled with 0, they haven't been filled yet
	 if (b[R][C] > 0) {
	    // check this cell vs its row
	    for (int c = 0; c < 9; c++) 
	       if (c != C) 
		  if (b[R][C] == b[R][c])
		     return false;
	    
	    // vs its column
	    for  (int r = 0; r < 9; r++) 
	       if (r != R)
		  if (b[R][C] == b[r][C])
		     return false;
	    
	    // vs its 3x3 box
	    int startR = R - (R % 3);
	    int startC = C - (C % 3);
	    for (int r = startR; r < (startR + 3); r++) 
	       for (int c = startC; c < (startC + 3); c++) 
		  if ((r != R) && (c != C))
		     if (b[R][C] == b[r][c])
			return false;
	 }
      }
   }
   return true;
}

// takes an index from 0 to 80 and returns the corresponding row for that index
int getRow(int index) {
   return index / 9;
}

// takes an index from 0 to 80 and returns the corresponding col for that index
int getCol(int index) {
   return index % 9;
}

// takes a 2D array of ints and returns the index of the first '0' going from
// left to right, top to bottom
// returns 81 if no '0' is found in indices 0 to 80
int getNextPosition(int b[9][9]) {
   int nextPos = 0;
   for (int r = 0; r < 9; r++) {
      for (int c = 0; c < 9; c++) {
	 if (b[r][c] == 0)
	    return nextPos;	
	 nextPos++;
      }
   }
   return 81; // no positions left to fill
}

// where index is 0 for top left value, and 80 for bot right value
// if index = 81 it is endofboard
// int row = index / maxRowCount
// int col = index % maxRowCount
bool backtrack(int b[9][9]) {
   int pos = getNextPosition(b);
   
   if (pos == 81)
      return true;
   
   for (int x = 1; x <= 9; x++) {
      b[getRow(pos)][getCol(pos)] = x;
      if (isValid(b)) 	 
	 if (backtrack(b))
	    return true;
   }
   b[getRow(pos)][getCol(pos)] = 0; // reset the value to 0   
   return false;
}


// formats output so the 9x9 board is display in sections of 3x3
void print(int b[9][9]) {
   
   for (int r = 0; r < 9; r++) {
      for (int c = 0; c < 9; c++) {
	 if (c == 3 || c == 6)
	    cout << "| ";
	 cout << b[r][c] << " ";
      }
      if (r == 2 || r == 5)
	 cout << "\n---------------------";
      cout << endl;
   }
   cout << endl;
   
}



int main() {

   int board[9][9];   
   ifstream fin;
   fin.open ("input");

   // read in values from input
   if (fin.is_open()) {
      for (int r = 0; r < 9; r++) 
	 for (int c = 0; c < 9; c++) 
	    fin >> board[r][c];	       
      fin.close();
   }
   else {
      cout << "could not open input file\n";
      exit(1); // error with reading input
   }
   
   
   if (backtrack(board)) 
      print(board);   
   else
      cout << "no solution exists\n";
   
   return 0;
}
