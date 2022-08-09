#include <iostream>
#include <vector>

class Coins
{
public:
    int coinChange(const std::vector<int>&, int); 
};

int Coins::coinChange(const std::vector<int>& coins, int amount)
{
    if (amount == 0) 
    {
        return 0;
    }
    if (amount < 0) 
    {
        return -1;
    }
    std::vector<int> x((amount + 1), (amount + 1));
    x[0] = 0;
    for (int i = 0; i <= amount; ++i) 
    {
        for (auto j : coins) 
        {
            if ((i - j) >= 0) 
            {
                x[i] = std::min(x[i], 1 + x[i - j]);
            }
        }
    }
    return x[amount] == amount + 1 ? -1 : x[amount];
}

int main()
{
    std::vector<int> coins = {1, 2, 3, 4, 5, 6};
    int amount = 20;
    Coins obj;
    std::cout << obj.coinChange(coins, amount);
}
