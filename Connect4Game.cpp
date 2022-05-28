// a5.cpp
//CMPT 130 
// cvattath@sfu.ca
//Chris Vattathichirayil 
// student number: 301328090 
// References: Toby donaldson lecture material and notes for all functions and int main. 
//Kyle Saburao for Directional checks, Jack Thomas for Directional checks , a3 for lowercase, James An for player drop and computermove 



#include <vector> 
#include <iostream> 
#include <string> 
#include <cstdlib>
#include <time.h>


using namespace std; 


//initialize array 
char boardgrid[6][7];


//Making the 2 dimensional array
void makeboard(){ 
	cout << "\t 1  2  3  4  5  6  7\n";
	for(int i = 0; i< 6; i++){
		cout << "\t";
		for (int j = 0; j < 7; j++){
			cout << '[' << boardgrid[i][j] << ']'; 
		}
		cout << '\n'; 
	}
}



// checking horizontal by going through every element in the array
int horizontal_check(){
	for (int row = 0; row < 6; ++row) {
		for (int col = 0; col < 7; ++col) {

			if (col + 3 < 7) {
				if (boardgrid[row][col] == boardgrid[row][col + 1]
					&& boardgrid[row][col] == boardgrid[row][col + 2]
					&& boardgrid[row][col] == boardgrid[row][col + 3]
					) {
					if (boardgrid[row][col] == 'P') {
						return 1;
					} else if (boardgrid[row][col] == 'C') {
						return -1;
					}
				}
			}

		}

	

	}
	
	return 0;
}




//check vertical by going through every element in the array
int vertical_check(){
	for (int row = 0; row < 6; ++row) {
		for (int col = 0; col < 7; ++col) {

			if (row + 3 < 6) {
				if (boardgrid[row][col] == boardgrid[row+ 1][col]
					&& boardgrid[row][col] == boardgrid[row+ 2][col]
					&& boardgrid[row][col] == boardgrid[row+ 3][col]
					) {
					if (boardgrid[row][col] == 'P') {
						return 1;
					} else if (boardgrid[row][col] == 'C') {
						return -1;
					}
				}
			}

		}
	}

	return 0;
}



//check diagonal by going through every element in the array
//diagonal right slant
int diagonal_checkupdown(){
	for (int row = 0; row < 6; ++row) {
		for (int column = 0; column < 7; ++column) {

			if ((row + 3 >=0) && (column - 3 >=0)) {
				if (boardgrid[row][column] == boardgrid[row - 1][column - 1]
					&& boardgrid[row][column] == boardgrid[row - 2][column - 2]
					&& boardgrid[row][column] == boardgrid[row - 3][column - 3]
					) {
					if (boardgrid[row][column] == 'P') {
						return 1;
					} else if (boardgrid[row][column] == 'C') {
						return -1;
					}
				}
			}

		}
	}

	return 0;
}



//check diagonal by going through every element in the array
//diagonal left slant
int diagonal_checkdownup(){
	for (int row = 0; row < 6; ++row) {
		for (int col = 0; col < 7; ++col) {
//row is treated as y 
			if (row >= 3 && col + 3 < 7) {
				if (boardgrid[row][col] == boardgrid[row - 1][col + 1]
					&& boardgrid[row-1][col+1] == boardgrid[row - 2][col + 2]
					&& boardgrid[row-2][col+2] == boardgrid[row - 3][col + 3]
					) {
					if (boardgrid[row][col] == 'P') {
						return 1;
					} else if (boardgrid[row][col] == 'C') {
						return -1;
					}
				}
			}

		}
	}

	return 0;
}




//allowing the player to replace an element within the horizontal (row) within the array and making sure it is a legal move. 
void playerdrop () {
	int input = 0;
	cout << "Pick a column number from 1-7\n";
	
	cin >> input;
	// Error check for invalid column input
	while (input < 1 || input > 7) {
		cout << "Column must be from 1 to 7";
		cin >> input;
	}
	//subtracts one from input to follow how computer need to read it
	input--;
	// if the input is valid it makes sure the lowest row of the column isn't occupied and places it in that column or it goes 
	// up the column until it isnt occupied
	if (input >= 0 || input < 7) {
		for (int r = 6; r >= 0; r--){
			if (boardgrid[r][input]== ' '){
			boardgrid[r][input] = 'P';
			break;
			}
			while(boardgrid[0][input] != ' '){
				cout << "Column full";
				cin >> input; 
				input--;
			}
		}
	}
}

        	


         



