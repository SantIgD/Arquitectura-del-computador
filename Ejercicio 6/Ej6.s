.data 
    format: .asciz "%ld\n"
    i: .quad 0xDEADBEEF
    format2: .asciz "%lx\n"
.text
.global main

    main:
        movq $format, %rdi # El primer argumento es el formato.
        movq $1234, %rsi # El valor a imprimir.
        xorq %rax, %rax # Cantidad de valores de punto flotante.
        call printf

## item a
        movq $format, %rdi # El primer argumento es el formato.
        movq %rsp, %rsi # El valor a imprimir.
        xorq %rax, %rax # Cantidad de valores de punto flotante.
        call printf
        
## item b
        movq $format, %rdi # El primer argumento es el formato.
        movq $format, %rsi # El valor a imprimir. Direccion
        xorq %rax, %rax # Cantidad de valores de punto flotante.
        call printf
## item c
        movq $format2, %rdi # El primer argumento es el formato.
        movq $format, %rsi # El valor a imprimir. DIreccion
        xorq %rax, %rax # Cantidad de valores de punto flotante.
        call printf

## item d
        movq $format2, %rdi # El primer argumento es el formato.
        movq (%rsp), %rsi # El valor a imprimir.
        xorq %rax, %rax # Cantidad de valores de punto flotante.
        call printf


## item e
        movq $format2, %rdi # El primer argumento es el formato.
        movq 8(%rsp), %rsi # El valor a imprimir.
        xorq %rax, %rax # Cantidad de valores de punto flotante.
        call printf

## item f
        movq $format, %rdi # El primer argumento es el formato.
        movq i, %rsi # El valor a imprimir. #copiamos el valor de i
        xorq %rax, %rax # Cantidad de valores de punto flotante.
        call printf

## item g
        movq $format2, %rdi # El primer argumento es el formato.
        movq $i, %rsi # El valor a imprimir. #copiamos el valor de i. DIreccion de memoria de i
        xorq %rax, %rax # Cantidad de valores de punto flotante.
        call printf

        ret
