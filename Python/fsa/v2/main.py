#/***************************************************************
#  Jared Bumgardner
#  main.py
#  Project 3
#
#  Main file drives execution of program. Prints to stdout.
#***************************************************************/
import sys
from tkinter import *
from fsa import FSA


def main():
    # Declaration
    input_file = sys.argv[1]

    # Open & Read FSA string from file, then build object.
    print("\n" + input_file)
    contents = open(input_file, "r").read()
    print(contents)
    finite_state_automaton = FSA()
    contents_list = contents.split(";")
    finite_state_automaton.num_states = contents_list.pop(0)
    finite_state_automaton.alphabet = contents_list.pop(0)
    finite_state_automaton.transition_string = contents_list.pop(0)
    finite_state_automaton.start_state = contents_list.pop(0)
    finite_state_automaton.accept_states = contents_list.pop(0)

    # Report if command line provided string is legal or not
    print("\nTesting String: " + sys.argv[2])
    string_to_test = open(sys.argv[2], "r").read()
    if finite_state_automaton.is_legal(string_to_test):
        print(string_to_test + " is a legal string")
    else:
        print(string_to_test + " is an illegal string")

    # Draw FSA in a window
    window = Tk()
    
    window.mainloop()

if __name__ == "__main__":
    main()
