积累了一些常用的模板，需要好好记住
1.二分查找：可用于已排序数组查找某个目标，或者查找数组中的峰顶和峰谷等。
2.丑数：可利用一个和规定质因数数目相同的指针，然后利用一个新数组保存生成的丑数，判别每次最小的丑数属于哪个质因数，并将其对应的指针加一
	该指针不代表质因数具体要乘的数，而是保存下来的丑数列表的下标。
3.移除重复字母或者规定的K位数，使得剩余最小或者最大。首先，通过计数确定每个的数目，随后利用与上一个作比较判断删除上一位是否会使结果变好。
	在这一过程中应当注意如果要删除的字符后面是否还有剩余以及当前的字符是否已经在前面存在（对于移除重复字母的题）。
	具体可以看https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters/solution/yi-zhao-chi-bian-li-kou-si-dao-ti-ma-ma-zai-ye-b-6/
4.从数组两边求和得到规定值的最小操作数或者用k步得到最大值。对于这类问题，要全部转化为求中间一段的最长满足条件或者规定步数得到最小值。
	见题5602. 将 x 减到 0 的最小操作数。
