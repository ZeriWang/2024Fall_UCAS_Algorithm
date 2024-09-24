def solve(N, D, weights, case_num):
    dp = {0: (0, 1)}  # 初始状态，和为0的组合数量为1，物品数量为0

    for weight in weights:
        new_dp = dp.copy()
        for current_sum in dp:
            new_sum = current_sum + weight
            new_count = dp[current_sum][1]
            new_items = dp[current_sum][0] + 1
            if new_sum not in new_dp:
                new_dp[new_sum] = (new_items, new_count)
            else:
                if new_dp[new_sum][0] == new_items:
                    new_dp[new_sum] = (new_items, new_dp[new_sum][1] + new_count)
                elif new_dp[new_sum][0] > new_items:
                    new_dp[new_sum] = (new_items, new_count)
        dp = new_dp

    if D not in dp:
        print(f"Case #{case_num}: IMPOSSIBLE")
    else:
        min_items = dp[D][0]
        count = dp[D][1]
        if count > 1:
            print(f"Case #{case_num}: AMBIGIOUS")
        else:
            print(f"Case #{case_num}: {min_items}")

def main():
    T = int(input())
    for t in range(1, T + 1):
        N, D = map(int, input().split())
        weights = list(map(int, input().split()))
        solve(N, D, weights, t)

if __name__ == "__main__":
    main()