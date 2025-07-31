from typing import List


def isValidSudoku(self, board: List[List[str]]) -> bool:
    row_memory = [set() for _ in range(9)]
    col_memory = [set() for _ in range(9)]
    sq_memory = [set() for _ in range(9)]

    for row_index in range(len(board)):
        for col_index in range(len(board[row_index])):
            sq_index = (row_index//3)*3 + (col_index//3)
            cell = board[row_index][col_index]
            if cell == '.':
                continue

            if (cell in row_memory[row_index]) or (cell in col_memory[col_index]) or (cell in sq_memory[sq_index]):
                return False

            row_memory[row_index].add(cell)
            col_memory[col_index].add(cell)
            sq_memory[sq_index].add(cell)
                            
    return True