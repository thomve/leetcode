def subsets(nums):
    result = []
    def backtrack(start, path):
        print("path", path)
        result.append(path[:])
        for i in range(start, len(nums)):
            path.append(nums[i])
            backtrack(i + 1, path)
            path.pop()
    backtrack(0, [])
    return result

print(subsets([1, 2, 3]))



def totalNQueens(n: int) -> int:
    result = 0
    colSet = set()
    posDiag = set()
    negDiag = set()
    def dfs(r):
        nonlocal result
        if r == n:
            result += 1
            return
        for c in range(n):
            if c in colSet or r+c in negDiag or r-c in posDiag:
                continue
            colSet.add(c)
            posDiag.add(r-c)
            negDiag.add(r+c)
            dfs(r+1)
            colSet.remove(c)
            posDiag.remove(r-c)
            negDiag.remove(r+c)
    dfs(0)
    return result

print(totalNQueens(4))


from typing import List, Tuple

Board = List[List[str]]  # '1'..'9' or '.'

def solve_sudoku(board: Board) -> bool:
    """
    Modifies board in place to a solved Sudoku. Returns True if solved.
    """

    rows = [set() for _ in range(9)]
    cols = [set() for _ in range(9)]
    boxes = [set() for _ in range(9)]

    def box_id(r, c): return (r // 3) * 3 + (c // 3)

    # initialize sets
    for r in range(9):
        for c in range(9):
            v = board[r][c]
            if v != '.':
                rows[r].add(v); cols[c].add(v); boxes[box_id(r, c)].add(v)

    def candidates(r, c):
        return set('123456789') - rows[r] - cols[c] - boxes[box_id(r, c)]

    def find_most_constrained_cell() -> Tuple[int, int, List[str]] | None:
        best = None
        best_opts = None
        for r in range(9):
            for c in range(9):
                if board[r][c] == '.':
                    opts = list(candidates(r, c))
                    if best is None or len(opts) < len(best_opts):
                        best = (r, c); best_opts = opts
                        if len(best_opts) == 1:
                            return (r, c, best_opts)  # early return
        return None if best is None else (*best, best_opts)

    def backtrack() -> bool:
        nxt = find_most_constrained_cell()
        if nxt is None:
            return True  # solved
        r, c, opts = nxt
        for v in opts:
            board[r][c] = v
            rows[r].add(v); cols[c].add(v); boxes[box_id(r, c)].add(v)
            if backtrack():
                return True
            rows[r].remove(v); cols[c].remove(v); boxes[box_id(r, c)].remove(v)
            board[r][c] = '.'
        return False

    return backtrack()


puzzle = [
    list("53..7...."),
    list("6..195..."),
    list(".98....6."),
    list("8...6...3"),
    list("4..8.3..1"),
    list("7...2...6"),
    list(".6....28."),
    list("...419..5"),
    list("....8..79"),
]
solved = solve_sudoku(puzzle)
if solved:
    for row in puzzle:
        print(" ".join(row))
