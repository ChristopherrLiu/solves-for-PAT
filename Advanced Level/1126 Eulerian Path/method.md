### 题意
判断一张图是欧拉图、半欧拉图还是非欧拉图

### 思路
题目中已经给出了判断方法，首先并查集判联通，不连通是非欧拉图；连通图中所有节点度数都为偶数则是欧拉图；有且仅有两个节点度数为奇数其余为偶数则是半欧拉图；均不满足则为非欧拉图