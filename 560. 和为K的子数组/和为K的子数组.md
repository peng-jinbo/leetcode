#### [560. 和为K的子数组](https://leetcode-cn.com/problems/subarray-sum-equals-k/)

考虑前缀和解法会超时，可以利用哈希表保存前缀和的数目，然后每次算的一个新前缀之后就去找新前缀减去目标值在哈希表中的数目。

