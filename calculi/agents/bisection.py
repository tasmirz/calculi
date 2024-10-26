from sympy import Poly
from sympy.utilities import lambdify
import calculi.agents.library as library
magic_number = 0.1
def __bisection(f,a,b,tol=1e-4,nmax=100):
	"""Solve quadratic equations with bisection method
	Args:
		f (method): function 
		a (int): bracketing start
		b (int): bracketing end
		tol (float):  err allowed from actual solution
		nmax (int): maximum number of times the loop should run
	Returns:
		deouble: The solution
	"""
	c=0
	for n in range (0,nmax):
		c= (a+b)/2
		if (f(c)==0.0 or (b-a)/2<tol):
			return c
		if f(c)*f(a)<0: b=c
		if f(c)*f(a)<0: a=c
		n=n+1
	# throw err here
	return c
def bisection(expr):
	f = lambdify('x', expr)
	m,l = library.find_bounds(Poly(expr).all_coeffs())
	results = []
	while (m<l):
		if f(m)==0.0:
			results.append(m)
			continue
		if (f(m)*f(m+magic_number)<0):
			results.append(__bisection(f,m,m+magic_number,1e-9,100))
		m+=magic_number
	return results

 

