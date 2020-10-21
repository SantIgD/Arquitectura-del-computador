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
        movq $formato, %rdi # El primer argumento es el formato.
        movq %rsp, %rsi # El valor a imprimir. Guardamos en rsi el chorro de bits que hay en rsp
        xorq %rax, %rax # Cantidad de valores de punto flotante.
        call printf
        
## item b
        movq $formato, %rdi # El primer argumento es el formato.
        movq $formato, %rsi # El valor a imprimir. Direccion
        xorq %rax, %rax # Cantidad de valores de punto flotante.
        call printf
## item c
        movq $formato2, %rdi # El primer argumento es el formato.
        movq $formato, %rsi # El valor a imprimir. DIreccion
        xorq %rax, %rax # Cantidad de valores de punto flotante.
        call printf

## item d, acceder al valor que apunta el tope de la pila.
        movq $formato, %rdi # El primer argumento es el formato.
        movq (%rsp), %rsi # El valor a imprimir.
        xorq %rax, %rax # Cantidad de valores de punto flotante.
        call printf


## item e
        movq $formato, %rdi # El primer argumento es el formato.
        movq 8(%rsp), %rsi # El valor a imprimir.
        xorq %rax, %rax # Cantidad de valores de punto flotante.
        call printf

## item f
        movq $formato, %rdi # El primer argumento es el formato.
        movq i, %rsi # El valor a imprimir. #copiamos el valor de i
        xorq %rax, %rax # Cantidad de valores de punto flotante.
        call printf

## item g
        movq $formato, %rdi # El primer argumento es el formato.
        movq $i, %rsi # El valor a imprimir. #copiamos el valor de i. DIreccion de memoria de i
        xorq %rax, %rax # Cantidad de valores de punto flotante.
        call printf


        ret
