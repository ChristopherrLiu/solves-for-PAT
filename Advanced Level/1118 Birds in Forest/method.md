### 题意
有$N$张照片，每张照片有$K$只鸟，同一张照片上的鸟一定是在一颗树上的，求最多可能有几颗树以及小鸟的数量，并判断任意两只鸟是否在同一棵树上

### 思路
典型的并查集题目，初始化$father$数组为$-1$, 对同一张照片中的所有小鸟做合并操作，最后统计$father[i] == -1$的数目即为树的数量，统计小鸟的数量可以用hash表