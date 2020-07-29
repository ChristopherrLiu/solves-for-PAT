### 题意
给出一个长为N的字符串，将它的字符按U字型打印出来，要求尽量方正，即设左边竖行、横行、右边竖行的字符数量分别为$n_1, n_2, n_3$，要求满足以下条件：

$$
\begin{aligned}
n_1 & + n_2 + n_3 - 2 = N \\
n_1 & = n_3 = max\{k | k \le n_2\text{ for all } 3 \le n_2 \le N\}
\end{aligned}
$$

### 思路
最优的情况必然是$n_1 = n_2 = n_3$，此时$n_1 = n_2 = n_3 = \frac{N + 2}{3}$，具体来说即：

$$
\begin{aligned}
n_1 = n_3 &= \lfloor \frac{N + 2}{3} \rfloor \\
n_2 &= N + 2 - n1 - 3
\end{aligned}
$$

然后注意输出格式即可