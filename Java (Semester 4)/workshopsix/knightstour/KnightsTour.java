// Name: Chaz-Lee Pierre
// Student No: 123206179
// Course: JAC444
// Purpose: Workshop 6
// KnightsTour.java

package knightstour;

import java.util.ArrayList;

public class KnightsTour {

  private final int N = 8; 																// size of board ( N * N )
  private final int horizontal[] = 														// list of moves knight can make ( x-pos )
	  {2, 1, -1, -2, -2, -1, 1, 2}; 	
  private final int vertical[] = 														// list of moves knight can make ( y-pos )
	  {1, 2, 2, 1, -1, -2, -2, -1}; 	
  private int[][] accessibility =														// accessibility heuristics
		{{2, 3, 4, 4, 4, 4, 3, 2},
		 {3, 4, 6, 6, 6, 6, 4, 3},
		 {4, 6, 8, 8, 8, 8, 6, 4},
		 {4, 6, 8, 8, 8, 8, 6, 4},
		 {4, 6, 8, 8, 8, 8, 6, 4},
		 {4, 6, 8, 8, 8, 8, 6, 4},
		 {3, 4, 6, 6, 6, 6, 4, 3},
		 {2, 3, 4, 4, 4, 4, 3, 2}};

  private int currentRow; 																// x-pos of knight on game board
  private int currentColumn; 															// y-pos of knight on game board
  private int currentMove; 																// move counter
  private int board[][]; 																// representation of game board

  KnightsTour() {
	  this(0,0);
  }
  
  /* this constructor initializes the object to
   * a safe empty state*/
  
  KnightsTour(int row, int column) {
      this.board = new int[N][N];
      for (int x = 0; x < N; x++)														// initialize all board pieces to safe empty state
          for (int y = 0; y < N; y++)
              this.board[x][y] = -1;
      this.board[row][column] = 0; 														// set board position ( row x column ) to be the initial position
      this.currentRow = row; 															// set knight's initial x-pos to row parameter received
      this.currentColumn = column; 														// set knight's initial y-pos to column parameter received
      this.currentMove = 1; 															// move counter
  }

  /* this function checks to see if the position
   * received is within bounds of the chess board
   * and if the board position is not already 
   * occupied */
  
  boolean checkBounds(int x, int y) {
      return ((x >= 0 && x < N) && 														// x must be between 0 - ( N - 1 )
          (y >= 0 && y < N) && 															// y must be between 0 - ( N - 1 )
          (this.board[x][y] == -1)); 													// board position must not be "occupied"
  }

  /* this function calculates the knights moves based 
   * on the received initial position and populates the
   * board with the path the knight took */
  
  public void calculateBoard(int row, int column) {
	  
      for (int r = 0; r < N; r++)														// iterate throughout the entire board ( N * N )
          for (int c = 0; c < N; c++) {
        	  
        	  if (this.currentMove >= N * N)											// if the current move is greater than the max number of
        		  return;																// possible moves, abort mission!
        	  
              ArrayList<Integer> possibleMoves = new ArrayList<>();						// keep a list of possible moves at the current position of the knight
              
              int lowest = N;															// stores lowest accessibility number relative to current position

              for (int moveNumber = 0; moveNumber < N; moveNumber++) {					// calculate lowest accessibility number, store move index in possibleMoves
                  int x = currentRow + horizontal[moveNumber];
                  int y = currentColumn + vertical[moveNumber];
                  if (checkBounds(x, y) && accessibility[x][y] >= 0) {					// check if potential move will be within bounds and accessibility is available
                      if (accessibility[x][y] <= lowest) { 		 
                          if (accessibility[x][y] < lowest) {							// if the accessibility number is lower than the current
                              possibleMoves.clear();									// lowest, clear out all existing potential moves as they
                              lowest = accessibility[x][y];								// aren't relevant any more and replace it with any potential
                          }																// new moves that share the same accessibility number
                          possibleMoves.add(moveNumber);
                      }
                  }
              }

              if (possibleMoves.isEmpty()) {											// if no possible moves were found, abort mission!
            	  return;
              
              } else { 																	// if possible moves were found, continue mission!
            	  
                  int moveNumber = possibleMoves.get((int)(Math.random() % possibleMoves.size())); // choose random move from possible moves list
                  
                  this.currentRow += this.horizontal[moveNumber]; 						// change the knight's row position based on accessibility move
                  this.currentColumn += this.vertical[moveNumber];						// change the knight's column position based on accessibility move
                  
                  this.board[this.currentRow][this.currentColumn] = this.currentMove++;	// store the move counter on the board and increment by one
                  
                  accessibility[this.currentRow][this.currentColumn] = -1;				// make the current accessibility position unavailable
                  
                  for (int i = 0; i < N; i++) {											// adjust the accessibility of all potential moves 
                      int x = this.currentRow + this.horizontal[i];						// around the knight's current position
                      int y = currentColumn + this.vertical[i];
                      if (this.checkBounds(x, y) && this.accessibility[x][y] > 0) {
                          accessibility[x][y]--;
                      }
                  }
              }
          }
  }
  
  /* this function resets the board to a safe empty state
	 * calculates the knights moves based on the received 
	 * initial position and returns updated chess board */
  
  public int[][] getBoard(int row, int column) {
	  for (int x = 0; x < N; x++)														// initialize all board pieces to safe empty state
          for (int y = 0; y < N; y++)
              this.board[x][y] = -1;
      this.board[row][column] = 0; 														// set board position ( row x column ) to be the initial position
      this.currentRow = row; 															// set knight's initial x-pos to row parameter received
      this.currentColumn = column; 														// set knight's initial y-pos to column parameter received
      this.currentMove = 1;																// move counter
      this.calculateBoard(row, column);
      return this.board;
  }
  
}

