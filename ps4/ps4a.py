# Problem Set 4A
# Name: Tung Do
# Collaborators:
# Time Spent: x:xx

def get_permutations(sequence):
    '''
    Enumerate all permutations of a given string
    sequence (string): an arbitrary string to permute. Assume that it is a non-empty string.
    You MUST use recursion for this part. Non-recursive solutions will not be accepted.
    Returns: a list of all permutations of sequence
    Example:
    >>> get_permutations('abc')
    ['abc', 'acb', 'bac', 'bca', 'cab', 'cba']

    Note: depending on your implementation, you may return the permutations in a different order than what is listed here.
    '''
    # if len(sequence) == 1:
        # return sequence
    # else:
        # first_char = sequence[0]
        # sequence = sequence.replace(first_char, "")
        # return get_permutations(sequence) + first_char

    sequence = list(sequence)
    out = []
    if len(sequence) == 1:
        return sequence
    else:
        for i,let in enumerate(sequence):
            for perm in get_permutations(sequence[:i] + sequence[i+1:]):
                out += [let + perm]
    return out

if __name__ == '__main__':
   #EXAMPLE
   example_input = 'aeiou'
   print('Input:', example_input)
   # print('Expected Output:', ['abc', 'acb', 'bac', 'bca', 'cab', 'cba'])
   print('Actual Output:', get_permutations(example_input))

#    # Put three example test cases here (for your sanity, limit your inputs to be three characters or fewer as you will have n! permutations for a sequence of length n)


