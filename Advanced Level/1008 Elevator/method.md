### 题意
一台电梯，上升一级需要6秒，下降一级需要4秒，停在某一层5秒，问对于给定的request list总共需要多少时间

### 思路
注意一个小坑点，我原来以为如果有连续的同一层需求在，比如3 3 3，那么只需要停一个5秒即可，但其实需要3 * 5 = 15秒