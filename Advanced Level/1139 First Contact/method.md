### 题意
$A,B$两个人之间联系要通过另外两个人$C,D$，其中$A$和$C$是朋友，$C$和$D$是朋友，$D$和$B$是朋友；且$A$和$C$性别相同，$D$和$B$性别相同

### 思路
对每个人记录性别相同的朋友，再用一个map记录两两之间是否是朋友，对于每个询问遍历$A$和$B$的同性朋友，判断他们是不是朋友，记录答案即可