

.text
.global resolver_matriz_2x2

        

filtrar_infinitos:

        movss   %xmm6,%xmm8  # Si xmmi = +-inf => xmm8 = (-1) * (-+inf) = +-inf => xmm8 = inf + (-inf) = NaN
        mulss   %xmm7,%xmm8  # 
        addss   %xmm6,%xmm8  # 

        ucomiss %xmm8,%xmm8
        jnz jmp singular

        pop %rax
        jmp *rax


resolver_matriz_2x2:

        # ax + by = c
        # dx + ey = f

 # Suponemos que los coeficientes y el vector de salida tienen componentes distintas a NaN o +- inf
    #rdi x
    #rsi y

    #xmm0 a
    #xmm1 b
    #xmm2 c
    #xmm3 d
    #xmm4 e
    #xmm5 f

        xorq %r8,%r8
        decq %r8
        cvtsi2ssq %r8,%xmm7 # xmm6 = -1

filtrar_no_numeros:  # Si alguno es +-inf o NaN, retornar -1

        ucomiss %xmm0,%xmm0
        jnz jmp singular #  xmmi = NaN 
        
        ucomiss %xmm1,%xmm1
        jnz jmp singular 

        ucomiss %xmm2,%xmm2
        jnz jmp singular 

        ucomiss %xmm3,%xmm3
        jnz jmp singular 

        ucomiss %xmm4,%xmm4
        jnz jmp singular 

        ucomiss %xmm5,%xmm5
        jnz jmp singular
        
#  => en las entradas no tengo ningun NaN

        movss   %xmm0,%xmm6  
        push continue_0
        jmp filtrar_infinitos
continue_0:
        movss   %xmm1,%xmm6  
        push continue_1
        jmp filtrar_infinitos
continue_1:
        movss   %xmm2,%xmm6  
        push continue_2
        jmp filtrar_infinitos
continue_2:
        movss   %xmm3,%xmm6  
        push continue_3
        jmp filtrar_infinitos
continue_3:
        movss   %xmm4,%xmm6  
        push continue_4
        jmp filtrar_infinitos
continue_4:
        movss   %xmm5,%xmm6  
        push continue_5
        jmp filtrar_infinitos
continue_5:
 
        # En este punto en las entradas estan limpias de NaN y de infinitos
        

verificar_ceros_coeficientes:

        xorq %r8,%r8
        cvtsi2ssq %r8,%xmm6 # xmm6 = 0

        # => a=?,b=?,d=?,e=?

if_case_1:
        ucomiss %xmm0,%xmm6     #xmm0 = a
        jz if_case_2            # => a=0,b=?,d=?,e=?
        
        # => a!=0,b=?,d=?,e=?
        
        ucomiss %xmm1,%xmm6     #xmm1 = b
        jz if_case_3            # => a!=0,b=0,d=?,e=? 

        # => a!=0,b!=0,d=?,e=?

        ucomiss %xmm3,%xmm6     #xmm3 = d
        jz if_case_4            # => a!=0,b=!0,d=0,e=?

        # => a!=0,b!=0,d!=0,e=?

        ucomiss %xmm4,%xmm6     #xmm4 = e
        jz case_5               # => a!=0, b!=0, d!=0, e=0

        # => a!=0,b!=0,d!=0,e!=0
        jmp case_1

if_case_2:

        # => a=0,b=?,d=?,e=?

        ucomiss %xmm1,%xmm6     #xmm1 = b
        jz singular             # => a=0,b=0,d=?,e=?

        # => a=0,b!=0,d=?,e=?

        ucomiss %xmm3,%xmm6     #xmm3 = d
        jz singular             # => a=0,b!=0,d=0,e=?

        # => a=0,b!=0,d!=0,e=?

        ucomiss %xmm4,%xmm6     #xmm4 = e
        jz case_6               # => a=0, b!=0, d!=0, e=0

        # =>  a=0, b!=0, d!=0, e!=0
        jmp case_2

if_case_3:

        # => a!=0,b=0,d=?,e=?

        ucomiss %xmm3,%xmm6     #xmm3 = d
        jz if_case_7             # => a!=0, b=0, d=0, e=?

        # => a!=0,b=0,d!=0,e=?

        ucomiss %xmm4,%xmm6     #xmm4 = e
        jz singular             # => a!=0, b=0, d!=0, e=0

        # => a!=0, b=0, d!=0, e!=0
        jmp case_3

if_case_4:

        # => a!=0,b=!0,d=0,e=?

        ucomiss %xmm4,%xmm6     #xmm4 = e
        jz singular             # => a!=0, b=0, d=0, e=0

        # => a!=0, b!=0, d=0, e!=0
        jmp case_4


if_case_7:

        # => a!=0, b=0, d=0, e=?
        
        ucomiss %xmm4,%xmm6     #xmm4 = e
        jz singular             # => a!=0, b=0, d=0, e=0

        # =>  a!=0, b=0, d=0, e!=0
        jmp case_7



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

singular:
      xorq %rax,%rax
      decq %rax

fin:
    ret
