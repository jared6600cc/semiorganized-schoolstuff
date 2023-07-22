# Jared Bumgardner
# COP4020
# Project 3
# fsa.py: Reads fsa.txt & a given_string.txt,
#         determines if it's a legal string using the Finite State Automata (FSA),
#         & draws FSA as a diagram
import sys
import math
from tkinter import *
import tkinter as tk
from tkinter import ttk

# Assuming 1080p screen resolution #
screen_width = 1920
screen_height = 1080


class DiagramFrame(ttk.Frame):
    def __init__(self, container):
        super().__init__(container)


class FSADiagram(tk.Tk):
    window_width = 0
    window_height = 0

    def __init__(self):
        super().__init__()

        # Configure window #
        self.title('FSA Diagram')
        window_width = screen_width / 2
        window_height = screen_height
        self.geometry("%dx%d" % (window_width, window_height))
        c = Canvas(self, width=window_width, height=window_height)
        c.pack()

        # Calculate diagram spacing values for states #
        state_diameter = 50
        state_radius = state_diameter / 2
        dist_between_states = state_diameter * 2
        x0 = (window_width / 2) - state_radius
        y0 = state_diameter / 2
        x1 = x0 + state_diameter
        y1 = y0 + state_diameter

        # Draw diagram #
        diagram_states = []
        diagram_state_centers = []
        for s in range(int(finite_state_automaton.num_states)):
            if s == 0:
                # Set up first state
                st = c.create_oval(x0, y0, x1, y1)
                diagram_state_centers.append([x0, y0, x1, y1])
                diagram_states.append(st)
                # Add state label
                c.create_text(x0 + state_radius, y0 + state_radius, text=s)
            else:
                # Update positions
                y0 += state_radius + dist_between_states
                y1 += state_radius + dist_between_states
                st = c.create_oval(x0, y0, x1, y1)
                diagram_state_centers.append([x0, y0, x1, y1])
                diagram_states.append(st)
                # Add state label
                c.create_text(x0 + state_radius, y0 + state_radius, text=s)
            if str(s) in finite_state_automaton.accept_states:
                # Add inner circle for accept states
                c.create_oval(x0 + 5, y0 + 5, x1 - 5, y1 - 5)

        # Draw transitions #
        long_transition_count = 0
        len_line = state_diameter * 2
        for s in range(int(finite_state_automaton.num_states)):
            current_center = diagram_state_centers[s]
            filtered_transitions = (x for x in finite_state_automaton.transitions if x[0] == s)
            for j in filtered_transitions:
                x = current_center[2] - state_radius
                y = current_center[3] - state_radius
                if j[1] == s:
                    # Transition to same state
                    circle_coordinates = [x + state_radius * (math.cos(math.pi / 4)),
                                          y + state_radius * (math.sin(math.pi / 4)),
                                          x + state_diameter - state_radius * (math.cos(math.pi / 2)),
                                          y + state_radius * math.sin(math.pi / 4),
                                          x + state_diameter + state_radius * math.cos(math.pi / 2),
                                          y - state_radius * math.sin(math.pi / 4),
                                          x + state_radius * math.cos(math.pi / 4),
                                          y - state_radius * math.sin(math.pi / 4)]
                    c.create_line(circle_coordinates, smooth=True, arrow=LAST)
                    label_text = ''.join((map(str, j[2])))
                    c.create_text(circle_coordinates[4], circle_coordinates[5], text=label_text)
                elif j[1] == s + 1:
                    # Transition straight down
                    line_coordinates = [current_center[0] + state_radius, current_center[1] + state_diameter,
                                        current_center[2] - state_radius,
                                        current_center[3] + dist_between_states - state_radius]
                    c.create_line(line_coordinates, arrow=tk.LAST)
                    label_y = line_coordinates[1] + (dist_between_states / 2)
                    label_text = ''.join((map(str, j[2])))
                    c.create_text(line_coordinates[0] + 10, label_y, text=label_text)
                elif j[1] - j[0] > 1 or j[1] - j[0] < -1:
                    # Transition elsewhere
                    long_transition_count += 1
                    x = x - state_radius * math.sin(math.pi / 2)
                    y = y - state_radius * math.cos(math.pi / 2)
                    long_line_coordinates = [x, y, x - (30 * long_transition_count), y,
                                             x - (30 * long_transition_count),
                                             y + ((state_radius + len_line) * (j[1] - j[0])), x,
                                             y + ((state_radius + len_line) * (j[1] - j[0]))]
                    c.create_line(long_line_coordinates, arrow=LAST)
                    label_y = long_line_coordinates[5] + dist_between_states
                    label_text = ''.join((map(str, j[2])))
                    c.create_text(long_line_coordinates[2] - 10, label_y, text=label_text)


class FSA:
    num_states = 0
    alphabet = 0
    transitions = []

    def __init__(self, infile_contents):
        # Populate obj fields #
        file_contents_list = infile_contents.split(";")
        self.num_states = file_contents_list.pop(0)
        self.alphabet = file_contents_list.pop(0)

        transition_string = file_contents_list.pop(0).split(",")
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
        self.start_state = file_contents_list.pop(0)
        self.accept_states = file_contents_list.pop(0)

    def report_legality(self, given_string):
        # Report to console if given_string is legal or not #
        if self.is_legal(given_string):
            print(given_string + " is a legal string")
        else:
            print(given_string + " is an illegal string")

    def is_legal(self, string):
        result = True
        curr_state = self.start_state
        # Push string through FSA #
        for ch in string:
            # Check if character is not in alphabet
            if ch not in self.alphabet:
                print("ERROR: " + ch + " in string is not in the FSAs alphabet")
                print(string + " is an illegal string")
                raise RuntimeError
            else:
                # Character is in alphabet; check for available moves
                # Do nothing if a transition is impossible
                for transition in self.transitions:
                    if transition[0] == int(curr_state):
                        if transition[2] == ch:
                            curr_state = transition[1]
                            break
        # Check if string ends in an accept state #
        if str(curr_state) in self.accept_states:
            result = True
        else:
            result = False

        return result


if __name__ == '__main__':
    # Read FSA string from file #
    try:
        with open(sys.argv[1]) as input_file:
            input_file_contents = input_file.read()
    except IOError:
        print("Failed to open input file")
        quit()

    # Build object based on given fsa.txt #
    try:
        finite_state_automaton = FSA(input_file_contents)
    except RuntimeError:
        print("Invalid FSA specified by input file")
        quit()

    # Determine legality of given string #
    try:
        string_to_test = open(sys.argv[2], "r").read()
        finite_state_automaton.report_legality(string_to_test)
    except RuntimeError:
        exit()

    # Draw FSA diagram & display to screen #
    diagram = FSADiagram()
    frame = DiagramFrame(diagram)
    diagram.mainloop()
