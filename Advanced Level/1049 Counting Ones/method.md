### 题意
给一个正数$N$，求在$[1,N]$的范围内所有整数的所有数位中数字$1$的出现次数

### 思路
数位DP，设$dp[i][j]$代表的是从$1$到以$j$开头的$i$位数中$1$的个数，比如$dp[2][1]$表示的就是$[1,10]$中$1$的个数，根据定义显然有：

$$
dp[1][k] = 1, 1 \le k \le 9
$$

转移公式为：

$$
dp[i][j] = \begin{cases}
\sum_{k = 1}^{i- 1}dp[k][9] + 1, j = 1 \\
10^{i-1} - 1 + dp[i][j - 1] + \sum_{k = 1}^{i- 1}dp[k][9], j = 2\\
dp[i][j - 1] + \sum_{k = 1}^{i- 1}dp[k][9], j \gt 2
\end{cases}
$$

对于最后的答案来说，若$N = a_{n} * 10^n + \ldots + a_{0}*10^0$，则有：

$$
ans = \sum_{i = 0}^n (dp[i + 1][a_i] + tag_i * N \% 10^{i + 1})
$$
$$
tag_i = 1\quad only\quad when\quad a_i = 1\quad else\quad tag_i = 0
$$