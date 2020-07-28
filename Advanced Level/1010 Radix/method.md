### 题意
给定两个数N1、N2以及标志tag和进制radix，其中tag为1表示N1的进制为radix，tag为2则表示N2的进制为radix；求是否存在进制r使得 N1 == N2，存在输出r，不存在输出Impossible

### 思路
二分查找寻找进制r即可，都转换为十进制比较