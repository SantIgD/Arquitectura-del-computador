.text

.global setjmp2
.global longjmp2

setjmp2:

    xorq %rax,%rax

    movq %rbx,(%rdi)
    movq %rbp,8(%rdi)
    movq %rsp,16(%rdi)
    
    movq (%rsp),%rdx   # rip en rdx
    movq %rdx, 24(%rdi)

    movq %r13,32(%rdi)
    movq %r14,40(%rdi) 
    movq %r15,48(%rdi)
    movq %r12,56(%rdi)

    fin:
    ret
    
longjmp2:  # rdi => la direccion donde almacenamos la informacion del estado
           # rsi => valor de retorno de setjmp2
    
    xorq %rax,%rax
    or   %rsi,%rax
    jnz continue
    incq %rax      # evita que retorne 0

    continue:
    movq (%rdi),%rbx
    movq 8(%rdi),%rbp
    movq 16(%rdi),%rsp

    
    movq 24(%rdi),%r8   # Valor de retorno del setjmp2
    movq %r8,(%rsp)

    movq 32(%rdi),%r13
    movq 40(%rdi),%r14
    movq 48(%rdi),%r15
    movq 56(%rdi),%r12
    
    jmp fin


    #ALTERNATIVA DE RETORNO 
    #pop %r8
    #jmp *%r8
