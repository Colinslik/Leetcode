class Solution:
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        sum = 0
        for x, val in enumerate(grid):
            for y, val2 in enumerate(val):
 #               print(x,y,val2)
                if val2 == 1:
                    sum += 4
                    if x!=0 and grid[x-1][y] == 1:
                        sum -= 2
                    if y!=0 and grid[x][y-1] == 1:
                        sum -= 2
        return sum
