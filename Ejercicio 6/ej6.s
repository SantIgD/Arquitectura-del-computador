

.text
    

filtrar_infinitos:

        movss   %xmm6,%xmm8  # Si xmmi = +-inf => xmm8 = (-1) * (-+inf) = +-inf => xmm8 = inf + (-inf) = NaN
        mulss   %xmm7,%xmm8  # 
        addss   %xmm6,%xmm8  # 

        popq %rcx

        ucomiss %xmm8,%xmm8
        jp singular

        jmp *%rcx

.global resolver_matriz_2x2 

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
        cvtsi2ssq %r8,%xmm7 # xmm7 = -1

filtrar_no_numeros:  # Si alguno es +-inf o NaN, retornar -1

        ucomiss %xmm0,%xmm0
        jp singular #  xmmi = NaN 
        
        ucomiss %xmm1,%xmm1
        jp singular 

        ucomiss %xmm2,%xmm2
        jp singular 

        ucomiss %xmm3,%xmm3
        jp singular 

        ucomiss %xmm4,%xmm4
        jp singular 

        ucomiss %xmm5,%xmm5
        jp singular
        
#  => en las entradas no tengo ningun NaN
        movss   %xmm0,%xmm6  
        pushq $continue_0
        jmp filtrar_infinitos
continue_0:
        movss   %xmm1,%xmm6  
        pushq $continue_1
        jmp filtrar_infinitos
continue_1:
        movss   %xmm2,%xmm6  
        pushq $continue_2
        jmp filtrar_infinitos
continue_2:
        movss   %xmm3,%xmm6  
        pushq $continue_3
        jmp filtrar_infinitos
continue_3:
        movss   %xmm4,%xmm6  
        pushq $continue_4
        jmp filtrar_infinitos
continue_4:
        movss   %xmm5,%xmm6  
        pushq $continue_5
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

        #y = (f-(cd)/a) * 1/(e-(bd)/a)
        #x = (c-by) * 1/a
        movq $1,%rax
        jmp verificar_respuestas

case_2: # a=0, b!=0, d!=0, e!=0

        # y = c/b
        # x = (f - (ec)/b) 1/d
        movq $2,%rax
        jmp verificar_respuestas

case_3: # a!=0, b=0, d!=0, e!=0

        # x = c/a
        # y = (f - (dc)/a) 1/e
        movq $3,%rax
        jmp verificar_respuestas

case_4: # a!=0, b!=0, d=0, e!=0

        # y = f/e
        # x = (c - (bf)/e) 1/a
        movq $4,%rax
        jmp verificar_respuestas

case_5: # a!=0, b!=0, d!=0, e=0
        #xmm0 a
    #xmm1 b
    #xmm2 c
    #xmm3 d
    #xmm4 e
    #xmm5 f

        # x = f/d
        # y = (c - (af)/d) 1/b

        # xmm10 = x = f/d 
        movss %xmm5,%xmm10
        divss %xmm3,%xmm10 

        

        movq $5,%rax
        jmp verificar_respuestas

case_6: # a=0, b!=0, d!=0, e=0  

        # xmm9 = y = c/b 
        movss %xmm2,%xmm9
        divss %xmm1,%xmm9
        
        # xmm10 = x = f/d
        movss %xmm5,%xmm10
        divss %xmm3,%xmm10
        

        movq $6,%rax
        jmp verificar_respuestas

case_7: # a!=0, b=0, d=0, e!=0

        # xmm9 = y = f/e
        movss %xmm5,%xmm9
        divss %xmm4,%xmm9

        # xmm10 = x = c/a
        movss %xmm2,%xmm10
        divss %xmm0,%xmm10

        movq $7,%rax

verificar_respuestas:
    # Verificar si en x o en y tenemos NaN o +-inf

    #xorq %rax,%rax
    #poner en x e y las respuestas
    jmp fin

singular:

      xorq %rax,%rax
      decq %rax

fin:
    ret
