.data
NaN : .float 

.text
.global main

filtrar_no_numeros:  # Si alguno es +-inf o NaN, retornar -1


filtrar_ceros:

main:

 # Suponemos que los coeficientes y el vector de salida tienen componentes distintas a NaN o +- inf
    #rdi x
    #rsi y

    #xmm0 a
    #xmm1 b
    #xmm2 c
    #xmm3 d
    #xmm4 e
    #xmm5 f

verificar_coeficientes:
    # Hacer los cmp necesarios para salvar a esta compania (ver en que caso estamos y saltar al caso)



case_1: # todos los coeficientes distintos de 0

        #y = (f-(cd)/a) 1/(e-(bd)/a)
        #x = (c-by)1/a
        jmp verificar_respuestas

case_2: # a=0, b!=0, d!=0, e!=0

        # y = c/b
        # x = (f - (ec)/b) 1/d
        jmp verificar_respuestas

case_3: # a!=0, b=0, d!=0, e!=0

        # x = c/a
        # y = (f - (dc)/a) 1/e
        jmp verificar_respuestas

case_4: # a!=0, b!=0, d=0, e!=0

        # y = f/e
        # x = (c - (bf)/e) 1/a
        jmp verificar_respuestas

case_5: # a!=0, b!=0, d!=0, e=0

        # x = f/d
        # y = (c - (af)/d) 1/b
        jmp verificar_respuestas

case_6: # a=0, b!=0, d!=0, e=0

        # y = c/b
        # x = f/d
        jmp verificar_respuestas

case_7: # a!=0, b=0, d=0, e!=0

        # y = f/e
        # x = c/a

verificar_respuestas:
    # Verificar si en x o en y tenemos NaN o +-inf



fin:
    ret
