;;-------------------------------------------------------
;; libasm.inc
;; A simple assembler test lib.
;;
;; Jens Kallup
;;
;; Version 1.  April 25, 2018
;;
;; usage:
;; nasm -f bin -o test test.asm
;;
;;-------------------------------------------------------------------
;; toASCII	takes the double word in eax.
;;
;; Example;
;; convert a byte value:
;;	mov	eax, 0
;;	mov	al, byte [someVar]
;;	call	toASCII
;;
;; convert a word variable:
;;	mov	ax, word [otherVar]
;;	call	toASCII
;;
;; convert a double-word variable:
;;	mov	eax, dword [thirdVar]
;;	call	toASCII
;;
;; convert register dx in decimal:
;;	mov	eax, edx
;;	call	toASCII
;;--------------------------------------------------------------
	section .text
toASCII:
	jmp .entry
	section .data
.operator:
	db	20

.error01:
	db 'format not know', 0
.error01_len: equ $ - .error01

	section .text
.entry:
	cmp	al, 'N' 	; is bin-num?
	je	.num
	;			   ; format not know
	mov	ecx, .error01	   ; point to error string
	mov	edx, .error01_len  ; length of string - init := 0
	call	printstr
	ret
	;
.num:
;	mov	al, byte [data_lhs+1]
	;
	cmp	al, '-' 	; is negative given?
	je	.ops
	cmp	al, '+' 	; is positive?
	je	.ops
	cmp	al, '*' 	; is mul?
	je	.ops
	cmp	al, '/' 	; is div?
	je	.ops
	;
	mov	al, '+' 	; default is plus!
.ops:
	;
	mov	al, 'A'		;
	movzx	eax, al

;	mov	eax, al	; set lower: data_lhs
	mov	edx, 10		; 1 character
	call	printstr
	ret			; return to callee function

;:------------------------------------------------------------------
;; dlopen	open .dll/.so file, and return handle to the file
;;
;; Example:
;;	mov	ebx, file-name
;;	call	dlopen
;;------------------------------------------------------------------
dlopen:
	mov	eax, SYS_OPEN
	SYSCALL
	mov	[file_desc], eax
	cmp	eax, -1
	jg	.ok
.err:
	mov	ecx, cant_load_libary
	mov	edx, cant_load_libary_len
	call	printstr
	
	mov	ebx, 1
	call	exit
	ret
.ok:
	ret
	
	section .data
cant_load_libary:	db "the library could not be loaded", 10, 0
cant_load_libary_len   equ $ - cant_load_libary
file_desc: dd 0
	section .text
;;------------------------------------------------------------------
;; exit:	exit the program with return-code in
;;		ebx.
;; Example:
;;	mov	ebx, return-code
;;	call	exit
;;------------------------------------------------------------------
exit:
	mov	eax, SYS_EXIT	; exit()
	int	0x80		; syscall
	ret

;;------------------------------------------------------------------
;; printstr:	print a string whose address is in
;;		ecx, and whose total number of chars
;;		is in edx.
;; Example:
;;	mov	ecx, msg
;;	mov	edx, MSGLEN
;;	call	prinstr
;;------------------------------------------------------------------
%ifdef PRINTSTR
printstr:
	mov	eax, SYS_WRITE
	mov	ebx, stdout
	int	80h		; syscall
	;
	ret
%endif

;;------------------------------------------------------------------
;; println:	put the cursor on the next line.
;;
;; Example:
;;	call	println
;;------------------------------------------------------------------
%ifdef PRINTLN
%define PRINTSTR
println:
	section .data
.nl:	db 9
	section .text

	push	ecx
	push	edx

	mov	ecx, .nl
	add	ecx, 1
	mov	edx, 1
	call	printstr

	pop	edx
	pop	ecx
	ret
%endif

;;----------------------------------------------------------------
;; is_number: check, if ascii number
;;
;; INPUT:
;;    al = ascii char - parameter 1
;;
;; OUTPUT:
;;	eq flag set for je, if numeric.
;;----------------------------------------------------------------
%ifdef IS_NUMBER
is_number:
	cmp	al, '0'
	jb	.not_number
	cmp	al, '9'
	ja	.not_number
	cmp	al, al
.not_number:
	ret
%endif
	
;;----------------------------------------------------------------
;; is_alpha: check, if alpha 0x20h -> 0x7e
;;
;; INPUT:
;;	al = ascii char
;; OUTPUT:
;;	eq flag set for je, if alpha
;;----------------------------------------------------------------
%ifdef IS_ALPHA
is_alpha:
	cmp	al, 0x20
	jb	.not_alpha
	cmp	al, 0x7e
	ja	.not_alpha
	cmp	al, al
.not_alpha:
	ret
%endif

