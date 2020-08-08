### 题意
给定一个序列和一个正数$p$，设某个序列最小值为$m$，最大值为$M$，那么满足$M \le m \times p$的序列称为完美序列，问在给定序列中最多可以选出几个数构成完美序列

### 思路
对于一个序列$\{a_1, a_2, a_3, \ldots, a_n\}$，根据$M \le m \times p$的条件，可以得到$m \le a_i \le m \times p$ $(i = 1,2,\ldots, n)$，那么我们可以考虑将序列排序，用双指针法就可以求解