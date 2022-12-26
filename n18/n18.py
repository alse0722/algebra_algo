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

def berlekamp():
    from numpy.polynomial import Polynomial as P
    import numpy as np

    from numpy.linalg import matrix_rank
    import fractions

    p = np.array([1, 0, 1, 1, 1])

    p1 = np.array([1])
    p2 = np.array([1, 0, 0])
    p3 = np.array([1, 0, 0, 0, 0])
    p4 = np.array([1, 0, 0, 0, 0, 0, 0])

    print(p1)
    print(p2)
    print(p3)
    print(p4)
    print()
    
    a1 = np.absolute(np.polydiv(p1, p)[1])[::-1].tolist()
    a2 = np.absolute(np.polydiv(p2, p)[1])[::-1].tolist()
    a3 = np.absolute(np.polydiv(p3, p)[1])[::-1].tolist()
    a4 = np.absolute(np.polydiv(p4, p)[1])[::-1].tolist()

    for i in range(len(a4)-len(a1)):
        a1.append(0)

    for i in range(len(a4)-len(a2)):
        a2.append(0)

    for i in range(len(a4)-len(a3)):
        a3.append(0)

    for i in range(len(a4)-len(a4)):
        a4.append(0)

    x = np.array([a1, a2, a3, a4])

    y = np.absolute(
        x-np.array([[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]]))
    print(y)

    r = matrix_rank(y)

    print(r)
    
berlekamp()