def prostewybieranie(a: list):
    numberOfIterations = 0
    for i in range(len(a)):
        k = i
        x = a[i]
        for j in range(i+1, len(a)):
            numberOfIterations += 1
            if a[j] < x:
                k = j
                x = a[j]
        a[k] = a[i]
        a[i] = x; # zamieniamy element i-ty z min

    return numberOfIterations


lists = [
     [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
     [10, 9, 8, 7, 6, 5, 4, 3, 2, 1],
     [1, 5, 4, 3, 4, 6, 8, 5, 1, 2],
     [1, 5, 4, 3, 12, 6, 8, 5, 1, 2],
     [1, 5, 4, 3, 2, 6, 8, 6, 1, 2],
     [1, 5, 4, 3, 2, 6, 8, 6, 1, 2],
     [1, 5, 4, 3, 2, 6, 8, 6, 1, 3],
     [1, 5, 4, 3, 2, 8, 8, 5, 1, 4],
     [1, 5, 4, 3, 2, 6, 8, 5, 2, 2],
     [1, 5, 4, 3, 2, 7, 8, 5, 1, 2],
    ]

for list in lists:
    print(prostewybieranie(list))