def bubblesort(A):
    """
    Sorts A using bubblesort algorithm.
    This function modifies A
    parameters:
    :param A: list of numbers 
    """
    for i in range(len(A)-1):
        for j in reversed(range(i+1, len(A))):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]

    return A

if __name__ == "__main__":
    A = [3, 4, -1, 6, 0, 10]
    print("original list:")
    print(A)
    print("sorted list with bubble sort algorithm")
    bubblesort(A)
    print(A)
