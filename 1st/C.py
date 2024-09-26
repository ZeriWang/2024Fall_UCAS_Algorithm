def solve_case(N, D, weights):
    dp = [float('inf')] * (D + 1)
    count = [0] * (D + 1)
    
    dp[0] = 0  # 0 weight requires 0 items
    count[0] = 1  # 1 way to pick nothing to make 0 weight

    for weight in weights:
        for w in range(D, weight - 1, -1):
            if dp[w - weight] + 1 < dp[w]:
                dp[w] = dp[w - weight] + 1
                count[w] = count[w - weight]
            elif dp[w - weight] + 1 == dp[w]:
                count[w] += count[w - weight]

    if dp[D] == float('inf'):
        return "IMPOSSIBLE"
    elif count[D] > 1:
        return "AMBIGUOUS"
    else:
        return dp[D]

def main():
    T = int(input())
    for case_num in range(1, T + 1):
        N, D = map(int, input().split())
        weights = list(map(int, input().split()))
        result = solve_case(N, D, weights)
        print(f"Case #{case_num}: {result}")