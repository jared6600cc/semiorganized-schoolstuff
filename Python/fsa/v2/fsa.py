class FSA:
    num_states = 0  # change type: a finite set of states
    alphabet = 0  # a finite alphabet
    transition_string = 0  # describes the transitions of the fsa
    start_state = 0  # an element of Q, the start state
    accept_states = 0  # accept states

    def is_legal(self, test_me):
        table = [[0 for i in range(int(self.num_states))] for j in range(int(self.num_states))]

        in_loop = False
        first_digit = -1
        second_digit = -1
        for c in self.transition_string:
            if c == '(':
                in_loop = True
                continue
            if c == ')':
                in_loop = False
                first_digit = -1
                second_digit = -1
                continue
            if c == ',':
                continue
            if c.isdigit():
                if int(first_digit) < 0:
                    first_digit = c
                else:
                    second_digit = c
            if c.isalpha():
                table[int(first_digit)][int(second_digit)] = c
                table[int(second_digit)][int(first_digit)] = c

        current_state = self.start_state
        for letter in test_me:
            if letter not in self.alphabet:
                return False
            else:
                row = table[int(current_state)]
                for r in row:
                    if r == letter:
                        current_state = row.index(r)
                        break

        if str(current_state) in self.accept_states:
            return True

        return False
