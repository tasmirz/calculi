# calculi
## Setup Instructions

### Create a Virtual Environment
```bash
python -m venv .venv
source .venv/bin/activate
```

### Install Requirements
```bash
pip install -r requirements.txt
```

### Build C++ Modules
```bash
make build
```

### Run the App
```bash
python -m calculi
```
## Algorithms

### Newton Raphson Method

#### Algorithm

1. **Start**
2. **Define function** as f(x)
3. **Define first derivative** of f(x) as g(x)
4. **Input initial guess** (x0), tolerable error (e), and maximum iteration (N)
5. **Initialize iteration counter** i = 1
6. If g(x0) = 0 then print "Mathematical Error" and go to step 12, otherwise go to step 7
7. **Calculate** x1 = x0 - f(x0) / g(x0)
8. **Increment iteration counter** i = i + 1
9. If i >= N then print "Not Convergent" and go to step 12, otherwise go to step 10
10. If |f(x1)| > e then set x0 = x1 and go to step 6, otherwise go to step 11
11. **Print root** as x1
12. **Stop**

#### Pseudocode

1. **Start**
2. **Define function** as f(x)
3. **Define derivative** of function as g(x)
4. **Input**:
    - Initial guess x0
    - Tolerable Error e
    - Maximum Iteration N
5. **Initialize iteration counter** step = 1
6. **Do**
    - If g(x0) = 0
        - Print "Mathematical Error"
        - Stop
    - End If
    - x1 = x0 - f(x0) / g(x0)
    - x0 = x1
    - step = step + 1
    - If step > N
        - Print "Not Convergent"
        - Stop
    - End If
    - While abs(f(x1)) > e
7. **Print root** as x1
8. **Stop**

### Secant Method

#### Algorithm

1. **Start**
2. **Define function** as f(x)
3. **Input initial guesses** (x0 and x1), tolerable error (e), and maximum iteration (N)
4. **Initialize iteration counter** i = 1
5. If f(x0) = f(x1) then print "Mathematical Error" and go to step 11, otherwise go to step 6
6. **Calculate** x2 = x1 - (x1 - x0) * f(x1) / (f(x1) - f(x0))
7. **Increment iteration counter** i = i + 1
8. If i >= N then print "Not Convergent" and go to step 11, otherwise go to step 9
9. If |f(x2)| > e then set x0 = x1, x1 = x2 and go to step 5, otherwise go to step 10
10. **Print root** as x2
11. **Stop**

#### Pseudocode

1. **Start**
2. **Define function** as f(x)
3. **Input**:
    - Initial guesses x0 and x1
    - Tolerable Error e
    - Maximum Iteration N
4. **Initialize iteration counter** step = 1
5. **Do**
    - If f(x0) = f(x1)
        - Print "Mathematical Error"
        - Stop
    - End If
    - x2 = x1 - (x1 - x0) * f(x1) / (f(x1) - f(x0))
    - x0 = x1
    - x1 = x2
    - step = step + 1
    - If step > N
        - Print "Not Convergent"
        - Stop
    - End If
    - While abs(f(x2)) > e
6. **Print root** as x2
7. **Stop**

### False Position Method

#### Algorithm

1. **Start**
2. **Define function** f(x)
3. **Choose initial guesses** x0 and x1 such that f(x0)f(x1) < 0
4. **Choose pre-specified tolerable error** e
5. **Calculate new approximated root** as:
    - x2 = x0 - ((x0 - x1) * f(x0)) / (f(x0) - f(x1))
6. **Calculate** f(x0)f(x2)
    - a. if f(x0)f(x2) < 0 then x0 = x0 and x1 = x2
    - b. if f(x0)f(x2) > 0 then x0 = x2 and x1 = x1
    - c. if f(x0)f(x2) = 0 then goto (8)
7. if |f(x2)| > e then goto (5) otherwise goto (8)
8. **Display** x2 as root
9. **Stop**

#### Pseudocode

1. **Start**
2. **Define function** f(x)
3. **Input**:
    - Lower and Upper guesses x0 and x1
    - Tolerable error e
4. If f(x0) * f(x1) > 0
    - Print "Incorrect initial guesses"
    - Goto 3
    - End If
5. **Do**
    - x2 = x0 - ((x0 - x1) * f(x0)) / (f(x0) - f(x1))
    - If f(x0) * f(x2) < 0
        - x1 = x2
    - Else
        - x0 = x2
    - End If
    - While abs(f(x2)) > e
6. **Print root** as x2
7. **Stop**

### Gauss Jordan Method

#### Algorithm

