/* Jared Bumgardner
 * Project 7
 * 2 Dec.
 * DalekGameFrame: GUI file.
 */

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class DalekGameFrame extends JFrame {
	// Instance Fields
	private DaleksGame game;
	JButton left, right, teleport;
	JTextArea display;
	boolean gameOverPrinted = false;

	public DalekGameFrame() {		
		super("1D Doctor");
		this.game = new DaleksGame();
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setResizable(false);
		this.setLayout(new FlowLayout());
		display = new JTextArea(15, 40);
		display.append(game.getWorld());
		JScrollPane scrollDisplay = new JScrollPane(display, JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);

		left = new JButton("Left");
		left.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent eL) {
				game.moveDoctor(-1);
				if(game.doctorCaught() && !gameOverPrinted) {
					gameOver();
					gameOverPrinted = true;
				} else {
					game.moveDaleks();
				}
				if(game.doctorCaught() && !gameOverPrinted) {
					gameOver();
				} else {
					display.append(game.getWorld());
					display.setCaretPosition(display.getDocument().getLength());
				}
			}
		});
		right = new JButton("Right");
		right.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent eR) {
				game.moveDoctor(1);
				if(game.doctorCaught() && !gameOverPrinted) {
					gameOver();
				} else {
					game.moveDaleks();
				}
				if(game.doctorCaught() && !gameOverPrinted) {
					gameOver();
				} else {
					display.append(game.getWorld());
					display.setCaretPosition(display.getDocument().getLength());
				}
			}
		});

		teleport = new JButton("Teleport");
		teleport.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent eT) {
				game.moveDoctor();
				if(game.doctorCaught() && !gameOverPrinted) {
					gameOver();
				} else {
					try {
						game.dalekPositions.add(game.safeRandomPosition());
						game.moveDaleks();
					} catch (Exception e) {
						System.out.println(e.getMessage());
					}
				}
				if(game.doctorCaught() && !gameOverPrinted) {
					gameOver();
				} else {
					display.append(game.getWorld());
					display.setCaretPosition(display.getDocument().getLength());
				}
				
			}
		});
		JPanel buttons = new JPanel();
		buttons.setLayout(new FlowLayout());
		buttons.add(left);
		buttons.add(right);
		buttons.add(teleport);

		this.add(buttons, 0);
		this.add(scrollDisplay, 1);
		this.pack();		

		this.setVisible(true);	
	}

	public void gameOver() {
		//Block out buttons
		left.setEnabled(false);
		right.setEnabled(false);
		teleport.setEnabled(false);
		//Final summary
		display.append("Doctor caught!\n");
		display.append("Number of moves: " + game.numMoves);
		display.setEditable(false);
	}
}
