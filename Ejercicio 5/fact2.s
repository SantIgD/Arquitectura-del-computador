.global fact2

fact2:
    movl %edi , %ecx
    movl $1 ,%eax
    cuerpo_for:
    mull %ecx
    loop cuerpo_for
    ret


