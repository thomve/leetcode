
"""
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
"""
def isMatch(s: str, p: str) -> bool:
    i = j = 0                 # i -> s index, j -> p index
    star = -1                 # last position of '*' in p
    match = 0                 # position in s corresponding to the char after last '*'

    while i < len(s):
        # chars match or '?'
        if j < len(p) and (p[j] == s[i] or p[j] == '?'):
            i += 1
            j += 1
        # see a '*': record it and move pattern forward
        elif j < len(p) and p[j] == '*':
            star = j
            match = i
            j += 1
        # mismatch: if we had a previous '*', expand it by one more char
        elif star != -1:
            j = star + 1
            match += 1
            i = match
        else:
            return False

    # consume trailing '*' in pattern (they can match empty suffix)
    while j < len(p) and p[j] == '*':
        j += 1

    return j == len(p)
