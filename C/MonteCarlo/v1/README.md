# DSA2-Project4
# Monte Carlo

University of West Florida 
Department of Computer Science 
Data Structures and Algorithms II

Probabilistic Algorithms Project

 

Project Description

The goals of this project are to:

implement two types of probabilistic algorithms

observe how expected results compare to observed results
Develop and test a program that implements the bad microchip problem and a simulation based upon probability distributions.

For the first part, the idea is that some batches of micro-chips might not be tested, and the goal is to detect bad batches without testing all the chips in the batch. We will be simulating the process of sampling chips from a collection of batches of chips.

Part 1a: Generate data sets.

Automate creation of what would otherwise be a user-specified number of datasets with a user-specified number of batches, batch size, percentage of the datasets containing bad chips, and percentage of bad chips in a dataset.

When the program runs, it will automatically read four (4) test files titled t1.txt, t2.txt, t3.txt, and t4.txt, containing specs for each run, simulating how the program would work if it were getting these parameters interactively from the user. These configuration files should have the following values written as integers, one per row:

Specification	t1.txt	t2.txt	t3.txt	t4.txt
Number of batches of items	100	100	500	500
Number of items in each batch	2000	2000	1000	1000
Percentage of batches containing bad items	24	10	5	1
Percentage of items that are bad in a bad batch	7	10	5	1
Items sampled from each batch	30	50	50	50
Generate a dataset from the input specification. The dataset will contain an individual file for each batch of items. Save each file in the dataset as ds1.txt,  ds2.txt, ... , dsn.txt. To create an individual file, decide if it has bad items or not. Run a loop for the number of items in the batch. If it is a good batch, just write 'g' to the file (one per line) for the total number of items in the batch. If it is a bad batch, use a random number generator for the input-specified percentage of bad chips: Example - assume the spec is that 10% of chips are bad. Generate datasets by generating random numbers on [0..99] if 0 .. 9 comes up, add a bad chip (write the char 'b' to the file), otherwise, add a good chip to the data set (write a 'g' to the file).

Part 1b: Implement the Monte Carlo algorithm to determine which of the chip batches are bad. It should know how many data sets there are, read them one at a time, sample the appropriate number of items, and report good batch or bad batch. Your output should look like the output below.


Example output:

Simulation 1: 
   Number of batches of items:                   100
   Number of items in each batch                2000
   Percentage of batches containing bad items     24%
   Percentage of items that are bad in a bad set   7%
   Items sampled from each set                    30

Generating data sets:
  Create bad set batch #  4, totBad =  133 total =  2000 badpct =  7
  Create bad set batch #  8, totBad =  145 total =  2000 badpct =  7
  Create bad set batch # 12, totBad =  122 total =  2000 badpct =  7
  Create bad set batch # 16, totBad =  142 total =  2000 badpct =  7
  Create bad set batch # 20, totBad =  160 total =  2000 badpct =  7
  Create bad set batch # 24, totBad =  148 total =  2000 badpct =  7
  Create bad set batch # 28, totBad =  166 total =  2000 badpct =  7
  Create bad set batch # 32, totBad =  137 total =  2000 badpct =  7
  Create bad set batch # 36, totBad =  145 total =  2000 badpct =  7
  Create bad set batch # 40, totBad =  123 total =  2000 badpct =  7
  Create bad set batch # 44, totBad =  123 total =  2000 badpct =  7
  Create bad set batch # 48, totBad =  165 total =  2000 badpct =  7
  Create bad set batch # 52, totBad =  142 total =  2000 badpct =  7
  Create bad set batch # 56, totBad =  117 total =  2000 badpct =  7
  Create bad set batch # 60, totBad =  144 total =  2000 badpct =  7
  Create bad set batch # 64, totBad =  124 total =  2000 badpct =  7
  Create bad set batch # 68, totBad =  152 total =  2000 badpct =  7
  Create bad set batch # 72, totBad =  120 total =  2000 badpct =  7
  Create bad set batch # 76, totBad =  141 total =  2000 badpct =  7
  Create bad set batch # 80, totBad =  158 total =  2000 badpct =  7
  Create bad set batch # 84, totBad =  119 total =  2000 badpct =  7
  Create bad set batch # 88, totBad =  144 total =  2000 badpct =  7
  Create bad set batch # 92, totBad =  145 total =  2000 badpct =  7
  Create bad set batch # 96, totBad =  158 total =  2000 badpct =  7
  Total bad sets = 24

Analyzing Data Sets:
  batch #0 is bad
  batch #4 is bad
  batch #12 is bad
  batch #16 is bad
  batch #20 is bad
  batch #24 is bad
  batch #28 is bad
  batch #32 is bad
  batch #36 is bad
  batch #40 is bad
  batch #44 is bad
  batch #48 is bad
  batch #52 is bad
  batch #60 is bad
  batch #64 is bad
  batch #68 is bad
  batch #72 is bad
  batch #76 is bad
  batch #80 is bad
  batch #84 is bad
  batch #88 is bad
  batch #92 is bad

Base = 0.930000 exponent = 30
P(failure to detect bad item) = 0.113367
P(batch is good) = 0.886633
Percentage of bad batches detected =  91.7%

Simulation 2: 
   Number of batches of items:                   100
   Number of items in each batch                2000
   Percentage of batches containing bad items     10%
   Percentage of items that are bad in a bad set  10%
   Items sampled from each set                    50

