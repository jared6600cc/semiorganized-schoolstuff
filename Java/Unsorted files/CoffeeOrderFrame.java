/* Jared Bumgardner
 * COP3022: Lab 6
 * 18 Nov 2022
 * CoffeeOrderFrame.java : Contains JFrame for taking coffee orders
 */

import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.BorderFactory;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JRadioButton;


public class CoffeeOrderFrame extends JFrame implements ActionListener {
	// Frame Variables
	JPanel jp1, jp2;
	JRadioButton regularB, decafB;
	JButton orderB;
	ButtonGroup buttonGroup;
	JCheckBox milkB, sugarB, sweetenerB;

	public CoffeeOrderFrame() {
		super();
		setTitle("Lab6: Bumgardner");
		setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
		setLayout(new GridLayout(1, 2));
		// Panel 1
		jp1 = new JPanel();
		regularB = new JRadioButton("Regular", true);
		regularB.addActionListener(this);
		decafB = new JRadioButton("Decaf");
		decafB.addActionListener(this);
		orderB = new JButton("Order");
		orderB.addActionListener(this);
		jp1.add(regularB);
		jp1.add(decafB);
		jp1.add(orderB);
		buttonGroup = new ButtonGroup();
		buttonGroup.add(regularB);
		buttonGroup.add(decafB);
		buttonGroup.add(orderB);
		this.add(jp1);

		// Panel 2
		jp2 = new JPanel();
		jp2.setLayout(new GridLayout(1, 3));
		jp2.setBorder(BorderFactory.createTitledBorder(BorderFactory.createEtchedBorder(), "Additions"));
		milkB = new JCheckBox("Milk");
		milkB.addActionListener(this);
		sugarB = new JCheckBox("Sugar");
		sugarB.addActionListener(this);
		sweetenerB = new JCheckBox("Sweetener");
		sweetenerB.addActionListener(this);
		jp2.add(milkB);
		jp2.add(sugarB);
		jp2.add(sweetenerB);
		this.add(jp2);

		// Finalize frame
		this.pack();
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if(e.getActionCommand().equals("Order")) {
			System.out.println("===== Order Confirmation =====");
			if(regularB.isSelected()) {System.out.println("Regular");}
			if(decafB.isSelected()) {System.out.println("Decaf");}
			if(milkB.isSelected()) {System.out.println("Milk");}
			if(sugarB.isSelected()) {System.out.println("Sugar");}
			if(sweetenerB.isSelected()) {System.out.println("Sweetener");}
			System.out.println("==============================");
		}
	}
}
