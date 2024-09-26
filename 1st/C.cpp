#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void solve_case(int N, int D, const vector<int>& weights) {
    vector<int> dp(D + 1, INT_MAX);    // 初始化 dp 数组为无穷大
    vector<int> count(D + 1, 0);       // 初始化组合数量数组为 0
    vector<int> last_used(D + 1, -1);  // 记录最后使用的物品
    
    dp[0] = 0;   // 0 重量需要 0 个物品
    count[0] = 1; // 只有一种方式达到 0 重量

    // 动态规划更新
    for (int weight : weights) {
        for (int w = D; w >= weight; --w) {
            if (dp[w - weight] != INT_MAX) {
                if (dp[w - weight] + 1 < dp[w]) {
                    dp[w] = dp[w - weight] + 1;
                    count[w] = count[w - weight]; // 继承组合数量
                    last_used[w] = weight; // 记录最后使用的物品
                } else if (dp[w - weight] + 1 == dp[w]) {
                    count[w] += count[w - weight]; // 更新组合数量
                }
            }
        }
    }

    // 输出结果
    if (dp[D] == INT_MAX) {
        cout << "IMPOSSIBLE\n";
    } else if (count[D] > 1) {
        cout << "AMBIGUOUS\n";
    } else {
        cout << dp[D] << "\n";
        
        // 输出选择的物品
        vector<int> chosen_items;
        for (int w = D; w > 0; w -= last_used[w]) {
            chosen_items.push_back(last_used[w]);
        }
        cout << "Chosen items: ";
        for (int item : chosen_items) {
            cout << item << " ";
        }
        cout << "\n";
    }
}

int main() {
    int T;
    cin >> T; // 读取测试用例数量
    for (int case_num = 1; case_num <= T; ++case_num) {
        int N, D;
        cin >> N >> D; // 读取物品数量和目标重量
        vector<int> weights(N);
        for (int i = 0; i < N; ++i) {
            cin >> weights[i]; // 读取每个物品的重量
        }
        cout << "Case #" << case_num << ": ";
        solve_case(N, D, weights); // 解决当前测试用例
    }
    return 0;
}