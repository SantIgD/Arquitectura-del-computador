.global main

main:

    movb $0xFF, %al  # al=0xFF.
    ret


#Con la expresion  "movb $0xFF, %al" 
#copiamos el valor 0xFF al subregistro al (es decir modificamos solo los 8 bits menos significativos del registro rax)

#El codigo devuelve 255 ya que es el byte menos significatio de rax
#en binario sin signo
