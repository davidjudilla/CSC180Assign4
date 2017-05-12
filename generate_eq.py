import math

inX = range(-13,13)
inY = range(-26,26,2)
outputs = []

def printH(l):
    b = "(def -list# ' ("
    for a in l:
        b += str(a) + " "
    b += "))"
    print(b)

for i in range(len(inX)):
    res = .25*(inX[i]**4) - (4*(inY[i]**3))
    a = inX[i]**2 - (inX[i]*inY[i]) + inX[i] + inY[i]**2 - inY[i]
    if a == 0:
    	continue
    res = math.sin(a)/a
    outputs.append(res)

printH(inX)
printH(inY)
printH(outputs)
