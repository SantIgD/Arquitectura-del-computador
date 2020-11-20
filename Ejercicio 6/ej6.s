

.text
    

filtrar_infinitos:

        movss   %xmm6,%xmm8  # Si xmmi = +-inf => xmm8 = (-1) * (-+inf) = +-inf => xmm8 = inf + (-inf) = NaN
        mulss   %xmm7,%xmm8  # 
        addss   %xmm6,%xmm8  # 

        popq %rcx

        ucomiss %xmm8,%xmm8
        jp singular

        jmp *%rcx

.global solve

solve:

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


        #xmm11 = (e-(bd)/a)
        movss %xmm3,%xmm11              # => xmm11 = d
        mulss %xmm1,%xmm11              # => b*d
        divss %xmm0,%xmm11              # => (bd)/a
        subss %xmm4,%xmm11              # => (bd)/a - e
        mulss %xmm7,%xmm11              # => d - (bd)/a

        #xmm10 = (f-(cd)/a)
        movss %xmm3,%xmm10              # => xmm10 = d
        mulss %xmm2,%xmm10              # => c*d
        divss %xmm0,%xmm10              # => (cd)/a
        subss %xmm5,%xmm10              # => (cd)/a - f
        mulss %xmm7,%xmm10              # => f - (cd)/a

        # xmm10 = y = (f-(cd)/a) * 1/(e-(bd)/a)
        divss %xmm11,%xmm10            

        # xmm9 = x = (c-by) * 1/a
        movss %xmm10,%xmm9              # => xmm9 = y
        mulss %xmm1,%xmm9               # => by
        subss %xmm2,%xmm9               # => by - c
        mulss %xmm7,%xmm9               # => c - by
        divss %xmm0,%xmm9               # => (c-by) * 1/a


        jmp verificar_respuestas

case_2: # a=0, b!=0, d!=0, e!=0

        # y = c/b
        # x = (f - (ec)/b) 1/d


        # xmm10 = y = c/b
        movss %xmm2,%xmm10
        divss %xmm1,%xmm10 

        # xmm9 = x = (f - (ec)/b) 1/d
        movss %xmm10,%xmm9       
        mulss %xmm4,%xmm9
        subss %xmm5,%xmm9 # => xmm9 = ((ec)/b - f)           
        mulss %xmm7,%xmm9 # => xmm7 = (-1) => xmm9 = (f - (ec)/b)
        divss %xmm3,%xmm9 # => xmm9 = (f - (ec)/b) 1/d


        jmp verificar_respuestas

case_3: # a!=0, b=0, d!=0, e!=0

        # x = c/a
        # y = (f - (dc)/a) 1/e


        # xmm9 = x = c/a 
        movss %xmm2,%xmm9
        divss %xmm0,%xmm9 

        # xmm10 = y = (f - (dc)/a) 1/e
        movss %xmm9,%xmm10       
        mulss %xmm3,%xmm10
        subss %xmm5,%xmm10 # => xmm9 = ((dc)/a - f)               
        mulss %xmm7,%xmm10 # => xmm7 = (-1) => xmm9 = (f - (dc)/a)
        divss %xmm4,%xmm10 # => xmm9 = (f - (dc)/a) 1/e

        jmp verificar_respuestas

case_4: # a!=0, b!=0, d=0, e!=0
        
        # y = f/e
        # x = (c - (bf)/e) 1/a
        
        # xmm10 = y = f/e
        movss %xmm5,%xmm10
        divss %xmm4,%xmm10 
        
        # xmm9 = x = (c - (bf)/e) 1/a
        movss %xmm10,%xmm9       
        mulss %xmm1,%xmm9
        subss %xmm2,%xmm9 # => xmm9 = ((bf)/e - c)               
        mulss %xmm7,%xmm9 # => xmm7 = (-1) => xmm9 = (c - (bf)/e)
        divss %xmm0,%xmm9 # => xmm9 = (c - (bf)/e) 1/a
        
        jmp verificar_respuestas

case_5: # a!=0, b!=0, d!=0, e=0
   
        # x = f/d
        # y = (c - (af)/d) 1/b

        # xmm9 = x = f/d 
        movss %xmm5,%xmm9
        divss %xmm3,%xmm9 

        # xmm10 = y = (c - (af)/d) 1/b
        movss %xmm9,%xmm10       
        mulss %xmm0,%xmm10
        mulss %xmm7,%xmm10
        mulss %xmm7,%xmm2
        subss %xmm2,%xmm10 # => xmm10 = ((af)/d - c)               
        # => xmm7 = (-1) => xmm9 = (c - (af)/d)
        divss %xmm1,%xmm10 # => xmm10 = (c - (af)/d) * 1/b
        
        jmp verificar_respuestas

case_6: # a=0, b!=0, d!=0, e=0  

        # xmm10 = y = c/b 
        movss %xmm2,%xmm10
        divss %xmm1,%xmm10
        
        # xmm9 = x = f/d
        movss %xmm5,%xmm9
        divss %xmm3,%xmm9
        
        jmp verificar_respuestas

case_7: # a!=0, b=0, d=0, e!=0

        # xmm10 = y = f/e
        movss %xmm5,%xmm10
        divss %xmm4,%xmm10

        # xmm9 = x = c/a
        movss %xmm2,%xmm9
        divss %xmm0,%xmm9

        movq $7,%rax

verificar_respuestas:
    # Verificar si en x o en y tenemos NaN o +-inf
    
    ucomiss %xmm10,%xmm10
    jp singular

    ucomiss %xmm9,%xmm9
    jp singular
  
    movss %xmm10,%xmm6  
    pushq $continue_8
    jmp filtrar_infinitos
continue_8:

    movss %xmm9,%xmm6  
    pushq $continue_9
    jmp filtrar_infinitos
continue_9:
    
    jmp no_singular

singular:

    xorq %rax,%rax
    decq %rax
    jmp fin

no_singular:
    
    xorq %rax,%rax
    movss %xmm9 ,(%rdi)
    movss %xmm10 , (%rsi)

fin:
    ret
