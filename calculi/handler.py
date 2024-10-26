# handler.py
import subprocess
from agents.bisection import bisection
from agents.rk4 import rk4
from agents.library import get_coff,sp
DIR = "calculi/cpp_agents"
def handle_method_selection(method_id, data_string,term,plt):
    data_lines = data_string.split('\n')
    
    match method_id:
        #case "jacobi":
        #    jacobi_method(data_lines)
        #case "gauss_seidel":
        #    gauss_seidel_method(data_lines)
        #case "gauss_elimination":
        #    gauss_elimination_method(data_lines)
        #case "gauss_jordan":
        #    gauss_jordan_method(data_lines)
        #case "lu_factorization":
        #    lu_factorization_method(data_lines)
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
        #case "matrix_inversion":
        #    matrix_inversion_method(data_lines)
        #case _:
        #    raise ValueError(f"Unknown method ID: {method_id}")