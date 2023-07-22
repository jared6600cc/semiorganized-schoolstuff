# Jared Bumgardner
# COP4020
# Project 4
# 10 April 2023
import sys


class FSA:
    num_states = 0
    alphabet = 0
    transitions = []
    start_state = 0
    accept_states = 0

    def __init__(self, infile_contents):
        contents_list = infile_contents.split(";")
        self.num_states = contents_list.pop(0)
        self.alphabet = contents_list.pop(0)

        transition_string = contents_list.pop(0).split(",")
        for stmt in transition_string:
            # Remove formatting from transition statement
            stmt = stmt.replace('(', '')
            stmt = stmt.replace(')', '')
            stmt = stmt.split(":")
            stmt[0] = int(stmt[0])
            stmt[1] = int(stmt[1])
            if stmt[2] not in self.alphabet:
                print("ERROR: Transition statement contains invalid char (not in alphabet)")
                raise RuntimeError
            self.transitions.append(stmt)
        self.start_state = contents_list.pop(0)
        self.accept_states = contents_list.pop(0)

    def generate_LISP_File(self):
        out_file = open("part2.lsp", "x")

        # Write demo()
        out_file.write("(defun demo()\n")
        out_file.write("  (setq inFile (open \"theString.txt\" :direction :input))\n")
        out_file.write("  (setq theString (read inFile))\n")
        out_file.write("  (close inFile)\n\n")
        out_file.write("  (setq numStates " + self.num_states + ")\n")
        out_file.write("  (setq alphabet \'(" + self.alphabet.replace(",", " ") + "))\n")
        out_file.write("  (setq startState " + self.start_state + ")\n")
        out_file.write("  (setq currState startState)\n")
        out_file.write("  (setq acceptStates \'(" + self.accept_states.replace(",", " ") + "))\n")
        out_file.write("  (setq transitions \'(")
        for t in self.transitions:
            tString = str(t)
            tString = tString.replace("[", "(")
            tString = tString.replace("]", ")")
            tString = tString.replace(",", " ")
            tString  = tString.replace("'", "")
            out_file.write(tString + "\n					  ")
        out_file.write("))\n")
        out_file.write("  (eval-fsa theString)\n")
        out_file.write("  (values)\n")
        out_file.write(")\n\n")

        # Write eval-fsa()
        out_file.write("\n(defun eval-fsa(s)\n")
        out_file.write("  (setq currChar (car s))\n")
        out_file.write("  (cond\n    ((null s)\n      (report-instring-validity)\n    )\n")
        out_file.write("    (t\n      (if(not(member currChar alphabet))\n")
        out_file.write("        (exit-abnormal \"String contains char not in alphabet\")\n")
        out_file.write("      )\n")
        out_file.write("      (mapcar \'match-transitions transitions)\n")
        out_file.write("      (eval-fsa(cdr s))\n    )\n  )\n)\n\n")

        # Write report-instring-validity()
        out_file.write("\n(defun report-instring-validity()\n")
        out_file.write("  (if(member currState acceptStates)\n")
        out_file.write("    (print \"Input string is VALID\")\n")
        out_file.write("    (print \"Input string is INVALID\")\n  )\n)\n\n")

        # Write exit-abnormal()
        out_file.write("\n(defun exit-abnormal(message)\n")
        out_file.write("  (report-instring-validity)\n")
        out_file.write("  (error message)\n)\n\n")

        # Write match-transitions()
        out_file.write("\n(defun match-transitions(trans)\n")
        out_file.write("  (if (and (eq currState (car trans)) (eq currChar (car(cdr(cdr trans)))))\n")
        out_file.write("    (setq currState (car (cdr trans)))\n")
        out_file.write("  )\n)")


def main():
    # Read FSA string from file
    try:
        with open(sys.argv[1]) as input_file:
            input_file_contents = input_file.read()
    except IOError:
        print("Failed to open input file")
        quit()

    # Build FSA object from file contents
    try:
        finite_state_automaton = FSA(input_file_contents)
    except RuntimeError:
        print("Invalid FSA specified by input file")
        quit()

    # Generate lisp program from FSA object
    try:
        finite_state_automaton.generate_LISP_File()
    except IOError:
        print("Failed to create part2.lsp")
        quit()


if __name__ == "__main__":
    main()