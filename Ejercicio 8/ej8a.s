.data
cadena: .asciz "123456"
.text
.global main

main:
	movq $cadena, %rdi
	movb $'0',%sil #Probar luego con diferentes valores (1,a,5....)
    

# si el char esta en la cadena en rax queda 
# la direccion en donde se encontro el char.
# Si no, en rax debe quedar el valor -1

.global busca
busca:
    xorq %rcx,%rcx
    xorq %rax,%rax
    xorq %r8,%r8
    decq %rax

bucle:
    movq (%rcx,%rdi,1),%r8
    cmp $0x00,%r8b
    jz fin

    cmp %r8b,%sil
    jz encontrado

    
    incq %rcx
    jmp bucle
	
encontrado:
    addq %rdi,%rcx
    movq %rcx,%rax    
fin:
    ret


   