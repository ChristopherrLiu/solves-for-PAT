### 题意
有54张扑克牌初始顺序为$S1, S2, \ldots, J1, J2$，给出一个shuffling数组$S[54]$，表示将第$i$张纸牌移动到第$S[i]$个位置，重复这个过程$K$次，输出最后的结果

### 思路
用一个数组$order$保存shuffle之后的顺序，另一个数组$temp$保存当前轮次的结果，每次shuffle时先更新$temp$数组，然后令$order[s[i]] = temp[i]$ $(1 \le i \le n)$，最后按要求输出即可