setup_protected_mode:

	cli	; Clear interrupts
	lgdt	[GDT_descriptor] ; Load GDT

	; Change the last bit of the cr0 register to 1
	mov		eax, cr0 
	or		eax, 1
	mov		cr0, eax ; Now we are in 32bit mode
	jmp		CODE_SEG:enter_protected_mode ; Far jump to code segment

%include"source_files/boot/GDT.asm"

[bits 32]
enter_protected_mode:
	jmp	KERNEL_LOCATION
