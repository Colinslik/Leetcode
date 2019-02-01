class Solution:
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        Top = "QWERTYUIOPqwertyuiop"
        Mid = "ASDFGHJKLasdfghjkl"
        Bot = "ZXCVBNMzxcvbnm"
        checkstr = ""
        output = []
        for i in words:
            wordlist = list(i)
            if Top.find(wordlist[0]) != -1:
                checkstr = Top
            elif Mid.find(wordlist[0]) != -1:
                checkstr = Mid
            elif Bot.find(wordlist[0]) != -1:
                checkstr = Bot
            else:
                continue
            output.append(i)
            for j in wordlist:
     #           print(j,checkstr)
                if checkstr.find(j) == -1:
                    output.pop()
                    break
        return output
