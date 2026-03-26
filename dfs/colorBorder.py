from typing import List

class Solution:
    def colorBorder(self, grid: List[List[int]], row: int, col: int, color: int) -> List[List[int]]:
        
        if grid[row][col] == color:
            return grid

        n, m = len(grid), len(grid[0])
        direc = ((0, 1), (0, -1), (1, 0), (-1, 0))
        vis = [[False] * m for _ in range(n)]
        borders = []
        
        def valid(x, y):
            n, m = len(grid), len(grid[0])
            return 0 <= x < n and 0 <= y < m

        def dfs(i, j):
            vis[i][j] = True
            is_border = False

            for x, y in direc:
                ni, nj = i + x, j + y
                if valid(ni, nj) and not vis[ni][nj] and grid[i][j] == grid[ni][nj]:
                    dfs(ni, nj)

                if not valid(ni, nj) or grid[i][j] != grid[ni][nj]:
                    is_border = True

            if is_border:
                borders.append((i, j))

        dfs(row, col)
        for i, j in borders:
            grid[i][j] = color

        return grid

