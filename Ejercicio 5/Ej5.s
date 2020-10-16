.global fact1

fact1:
    movl $0 , %eax
    cmpl %edi , %eax
    jz es_igual_a_edi

    jmp seguir


    seguir

    seguir
        ret


