#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.
// Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.
// For example, "AACCGGTT" --> "AACCGGTA" is one mutation. 
// There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.
// Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.
// Note that the starting point is assumed to be valid, so it might not be included in the bank.
class Mutation
{
public:
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (!bankSet.count(endGene))
            return -1;

        vector<char> genes = {'A', 'C', 'G', 'T'};
        queue<pair<string, int>> q;
        q.push({startGene, 0});

        while (!q.empty())
        {
            auto [current, mutations] = q.front();
            q.pop();

            if (current == endGene)
                return mutations;

            for (int i = 0; i < 8; i++)
            {
                char original = current[i];
                for (char g : genes)
                {
                    if (g == original)
                        continue;

                    current[i] = g;
                    if (bankSet.count(current))
                    {
                        q.push({current, mutations + 1});
                        bankSet.erase(current);
                    }
                }
                current[i] = original;
            }
        }

        return -1;
    }
};

int main()
{
    Mutation m;
    string startGene = "AACCGGTT";
    string endGene = "AACCGGTA";
    vector<string> bank = {"AACCGGTA"};

    cout << "Minimum mutations: " << m.minMutation(startGene, endGene, bank) << endl;
    return 0;
}