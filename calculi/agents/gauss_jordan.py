from agents.library import unify,row_echelonU,row_echelon
def gauss_jordan(A):
    arr = []
    B = unify(row_echelonU(row_echelon(A)))
    for i in range(len(B)):
        arr.append(B[i][len(B[i])-1])
    return arr
   