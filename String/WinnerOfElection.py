def find_winner(d):
    max_index = 0
    count = 1
    max_candidate = d[0]
    for i in range(1, len(d))::
        if d[i] == max_candidate:
            count += 1
        elif:
            count -= 1
        if count == 0:
            max_index = i
            count = 1
    return d[max_index]
