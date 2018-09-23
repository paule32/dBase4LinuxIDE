%define IS_ALPHA
%define PRINTSTR
%define CRT_PUTCHAR_AT
%define CRT_OPEN
%define CRT_CLOSE
%define CRT_CLEAR
%define CRT_REPEAT_HORIZONTAL
%define MOV_COLOR

%assign stdout           1       ; flag for "write" to stdout

%assign true  1          ; bool true
%assign false 0

%macro SYSCALL 0
int 0x80
%endmacro

SYS_EXIT	EQU 01h  ; syscall for "exit" 32-bit x86 kernel api
SYS_READ        EQU 03h  ;
SYS_WRITE       EQU 04h  ; syscall for "write" ...
SYS_OPEN	EQU 05h
SYS_CLOSE	EQU 06h
SYS_LSEEK	EQU 13h


O_RDONLY	equ 0
O_WRONLY	equ 1
O_RDWR		equ 2

