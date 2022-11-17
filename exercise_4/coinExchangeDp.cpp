#include <iostream>
#include <climits>

using namespace std;

int minimumCoinChange(int target, int *coins, int coinsNumber)
{
    int table[coinsNumber + 1][target + 1];

    for (int i = 0; i <= coinsNumber; i++)
        table[i][0] = 0;

    for (int j = 1; j <= target; j++)
        table[0][j] = INT_MAX;

    for (int i = 1; i <= coinsNumber; i++)
        for (int j = 1; j <= target; j++)
            if (coins[i - 1] <= j)
                table[i][j] = min(table[i - 1][j], 1 + table[i][j - coins[i - 1]]);
            else table[i][j] = table[i - 1][j];

    return table[coinsNumber][target];
}

int main(void)
{
    int n = 5;
    int coins[] = {1, 5, 10, 20, 100};
    int K;
    cout<<"Insert the change needed: ";
    cin>>K;
    cout << "The minimum coin change for the value requested is: " << minimumCoinChange(K, coins, n) << ".\n";
    return 0;
}