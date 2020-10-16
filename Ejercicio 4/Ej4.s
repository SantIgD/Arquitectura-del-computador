    .global main
main:
    movl $-1,%eax # Solo para este size el mov pone en 0
                  # la parte alta del registro.
    movl $2, %ecx
    imull %ecx #Resulado en edx:eax

    # Anda para negativos que se representen con 32 bits (solo observamos el resultado almacenado en eax, ignoramos el edx)
    xorq %r13, %r13
    not  %r13
    shlq $32, %r13

    orq %r13, %rax


    xorq %rax,%rax
    movw $-1,%ax
    movw $2, %cx
    mulw %cx # dx:ax
    
    shlq $16, %rdx
    shlq $48, %rax
    shrq $48, %rax   # [h] logico agrega 0, [a] aritmetico si es negativo completa con 1
    


    orq %rdx , %rax


    
    ret

    