.text
.global fact1

fact1:
   cmpq $1,%rdi
   jb caso_base   # rdi <= 1
   jmp caso_recursivo

caso_base:
   xorq %rax ,%rax
   incq %rax
   jmp fin
   
caso_recursivo:
   pushq %rdi  
   decq %rdi
   call fact1
   popq %rdi
   mull %edi

fin:
   ret

