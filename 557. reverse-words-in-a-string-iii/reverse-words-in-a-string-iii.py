class Solution:
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        reversestr = ""
        temp = []
        for i in reversed(s):
            if i == ' ':
                reversestr = " " + ''.join(temp) + reversestr
  #              print (reversestr)
                del temp[:]
            else:
                temp.append(i)
        if temp:
            reversestr = ''.join(temp) + reversestr
   #         print (reversestr)
            del temp[:]
        return reversestr
