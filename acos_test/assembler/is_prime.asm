section .text
global is_prime

is_prime:
    
    cmp eax, 2
    jb .not_prime
    je .is_prime

    test eax, 1
    jz .not_prime

    mov ecx, 3
    mov ebx, eax

.check_loop:
    mov eax, ecx
    mul eax
    cmp eax, ebx
    jg .is_prime

    mov edx, 0
    mov eax, ebx
    div ecx
    cmp edx, 0
    je .not_prime

    add ecx, 2
    jmp .check_loop

.is_prime:
    mov eax, 1
    ret

.not_prime:
    xor eax, eax
    ret
