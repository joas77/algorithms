def merge(left, right):
    result = []
    left_idx, right_idx = 0, 0
    while left_idx < len(left) and right_idx < len(right):
        # change the direction of this comparison to change the direction of the sort
        if left[left_idx] <= right[right_idx]:
            result.append(left[left_idx])
            left_idx += 1
        else:
            result.append(right[right_idx])
            right_idx += 1
 
    if left_idx < len(left):
        result.extend(left[left_idx:])
    if right_idx < len(right):
        result.extend(right[right_idx:])
    return result

def merge_sort(m):
    if len(m) <= 1:
        return m
 
    middle = len(m) // 2
    left = m[:middle]
    right = m[middle:]
 
    left = merge_sort(left)
    right = merge_sort(right)
    return list(merge(left, right))

if __name__ == "__main__":
    L = [1,2,3]
    R = [4,5,6]
    m = merge(L,R)
    assert m == [1,2,3,4,5,6]
    assert merge([1], [1]) == [1,1]
    assert merge([1,2,3], [4,5,6,7]) == [1,2,3,4,5,6,7]
    assert merge([4, 5, 7], [1, 2, 3, 6]) == [1,2,3,4,5,6,7]

    unsorted = [4,5,1, -2, 10,3]
    assert merge_sort(unsorted) == sorted(unsorted)
    