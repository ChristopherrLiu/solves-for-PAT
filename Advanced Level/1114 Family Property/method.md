### 题意
给出$N$个人的家庭成员和他所拥有的房产面积，求每个家庭的房产面积和已经有用房产的人数

### 思路
建树，求连通块，dfs维护一下信息就好，注意数组要开大一点，因为实际点的数量可能远远比$N$大