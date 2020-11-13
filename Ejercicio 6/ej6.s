.data
NaN : .float 

.text
.global main

filtrar_no_numeros:  # Si alguno es +-inf o NaN, retornar -1


filtrar_ceros:

main:


    #rdi x
    #rsi y

    #xmm0 a
    #xmm1 b
    #xmm2 c
    #xmm3 d
    #xmm4 e
    #xmm5 f

    #movss NaN,%xmm0
    #ucomiss %xmm0,%xmm0

    xorq %rax,%rax
    incq %rax
    cvtsi2ssq %rax,%xmm0 

    xorps %xmm0,%xmm0

    divss %xmm0,%xmm0

    xorps %xmm1,%xmm1

    xorq %rax,%rax
    incq %rax
    cvtsi2ssq %rax,%xmm1 

    addss %xmm0,%xmm1


    

    # x = (c - by)/a
    # (d/a) (c - by) + ey = f
    # (d/a) (-by) + ey = f - (d/a) c 
    # y ((d/a) (-b) + e) = f - (d/a) c 
    # y = (f - (d/a) c ) / ((d/a) (-b) + e)


    



    ret
