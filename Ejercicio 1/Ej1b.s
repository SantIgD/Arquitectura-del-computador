.global main

main:
    movb $0xFE, %al  # copia el valor 0xFE al subregistro al
    movb $-1, %bl    # copia el valor -1 al subregistro bl
    addb %bl, %al    # al+= bl. Suma al subregistro al el valor contenido en bl
    incb %bl         # bl+=1. Incrementa el valor en 1 del subregistro bl
    ret              
    
#El codigo devuelve 253(decimal) ya que es el byte menos significatio de rax
#en binario sin signo
