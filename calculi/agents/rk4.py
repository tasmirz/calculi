from sympy import Poly
from math import *
from sympy.utilities import lambdify
def __rk4(f,c,start,end,h):
    x= start
    y= c
    retx = []
    rety = []
    while (x<end+h):
        retx.append(x)
        rety.append(y)
        k1 = f(x,y)
        k2 = f(x+h/2,y+h*k1/2)
        k3 = f(x+h/2,y+h*k2/2)
        k4 = f(x+h,y+h*k3)
        yn = y + h/6* (k1+2*k2+2*k3+k4)
        x+=h
        y=yn
    return [retx,rety]

def rk4(expr,cc):
    #f = eval(f"lambda x, y: {expr}")
    f = lambdify(('x', 'y'), expr)
    return __rk4(f,cc,0,10,.1)