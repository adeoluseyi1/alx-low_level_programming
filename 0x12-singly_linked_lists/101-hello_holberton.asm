section .data
    format db "Hello, Holberton", 0

section .text
    global main
    extern printf

main:
    mov edi, format
    call printf
    ret
