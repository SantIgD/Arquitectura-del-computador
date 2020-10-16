.global main

main:

        #a)
        xorq %rax, %rax  # Ponemos en 0 rax
        inc  %eax

        shll $31 , %eax

        #b)
        xorq %rax, %rax # Inicializar registros
        xorq %rdx, %rdx

        incl  %eax
        incl  %edx    
        
        shll $31 , %eax
        shll $15 , %edx

        orl   %edx, %eax
        
        #c)
        xorq %rax, %rax # Inicializar registros
        xorq %rdx, %rdx

        decl %edx
        decl %eax
        shll $8 , %edx

        andl %edx , %eax

        #d)
        movl $0xaa, %edx
        movl $0xaa, %eax
        shll $24 , %eax

        orl %edx , %eax

        #e)
        xorq %rax, %rax # Inicializar registros
        incl %eax            # Poner 1 en rax
        shll $2 , %eax       # Correr 2 bits a la izquierda (queda 4 en rax)
        incl %eax            # Incrementamos en 1 en rax (queda 5 en rax)

        shll $8 , %eax


        #f)
        xorq %rax, %rax # Inicializar registros
        xorq %rdx, %rdx

        notl %edx
        incl %eax

        shll  $8, %eax
        notl %eax

        andl %edx, %eax

        #g)
        xorq %rax, %rax # Inicializar registros
        xorq %rdx, %rdx

        decl %edx
        addl %edx, %eax 


        #h)
        xorq %rax, %rax # Inicializar registros
        incl %eax
        shll $31 , %eax
        addl %eax ,%eax 

        ret
