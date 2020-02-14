#ifndef DPBASED_H
#define DPBASED_H

/**
 * @brief Dynamic Programming Based
 * 1. 0/1 Knapsack Problem
 * 2. Longest Common Subsequence
 * 3. Sumset Sum
 */

class DPBased
{
public:
    DPBased();
    void knapsack01_problem(int*, int*, int, int);
    void lcs_problem(char*, char*, int, int);
    void sumsetsum_problem(int*, int, int);
};

#endif // DPBASED_H
