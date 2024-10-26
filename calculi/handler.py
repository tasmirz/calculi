# handler.py
import subprocess
from agents.bisection import bisection
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
            term.write("hi")
            term.write(sp(DIR+ '/false_position.out',get_coff(data_string)).join(' '))
        #case "secant":
        #    secant_method(data_lines)
        #case "newton_raphson":
        #    newton_raphson_method(data_lines)
        #case "runge_kutta":
        #    runge_kutta_method(data_lines)
        #case "matrix_inversion":
        #    matrix_inversion_method(data_lines)
        #case _:
        #    raise ValueError(f"Unknown method ID: {method_id}")