.data 

.align 16

.text
.global sum
.global sum_simd

sum:

    #rdi *a
    #rsi *b
    #rdx len

    xorq %rcx,%rcx
    orl %edx,%ecx


    
    # 1 float => 4 Bytes
    
    suma_flotantes_simpleP:
        movss (%rsi),%xmm0
        movss (%rdi),%xmm1
        addss %xmm1,%xmm0
        movss %xmm0,(%rdi)

        addq $4,%rdi
        addq $4,%rsi
    loop suma_flotantes_simpleP

    ret 


sum_simd:

    
    movq %rdx,%rax
    xorq %rdx,%rdx
    
    movq $4,%r8
    div %r8

    movq %rax,%rcx
    
    suma_flotantes_simpleP_simd:
        movaps (%rsi),%xmm0
        movaps (%rdi),%xmm1
        addps %xmm1,%xmm0
        movaps %xmm0,(%rdi)

        addq $16,%rdi
        addq $16,%rsi
    loop suma_flotantes_simpleP_simd
    
    andq %rdx,%rdx
    jz finalizar

    # 1 <= rdx <= 3
    # %rdi nos queda el puntero a la posicion del float en a que todavia no sumamos (rax*16)
    # %rsi nos queda el puntero a la posicion del float en b que todavia no sumamos (rax*16)

    callq sum
    
    finalizar:
    ret


    










