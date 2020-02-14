#include "dpbased.h"

#include <iostream>
#include <algorithm>

DPBased::DPBased() {}

/**
 * @brief DPBased::knapsack01_problem
 * Time Complexity: O(W*total_items)
 */
void DPBased::knapsack01_problem(int* pVal, int* pWt, int total_wt, int val_size) {
    int KS[val_size+1][total_wt+1];

    for (int i=0; i<=val_size; ++i) {
        for (int j=0; j<=total_wt; ++j) {

            if (i==0 || j==0) {
                KS[i][j] = 0;
                continue;
            }

            if (j-pWt[i-1] >= 0) {
                KS[i][j] = std::max(KS[i-1][j], KS[i-1][j-pWt[i-1]] + pVal[i-1]);
            } else {
                KS[i][j] = KS[i-1][j];
            }

        }
    }

    std::cout << KS[val_size][total_wt] << std::endl;
}

/**
 * @brief DPBased::lcs_problem
 * Time Complexity: O(str1str2)
 */
void DPBased::lcs_problem(char* str1, char* str2, int str1_size, int str2_size) {
    int LCS[str1_size+1][str2_size+1];
    int max = 0;

    for (int i=0; i<str1_size; ++i) {
        for (int j=0; j<=str2_size; ++j) {

            if (i==0 || j==0) {
                LCS[i][j] = 0;
                continue;
            }

            if (str1[i-1] == str2[j-1]) {
                LCS[i][j] = LCS[i-1][j-1] + 1;
            } else {
                LCS[i][j] = std::max(LCS[i-1][j], LCS[i][j-1]);
            }

            if (LCS[i][j] > max) {
                max = LCS[i][j];
            }

        }
    }

    std::cout << max << std::endl;
}

/**
 * @brief DPBased::sumsetsum_problem
 * Time Complexity: O(arr*sum)
 */
void DPBased::sumsetsum_problem(int* pArr, int sum, int arr_size) {
    bool SS[arr_size+1][sum+1];

    for (int i=0; i<=arr_size; ++i) {
        SS[i][0] = true;
    }

    for (int i=1; i<=sum; ++i) {
        SS[0][i] = false;
    }

    for (int i=1; i<=arr_size; ++i) {
        for (int j=1; j<=sum; ++j) {

            if (j < pArr[i-1]) {
                SS[i][j] = SS[i-1][j];
            } else {
                SS[i][j] = (SS[i-1][j] || SS[i-1][j-pArr[i-1]]);
            }

        }
    }

    std::cout << SS[arr_size][sum] << std::endl;
}
