### 题意
判断给出的点集是否是最大团

### 思路
按照题目给出的条件对点集两两循环判断是否相邻，如果有不相邻的就不是团；如果是团再遍历点集中任意一个点的相邻点，判断它是否与剩下的点相邻，如果找到任何一个满足条件的则证明不是最大团