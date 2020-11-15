.global main

main:
        xorq %rax,%rax

        xorq %r8,%r8
        decq %r8
        cvtsi2ssq %rax,%xmm0  # xmm0 = 0
        cvtsi2ssq %r8,%xmm1   # xmm1 = -1
        cvtsi2ssq %r8,%xmm2   # xmm2 = -1
        divss %xmm0,%xmm1     # xmm1 = -1/0 = -inf
        divss %xmm0,%xmm0     # xmm0 = 0/0  = NaN
        ucomiss %xmm1,%xmm2   # no se prende PF
        ucomiss %xmm0,%xmm2   # se prende PF
        
        # Verificador infinitos
        movss   %xmm1, %xmm3  # xmm3 = -inf
        mulss   %xmm2,%xmm3   # xmm3 = (-1) * (-inf) = inf
        addss   %xmm1,%xmm3   # xmm3 = inf + (-inf) = NaN

        ucomiss %xmm1,%xmm1

        addss %xmm0,%xmm1     # xmm1 = NaN + (-inf) = NaN  
        