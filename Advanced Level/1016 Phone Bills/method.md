### 题意
给出一些用户的电话账单和按小时记的通话费用，要求按用户姓名的字典序输出月账单，账单包括每次通话的开始时间和结束时间，总通话时间，费用，以及该月的总费用

### 思路
模拟题，首先对所有的通话记录按姓名->开始时间的优先级排序，然后遍历，对能配对的通话记录标记信息，最后输出即可