1. **Start**
2. **Read Number of Unknowns**: n
3. **Read Augmented Matrix** (A) of n by n+1 Size
4. **Transform Augmented Matrix** (A) to Diagonal Matrix by Row Operations
5. **Obtain Solution** by Making All Diagonal Elements to 1
6. **Display Result**
7. **Stop**

#### Pseudocode

1. **Start**
2. **Input the Augmented Coefficients Matrix** (A):
    - For i = 1 to n
        - For j = 1 to n+1
            - Read A<sub>i,j</sub>
        - Next j
    - Next i
3. **Apply Gauss Jordan Elimination** on Matrix A:
    - For i = 1 to n
        - If A<sub>i,i</sub> = 0
            - Print "Mathematical Error!"
            - Stop
        - End If
        - For j = 1 to n
            - If i ≠ j 
                - Ratio = A<sub>j,i</sub>/A<sub>i,i</sub>
                - For k = 1 to n+1
                    - A<sub>j,k</sub> = A<sub>j,k</sub> - Ratio \* A<sub>i,k</sub>
                - Next k
            - End If
        - Next j
    - Next i
4. **Obtaining Solution**:
    - For i = 1 to n 
        - X<sub>i</sub> = A<sub>i,n+1</sub>/A<sub>i,i</sub>
    - Next i
5. **Display Solution**:
    - For i = 1 to n
        - Print X<sub>i</sub>
    - Next i
6. **Stop**

---

Note: All array indexes are assumed to start from 1.

### Jacobi Iteration Method

#### Algorithm

1. **Start**
2. **Arrange given system of linear equations** in diagonally dominant form
3. **Read tolerable error** (e)
4. **Convert the first equation** in terms of first variable, second equation in terms of second variable and so on
5. **Set initial guesses** for x0, y0, z0 and so on
6. **Substitute value** of x0, y0, z0 ... from step 5 in equation obtained in step 4 to calculate new values x1, y1, z1 and so on
7. If |x0 - x1| > e and |y0 - y1| > e and |z0 - z1| > e and so on then goto step 9
8. **Set** x0=x1, y0=y1, z0=z1 and so on and goto step 6
9. **Print value** of x1, y1, z1 and so on
10. **Stop**

### Gauss Seidel Iterative Method

#### Algorithm

1. **Start**
2. **Arrange given system of linear equations** in diagonally dominant form
3. **Read tolerable error** (e)
4. **Convert the first equation** in terms of first variable, second equation in terms of second variable and so on
5. **Set initial guesses** for x0, y0, z0 and so on
6. **Substitute value** of y0, z0 ... from step 5 in first equation obtained from step 4 to calculate new value of x1. Use x1, z0, u0 .... in second equation obtained from step 4 to calculate new value of y1. Similarly, use x1, y1, u0... to find new z1 and so on
7. If |x0 - x1| > e and |y0 - y1| > e and |z0 - z1| > e and so on then goto step 9
8. **Set** x0=x1, y0=y1, z0=z1 and so on and goto step 6
9. **Print value** of x1, y1, z1 and so on
10. **Stop**

### Gauss Elimination Method

#### Algorithm

1. **Start**
2. **Read Number of Unknowns**: n
3. **Read Augmented Matrix** (A) of n by n+1 Size
4. **Transform Augmented Matrix** (A) to Upper Triangular Matrix by Row Operations
5. **Obtain Solution** by Back Substitution
6. **Display Result**
7. **Stop**

#### Pseudocode

1. **Start**
2. **Input the Augmented Coefficients Matrix (A):**
    - For i = 1 to n
        - For j = 1 to n+1
            - Read A<sub>i,j</sub>
        - Next j
    - Next i
3. **Apply Gauss Elimination on Matrix A:**
    - For i = 1 to n-1
        - If A<sub>i,i</sub> = 0
            - Print "Mathematical Error!"
            - Stop
        - End If
        - For j = i+1 to n
            - Ratio = A<sub>j,i</sub>/A<sub>i,i</sub>
            - For k = 1 to n+1
                - A<sub>j,k</sub> = A<sub>j,k</sub> - Ratio \* A<sub>i,k</sub>
            - Next k
        - Next j
    - Next i
4. **Obtaining Solution by Back Substitution:**
    - X<sub>n</sub> = A<sub>n,n+1</sub>/A<sub>n,n</sub>
    - For i = n-1 to 1 (Step: -1)
        - X<sub>i</sub> = A<sub>i,n+1</sub>
        - For j = i+1 to n
            - X<sub>i</sub> = X<sub>i</sub> - A<sub>i,j</sub> \* X<sub>j</sub>
        - Next j
        - X<sub>i</sub> = X<sub>i</sub>/A<sub>i,i</sub>
    - Next i
