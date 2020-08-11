### 题意
键盘上有些按键损坏了，每次按下损坏的按键就会连续输入$k$次，现给出一串字符，问有那几个按键可能是坏的，并输出原字符串

### 思路
判断一个按键是否损坏的依据是：每次出现必定连续出现$k$的整数倍次，不满足此条件的就是正常按键。因此我们遍历字符串，对每个字符找出连续出现的次数一旦不是$k$的整数倍就将该字符的标志置$false$，然后再遍历一次字符串记录所有标志为$true$的字符（只记录一次），并将为$true$的字符变为$num / k$次，$num$是连续出现的次数