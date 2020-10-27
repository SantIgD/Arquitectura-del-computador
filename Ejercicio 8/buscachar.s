.data
cadena: .asciz "123456"
.text
.global main

main:
	movq $cadena, %rdi
	movb $'3',%sil #Probar luego con diferentes valores (1,a,5....)
    

# si el char esta en la cadena en rax queda 
# la direccion en donde se encontro el char.
# Si no, en rax debe quedar el valor -1

.global busca
busca:
    xorq %rcx,%rcx
    xorq %rax,%rax
    decq %rax          # por defecto colocamos rax en -1

bucle:
    cmpb $0x00,(%rcx,%rdi,1)   # Comparamos con el caracter de fin de string 
    jz no_encontrado           # El caracter no pertenece a la cadena almacenada     

    cmpb (%rcx,%rdi,1),%sil    # Comparamos con el caracter que estamos interesados en encontrar
    jz encontrado

    
    incq %rcx
    jmp bucle
	
encontrado:
    addq %rdi,%rcx     # en rcx queda almacenada la direccion del caracter encontrado 
    movq %rcx,%rax    
no_encontrado:
    ret


   