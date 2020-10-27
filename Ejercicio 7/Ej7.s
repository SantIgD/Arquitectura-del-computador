.text 
.global main

main:

#a
    movq $0x123456789ABCDEF,%rax
    rolq $32 , %rax
    
#b
    movq $0x123456789abcdef, %rax # Copiamos en rax el numero a verificar la cantidad de 1's

    movq $64, %rcx
    xorq %r8,%r8
    incq %r8
   

# Alternativa con testq (realizando and sin guardar resultado) y zeroflag
    xorq %r9,%r9
    for_body:
       testq %rax , %r8 
       jnz es_1
       jmp es_0
    es_1: 
        incq %r9

    es_0:
       rorq $1 ,%rax
    loop for_body     # La respuesta quedo almacenada en r9 


# Alternativa utilizando carryflag (por comportamiento del ror/rol)
    movq $64, %rcx
    xorq %r9,%r9
    for_body2:
       rorq $1 ,%rax
       jc es_1a
       jmp es_0b
    es_1a: 
        incq %r9

    es_0b:
       
    loop for_body2

    movq %r9,%rax

    ret