;;----------------------------------------------------------------
;; crt_putchar_at: display one colored char at location
;;
;; INPUTS:
;;	eax = color - attribute, foreground, background
;;	bl  = column
;;	bh  = row
;;	cx  = char (ascii)
;;
;; OUTPUT:
;;	one colored character
;;----------------------------------------------------------------
%ifdef CRT_PUTCHAR_AT
%define CRT_SET_COLOR	; enable color
%define PRINTSTR	; print string
%define CRT_MOVE_CURSOR ; move the text cursor
%define CRT_SET_COLOR   ; color of character
%define CRT_STR
crt_putchar_at:
	push	ecx
	push	ebx
	call	crt_set_color
	pop	eax
	call	crt_move_cursor
	pop	ecx
	
	cmp	cl, 0x20	; jmp if alpha
	jae	.display_2
	mov	cl, '?'
.display_2:
	cmp	cl, 0x7e
	jbe	.display_4	; jmp if alpha
	mov	cl, '?'
.display_4:
;	mov	byte [.char_out], cl
;	mov	ecx, .char_out
	call	printstr
	ret
	
	section .data
printformat	dw __utf16__("%1c"), 0
;.char_out:
;	db	0
	section .text
%endif

;;----------------------------------------------------------------
;; crt_move_cursor:  move console cursor
;;
;; INPUTS:
;;	al = column
;;	ah = row
;;
;; OUTPUT:
;;	cursor placed on screen
;;
;; NOTES:
;;	this function moves the cursor by sending vt100
;;	escape commands to crt.
;;----------------------------------------------------------------
%ifdef CRT_MOVE_CURSOR
%define QUICK_ASCII
%define PRINTSTR
crt_move_cursor:
	push	edi
	push	eax
	mov	word [vt_row], '00'
	mov	word [vt_column], '00'
	mov	edi, vt_column + 2
	call	quick_ascii
	pop	eax
	xchg	ah, al
	mov	edi, vt_row + 2
	call	quick_ascii
	mov	ecx, vt100_cursor
	mov	edx, vt100_end - vt100_cursor
	call	printstr
	pop	edi
	ret
%endif

;;----------------------------------------------------------------
;; quick_ascii: al = ascii
;;		edi = stuff end point
;;----------------------------------------------------------------
%ifdef QUICK_ASCII
quick_ascii:
	push	byte 10
	pop	ecx
	and	eax, 0xff	; isolate al
.to_entry:
	xor	edx, edx
	div	ecx
	or	dl, 0x30
	mov	byte [edi], dl
	dec	edi
	or	eax, eax
	jnz	.to_entry
	ret
	
	section .data
vt100_cursor:
	db	0x1b, '['
vt_row:
	db	'000'		; row
	db	';'
vt_column:
	db	'000'		; column
	db	'H'
vt100_end:
	section .text
%endif

;;----------------------------------------------------------------
;; crt_str:  display asciiz string at current position
;;
;; INPUTS:
;;	ecx = ptr to string
;;
;; OUTPUT:
;;	uses current color, see crt_set_color, crt_clear
;;----------------------------------------------------------------
%ifdef CRT_STR
%define CRT_WRITE
crt_str:
	xor	edx, edx
.count_again:
	cmp	[ecx + edx], byte 0x00
	je	crt_write
	inc	edx
	jmp	short .count_again
	ret
%endif

;;----------------------------------------------------------------
;; crt_write;  display block of data
;;
;; INPUTS:
;;	ecx = ptr to data
;;	edx = length of block
;;
;; OUTPUT:
;;	uses current color
;;----------------------------------------------------------------
%ifdef CRT_WRITE
%define PRINTSTR
crt_write:
	call	printstr
	ret
%endif

;;----------------------------------------------------------------
;; crt_clear:  clear the console screen
;;
;; INPUTS:
;;	eax = screen color
;;	bl  = char
;;
;; OUTPUT:
;;	screen is cleared
;;----------------------------------------------------------------
%ifdef CRT_CLEAR
%define CRT_STR
%define CRT_OPEN
crt_clear_char:
	
	ret
crt_clear:
	call	crt_set_color
	mov	ecx, clear_msg
	call	crt_str
	ret
%endif

;;----------------------------------------------------------------
;; crt_set_color: set the color of actual console character
;;
;; INPUTS:
;;	eax = color code
;;	eax = aaxxffbb  aa-attr ff-foreground bb-background
;;	30-blk 31-red 32-grn 33-brwn 34-blu 35-purple 36-cyan 37-gry
;;	attributes: 30-normal 31-bold 34-underscore 37-inverse
;;
;; OUTPUT:
;;	vt100 color string sent to display
;;----------------------------------------------------------------
%ifdef CRT_SET_COLOR
%define INSERT_COLORS
%define CRT_STR
%define VT100_COLOR_STR
crt_set_color:
	call	insert_colors
	mov	ecx, vt100_color_str
	call	crt_str
	ret
