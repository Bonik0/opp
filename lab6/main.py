import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import sympy as sp
import math

Pi = math.acos(-1)

def Rot2D(X, Y, Alpha):
    RX = X*np.cos(Alpha) - Y*np.sin(Alpha)
    RY = X*np.sin(Alpha) + Y*np.cos(Alpha)
    return RX, RY

t = sp.Symbol('t')
T = np.linspace(0, 10, 1000)

r = t + 0.5 * sp.sin(8 * t)
phi = 1 + sp.sin(8 * t)
x = r * sp.cos(phi)
y = r * sp.sin(phi)
Vx = sp.diff(x, t)
Vy = sp.diff(y, t)
Ax = sp.diff(x, t, 2)
Ay = sp.diff(y, t, 2)
w = sp.diff(phi, t)

X = np.zeros_like(T)
Y = np.zeros_like(T)
VX = np.zeros_like(T)
VY = np.zeros_like(T)
AX = np.zeros_like(T)
AY = np.zeros_like(T)
W = np.zeros_like(T)

for i in np.arange(len(T)):
    X[i] = sp.Subs(x, t, T[i])
    Y[i] = sp.Subs(y, t, T[i])
    VX[i] = sp.Subs(Vx, t, T[i])
    VY[i] = sp.Subs(Vy, t, T[i])
    AX[i] = sp.Subs(Ax, t, T[i])
    AY[i] = sp.Subs(Ay, t, T[i])
    W[i] = sp.Subs(w, t, T[i])

fig = plt.figure()

ax1 = fig.add_subplot(1, 1, 1)
ax1.axis('equal')
ax1.set(xlim=[-5, 15], ylim=[-5, 15])
ax1.plot(X, Y)

P = ax1.plot(X[0], Y[0], marker='o')[0]

ArrowX = np.array([-0.2, 0, -0.2])
ArrowY = np.array([-0.1, 0, 0.1])


RVLine = ax1.plot([0, X[0]], [0, Y[0]], 'black')[0]

RVArrowX, RVArrowY = Rot2D(ArrowX, ArrowY, math.atan2(Y[0], X[0]))
RVArrow = ax1.plot(RVArrowX+X[0], RVArrowY+Y[0], 'black')[0]


VLine = ax1.plot([X[0], X[0]+VX[0]], [Y[0], Y[0]+VY[0]], 'red')[0]

VArrowX, VArrowY = Rot2D(ArrowX, ArrowY, math.atan2(VY[0], VX[0]))
VArrow = ax1.plot(VArrowX+X[0]+VX[0], VArrowY+Y[0]+VY[0], 'red')[0]


ALine = ax1.plot([X[0], X[0]+AX[0]], [Y[0], Y[0]+AY[0]], 'blue')[0]  

AArrowX, AArrowY = Rot2D(ArrowX, ArrowY, math.atan2(AY[0], AX[0]))
AArrow = ax1.plot(AArrowX+X[0]+AX[0], AArrowY+Y[0]+AY[0], 'blue')[0]

RX, RY = Rot2D(X[0]+VX[0]/W[0], Y[0]+VY[0]/W[0], Pi/2)  
RLine = ax1.plot([X[0], RX], [Y[0], RY], 'green')[0]  

RArrowX, RArrowY = Rot2D(ArrowX, ArrowY, math.atan2(RY, RX))
RArrow = ax1.plot(RArrowX+RX, RArrowY+RY, 'green')[0]

def anima(i):
    P.set_data(X[i], Y[i])

    RVLine.set_data([0, X[i]], [0, Y[i]])
    RVArrowX, RVArrowY = Rot2D(ArrowX, ArrowY, math.atan2(Y[i], X[i]))
    RVArrow.set_data(RVArrowX+X[i], RVArrowY+Y[i])

    VLine.set_data([X[i], X[i]+VX[i]], [Y[i], Y[i]+VY[i]])
    VArrowX, VArrowY = Rot2D(ArrowX, ArrowY, math.atan2(VY[i], VX[i]))
    VArrow.set_data(VArrowX+X[i]+VX[i], VArrowY+Y[i]+VY[i])

    ALine.set_data([X[i], X[i]+AX[i]], [Y[i], Y[i]+AY[i]])
    AArrowX, AArrowY = Rot2D(ArrowX, ArrowY, math.atan2(AY[i], AX[i]))
    AArrow.set_data(AArrowX+X[i]+AX[i], AArrowY+Y[i]+AY[i])

    RX, RY = Rot2D(VX[i] / W[i], VY[i] / W[i], Pi / 2)
    RLine.set_data([X[i], X[i]+RX], [Y[i], Y[i]+RY])
    RArrowX, RArrowY = Rot2D(ArrowX, ArrowY, math.atan2(RY, RX))
    RArrow.set_data(RArrowX+X[i]+RX, RArrowY+Y[i]+RY)

    return P, VLine, VArrow, ALine, AArrow, RLine, RArrow

anim = FuncAnimation(fig, anima, frames=1000, interval=50, repeat=False)

plt.show()