def unique_paths(m: int, n: int) -> int:
    # compute C(m+n-2, min(m-1, n-1)) multiplicatively to avoid overflow
    a = m + n - 2
    b = min(m - 1, n - 1)
    ans = 1
    for i in range(1, b + 1):
        ans = ans * (a - b + i) // i
    return ans