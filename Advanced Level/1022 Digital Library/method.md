### 题意
给出n本书的信息，包括id、书名、作者、关键词、出版社、出版年份，查询时给出任意一项属性输出所有符合条件书籍的id

### 思路
用map维护属性与书籍id的关系即可，对于每一个映射关系，使用set维护id，即可去重也可排序