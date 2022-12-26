import warnings
from sympy.polys.galoistools import gf_monic
from sympy.polys.galoistools import gf_div
from sympy.polys.galoistools import gf_sub_mul
from sympy.polys.galoistools import gf_mul_ground
from sympy.polys.domains import ZZ
import numpy.core.numeric as NX
from numpy.lib.twodim_base import diag
from numpy.linalg import eigvals
from numpy.core import (hstack)
import numpy as np


def roots(p):
    p = np.array(p)
    # find non-zero array entries
    non_zero = NX.nonzero(NX.ravel(p))[0]

    # Return an empty array if polynomial is all zeros
    if len(non_zero) == 0:
        return NX.array([])

    # find the number of trailing zeros -- this is the number of roots at 0.
    trailing_zeros = len(p) - non_zero[-1] - 1

    # strip leading and trailing zeros
    p = p[int(non_zero[0]):int(non_zero[-1])+1]

    
    if not issubclass(p.dtype.type, (NX.floating, NX.complexfloating)):
        p = p.astype(float)

    N = len(p)
    if N > 1:
        # наш полином будет являться характеристическим многочленом сопровождающей матрицы
        # Строим сопровождающую матрицу и находим ее собсвтенные значения (корни)
        A = diag(NX.ones((N-2,), p.dtype), -1)
        A[0, :] = -p[1:] / p[0]
        # находим решения характеристического уравнения матрицы
        roots = eigvals(A)
        # которые равны собственным значениям матрицы, то есть найдем корни полинома
    else:
        roots = NX.array([])

    roots = hstack((roots, NX.zeros(trailing_zeros, roots.dtype)))
    return roots

def poly_horner(A, x):
    p = A[-1]
    i = len(A) - 2
    while i >= 0:
        p = p * x + A[i]
        i -= 1
    return p

polynom = [1, -2, 1]

print("poly:")
print(polynom)
print()

rootsPol = roots(polynom)
rootsInt = []

for i in rootsPol:
    rootsInt.append(float(i))
    
n = len(rootsPol)
print(rootsInt)

values = []
for i in rootsPol:
    values.append(poly_horner(polynom, i))

print(values)