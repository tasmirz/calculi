def rk4(f,c,start,end,h):
    x= start
    y= c
    retx = []
    rety = []
    while (x<end+h):
        retx.append(x)
        rety.append(y)
        k1 = f(x,y,c)
        k2 = f(x+h/2,y+h*k1/2,c)
        k3 = f(x+h/2,y+h*k2/2,c)
        k4 = f(x+h,y+h*k3,c)
        yn = y + h/6* (k1+2*k2+2*k3+k4)
        x+=h
        y=yn
    return [retx,rety]

    