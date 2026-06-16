default rel

section .text

global contarCaracteres
global validarMovimiento
global calcularPuntaje
global detectarObjeto
global contarCeldasLibres

; ==================================================
; contarCaracteres
;
; RCX = mapa
; RDX = totalCeldas
; R8B = caracter
;
; retorna:
; RAX = cantidad encontrada
; ==================================================

contarCaracteres:

    xor rax,rax
    xor r9,r9

.contar_loop:

    cmp r9,rdx
    jge .contar_fin

    mov bl,[rcx+r9]

    cmp bl,r8b
    jne .contar_sig

    inc rax

.contar_sig:

    inc r9
    jmp .contar_loop

.contar_fin:
    ret


; ==================================================
; validarMovimiento
;
; RCX = mapa
; RDX = columnas
; R8  = fila
; R9  = columna
;
; retorna:
; 1 = válido
; 0 = pared
; ==================================================

validarMovimiento:

    mov rax,r8

    imul rax,rdx

    add rax,r9

    mov bl,[rcx+rax]

    cmp bl,'#'
    je .bloqueado

    mov rax,1
    ret

.bloqueado:

    xor rax,rax
    ret


; ==================================================
; calcularPuntaje
;
; RCX = monedas
; RDX = pasos
; R8  = niveles
;
; puntaje =
; monedas*100 - pasos + niveles*500
;
; retorna:
; RAX = puntaje
; ==================================================

calcularPuntaje:

    mov rax,rcx

    imul rax,100

    sub rax,rdx

    mov r9,r8

    imul r9,500

    add rax,r9

    ret


; ==================================================
; detectarObjeto
;
; RCX = mapa
; RDX = columnas
; R8  = fila
; R9  = columna
;
; quinto parámetro:
; [rsp+40]
;
; retorna:
; 1 = coincide
; 0 = no coincide
; ==================================================

detectarObjeto:

    mov rax,r8

    imul rax,rdx

    add rax,r9

    mov bl,[rcx+rax]

    movzx r10, byte [rsp+40]

    cmp bl,r10b
    jne .no

    mov rax,1
    ret

.no:

    xor rax,rax
    ret


; ==================================================
; contarCeldasLibres
;
; RCX = mapa
; RDX = totalCeldas
;
; retorna:
; RAX = cantidad de '.'
; ==================================================

contarCeldasLibres:

    xor rax,rax
    xor r8,r8

.loop_libres:

    cmp r8,rdx
    jge .fin_libres

    mov bl,[rcx+r8]

    cmp bl,'.'
    jne .sig_libres

    inc rax

.sig_libres:

    inc r8
    jmp .loop_libres

.fin_libres:

    ret