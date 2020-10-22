.data 
    formato: .asciz "%ld\n" #ld => decimal en 64 bits //  p "%p\n",&formato: imprime dir de formato
    i: .quad 0xDEADBEEF
    formato2: .asciz "%lx\n"
.text
.global main

    main:
        movq $formato, %rdi # El primer argumento es el formato.
        movq $1234, %rsi # El valor a imprimir.
        xorq %rax, %rax # Cantidad de valores de punto flotante.
        call printf

## item a, valor del registro rsp (chorro de bits en rsp - por ser rsp, este chorro de bits representa la direccion del tope la pila -)
        movq $formato, %rdi # $formato: direccion de memoria de la etiqueta formato
        movq %rsp, %rsi     # El valor a imprimir: Guardamos en rsi el chorro de bits que hay en rsp
        xorq %rax, %rax     
        call printf
        
## item b, imprimimos la direccion de la etiqueta formato en decimal 64bits
        movq $formato, %rdi # $formato: direccion de memoria de la etiqueta formato
        movq $formato, %rsi # El valor a imprimir: Direccion de memoria de la etiqueta formato
        xorq %rax, %rax 
        call printf

## item c, imprimimos la direccion de la etiqueta formato en hexadecimal 64bits
        movq $formato2, %rdi # El primer argumento: direccion de memoria de la etiqueta formato2
        movq $formato, %rsi  # El valor a imprimir:  Direccion de memoria de la etiqueta formato
        xorq %rax, %rax
        call printf

## item d, acceder al valor que apunta el tope de la pila.
        movq $formato, %rdi # El primer argumento: direccion de memoria de la etiqueta formato
        movq (%rsp), %rsi   # El valor a imprimir: elemento en el tope de la pila
        xorq %rax, %rax 
        call printf


## item e, acceder al valor que se encuentra en la direccion rsp+8
        movq $formato, %rdi # El primer argumento: direccion de memoria de la etiqueta formato
        movq 8(%rsp), %rsi  # El valor a imprimir: el quad anterior al quad del tope de la pila
        xorq %rax, %rax 
        call printf

## item f, el valor que se encuentra en la etiqueta i
        movq $formato, %rdi # El primer argumento: direccion de memoria de la etiqueta formato
        movq i, %rsi        # El valor a imprimir: el valor que hay en la etiqueta i
        xorq %rax, %rax 
        call printf

## item g, la direccion de memoria de la etiqueta i
        movq $formato, %rdi # El primer argumento: direccion de memoria de la etiqueta formato
        movq $i, %rsi       # El valor a imprimir: direccion de memoria de la etiqueta i
        xorq %rax, %rax 
        call printf


        ret
