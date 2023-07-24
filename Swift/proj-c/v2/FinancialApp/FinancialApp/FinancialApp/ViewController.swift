//
//  ViewController.swift
//  FinancialApp
//
//  Created by Jared Bumgardner on 3/30/17.
//  Copyright © 2017 Jared Bumgardner. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    
    //Mortgage variables
    var balance: Double = 0.0
    var interest: Double = 0.0
    var period: Double = 0.0
    
    
    
    //Future Value variables
    var deposit: Double = 0.0
    var interestFV: Double = 0.0
    var periodFV: Double = 0.0
    
    
    //===============MORTGAGE UI & ACTIONS===============//
    //-----Balance text field
    //-----& Action
    @IBOutlet weak var balanceTextField : UITextField!
    @IBAction func balanceTextChanged(sender: UITextField){
        //Balance was edited
        if let text = sender.text, let _balance  = Double(text){
            self.balance = _balance
            print("\(balance)")
        }
     }
    
    
    
    //-----Interest text field
    //-----& Action
    @IBOutlet weak var interestTextField : UITextField!
    @IBAction func interestTextChanged(sender: UITextField){
        //Interest was edited
        if let text = sender.text, let _interest = Double(text){
            self.interest = _interest
            print("\(interest)")
        }
    }
    
    
    
    //-----Period text field
    //-----& Action
    @IBOutlet weak var periodTextField : UITextField!
    @IBAction func periodTextChanged(sender: UITextField){
        //Period was edited
        if let text = sender.text, let _period = Double(text){
            self.period = _period
            print("\(period)")
        }
    }
    
    
    
    //-----Label to display final mortgage
    @IBOutlet weak var mortgageResultLabel : UILabel!
    
    
    
    //===============FUTURE VALUE UI & ACTIONS===============//
    //-----Deposit text field
    //-----& Action
    @IBOutlet weak var depositTextField : UITextField!
    @IBAction func depositTextChanged(sender: UITextField){
        //Deposit was edited
        if let text = sender.text, let _deposit = Double(text){
            self.deposit = _deposit
            print("\(deposit)")
        }
    }
    
    
    
    //-----Interestfv text field
    //-----& Action
    @IBOutlet weak var interestFVTextField : UITextField!
    @IBAction func interestFVTextChanged(sender: UITextField){
        //Interest was edited
        if let text = sender.text, let _interestFV = Double(text){
            self.interestFV = _interestFV
        }
    }
    
    
    
    //-----Periodfv text field
    //-----& Action
    @IBOutlet weak var periodFVTextField : UITextField!
    @IBAction func periodFVTextChanged(sender: UITextField){
        //Period was edited
        if let text = sender.text, let _periodFV = Double(text){
            self.periodFV = _periodFV
            print("\(periodFV)")
        }
    }
    
    
    
    //===============UTILITY FUNCTIONS===============//
    override func viewDidLoad() {
        super.viewDidLoad()
    }

    
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    
    
    //-----Mortgage submit button
    @IBAction func submitButtonPressed(sender: UIButton){
        
        //Determine mortgage
        interest = (interest/100)/12
        let first = interest * pow(1+interest, period)
        let second = pow(1 + interest, period) - 1
        var mortgageResult = balance * (first/second)
        mortgageResult = round(100 * mortgageResult)/100
        
        //Display value
        print("\(mortgageResult)")
        self.mortgageResultLabel.text = "\(mortgageResult)"
    }
    
    
    
    //-----Future value submit button
    @IBAction func submitFVButtonPressed(sender: UIButton){
        
        //Calculate Future Value
        var fvResult = deposit * pow(1 + interestFV, periodFV)
        fvResult = round(100 * fvResult)/100
        
        //Display value
        self.futureValueResultLabel.text = "\(fvResult)"
    }
    
    
    
    //-----Future value label
    @IBOutlet weak var futureValueResultLabel: UILabel!
}
