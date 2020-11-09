.text

.global setjmp2
.global longjmp2

setjmp2:

    xorq %rax,%rax

    movq %rbx,(%rdi)
    movq %rbp,8(%rdi)
    movq %rsp,16(%rdi)
    movq %r10,24(%rdi)

    movq (%rsp),%rdx
    movq %rdx, 32(%rdi)

    movq %r13,40(%rdi)
    movq %r14,48(%rdi) 
    movq %r15,56(%rdi)
    movq %r12,64(%rdi)

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
    movq 24(%rdi),%r10
    
    movq 32(%rdi),%r8   # Valor de retorno del setjmp2
    movq %r8,(%rsp)

    movq 40(%rdi),%r13
    movq 48(%rdi),%r14
    movq 56(%rdi),%r15
    movq 64(%rdi),%r12
    
    jmp fin


    #ALTERNATIVA DE RETORNO
    #subq $8,%rsp        # "Pop", para que rsp apunte al final de la pila 
    #jmp *%r8


#e12
#A que se refiere con comparar las direcciones(sabemos que la diferencia deberia ser aproximadamente 4096)
#que habria que entregar del apartado a
#podemos entregar las modificaciones del apartado b y c juntas

