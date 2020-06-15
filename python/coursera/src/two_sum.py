def alg(test_file):
    with open(test_file) as file:
        data = [int(elem) for elem in file.readlines()]

    data_set = set(data)
    target_counter = 0
    # pairs = []
    for t in range(-10_000,10_001):
        for x in data_set:
            y = t - x
            if y != x and  y in data_set:
                target_counter += 1
                # pairs.append((x,y))
                print(target_counter)
                break
                
    # print(pairs)
    # print(target_counter)
    return target_counter

if __name__ == "__main__":
    alg("algo1-programming_prob-2sum.txt")