comparisions_count = 0
def quicksort(A:list, left_index:int, right_index:int, pivot_rule="first")->int:
    # global comparisions_count
    if left_index >= right_index: # 0 or 1-element sub array
        return

    pivot = choose_pivot(A, left_index, right_index, pivot_rule=pivot_rule)
    A[left_index], A[pivot] = A[left_index], A[pivot] # make pivot first
    j = partition(A, left_index, right_index)  # j = new pivot position

    quicksort(A, left_index, j - 1, pivot_rule=pivot_rule) # recurse on first part
    # comparisions_count += j - 1 - left_index
    quicksort(A, j+1, right_index, pivot_rule=pivot_rule) 
    # comparisions_count += right_index - (j + 1)

def partition(A:list, left_index:int, right_index:int):
    pivot = A[left_index] 
    i = left_index + 1
    global comparisions_count

    for j in range(left_index+1, right_index+1):
        if A[j] < pivot:
            A[j], A[i] = A[i], A[j]
            i += 1      # restores invariant
            comparisions_count += 1
    A[left_index], A[i-1] = A[i-1], A[left_index] # place pivot correctly
    return i - 1 # report final pivot position

def choose_pivot(A:list, left_index:int, right_index:int, pivot_rule="first")->int:
    pivot = left_index
    if pivot_rule == "first":
        pivot = left_index
    elif pivot_rule == "last":
        pivot = right_index
    elif pivot_rule == "3-median":
        pass

    return pivot

def get_data_set(file_path:str)->list:
    file = open(file_path)
    integers = [int(line.strip()) for line in file.readlines()]
    return integers


if __name__ == "__main__":
    
    A = [3,8,2,5,1,4,7,6]

    partition(A, 0, len(A)-1)
    assert A == [1,2,3,5,8,4,7,6]

    A1 = [2, 4, 3, 7, 6, 5, 8, 1, 9]
    partition(A1, 0, len(A1)-1)
    # print(A1)

    B = [2, 4, 3, 7, 6, 5, 8, 1, 9]
    quicksort(B, 0,len(B)-1)
    # print(B)

    comparisions_count = 0
    test1 = get_data_set("datasets/problem5.6test1.txt")
    quicksort(test1, 0, len(test1)-1)
    print(comparisions_count)
    print(test1)

    comparisions_count = 0
    test2 = get_data_set("datasets/problem5.6test2.txt")
    quicksort(test2, 0, len(test2)-1)
    print(comparisions_count)
    print(test1)