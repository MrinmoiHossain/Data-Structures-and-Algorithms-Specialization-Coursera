def get_change(m):
    coins = [1, 3, 4]
    min_num_coins = [0] * (m + 1)
    
    for i in range(1, m + 1):
        min_num_coins[i] = 2**32
        for j in range(0, 3):
            if i >= coins[j]:
                num_coins = min_num_coins[i - coins[j]] + 1
                min_num_coins[i] = min(min_num_coins[i], num_coins)
    
    return min_num_coins[m]

if __name__ == '__main__':
    m = int(input())
    print(get_change(m))
