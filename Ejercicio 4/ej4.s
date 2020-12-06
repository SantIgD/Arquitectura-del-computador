.text
.arm

.global campesino_ruso

campesino_ruso:

    MOV r2,#0
    MOV r4,#0   @bandera auxiliar

while:
    CMP r1,#1
    MOVLS r4,#1
    
    ANDHIS r3,r1,#1
       @then
        ADDNE r2,r2,r0
        SUBNE r1,r1,#1
       @else
        MOVEQ  r0,r0,LSL #1
        MOVEQ  r1,r1,LSR #1
    CMP r4,#0
    BEQ while
    MOVAL  r0,r0,LSR #1
    ADD r0,r2,r0
    BX lr









