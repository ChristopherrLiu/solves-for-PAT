### 题意
给出$N$个人互相之间的关注信息，当一个人发微博时，他的粉丝可以转发，问经过不多于$L$次转发之后，有多少人能看到这条微博

### 题意
根据题意建图：被关注的到关注者连边，然后bfs就可以了