#include <iostream>
#include <climits>

using namespace std;

// target: it's the value we want to know the minimum coins to make it
// coins and coinsNumber is the array and the lenght of the array of coins
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
                // We evaluate the minimum using the previous or the actual value - the coin + 1
                table[i][j] = min(table[i - 1][j], 1 + table[i][j - coins[i - 1]]);
            // If the coin is greater than the change then we use the previous result
            else table[i][j] = table[i - 1][j];

    return table[coinsNumber][target];
}

int main(void)
{
    // Coins number is always gonna be five, because of the problem
    int n = 5;
    int coins[] = {1, 5, 10, 20, 100};
    int K;
    cout<<"Insert the change needed: ";
    cin>>K;
    cout << "The minimum coin change for the value requested is: " << minimumCoinChange(K, coins, n) << ".\n";
    return 0;
}