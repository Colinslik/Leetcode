class Solution:
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        posx = 0
        posy = 0
        for i in moves:
     #       print(i)
            if i == "U":
                posx += 1
            elif i == "D":
                posx -= 1
            elif i == "R":
                posy += 1
            elif i == "L":
                posy -= 1
            else:
                print("Input error.")
                break
        if posx == 0 and posy ==0:
            return bool(1)
        else:
            return bool(0)
