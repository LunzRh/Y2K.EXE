[BITS 		16]						; Bootloader file 16 bits
[ORG 	0x7C00]						; Memory region that BIOS load the file


; Setup video segment 320x200 - 256 color
setup:
	cli
	push 0x0A000
	pop es
	xor di, di
	mov ax, 0x13
	int 	0x10

main:
	mov cx, 0x15
	call sleep
	mov si, str1
	mov dl, 0x0c
	mov dh, 0x0a
	call cursor
	call print
	
	mov cx, 0x15
	call sleep
	mov si, str2
	mov dl, 0x06
	mov dh, 0x0c
	call cursor
	call print

	; Prepare for notepad_rules mode...	
	mov cx, 0x15
	call sleep
	
	xor dl, dl
	xor dh, dh
	call cursor
	
	mov si, str3
	mov bl, 0x7
	sigma:
		mov ah, 0xe
		lodsb
		int 0x10
		or al, al
		jnz sigma
	
	
	add dl, 0x10
	call cursor
	
	notepad_rules:
		; Read char from keyboard
		xor ah, ah
		int 0x16
		
		; Verify if Backspace key was pressed
		cmp al, 0x8
		je delete_char
		
		; Verify if Enter key was pressed
		cmp al, 0x0d
		je inc_y
		
		; Verify if the line reached on end
		cmp dl, 0x27
		jge inc_y
		

		cmp al, 0x1b
		je e1
		cmp al, 0x36
		je e2
		cmp al, 0x39
		je e3
		cmp al, 0x09
		je e4

		
		; Print char on screen
		mov ah, 0x0a
		xor bh, bh
		mov bl, 0x0f
		mov cx, 0x01
		int 0x10
		
		inc dl
		call cursor
		jmp notepad_rules
		
		inc_y:
			xor dl, dl
			inc dh
			call cursor
			jmp notepad_rules
		delete_char:
			dec dl
			call cursor
			jmp notepad_rules
e1:
	mov si, easter1
	jmp eternal
e2:
	mov si, easter2
	jmp eternal
e3: 
	mov si, easter3
	jmp eternal
e4:
	mov si, easter4

eternal:
	xor dl, dl
	xor dh, dh
	call cursor
	call print
	hlt


; Set cursor position
; dl - Columns 	- x
; dh - Rows		- y
cursor:
	cli
	mov ah, 0x2
	mov bh, 0x0
	int 	0x10
	ret

; Print some gay string
; si - string
print:
	cli
	mov bl, 0x21
	l:
		mov ah, 0xe
		lodsb
		inc bl
		int 	0x10
		or al, al
		jnz l
	ret

; Delay
; cx - delay value in microsseconds
sleep:
	cli
	mov ah, 0x86
	mov dx, 0x0
	int 0x15
	ret



str1 db "Happy new Year!", 0
str2 db "Enjoy this useless payload...", 0
str3 db "Type something: ", 0

easter1 db "You find a EasterEgg, OMG!", 0
easter2 db "This Code is so buggy. >:C", 0
easter3 db "I really hate this mbr payload.", 0
easter4 db "You're very gay. B)", 0


times 510 - ($-$$) db 0		; Fill the file with 0 510 times'
dw 0xAA55					; Magic number used by BIOS to identify the file