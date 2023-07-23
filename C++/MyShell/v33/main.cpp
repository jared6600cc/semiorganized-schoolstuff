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
#include <string.h>
#include "commands.hpp"
#include "directory.hpp"


using namespace std;



int main(int argc, const char * argv[]) {
    // Declarations
    string inString;                //variable: holds user input
    Directory C;                    //variable: holds ref. to sessions file structure
    
    //Open input file
    FILE* inFile = fopen("inputCommands.txt", "r");
    
    //Enter loop until exit command is input
    char* line = NULL;
    size_t len = 0;
    while(getline(&line, &len, inFile) != -1){      //bye
        if(strstr(line, "bye") != NULL)
            break;
        else {
            //Take input
            if(strstr(line, "ls"))                  //ls
                ls(C.curr);
            else if(strstr(line, "mkdir"))          //mkdir
                mkdir();
            else if(strstr(line, "cd"))             //cd
                cd();
            else if(strstr(line, "pwd"))            //pwd
                pwd();
            else if(strstr(line, "addf"))           //addf
                addf();
            else if(strstr(line, "mv"))             //mv
                mv();
            else if(strstr(line, "cp"))             //cp
                cp();
            else if(strstr(line, "rm"))             //rm
                rm();
            else if(strstr(line, "whereis"))        //whereis
                whereis();
        }//end else
    }//end while
    
    cout << "Done...\n";
    fclose(inFile);
    return 0;
}
