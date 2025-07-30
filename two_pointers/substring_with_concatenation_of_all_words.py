"""
You are given a string s and an array of strings words. All the strings of words are of the same length.
A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.
For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.
"""
from typing import List
from collections import defaultdict

def findSubstring(s: str, words: List[str]) -> List[int]:
        ans = []
        if not s or not words:
            return ans

        word_count = defaultdict(int)
        for word in words:
            word_count[word] += 1

        word_length = len(words[0])
        total_words = len(words)
        total_length = word_length * total_words

        for i in range(word_length):
            visited = defaultdict(int)
            count = 0
            j = i

            for k in range(i, len(s) - word_length + 1, word_length):
                substr = s[k:k + word_length]

                if substr not in word_count:
                    visited.clear()
                    count = 0
                    j = k + word_length
                else:
                    visited[substr] += 1
                    count += 1

                    while visited[substr] > word_count[substr]:
                        left_word = s[j:j + word_length]
                        visited[left_word] -= 1
                        count -= 1
                        j += word_length

                    if count == total_words:
                        ans.append(j)

        return ans