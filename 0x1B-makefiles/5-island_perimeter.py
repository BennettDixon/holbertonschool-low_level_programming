#!/usr/bin/python3
"""
module for interview prep, tried more efficient solution but too much
"""


def island_perimeter(grid):
    """ gets perimeter of island represented as grid
    """
    if not isinstance(grid, list):
        return 0
    island_p = 0
    for row_i, row in enumerate(grid):
        if not isinstance(row, list):
            return 0
        for col_i, block in enumerate(row):
            if type(block) is not int:
                return 0
            if block == 1:
                island_p += get_block_sum(grid, row_i, col_i)
    return island_p


def get_block_sum(grid, r_i, c_i):
    """
    gets the perimeter of a block
    """
    next_block = None
    block_p = 4
    try:
        r_block = grid[r_i][c_i + 1]
        l_block = grid[r_i][c_i - 1]
        t_block = grid[r_i - 1][c_i]
        b_block = grid[r_i + 1][c_i]
    except:
        raise ValueError("ISLAND IS NOT SURROUNDED BY WATER")

    block_p += -1 * (r_block + l_block + t_block + b_block)
    return block_p
