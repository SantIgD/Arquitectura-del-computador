.text
.global fact1

fact1:
    xorq %rax,%rax    # Ponemos en 0 rax
    incq %rax         # Ponemos en 1 rax 

comparar:
    andl %edi,%edi    # Verificar que edi no almacene el valor 0
    jz es_0           # Si es 0 hace un salto al retorno

    mull %edi         # Multiplicamos el valor de edi por el valor de eax y se almacena en eax
    decl %edi         # Decrementamos el valor de edi en 1
    jmp comparar      # Saltamos a comparar
   
es_0:
    ret               # Retornamos el valor en rax donde solo eax tiene informacion

    