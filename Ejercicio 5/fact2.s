
.global fact2

fact2:
    
    xorq %rax,%rax # Ponemos rax en 0
    incq %rax      # Ponemos rax en 1

    cmpl $0,%edi
    jz es_0        # Verificar si el numero ingresado es 0, en caso de ser 0 terminar

    movl %edi , %ecx  # Copiamos el valor del argumento a ecx (contador del loop)
    cuerpo_for:
    mull %ecx         # Multiplicamos el valor del contador por eax y se almacena en eax
    loop cuerpo_for
es_0:
    ret               # Retornamos rax, que solo tiene informacion en eax (32 bits)