5. **Display Solution:**
    - For i = 1 to n
        - Print X<sub>i</sub>
    - Next i
6. **Stop**

---

Note: All array indexes are assumed to start from 1.

### Bisection Method

#### Algorithm

1. **Start**
2. **Define function f(x)**
3. **Choose initial guesses** x0 and x1 such that f(x0)f(x1) < 0
4. **Choose pre-specified tolerable error** e
5. **Calculate new approximated root** as x2 = (x0 + x1)/2
6. **Calculate** f(x0)f(x2)
    - a. if f(x0)f(x2) < 0 then x0 = x0 and x1 = x2
    - b. if f(x0)f(x2) > 0 then x0 = x2 and x1 = x1
    - c. if f(x0)f(x2) = 0 then goto (8)
7. if |f(x2)| > e then goto (5) otherwise goto (8)
8. **Display** x2 as root
9. **Stop**

#### Pseudocode

1. **Start**
2. **Define function f(x)**
3. **Input:**
    - a. Lower and Upper guesses x0 and x1
    - b. Tolerable error e
4. If f(x0)\*f(x1) > 0
    - Print "Incorrect initial guesses"
    - Goto 3
    - End If
5. **Do:**
    - x2 = (x0+x1)/2
    - If f(x0)\*f(x2) < 0
        - x1 = x2
    - Else
        - x0 = x2
    - End If
    - While abs(f(x2) > e
6. **Print root** as x2
7. **Stop**

### Fourth Order Runge Kutta (RK) Method

#### Algorithm

1. **Start**
2. **Define function f(x,y)**
3. **Read values of initial condition** (x0 and y0), number of steps (n) and calculation point (xn)
4. **Calculate step size** (h) = (xn - x0)/n
5. **Set** i=0
6. **Loop:**
    - k1 = h \* f(x0, y0)
    - k2 = h \* f(x0+h/2, y0+k1/2)
    - k3 = h \* f(x0+h/2, y0+k2/2)
    - k4 = h \* f(x0+h, y0+k3)
    - k = (k1+2\*k2+2\*k3+k4)/6
    - yn = y0 + k
    - i = i + 1
    - x0 = x0 + h
    - y0 = yn
    - While i < n
7. **Display** yn as result
8. **Stop**

### Finding Inverse of Matrix Using Gauss Jordan Method

#### Algorithm

1. **Start**
2. **Read Order of Matrix** (n)
3. **Read Matrix** (A) of Order (n)
4. **Augment and Identity Matrix** of Order n to Matrix A
5. **Apply Gauss Jordan Elimination** on Augmented Matrix (A)
6. **Perform Row Operations** to Convert the Principal Diagonal to 1
7. **Display the Inverse Matrix**
8. **Stop**

#### Pseudocode

1. **Start**
2. **Read Order of Matrix** (n)
3. **Read Matrix (A):**
    - For i = 1 to n
        - For j = 1 to n
            - Read A<sub>i,j</sub>
        - Next j
    - Next i
4. **Augment Identity Matrix** of Order n to Matrix A:
    - For i = 1 to n
        - For j = 1 to n
            - If i = j
                - A<sub>i,j+n</sub> = 1
            - Else
                - A<sub>i,j+n</sub> = 0
            - End If
        - Next j
    - Next i
5. **Apply Gauss Jordan Elimination** on Augmented Matrix (A):
    - For i = 1 to n
        - If A<sub>i,i</sub> = 0
            - Print "Mathematical Error!"
            - Stop
        - End If
        - For j = 1 to n
            - If i ≠ j
                - Ratio = A<sub>j,i</sub>/A<sub>i,i</sub>
                - For k = 1 to 2\*n
                    - A<sub>j,k</sub> = A<sub>j,k</sub> - Ratio \* A<sub>i,k</sub>
                - Next k
            - End If
        - Next j
    - Next i
6. **Row Operation to Convert Principal Diagonal to 1:**
    - For i = 1 to n
        - For j = n+1 to 2\*n
            - A<sub>i,j</sub> = A<sub>i,j</sub>/A<sub>i,i</sub>
        - Next j
    - Next i
7. **Display Inverse Matrix:**
    - For i = 1 to n
        - For j = n+1 to 2\*n
            - Print A<sub>i,j</sub>
        - Next j
    - Next i
8. **Stop**

---

Note: All array indexes are assumed to start from 1.
