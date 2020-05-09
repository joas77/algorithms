def merge_and_countSplitInv(left, right):
    result = []
    left_idx, right_idx = 0, 0
    split_inv = 0
    while left_idx < len(left) and right_idx < len(right):
        # change the direction of this comparison to change the direction of the sort
        if left[left_idx] < right[right_idx]:
            result.append(left[left_idx])
            left_idx += 1
        else:
            result.append(right[right_idx])
            right_idx += 1
            split_inv += len(left) - left_idx + 1 
 
    if left_idx < len(left):
        result.extend(left[left_idx:])
    if right_idx < len(right):
        result.extend(right[right_idx:])
    
    return result, split_inv

def sort_count_inv(A):
    if len(A)<=1:
        return A, 0
    
    middle = len(A) // 2
    C, left_inv = sort_count_inv(A[:middle])
    D, right_inv = sort_count_inv(A[middle:])
    sorted_arr, split_inv = merge_and_countSplitInv(C, D)

    return (sorted_arr, left_inv + right_inv + split_inv)

def brute_force_count_inv(A):
    n = len(A)
    count_inv = 0
    for i in range(n-1):
        for j in range(i+1, n):
            if A[i] > A[j]:
                count_inv += 1

    return count_inv


if __name__ == "__main__":

    integer_arr_file = open("IntegerArray.txt")
    int_array = [int(i) for i in integer_arr_file.readlines()]
    integer_arr_file.close()

    # small test case
    #sorted_arr, count_inv = sort_count_inv([1,3,5,2,4,6])
    count_inv = brute_force_count_inv([1,3,5,2,4,6])
    assert count_inv == 3
    #sorted_arr, count_inv = sort_count_inv([1,5,3,2,4])
    count_inv = brute_force_count_inv([1,5,3,2,4])
    assert count_inv == 4


    sorted_arr, count_inv = sort_count_inv(int_array)
    print(count_inv)
    count_inv = brute_force_count_inv(int_array)
    print(count_inv)