### 题意
给定n个城市m条路，每个城市有若干个救援小组，联通城市之间的距离已知。给定起点和终点，求从起点到终点的最短路条数以及最短路上的救援小组数目之和最大

### 思路
求最短路数目，以及所有最短路中点权的最大值，用dijkstra算法即可，在更新最短路的同时维护最短路数目和点权最大