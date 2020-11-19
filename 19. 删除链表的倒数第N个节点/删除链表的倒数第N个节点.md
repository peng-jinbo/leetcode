#### [19. 删除链表的倒数第N个节点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)

利用前后相距为N的两个指针，一起向next移动，当后面指针到达NULL时，前面指针指向的就是要删除的节点，需要注意要用一个指针记录要删除节点的前一个节点，同时如果要删除的节点是头节点时也要单独考虑。

