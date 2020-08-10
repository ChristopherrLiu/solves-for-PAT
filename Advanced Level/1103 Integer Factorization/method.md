### 题意
将一个正整数$N$划分为$K$个数$P$的次方，其中$N \le 400$，$1 \lt P \le 7$，如果有多个答案，输出$K$个数和最小的，如果还有多个输出字典序最小的

### 思路
这题与[PAT 1068](https://pintia.cn/problem-sets/994805342720868352/problems/994805402305150976)有相似之处，首先预处理出$factor$数组，其中$factor[i][j] = i ^ j$，然后用$dp[i][j][k]$表示用范围在$[1, i]$之间的$k$个因子的$p$次方和正好组成$j$的最大因子和，若为$-1$则表示找不到$k$个因子满足条件。初始化所有元素为$-1$，只使得$dp[i][0][0] = 0$，转移方程为：

$$
dp[i][j][k] = dp[i - 1][j][k], then
$$

$$
dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - l * factor[i][p]][k - l] + l * i) 
$$

$$
if \quad dp[i - 1][j - l * factor[i][p]][k - l] != -1
$$

因为要输出字典序的最大的，所以$i$从小到大遍历，遇到$p[i - 1][j - l * factor[i][p]][k - l] + l * i$与$dp[i][j][k]$相等的情况也进行转移，就可以保证字典序最大；输出因子的方法与PAT 1068相似，不再赘述了