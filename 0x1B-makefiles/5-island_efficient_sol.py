#!/usr/bin/python3
"""
module is for interview prep -- calculate island perimeter
"""


def island_perimeter(grid):
    """ island_perimeter is used to get perimeter of island,
        -> island presumed to have no lakes
        -> either one island or none
        -> ISLAND IS SURROUNDED BY WATER
    """
    if not isinstance(grid, list):
        raise TypeError("island_perimeter must be given list of lists")

    land_found = []
    next_block = None
    island_p = 0
    for r_i, row in enumerate(grid):
        if not isinstance(row, list):
            raise TypeError("island_perimeter must be list of lists")

        if next_block is None and len(land_found) == 0:
            for c_i, land in enumerate(row):
                if (land != 1 and land != 0):
                    raise ValueError("island_perimiter values must be 1 or 0")
                elif land == 1:
                    block_d = get_next_block(grid, row, r_i, c_i, land_found)
                    next_block = block_d['block']
                    island_p += block_d['perimeter']
                    break
        if next_block is not None:
            break
    furthest_row = 0
    while r_i < len(grid) and next_block is not None:
        if r_i > furthest_row:
            furthest_row = r_i
        if next_block[1] < r_i:
            r_i = next_block[1]
        if next_block[1] != r_i:
            r_i += 1
            continue
        else:
            block_d = get_next_block(grid, grid[r_i], next_block[1],
                                     next_block[2], land_found)
            if next_block is not None \
               and (next_block[1], next_block[2]) not in land_found[:-1]:
                island_p += block_d['perimeter']
            next_block = block_d['block']
        if next_block is None and r_i + 1 < len(grid) - 1:
            for b in land_found:
                if b[0] == furthest_row - 1:
                    next_block = (1, b[0], b[1])
                    break
        elif next_block is None:
            break
        r_i += 1
    return island_p


def get_next_block(grid, row, r_i, c_i, land_found):
    next_block = None
    block_p = 4
    land_found.append((r_i, c_i))
    try:
        r_block = row[c_i + 1]
        l_block = row[c_i - 1]
        t_block = grid[r_i - 1][c_i]
        b_block = grid[r_i + 1][c_i]
    except:
        raise ValueError("ISLAND IS NOT SURROUNDED BY WATER")

    blocks = [(t_block, r_i - 1, c_i),
              (r_block, r_i, c_i + 1),
              (l_block, r_i, c_i - 1),
              (b_block, r_i + 1, c_i)]

    block_p += -1 * (r_block + l_block + t_block + b_block)
    for block in blocks:
        if block[0] == 1:
            if (block[1], block[2]) not in land_found:
                next_block = block
                break
    return {'block': next_block, 'perimeter': block_p}
