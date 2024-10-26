import numpy as np
def mat_inv(I, epsilon):
	A= np.copy(I)
	for j in range(len(A)):
		i = len(A)-1
		while (i>j):
			if (A[i-1][j]<=epsilon): A[[i,i-1]]=A[[i-1,i]]
			else:
				A[i] = A[i] - A[i-1]*A[i][j]/A[i-1][j]
			i-=1
	for i in range(len(A)):
		if A[i][i] == 0.0: raise Exception("No particular solution")
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