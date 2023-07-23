//
//  main.cpp
//  Project1
//
//  Created by Jared Bumgardner on 9/19/19.
//  Copyright © 2019 Jared Bumgardner. All rights reserved.
//



#include <iostream>
#include <string>
#include <fstream>
#include "commands.hpp"
using namespace std;



int main(int argc, const char * argv[]) {
    // Declarations
    string inString;                //variable: holds user input
    
    //Open input file
    ifstream inFile;
    string STRING;
    inFile.open("inputCommands.txt");
    if(inFile.is_open()){
        cout << "File found!\n";
    } else { cout << "File not found...\n";}
    
    // Enter loop until exit command is input
    while(inString != "bye"){
        //Take input
        std :: cout << "$ ";
        cin >> inString;
        
        //Execute input                                         //TODO: Switch? Automated cmd population?
        if(inString == "ls")
            ls();
        else if(inString == "mkdir")
            mkdir();
        else if(inString == "cd")
            cd();
        else if(inString == "pwd")
            pwd();
        else if(inString == "addf")
            addf();
        else if(inString == "mv")
            mv();
        else if(inString == "cp")
            cp();
        else if(inString == "rm")
            rm();
        else if(inString == "whereis")
            whereis();
    }
    return 0;
}
