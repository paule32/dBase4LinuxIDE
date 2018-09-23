;;-------------------------------------------------------
;; Jens Kallup
;; Version 1.  April 25, 2018
;;
;; usage:
;; nasm -f bin -o test test.asm
;;-------------------------------------------------------
%include 'header.asm'	;; elf32 binary header
%include 'funcs.asm'	;; this file contains used functions
			;; the purpose of this is, to save code space!

;;----------------------------------------------------------------
	section .text
	global _start
_start:
	mov	eax, SYS_OPEN
	mov	ebx, func_file_name
	call	dlopen
	mov	[file_desc], eax
	cmp	eax, -1
	jg	.ok
.err1:
	mov	ecx, file_not_found
	mov	edx, file_not_found_len
	call	printstr
	;
	mov	ebx, 1				; exit code
	call	exit
	ret
.ok:
	mov	eax, SYS_CLOSE
	mov	ebx, [file_desc]
	SYSCALL
	cmp	eax, -1
	je	.err2
	;
	mov	ecx, file_found
	mov	edx, file_found_len
	call	printstr
	jmp	.end
.err2:
	mov	ecx, file_err_on_close
	mov	edx, file_err_on_close_len
	call	printstr
	mov	ebx, 1
	call	exit
	ret
.end:
	call    testmal

	mov	ebx, 0
	call	exit
	ret

	section .data
mmap_arg:
  .addr 	dd 0
  .len		dd 512
  .prot 	dd 3
  .flags	dd 34
  .fd		dd -1
  .offset	dd 0
  	section .text
mallocSample:
	mov	eax, 90
	lea	ebx, [mmap_arg]
	int	80h
	ret
testmal:
	call	mallocSample
	ret

	section .data
errorcode:
	db	0
func_file_name:
	db "funcs.bin", 0

;;-----------------------------------------------------
;;file_desc:		dd	0
;;
file_not_found: 	db "file not found.", 10, 0
file_not_found_len	equ $ - file_not_found
;;
file_found:		db "file found", 10, 0
file_found_len		equ $ - file_found
;;
file_err_on_close:	db "file can't be closed", 10, 0
file_err_on_close_len	equ $ - file_err_on_close
;;-----------------------------------------------------

	section .text
%include 'libasm.inc'	;; library file

filesize	equ	$ - $$
