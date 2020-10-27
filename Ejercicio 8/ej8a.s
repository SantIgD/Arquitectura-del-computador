.data
cadena: .asciz "123456"
.text
.global main

main:
	movq $cadena, %rdi
	movb $'1',%sil #Probar luego con diferentes valores (1,a,5....)
    

# si el char esta en la cadena en rax queda 
# la direccion en donde se encontro el char.
# Si no, en rax debe quedar el valor -1

.global busca
busca:
    xorq %rcx,%rcx
    xorq %r8,%r8   
    xorq %rax,%rax
    decq %rax                # por defecto colocamos rax en -1

bucle:
    movq (%rcx,%rdi,1),%r8
    cmp $0x00,%r8b           # Comparamos con el caracter de fin de string (No se encontro)
    jz no_encontrado                  

    cmp %r8b,%sil            # Comparamos con el caracter que estamos interesados en encontrar
    jz encontrado

    
    incq %rcx
    jmp bucle
	
encontrado:
    addq %rdi,%rcx           # en rcx queda almacenada la direccion del caracter encontrado 
    movq %rcx,%rax    
no_encontrado:
    ret


   