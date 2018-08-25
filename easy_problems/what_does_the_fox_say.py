for i in range(int(input())):
    words = input().split()
    known_sounds = set()
    nextLine = input().split()

    while nextLine[1] != "does":
        known_sounds.add(nextLine[2])
        nextLine = input().split()

    ans = []
    for word in words:
        if word not in known_sounds: ans.append(word)

    print(" ".join(ans))
