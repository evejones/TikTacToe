/**************************************************
TicTacToe with  human to computer 
and computer to computer mode
(Wargame mode -
 use 'w' to activate when asked for another game)
Released: 2012
Author: Eve Jones
Version: 1.0
Tested: Unix
**************************************************/

#include <stdio.h>
#include <stdlib.h>


/************** global variables **************/

int board[3][3]; // game board

/************** functions **************/

/**
 * Make array to contain board and populate with internal marker for empty positions
 */
void initBoard () {
	
	int i,j;
	
	for(i=0;i<3;i++) {
		for(j=0; j<3;j++) {
			board[i][j] = '*'; // internal marker for empty position
		} //end i
	}//end j

	
}// end initBoard()

/**
 * Display board
 */
void displayBoard() {
	
	char showBoard[3][3];
	int i,j;
	
	//remove internal marker for empty position
	for(i=0;i<3;i++) {
		for(j=0; j<3;j++) {			
			if(board[i][j] == '*') {
				showBoard[i][j] = ' ';
			} else {
				showBoard[i][j] = board[i][j];
			}			
		} //end i
	}//end j
	
	// format and display board
	printf("\n\n\t %c | %c | %c\n",
		   showBoard[0][0], showBoard[0][1], showBoard[0][2]);
	printf("\t---+---+---\n");
	printf(" \t %c | %c | %c\n",
		   showBoard[1][0], showBoard[1][1], showBoard[1][2]);
	printf("\t---+---+---\n");
	printf("\t %c | %c | %c\n\n",
		   showBoard[2][0], showBoard[2][1], showBoard[2][2]);
	
} // end displayBoard()


/**
 * Check for winner
 */

int check () {
	int i;
	char key = '*';
	// Check Rows
	for (i=0; i<3;i++)
		if (board [i][0] == board [i][1] && board [i][0] == board [i] [2] && board [i] [0] != '*')
			key = board [i] [0];
	// check Columns
	for (i=0; i<3;i++)
		if (board [0][i] == board [1][i] && board [0][i] == board [2] [i] && board [0] [i] != '*')
			key = board [0] [i];
	// Check Diagonals
	if (board [0][0] == board [1][1] && board [1][1] == board [2] [2] && board [1] [1] != '*') 
		key = board [1] [1];
	if (board [0][2] == board [1][1] && board [1][1] == board [2] [0] && board [1] [1] != '*') 
		key = board [1][1];
	
	//Declare Winner if any
	
	if (key == 'X') {
		printf("X - Player Wins\n\n");
		return 1;
	}
	
	if (key == 'O') {
		printf("O - Computer Wins\n\n");
		return 1;
	}
	return 0;
	
}

/**
 * Get player input
 */
void input() {
	int x,y;
	printf ("\nEnter X Coordinate - ");
	scanf ("%d",&x);
	printf ("\nEnter Y Coordinate - ");
	scanf ("%d", &y);
	if(x>=0 && x<3 && y>=0 && y<3) {
		
		if(board[x][y] == '*') {
			board[x][y]= 'X';
		} else {
			displayBoard ();
			printf ("\nPosition Occupied. Try again\n");
			input ();		
		}
		
	} else {
		displayBoard ();
		printf ("\nX,Y is out of range. Try again\n");
		input ();		
	}
	
}

/**
 * Computer moves
 *
 * @param char x,o - 'X','O' or 'O','X'
 *
 */
