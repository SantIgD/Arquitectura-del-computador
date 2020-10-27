.data
	cadenalarga: .asciz "123456"
	cadenacorta: .asciz "23456" #=>1 , 124=>1, 456=>0
.text
.global main
main:
	movq $cadenalarga, %rdi
	movq $cadenacorta, %rsi
	movl $5,%edx            #debe ser la longitud de cadenacorta
	
.global compara
compara:
    #retorna 0 si las cadenas son iguales en los ultimos %edx caracteres
    #retorna 1 si son distintas

	xorq %rax, %rax
	xorq %rcx ,%rcx # Iterador
    xorq %r8 ,%r8

buscar_0x00_larga:
    
    cmpb $0x00,(%r8,%rdi,1)

    jz encontrado

    incq %r8
    jmp buscar_0x00_larga

    encontrado:             # En r8 tenemos la cantidad de Bytes desde el inicio de la cadena larga hasta el 0x00
    decq %r8                # En r8 tenemos la cantidad de Bytes desde el inicio de la cadena larga hasta el ultimo caracter

    addq %rdi, %r8          # En %r8 tenemos la direccion de memoria del ultimo caracter de la cadena larga

    movl %edx,%ecx          # En rcx tengo la cantidad de caracteres a comparar, iterador (parte alta en 0 por caracteristica de l)
    xorq %r9,%r9

    
comparacion_de_caracteres:
   

    movb -1(%rsi,%rcx),%r10b  # Caracter de la cadena corta en la posicion  %rcx+%rsi-1 de la cadena corta

    cmpb %r10b,(%r8,%r9)      # Comparo los caracteres,  (%r8,%r9) => caracter de la cadena larga 
                              # El compilador nos dice que son demasiadas referencias a memorias
                              # si intentamos comparar ambos directamente con la forma k(a,b,c)
    jnz  fin_comparacion
    decq %r9                  # Con este registro me muevo hacia atras en la cadena larga    
loop comparacion_de_caracteres

    jz fin   # las cadenas coinciden en los ultimos edx caracteres

fin_comparacion: # las cadenas no coinciden en los ultimos edx caracteres
    incq %rax
    
fin:	
    ret