// using a random number generator to generate a legal column number and inputting as a move into the array. 
void computermoveEZ(){ 
	
	int j = 0;

    srand(time(NULL));  // set random number seed based on current time

    // random number between 1 and 7 will be chosen 
    int randnum = 1 + rand() % 7;
    
    	j = randnum;
    	for (int r = 6; r >= 0; r--){
			if (boardgrid[r][j]== ' '){
				boardgrid[r][j] = 'C';
				break;
			}
		}  			
}
    		
    
 // turns a word into the lowercase version of that word.   
void lowercase(string& word){
	for(size_t i = 0; i < word.size(); i++) {
		word[i] = tolower(word[i]);
	
	}
 }





int main() { 

//game banner 
cout << "\n\n+...................................+\n"
	 << "|  Welcome to the Connect Four Game |\n" 
	 << "+...................................+\n\n";


// the YESorNO is initialized to true and works like a boolean where if user inputs no at end of game 
//the game ends and if user inputs yes the another round is set up.
string YESorNO;
YESorNO = "yes";
while(YESorNO == "yes"){


//player is given a choice between the easy mode or the hard mode 
	cout << "Choose difficulty (easy or hard):\n";
	string difficulty; 
	cin >> difficulty ; 
	lowercase(difficulty);

	if (difficulty == "easy" || difficulty == "hard"){
			
		for(int i = 0; i< 6; i++){
			for( int j = 0; j <=6; j++){ 
				boardgrid [i][j] = ' ';
			}
		}
		//initialization of integers that will be used as the arguement in a while loop
		int vertstatusplayer = 0;
		int horizstatusplayer = 0;
		int vertstatuscomp = 0;
		int horizstatuscomp = 0;
		int diag1statusplayer = 0;
		int diag2statusplayer = 0; 

		// using the integer variables shown before to execute a round because all statements hold true
		while (vertstatusplayer == 0 && horizstatusplayer == 0 && 
			   vertstatuscomp == 0 && horizstatusplayer == 0 && 
			   diag2statusplayer == 0 && diag1statusplayer == 0) { 

			//makes board and let's player do first move. 
			makeboard();	
			playerdrop();
			cout << "	....PLAYER'S MOVE...\n"; 

			//does Vertical checks and if the vertical check returns -1 or 1 the computer won or player won respectively 
			vertstatusplayer = vertical_check();
			if (vertstatusplayer == -1) {
				makeboard();
				cout << "Computer won\n";
				 
			}
			if (vertstatusplayer == 1){
				makeboard();
				cout << "Player won\n";
				
			}
			

			//does horizontal checks in the same manner as vertical checks
			horizstatusplayer = horizontal_check();
			if (horizstatusplayer == -1) {
				makeboard();
				cout << "Computer won\n";
				
			}
			if (horizstatusplayer == 1){
				makeboard();
				cout << "player won\n";
		
			}
			
			//does diagonal checks in the same manner as horizontal checks 
			diag1statusplayer = diagonal_checkupdown(); 
			if (diag1statusplayer == -1) {
				makeboard();
				cout << "Computer won\n";
				
			}
			if (diag1statusplayer == 1){
				makeboard();
				cout << "player won\n";
			
			}

			//does the second diagonal check using the second diagonal check function
			diag2statusplayer = diagonal_checkdownup(); 
			if (diag2statusplayer == -1){
				makeboard();
				cout << "Computer won on diagonal\n";
				
			}
			if (diag2statusplayer == 1){
				makeboard();
				cout << "player won on diagonal\n";
			
			}
			



			// Makes board again and lets the computer do its move this time. Executing all checks 
			makeboard();
			computermoveEZ();
			cout<< "\n	...COMPUTER'S MOVE..\n";

			vertstatuscomp = vertical_check();
			if (vertstatuscomp == -1) {
				makeboard();
				cout << "Computer won\n";
				
			}
			if (vertstatuscomp == 1){
				makeboard();
				cout << "Player won\n";
			
			}
			


			horizstatuscomp = horizontal_check();
			if (horizstatuscomp == -1) {
				makeboard();
				cout << "Computer won\n";
			
			}
			if (horizstatuscomp == 1){
				makeboard();
				cout << "player won\n";
			
			}
			
			
			
			}

		}

	}

// After going through all player move and computer moves untill someone wins, the player is prompted 
// whether they would like to play again to which they input the condition in which the while loop can execute again.
cout << "Would you like to play again? (YES or NO)"; 
cin >> YESorNO; 
lowercase (YESorNO);
}








