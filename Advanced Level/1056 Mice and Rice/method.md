### 题意
$N_P$个人有各自的分数，按照一定的顺序参加比赛，比赛规则为：每次按顺序取$N_G$个人比较，分数最高的进入下一轮，这一轮剩下的所有人都获得相同的名次；重复这个过程直到决出最终的胜者，输出所有人的名次

### 思路
递归处理，每次递归子过程的参数为$m$表示当前参与比赛的人，按组选出获胜的人存入数组$nextm$，若$nextm.size()  == 1$则递归中止，反之$nextm$作为参数进入下次循环，另设$r$作为名次计数器，每次递归退出时更新$r = nextm.size()$