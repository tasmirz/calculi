# handler.py
import subprocess
from calculi.agents.bisection import bisection
from calculi.agents.rk4 import rk4
from calculi.agents.library import get_coff,sp
from calculi.agents.gaussian_ellimination import gaussian_ellimination  
from calculi.agents.gauss_jordan import gauss_jordan
from calculi.agents.mat_inv import mat_inv
import numpy as np
DIR = "calculi/cpp_agents"
def handle_method_selection(method_id, data_string,term,plt):
    data_lines = data_string.split('\n')
    
    match method_id:
        case "jacobi":
            st = data_string
            term.write(sp('calculi/cpp_agents/Jacobi_method.out', st))
        case "gauss_seidel":
            st = data_string
            term.write(sp('calculi/cpp_agents/Gauss-Seidel_method.out', st))
        case "gauss_elimination":
            matrix = []
            for line in data_lines:
                row = list(map(float, line.split()))
                matrix.append(row)
            matrix = np.array(matrix)
            term.write(gaussian_ellimination (matrix))
        case "gauss_jordan":
            matrix = []
            for line in data_lines:
                row = list(map(float, line.split()))
                matrix.append(row)
            matrix = np.array(matrix)
            term.write(gauss_jordan(matrix))
        case "lu_factorization":
            st = ""
            for i in get_coff(data_string):
                st += str(i) + " "
            term.write(sp('calculi/cpp_agents/LU_method.out', st))
        case "bi_section":
            term.write(bisection(data_string))
            
        case "false_position":
            st =""
            for i in get_coff(data_string):
                st+=str(i)+" "
            term.write(sp('calculi/cpp_agents/false_position.out',st))
        case "secant":
            st =""
            for i in get_coff(data_string):
                st+=str(i)+" "
            term.write(sp('calculi/cpp_agents/secant_method.out',st))
        case "newton_raphson":
            st =""
            for i in get_coff(data_string):
                st+=str(i)+" "
            term.write(sp('calculi/cpp_agents/Newton_Raphson.out',st))
        case "runge_kutta":
            DD = data_lines[0]
            cc = float(data_lines[1])
            
            x,y = rk4(DD,cc)
            for i in range(len(x)):
                term.write(f"x: {x[i]}, y: {y[i]}\n")
            plt.scatter(x,y)
            plt.xlabel('x')
            plt.ylabel('y')
            plt.title('Runge-Kutta Method')
            plt.show()
        case "matrix_inversion":
            matrix = []
            for line in data_lines:
                row = list(map(float, line.split()))
                matrix.append(row)
            matrix = np.array(matrix)
            term.write(mat_inv(matrix,1e-10))
        #case _:
        #    raise ValueError(f"Unknown method ID: {method_id}")