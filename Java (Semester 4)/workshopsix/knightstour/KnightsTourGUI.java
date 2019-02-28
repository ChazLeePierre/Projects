// Name: Chaz-Lee Pierre
// Student No: 123206179
// Course: JAC444
// Purpose: Workshop 6
// KnightsTourGUI.java

package knightstour;

import java.awt.Color;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class KnightsTourGUI extends JFrame {
	private final int N = 8; 															// size of board ( N * N )
	
	private KnightsTour knightstour;													// KnightsTour object
	
	// knight positioning
	private int currentRow;
	private int currentCol;
	private int lastMove;
	private int lastRow;
	private int lastCol;
	
	private JLabel[] horizontalLabel;													// horizontal labels of the chess board
	private JLabel[] verticalLabel;														// vertical labels of the chess board
	private JButton boardGUI[][];														// view model of the chess board
	private int board[][];																// data model of the chess board
	
	private JTextArea console;															// displays knight information
	
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					KnightsTourGUI gui = new KnightsTourGUI();
					gui.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
	
	KnightsTourGUI() {
		
		// initialize JFrame
		this.setTitle("Knights Tour [JAC444] Chaz-Lee Pierre");
		this.setBounds(300, 300, 750, 880);
		this.setResizable(false);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.getContentPane().setLayout(null);
		
		// initialize board
		knightstour = new KnightsTour();																
		board = knightstour.getBoard(currentRow, currentCol);							// initializes the board with the starting coordinates [0][0]
		
		// initialize GUI components array
		boardGUI = new JButton[N][N];
		horizontalLabel = new JLabel[N];
		verticalLabel = new JLabel[N];
		
		calculateLastMove();															// calculates the last move and records the position where it occurred
		
		for (int x = 0; x < N; x++) {
			
			// initialize each horizontal label 
			horizontalLabel[x] = new JLabel(Integer.toString(x + 1));
			horizontalLabel[x].setBounds(70 + (x * 90), 10, 20, 20);					// each iteration, offset the x position from the last label
			horizontalLabel[x].setFont(new Font("SansSerif", Font.PLAIN, 20));
			this.getContentPane().add(horizontalLabel[x]);
			
            for (int y = 0; y < N; y++) {
            	
            	// initialize each vertical label (only on the first iteration)
            	if (x == 0) {
            		verticalLabel[x] = new JLabel(Integer.toString(y + 1));
        			verticalLabel[x].setBounds(10, 65 + (y * 90), 20, 20);				// each iteration, offset the y position from the last label
        			verticalLabel[x].setFont(new Font("SansSerif", Font.PLAIN, 20));
        			this.getContentPane().add(verticalLabel[x]);
            	}
            	
            	// initialize each JButton (aka board piece)
            	boardGUI[x][y] = new JButton();
            	boardGUI[x][y].addActionListener(new BoardPositionListener(x,y)); 		// onClick event, update board to reflect new starting position
            	updateBoardButton(x, y);
            	
            	this.getContentPane().add(boardGUI[x][y]);
            }
		}
		
		// initialize console
		console = new JTextArea(knightInformation());
		console.setFont(new Font("SansSerif", Font.PLAIN, 20));
		console.setWrapStyleWord(true);
		console.setLineWrap(true); 
		console.setBackground(Color.LIGHT_GRAY);
		console.setEditable(false);
		console.setBounds(0, 750, 750, 100);
		this.getContentPane().add(console);
	}
	
	/* this function calculates the last move
	 * and records the position where it occurred */
	
	private void calculateLastMove() {
		lastMove = -1;
    	for (int x = 0; x < N; x++)
			for (int y = 0; y < N; y++) {
				if (board[x][y] > lastMove) {
					lastMove = board[x][y];
					lastRow = x;
					lastCol = y;
				}
			}
	}
	
	/* this function updates the current board position
	 * to reflect changes made to the data model of the
	 * chess board */
	
	private void updateBoardButton(int x, int y) {
		boardGUI[x][y].setBounds(30 + (x * 90), 30 + (y * 90), 90, 90); 				// each iteration, offset the x & y position from the last button
    	boardGUI[x][y].setText(
        		(board[x][y] != -1) ? 													// make null values more readable (-1 becomes '-')
        		Integer.toString(board[x][y] + 1) : "-"
        	);
    	boardGUI[x][y].setBackground(null);												// reset button color in case previous board piece was coloured
    	if (board[x][y] == 0) {
    		boardGUI[x][y].setBackground(Color.GREEN);									// turn starting position GREEN
    	} else if (board[x][y] == -1) {
    		boardGUI[x][y].setBackground(Color.RED);									// turn inaccessible positions RED
    	} else if (board[x][y] == lastMove) {
    		boardGUI[x][y].setBackground(Color.YELLOW);									// turn last knight position YELLOW
    	}
    	boardGUI[x][y].setFont(new Font("SansSerif", Font.BOLD, 40));
    	boardGUI[x][y].setHorizontalAlignment(JTextField.CENTER);
	}
	
	/* this function returns knight 
	 * information for display purposes*/
	
	private String knightInformation() {
		return "The knight started his travel at position [" + (currentRow + 1) + "][" + (currentCol + 1) + "]\n" +
	    		"Did he complete his path? " + ((lastMove == (N*N) - 1) ? "Yes, with ease" : "Unfortunately, not this time") + ".\n" +
	    		"The knight's final position is position [" + (lastRow + 1) + "][" + (lastCol + 1) + "] on move [" + (lastMove + 1) + "].\n";
	}
	
	
	/* this listener updates the current board position
	 * to reflect changes made to the data model of the
	 * chess board */
	
	private class BoardPositionListener implements ActionListener {
	    private int row;
	    private int col;
	    
	    public BoardPositionListener(int row, int col) {
	        this.row = row;
	        this.col = col;
	    }

	    public void actionPerformed(ActionEvent e) {
	    	// get new board
	    	KnightsTour k = new KnightsTour();
	    	currentRow = this.row;
	    	currentCol = this.col;
	    	board = k.getBoard(currentRow, currentCol);
	    	
	    	calculateLastMove();
	    	for (int x = 0; x < N; x++)
	            for (int y = 0; y < N; y++) {
	            	updateBoardButton(x, y);
	            }
	    	console.setText(knightInformation());
	    }
	}

}
