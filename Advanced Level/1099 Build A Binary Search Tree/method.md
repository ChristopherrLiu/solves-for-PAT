### 题意
给出一颗二叉树和一系列数据，可以得到一棵确定的二叉搜索树。输出该二叉搜索树的层次遍历

### 思路
首先根据二叉搜索树的性质，它的中序遍历一定是有序的，因此我们可以将输入的数据排序，然后中序遍历给定的二叉树将搜索树还原出来，接着bfs输出层序遍历即可