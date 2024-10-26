from agents.library import unify,row_echelonU,row_echelon
def gaussian_ellimination(A):
    arr = []
    B = unify(row_echelonU(row_echelon(A)))
    arr = [0 for i in range(len(B[0])-1)]
    l=len(B)-1
    k=0;
    while(l>=0):
        sum=B[l][len(B[0])-1]
        for i in range(l+1,len(B[0])-1):
            sum-=arr[i]*B[l][i]
        arr[l]=sum
        l-=1
        k+=1
    return arr