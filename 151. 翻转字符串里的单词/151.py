class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        list1 = s.split()
        re = ''
        for word in list1:
            re = word + ' ' + re

        return re[:len(re)-1]