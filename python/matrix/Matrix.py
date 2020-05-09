import random

class SquareMatrix:
    def __init__(self, n):
        self._matrix = [[0 for i in range(n)] for i in range(n)]
        self._rows = n

    def __getitem__(self, i):
        return self._matrix[i]

    def __repr__(self):
        return self._matrix

    def __str__(self):
        return str(self._matrix)

    @property
    def rows(self):
        return self._rows

    def pprint(self):
        # pretty print matrix
        for i in range(self.rows):
            print("[", end="\t")
            for j in range(self.rows):
                print(self._matrix[i][j], end="\t")

            print("]")                

def random_sqr_matrix(rows, min=0, max=100):
    random_matrix = SquareMatrix(rows)
    for i in range(rows):
        for j in range(rows):
            random_matrix[i][j] = random.randint(min, max)

    return random_matrix


def square_matrix_mult(A,B):
    n = A.rows
    C = SquareMatrix(n)
    
    for i in range(n):
        for j in range(n):
            for k in range(n):
                C[i][j] += A[i][k]*B[k][j]

    return  C

if __name__ == "__main__":
    A = random_sqr_matrix(2, max=10)
    B = random_sqr_matrix(2, max=10)
    print("square matrix")
    print("Matrix A")
    A.pprint()
    print("Matrix B")
    B.pprint()
    print("A*B")
    square_matrix_mult(A,B).pprint()

