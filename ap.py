def solve(grid):
    l = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
    for i in range(5):
        for j in range(2):
            if grid[i][j] > 2:
                return "No"
    for i in range(5):
        l[grid[i][0]][grid[i][1]] = 1
    if l == [[1, 1, 1], [0, 1, 0], [0, 1, 0]]:
        return "Yes"
    elif l == [[0, 1, 0], [0, 1, 0], [1, 1, 1]]:
        return "Yes"
    elif l == [[1, 0, 0], [1, 1, 1], [1, 0, 0]]:
        return "Yes"
    elif l == [[0, 0, 1], [1, 1, 1], [0, 0, 1]]:
        return "Yes"
    return "No"


t = int(input().strip())

for t_itr in range(t):
    xm = 1000001
    ym = 1000001
    points = []

    for _ in range(5):
        points.append(list(map(int, input().rstrip().split())))
        xm = min(xm, points[_][0])
        ym = min(ym, points[_][1])
    for _ in range(5):
        points[_][0] -= xm
        points[_][1] -= ym

    result = solve(points)

    print(result + '\n')
