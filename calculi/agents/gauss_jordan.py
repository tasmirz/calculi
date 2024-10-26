from calculi.library import gauss_jordan,row_echelon
def gauss_jordan(A):
    arr = []
    B = gauss_jordan(row_echelon(A))
    for i in range(len(B)):
        arr.append(B[i][len(B)-1])
    return B