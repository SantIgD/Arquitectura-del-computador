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
	xorq %rax, %rax
	xorq %rcx ,%rcx # Iterador
    xorq %r8 ,%r8



buscar_0x00_larga:
    #retorna 0 si las cadenas son iguales en los primeros %edx caracteres
    #retorna 1 si son distintas


    movq (%rcx,%rdi,1),%r8
    incq %rcx
    cmp $0x00,%r8b
    jnz buscar_0x00_larga
    decq %rcx
    decq %rcx


# En rcx tenemos la cantidad de bytes que tenemos que movernos para pararnos
# en el ultimo caracter de la cadena larga
    
    xorq %r8,%r8
    addq %rdi, %r8
    addq %rcx, %r8  # En %r8 tenemos la direccion de memoria del ultimo caracter de la cadena larga

    movq %rdx,%rcx # En rcx tengo la cantidad de caracteres a comparar, iterador
    xorq %r9,%r9

    decq %rsi # Direccion de la cadena corta

comparacion_de_caracteres:
    movq (%r8,%r9),%r10  # Caracter en la posicion  %r9+%r8 de la cadena larga
    decq %r9

    movq (%rsi,%rcx),%r11  # Caracter en la posicion  %rcx+%rsi de la cadena corta

    cmpb %r11b,%r10b # comparo los caracteres
    jnz  fin_comparacion


loop comparacion_de_caracteres
fin_comparacion:
    incq %rsi # volver al primer Byte de la cadena corta
    
    andq %rcx,%rcx
    jz fin
    incq %rax


fin:	

    ret
