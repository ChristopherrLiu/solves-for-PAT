### 题意
给出二叉树的后序遍历和中序遍历，求层次遍历

### 题意
首先根据二叉树的后序遍历和中序遍历求出树的结构，方法为后序遍历的末尾元素为当前子树的根节点，在中序遍历中找出该节点根据子树数量进行划分，递归求解；求出子树结构之后再对树进行bfs即可