. . .



 Part 2: A Monte Carlo Simulation. Implement the process of converting historical data into the probability of occurrence of various outcomes, extracting probability distributions, assigning random number intervals, and running a simulation. Assume we are dealing with bacteria counts in Escambia bay. Our data might be like the following for 100 days of observation:

100
7
0-2000: 15
2000-4000: 25
4000-8000: 20
8000-12000: 15
12000-18000: 10
18000-24000: 10
24000-28000: 5
ml

The goal will be to read the data, compute the probability distribution, carry out a simulation, and predict the expected bacterial reading. Data will be in a file entitled readings.txt. The file readings.txt will first have an integer indicating how many days of data are included (100 in the above example) followed by the number of categories of data (7 in the above example). This second integer will be followed by the textual description of the range of values, a colon (:), and then the number of days on which that observation occurred. After all the count data, units will be indicated (in this case, ml). This part of the program should read these values, simulate a user-specified number of days (see below), and compute and display the expected value from the analytical model.

Output from this data should look like this:

Simulated days: 100
Number of categories: 7
Ranges and occurrences in each range:
0-2000: 15
2000-4000: 25
4000-8000: 20
8000-12000: 15
12000-18000: 10
18000-24000: 10
24000-28000: 5
Units of measure: ml
Analytical model: 8500.0. Expected value is in the 8000-12000/ml range.
Simulation: 8001.5. Expected value is in the 8000-12000ml range.
Note: Since the categories have values that are on a range, we will need to use category mean values for the analytical model and simulation. Here is a small program that will tokenize the strings holding the categories and turn the values into integers:

/*****************************************************
 Program: MonteTokenizer.c
 Programmer: John Coffey
 Purpose: Demonstrate tokenizing the ranges out of
 text data for project 4. 
 *****************************************************/
#include<stdio.h>
#include <string.h>
#define LEN 100
char* getMeasure(char * line, int which)
{
  char *token;
  char *search = "-:";
   token = strtok(line, search);
  if (which==1)
    return token;
  else
  {
    token = strtok(NULL, search);
    return token;
  }
}
int main()
{
  char measure[LEN] = "4000-8000:";
  char temp[LEN];
  strcpy(temp, measure);
  char* val = getMeasure(temp,1);
  printf("after call 1 val = %d\n",atoi(val));
  strcpy(temp, measure); 
  val = getMeasure(temp,2);
  printf("after call 2 val = %d\n",atoi(val));
  return 0;
}
Here is an alternate version custom tokenizer (in case you do not like strtok())

/*****************************************************
 Program: Tokenizer2.c
 Programmer: John Coffey
 Purpose: Demonstrate tokenizing the ranges out of
 text data for project 4. 
 *****************************************************/
#include<stdio.h>
#include <string.h>

#define LEN 100

void getMeasure(char * line, char * first, char * second, char * third)
{
  int pos,p2,p3;
  for(pos = 0;line[pos]!='-'; pos++)
    first[pos] = line[pos];
  first[pos] = '\0';
  p2 = pos+1; pos = 0;
  for(; line[p2]!=':';p2++)
    second[pos++] = line[p2];
  second[pos]='\0';
  p3 = p2+1; pos = 0;
  for(; line[p3]!='\0';p3++)
    third[pos++]=line[p3];
  third[pos]='\0';  
    
}

int main()
{
  char measure[LEN] = "4000-8000:34";
  char t1[LEN];
  char t2[LEN];
  char t3[LEN];
  getMeasure(measure,t1,t2,t3);
  printf("[%s] [%s] [%s] [%s]\n",measure,t1,t2,t3);
  return 0;
}

Inputs and Outputs

When your program runs, it will first automatically generate the data sets for part 1, carry out the simulation, and report results. Then, it will read the readings.txt for part 2. It will use the number of days from the readings.txt as the number of days to simulate, so NO user interaction should be needed. It will also calculate and report the expected value of the analytical model. ALL results will go to the console. Note that different data (different numbers of categories and percents) in readings.txt should work properly. 

Deliverables

You will submit the following for this project: 
1. The functional decomposition for your program.
2. A User's manual that describes how to set up and run your program.
3. Your source code in C.
4. A makefile for the project 

 Submission Requirements:  

1. Compile and run your program one last time before submitting it. Your program must run with gcc in the Linux lab.
2. Place every file in your submission in a SINGLE DIRECTORY named <last name>-<first initial>-p<number>. For instance, I would create directory:  coffey-j-p4  for project 4.
3. zip that FOLDER into a .zip file with the SAME NAME. This means that inside your zip file, you will have exactly one folder (from the example: coffey-j-p3) showing at the top level. Inside that folder will be ALL the files in your project.
4. DO NOT make separate folders for documentation and source files (or anything else) inside the main folder. Having such a setup simply necessitates more navigation time to get where we need to go to grade.
5. Any needed input files should be in the top-level folder along with the source code.
6. MacOS users - remove the _MacOS_ utility folder before you zip up the file. If you cannot, delete it from the archive once the archive is created. It just takes up space and is not needed for anything we do with your submissions.
7. Login to Canvas. Select our course.
9. Go to Assignments and select the appropriate project. Click the Submit button.
10. Upload your zip file. Check to insure that the file was uploaded. ALWAYS give yourself enough time. If you are trying to submit at 11:57pm on your machine, the clock might be off and the dropbox might already be closed.

Please review the policy on ACADEMIC MISCONDUCT. This is an individual assignment.
