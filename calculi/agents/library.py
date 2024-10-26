import numpy as np
import math
def to_np(A):
    return np.array(A)
def row_abs_sum(A,i):
    ret = 0 
    for j in range(len(A)):
        if (j==i): continue
        ret+=abs(A[j])
    return ret
def is_digonally_domainant(A):
    for i in range(len(A)):
        if abs(A[i][i])-row_abs_sum(A[i],i)<0: return False
    return True
def make_diagonally_dominat(I):
    if is_digonally_domainant(I): return I
    A=np.copy(I)
    st = set(())
    for i in range(len(A)): st.add(i)
    lst =[]
    if not __make_dd(A,0,lst,st):
        raise Exception("Cannot convert")
    for i in range(len(A)):
        A[i] = I[lst[i]]
    return A
def __make_dd(A,row,lst:list,st:set):
    """
    Dynamic progamming approach to make matrix diagonally dominant
    """
    if len(st)==0: return True
    print(lst)
    print(st)
    for i in st:
        if abs(A[i][row])-row_abs_sum(A[i],row)>=0:
            st.remove(i)
            lst.append(i)
            if (__make_dd(A,row+1,lst,st)): return True
            st.add(i)
            del lst[-1]
    return False
def row_echelonU(I,epsilon=0.0):
    A= np.copy(I)
    j=len(A)-1
    while(j>0):
            i = 0
            while (i<j):
                if (A[i+1][j]<=epsilon): A[[i,i+1]]=A[[i+1,i]]
                else:
                    A[i] = A[i] - A[i+1]*A[i][j]/A[i+1][j]
                i+=1
            j-=1
    return A
def row_echelon(I,epsilon=0.0):
    A= np.copy(I)
    for j in range(len(A)-1):
            i = len(A)-1
            while (i>j):
                if (A[i-1][j]<=epsilon): A[[i,i-1]]=A[[i-1,i]]
                else:
                    A[i] = A[i] - A[i-1]*A[i][j]/A[i-1][j]
                i-=1
    for i in range(len(A)):
        if A[i][i] == 0.0: raise Exception("No particular solution")
    return A
def unify(I):
    A= np.copy(I)
    for i in range(len(A)):
        #if A[i][i] == 0.0: raise Exception("No particular solution")
        A[i]/=A[i][i];
    return A
def find_bounds(coefficients):
	a_n = coefficients[0]
	M = 1 + max(abs(coeff / a_n) for coeff in coefficients[1:])
	return (-M+1, M+1)