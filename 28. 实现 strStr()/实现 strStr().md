#### [28. 实现 strStr()](https://leetcode-cn.com/problems/implement-strstr/)

判断haystack的第i位置元素是否和needle的第一个相等，如果相等则继续判断haystack的i到i+m的元素是否和needle的元素一一相等，m是needle的长度，中间有一个不相等则继续找i，如果确实完全匹配则返回当前i。