void computer(char x,char o) {
	int i,j;
//------can computer win in one move --------------

	for (i=0; i<3;i++) {	
		
		// Check Rows
		if (board[i][0] ==  o && board[i][1] == o && board[i][2] == '*' ) {
			board[i][2] = o;
			return;
		}
		if (board[i][1] ==  o && board[i][2] == o && board[i][0] == '*' ) {
			board [i][0] = o;
			return;
		} 	
		if (board[i][0] ==  o && board[i][2] == o && board[i][1] == '*' ) {
			board[i][1] = o;
			return;
		}
		
		// check columns
		if (board[0][i] ==  o && board[1][i] ==o && board[2][i] == '*') {
			board[2][i] = o;
			return;
		} 
		if (board[1][i] ==  o && board[2][i] ==o && board[0][i] == '*') {
			board [0][i] = o;
			return;
		} 
		if (board[0][i] ==  o && board[2][i] ==o && board[1][i] == '*') {
			board[1][i] = o;
			return;
		} 

		
	} // end for
	

	// Check Diagonals
	if (board[0][0] ==  o && board[1][1] == o && board[2][2] == '*') {
		board[2][2]=o;
		return;
	} 
 	if (board [1][1] ==  o && board [2][2] == o && board [0][0] == '*') {
		board[0][0]=o;
		return;
	} 
 	if (board [0][0] ==  o && board [2][2] == o && board [1][1] == '*') {
		board[1][1]=o;
		return;
	} 
	if (board [0][2] == o && board [1][1]  == o && board [2][0] == '*') {
		board [2][0]=o;
		return;
	} 
	if (board [0][2] == o && board [2][0]  == o && board [1][1] == '*') {
		board [1][1]=o;
		return;
	} 
	if (board [2][0] == o && board [1][1]  == o && board [0][2] == '*') {
		board [0][2]=o;
		return;
	}
	
		// ---------- check if computer can block X in one move ---------
	
	
	for (i=0; i<3;i++) {

		// Check Rows
		if (board[i][0] == x && board[i][1] == x && board[i][2] == '*' ) {
			board[i][2] = o;
			return;
		} 
		if (board[i][1] == x && board[i][2] == x && board[i][0] == '*' ) {
			board [i][0] = o;
			return;
		}
		if (board[i][0] == x && board[i][2] == x && board[i][1] == '*' ) {
			board[i][1] = o;
			return;
		} 		
		if (board[0][i] == x && board[1][i] ==x && board[2][i] == '*') {
			board[2][i] = o;
			return;
		}		
		if (board[1][i] == x && board[2][i] ==x && board[0][i] == '*') {
			board [0][i] = o;
			return;
		}
		if (board[0][i] == x && board[2][i] ==x && board[1][i] == '*') {
			board[1][i] = o;
			return;
		} 
		
		
	} // end for
	
	
	// Check Diagonals
	if (board[0][0] == x && board[1][1] == x && board[2][2] == '*') {
		board[2][2]=o;
		return;
	} 
	if (board [1][1] == x && board [2][2] == x && board [0][0] == '*') {
		board[0][0]=o;
		return;
	} 
	if (board [0][0] ==x && board [2][2] == x && board [1][1] == '*') {
		board[1][1]=o;
		return;
	} 
	if (board [0][2] ==x && board [1][1]  == x && board [2][0] == '*') {
		board [2][0]=o;
		return;
	} 
	if (board [0][2] == x && board [2][0]  == x && board [1][1] == '*') {
		board [1][1]=o;
		return;
	} 
	if (board [2][0] == x && board [1][1]  == x && board [0][2] == '*') {
		board [0][2]=o;
		return;
	}	
	
	// --------------- defensive moves --------------------


	// try *0 if x and o	
	//  x | *0 |  
	// ---+---+---
 	//    |  0 |  
	// ---+---+---
	//    |  * | x
	
	//  x |   |  
	// ---+---+---
 	//  * | 0 | *0
	// ---+---+---
	//    |   |  x	
	
	//    |   | x 
	// ---+---+---
 	//  * | 0 | *0 
	// ---+---+---
	//  x |   |  	
	
	//    | *0 | x 
	// ---+---+---
 	//    |  0 |  
	// ---+---+---
	//  x |  * |  	
	
	if(board [1][1]  == o) {
	
		for(i=0;i<3;i+=2) {
			
			for(j=0;j<2;j++) {
		
				if (board [0][i] == x && board [2][2-i]  == x && board [j][1-j] == '*' && board [2-j][j+1] == '*') {
					board [j][j+1]=o;
					return;
				}
		
			}// j
			
		}// i

	}
	
	// try 0 if x
	//   |   |  
	// ---+---+---
	//   |   | X
	// ---+---+---
	//   | X | 0
	
	//    |   |  
	// ---+---+---
	//  X |   |  
	// ---+---+---
	//  0 | X |  
	
	
	//  0 | x |  
	// ---+---+---
 	//  X |   |  
	// ---+---+---
	//    |   |  
	
	//   | X | 0
	// ---+---+---
 	//   |   | X
	// ---+---+---
	//   |   |  	
	
	for(i=0;i<3;i+=2) {		
		for(j=0;j<3;j+=2) {			
			if (board [j][1] == x && board [1][i]  == x && board [j][i] == '*') {
				board [j][i]=o;
				return;
			}			
		} //j
		
	} //i
	
	//-----------------------------------
	// first available best position
	
	//center
	if(board [1] [1] == '*') {
		board [1] [1] = o;
		return;
	}	
	
	// corners	
	for (i=0;i<3;i+=2) {
		for (j=0;j<3;j+=2) {
				if (board [i] [j] == '*') {
					board [i] [j] = o;
					return;
				}

			}// j
	} // i
			
	

	// any possible remaining position: 01, 12, 10, 21		
	for (i=0;i<2;i++) {
		for (j=0;j<2;j++) {
			if (board [i+j] [j-i+1] == '*') {
				board [i+j] [j-i+1] = o;
				return;
			}
	
	
}
	}

} // end computer moves


/**
 *
 * Play the game
 *
 * @param char w - war game mode 'w'
 *
 */
void play(char w) {
	int i;
	
	for (i = 0; i<5;i++) {
		
		if(w!='w') input();
		computer('X','O');		
		if(w=='w') {
			computer('O','X');			
		}
		displayBoard();	
		//dont check if too few moves
		if(i>1) {		
			if(check()) return;
		}
		
	} // end for
	
	
	printf ("DRAW\n\n");
	
} // end play

/**
 * Display the board legend ( x,y coordinates )
 *
 */
void showLegend() {
	
	printf("\n\n\t 0,0 | 0,1 | 0,2\n");
	printf("\t-----+-----+-----\n");
	printf(" \t 1,0 | 1,1 | 1,2\n");
	printf("\t-----+-----+-----\n");
	printf("\t 2,0 | 2,1 | 2,2\n\n");
	
}


/**************** main ********************/

int main () {
	char a='a';
	
	printf ("\n\n*** War Games ***\n\nWar, what is it good for ?\n\n");
	
	showLegend();
	
	printf ("\n\nLet`s play!\n\n");
	
	while(1) {
		initBoard();	
		play(a);
		printf ("\n\nAnother round?(y/n)\n\n");
		scanf ("%s",&a);
		if(a != 'y') break;
	}
	
	// war game mode
	if(a == 'w') {
		printf ("\n\n*** War Games Sim Mode ***\n\n");
		while(1) {
			initBoard();	
			play(a);
		}
	}
	
	printf ("\n\nWe shall meet on the battlefield again!\n\n");
	
    return 0;
	
}// end main()
