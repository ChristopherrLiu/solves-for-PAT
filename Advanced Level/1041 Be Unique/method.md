### 题意
给出一组数，范围为$[1,10^4]$，其中的数可能会出现多次，找出第一个中出现一次的数，如果没有输出None

### 思路
由于数的的范围较小，可以开一个$10^4$的数组记录出现频率，然后遍历找出第一个频率为1的数