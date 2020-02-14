#include <iostream>

#include <dpbased.h>

using namespace std;

/**
 * @brief
 * list of algorithms divided based upon it nature of problem
 * 1. Dynamic Programming
 *  a. 0/1 Knapsack Problem
 *  b. Longest Common Subsequence
 *  c. Subset Sum
 * @return
 */

int main()
{
    DPBased objDP;

    // 0/1 Knapsack Problem - bottom up approach
    int val[] = {22, 20, 15, 30, 24, 54, 21, 32, 18, 25};
    int wt[] = {4, 2, 3, 5, 5, 6, 9, 7, 8, 10};
    int val_size = sizeof(val)/sizeof(val[0]);
    int total_wt = 30;
    objDP.knapsack01_problem(&val[0], &wt[0], total_wt, val_size);

    // Longest Common Subsequence
    char str1[] = "ABCDGHLQR";
    int str1_size = sizeof(str1)/sizeof(str1[0]);
    char str2[] = "AEDPHR";
    int str2_size = sizeof(str2)/sizeof(str2[0]);
    objDP.lcs_problem(&str1[0], &str2[0], str1_size, str2_size);

    // Subset Sum
    int arr[] = {2, 3, 7, 8};
    int sum = 11;
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    objDP.sumsetsum_problem(&arr[0], sum, arr_size);

    return 0;
}
