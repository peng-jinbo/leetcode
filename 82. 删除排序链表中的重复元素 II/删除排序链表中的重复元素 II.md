#### [82. 删除排序链表中的重复元素 II](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/)

使用双指针来判断是否相等，不相等则更新第一个指针，并将结果与其连接，相等则找到下一个不相等的数出现，然后更新第一个指针和第二个指针再重复以上判断。注意末尾的处理。