clear_msg:
	db	0x1b, '[H'
	db	0x1b, '[2J', 0
%endif

;;----------------------------------------------------------------
;; vt100_color_str - escape \mESC data string's
;;----------------------------------------------------------------
%ifdef VT100_COLOR_STR
	section .data
vt100_color_str:
	db	0x1b, '['
vcs_atr:
	db	0, 'm', 0x1b, '[4'
vcs1:	db	0, 'm', 0x1b, '[3'
vcs2:	db	0, 'm', 0
	section .text
%endif

;;----------------------------------------------------------------
;; insert_colors:
;;
;; INPUTS:
;;	eax = color data
;;
;; OUTPUT:
;;	vt100 color string
;;----------------------------------------------------------------
%ifdef INSERT_COLORS
%define VT100_COLOR_STR
insert_colors:
	mov	byte [vcs1], al
	mov	byte [vcs2], ah
	rol	eax, 8
	mov	byte [vcs_atr], al
	ret
%endif

;;----------------------------------------------------------------
;; crt_open: get crt parameters and setup termios
;;
;; INPUTS:
;;	none
;;
;; OUTPUT:
;;	[crt_rows]    - global variable [byte] with row count
;;	[crt_columns] - global variable [byre] with col count
;;----------------------------------------------------------------
%ifdef CRT_OPEN
%define CRT_CLOSE
%define CRT_CLEAR
struc winsize_struc
	.ws_row: resw 1
	.ws_col: resw 1
	.size:
endstruc

struc termios_struc
	.c_iflag: resd 1
	.c_oflag: resd 1
	.c_cflag: resd 1
	.c_lflag: resd 1
	.c_line : resb 1
	.c_cc   : resb 19
	.size:
endstruc

crt_open:
	call	crt_clear
	;
	mov	ecx, 0x5413
	mov	edx, winsize
	call	IOctlTerminal
	mov	eax, [edx]
	cmp	eax, 0x0000FFFF
	jb	.sd_err
	or	eax, eax
	jnz	.sd_10
.sd_err:
	mov	eax, 0x00500018

;; setup singe window template
.sd_10:
	mov	[crt_rows], al
	shr	eax, 16
	mov	[crt_columns], al
	
	mov	ecx, 0x5401
	call	IOctlTerminal0
	mov	esi, edx
	mov	edi, termios
	mov	edx, edi
	push	byte termios_struc_size
	pop	ecx
	cld
	rep	movsb
	mov	byte [edx + termios_struc.c_cc+6], 1
	mov	byte [edx + termios_struc.c_lflag+0], (~0000002q & ~0000001q & ~0000010q)
	mov	byte [edx + termios_struc.c_iflag+1], (~(0002000q >> 8) & ~(0000400q >> 8))
	mov	ecx, 0x5402
	call	IOctlTerminal
	ret
%endif

;;----------------------------------------------------------------
;; crt_hide_cursor: hide the console cursor
;;
;; INPUTS:
;;	none
;;
;; OUTPUTS:
;;	none, register ecx modified
;;----------------------------------------------------------------
%ifdef CRT_HIDE_CURSOR
%define CRT_OPEN
crt_hide_cursor:
	mov	ecx, hide_string
	call	crt_str
	ret
	section .data
hide_string:
	db	0x1b, '[?25l', 0
	section .text
%endif

;;----------------------------------------------------------------
;; crt_show_cursor:  show the console cursor
;;
;; INPUTS:
;;	none
;;
;; OUTPUTS:
;;	none, register ecx modified
;;----------------------------------------------------------------
%ifdef CRT_SHOW_CURSOR
%define CRT_OPEN
crt_show_cursor:
	mov	ecx, show_string
	call	crt_str
	ret
	section .data
show_string:
	db	0x1b, '[?25h', 0
	section .text
%endif

;;----------------------------------------------------------------
;; crt_close: close the termio session
;;
;; INPUTS:
;;	none
;;
;; OUTPUT:
;;	none
;;----------------------------------------------------------------
%ifdef CRT_CLOSE
%define CRT_OPEN
crt_close:
	mov	ecx, 0x5402
IOctlTerminal0:
	mov	edx, termios_orig
IOctlTerminal:
	xor	ebx, ebx	; get code for stdin
	mov	eax, 0x54
	int	0x80
	ret
	
	section .bss
;;--------------------------------------------------------------------------
termios: 		resb termios_struc.size * 1
termios_len:		equ	($ - termios) / termios_struc.size

termios_orig:		resb termios_struc.size * 1
termios_orig_len:	equ	($ - termios_orig) / termios_struc.size

winsize:		resb winsize_struc.size * 1
winsize_len:		equ	($ - winsize) / winsize_struc.size
;;---------------------------------------------------------------------------
	section .data
