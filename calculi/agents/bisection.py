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
		if (f(c)==0 or (b-a)/2<tol):
			return c
		if f(c)*f(a)<0: b=c
		if f(c)*f(a)<0: a=c
		n=n+1
	# throw err here
	return c
def bisection(expr,tol,nnamx):
	pass