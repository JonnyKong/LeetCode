class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s:
            return ''
        p = []
        l = s.strip().split(' ')
        l.reverse()
        print(l)
        for temp in l:
            if(temp != ''):
                p.append(temp)
        return ' '.join(p)