crt_rows	dd	0	; value number of rows on terminal
crt_columns	dd	0	; number of columns on terminal

	section .text
%endif

;;----------------------------------------------------------------
;; reset_terminal:  set terminal default values
;;----------------------------------------------------------------
%ifdef RESET_TERMINAL
%define SEND_STRINGS
reset_terminal:
	mov	esi, exit_table
	call	send_strings
	ret
%endif

;;----------------------------------------------------------------
;;
;;----------------------------------------------------------------
%ifdef SEND_STRINGS
%define PRINTSTR
send_strings:
.is_loop:
	lodsb
	or	eax, eax
	jz	.is_done
	push	esi
	mov	ecx, eax
	call	printstr
	pop	esi
	jmp	.is_loop
.is_done:
	ret
	
exit_table:
	dd	e1
	dd	e2
	dd	e3
	dd	e4
	dd	e5
	dd	e6
	dd	e7
	dd	e8
	dd	e9
	dd	e10
	dd	0
	
e1	db	0x1b, '7', 0		; save cursor
e2	db	0x1b, '[?1l', 0
e3	db	0x1b, '[?3l', 0
e4	db	0x1b, '[?5l', 0
e5	db	0x1b, '[?6l', 0
e6	db	0x1b, '[?7h', 0
e7	db	0x1b, '[?8h', 0
e8	db	0x1b, '[r', 0x1b, [0m', 0
e9	db	0x1b, '8', 0
e10	db	0x1b, '[?25h', 0	; unhide the cursor
%endif

;;----------------------------------------------------------------
;; color_cursor:  place a colored cursor on the screen
;;
;; INPUTS:
;;	eax = cursor color
;;	bh  = row
;;	bl  = column
;;	ecx = ptr to data under cursor (display char)
;;
;; OUTPUTS:
;;	solid character displayed
;;----------------------------------------------------------------
%ifdef COLOR_CURSOR
%define CRT_PUTCHAR_AT
%define MOV_COLOR
color_cursor:
	mov	cl, [ecx]
	cmp	cl, 0x0a
	je	.cc_x05
	cmp	cl, 0x09
.cc_x05:
	mov	cl, 0x20
	jne	.cc_x10
.cc_x10:
	call	crt_putchar_at
	ret
%endif

;;----------------------------------------------------------------
;; mov_color:
;;----------------------------------------------------------------
%ifdef MOV_COLOR
%define VT100_COLOR_STR
%define STR_MOVE
%define INSERT_COLORS
mov_color:
	push	esi
	call	insert_colors
	mov	esi, vt100_color_str
	call	str_move
	pop	esi
	ret
%endif

;;----------------------------------------------------------------
;;  crt_repeat_horizontal:  repeat display character
;;
;; INPUTS:
;;	eax = color
;;	cx  = character to repeat at cursor position
;;	bl  = column
;;	bh  = row
;;	dl  = number of times to display character
;;
;; OUTPUT:
;;	eax = negative system error# or positive if success
;;----------------------------------------------------------------
%ifdef CRT_REPEAT_HORIZONTAL
%define CRT_PUTCHAR_AT
%define MOV_COLOR
crt_repeat_horizontal:
.looper:
	inc	bl		; next column
	;
	push	ebx
	push	ecx
	push	edx
	call	crt_putchar_at
	;
	pop	edx
	pop	ecx
	pop	ebx
	;		
	dec	dl
	cmp	dl, 1
	jne	.looper
.done:
	ret
%endif

;;----------------------------------------------------------------
;; crt_repeat_vertical:  repeat char vertically
;;
;; INPUTS:
;;	al = column (ascii)
;;	ah = row (ascii)
;;	bl = char
;;	bh = repeat count
;;
;; OUTPUTS:
;;	display character in vertical column
;;----------------------------------------------------------------
%ifdef CRT_REPEAT_VERTICAL
crt_repeat_vertical:
	mov	byte [display_char], bl
	mov	byte [repeat_count], bh
drv_lp:
	push	eax
	call	move_cursor	; al = column; ah = row
	;
	mov	ecx, display_char
	mov	edx, 1
	call	printstr
	;
	pop	eax
	inc	ah
	dec	byte [repeat_count]
	jnz	drv_lp
	ret
	
	section .data
display_char	db	0
repeat_count	db	0
	section .text
%endif

;;----------------------------------------------------------------
;; str_move:  move asciiz string
;;
;; INPUTS:
;;	esi = input string ptr (asciiz)
;;	edi = destination ptr
;;
;; OUTPUT:
;;	edi points at zero (end of moved ascizz string)
;;----------------------------------------------------------------
%ifdef STR_MOVE
str_move:
	cld
ms_loop:
	lodsb
	stosb
	or	al, al
	jnz	ms_loop 	; loop till done
	dec	edi
	ret
%endif

