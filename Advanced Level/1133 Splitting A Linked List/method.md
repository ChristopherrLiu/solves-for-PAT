### 题意
将一个链表重新排列，从左到右分为$x \le 0$、$0 \le x \le k$、$k \le x$三部分，每个部分内部按照原顺序排列

### 思路
建立链表，去除脏节点，遍历连别分别用三个vector分别存放三个部分，最后按照顺序输出