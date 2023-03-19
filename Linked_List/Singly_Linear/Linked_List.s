	.file	"Linked_List.cpp"
	.text
.lcomm _ZStL8__ioinit,1,1
	.align 2
	.globl	_ZN4NodeC2Ev
	.def	_ZN4NodeC2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN4NodeC2Ev
_ZN4NodeC2Ev:
.LFB1841:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movl	$0, (%rax)
	movq	16(%rbp), %rax
	movq	$0, 8(%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.globl	_ZN4NodeC1Ev
	.def	_ZN4NodeC1Ev;	.scl	2;	.type	32;	.endef
	.set	_ZN4NodeC1Ev,_ZN4NodeC2Ev
	.align 2
	.globl	_ZN4NodeD2Ev
	.def	_ZN4NodeD2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN4NodeD2Ev
_ZN4NodeD2Ev:
.LFB1844:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	leaq	32(%rsp), %rbp
	.seh_setframe	%rbp, 32
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	32(%rbp), %rax
	movl	$0, (%rax)
	movq	32(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	je	.L5
	movq	32(%rbp), %rax
	movq	8(%rax), %rbx
	testq	%rbx, %rbx
	je	.L4
	movq	%rbx, %rcx
	call	_ZN4NodeD1Ev
	movl	$16, %edx
	movq	%rbx, %rcx
	call	_ZdlPvy
.L4:
	movq	32(%rbp), %rax
	movq	$0, 8(%rax)
.L5:
	nop
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.globl	_ZN4NodeD1Ev
	.def	_ZN4NodeD1Ev;	.scl	2;	.type	32;	.endef
	.set	_ZN4NodeD1Ev,_ZN4NodeD2Ev
	.align 2
	.globl	_ZN10LinkedListC2Ev
	.def	_ZN10LinkedListC2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN10LinkedListC2Ev
_ZN10LinkedListC2Ev:
.LFB1847:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movq	$0, 8(%rax)
	movq	16(%rbp), %rax
	movl	$0, (%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.globl	_ZN10LinkedListC1Ev
	.def	_ZN10LinkedListC1Ev;	.scl	2;	.type	32;	.endef
	.set	_ZN10LinkedListC1Ev,_ZN10LinkedListC2Ev
	.align 2
	.globl	_ZN10LinkedListD2Ev
	.def	_ZN10LinkedListD2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN10LinkedListD2Ev
_ZN10LinkedListD2Ev:
.LFB1850:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	leaq	32(%rsp), %rbp
	.seh_setframe	%rbp, 32
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	32(%rbp), %rax
	movl	$0, (%rax)
	movq	32(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	je	.L10
	movq	32(%rbp), %rax
	movq	8(%rax), %rbx
	testq	%rbx, %rbx
	je	.L9
	movq	%rbx, %rcx
	call	_ZN4NodeD1Ev
	movl	$16, %edx
	movq	%rbx, %rcx
	call	_ZdlPvy
.L9:
	movq	32(%rbp), %rax
	movq	$0, 8(%rax)
.L10:
	nop
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.globl	_ZN10LinkedListD1Ev
	.def	_ZN10LinkedListD1Ev;	.scl	2;	.type	32;	.endef
	.set	_ZN10LinkedListD1Ev,_ZN10LinkedListD2Ev
	.align 2
	.globl	_ZN10LinkedList11count_nodesEv
	.def	_ZN10LinkedList11count_nodesEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN10LinkedList11count_nodesEv
_ZN10LinkedList11count_nodesEv:
.LFB1852:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "\12List is empty.\12\0"
	.align 8
.LC1:
	.ascii "\12Data from the linked list : \12\0"
.LC2:
	.ascii "|\0"
.LC3:
	.ascii "|->\0"
.LC4:
	.ascii "NULL\12\0"
	.text
	.align 2
	.globl	_ZN10LinkedList7displayEv
	.def	_ZN10LinkedList7displayEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN10LinkedList7displayEv
_ZN10LinkedList7displayEv:
.LFB1853:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L14
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	jmp	.L13
.L14:
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	jmp	.L16
.L17:
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rcx
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %edx
	call	_ZNSolsEi
	movq	%rax, %rcx
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
.L16:
	cmpq	$0, -8(%rbp)
	jne	.L17
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	nop
.L13:
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC5:
	.ascii "\12Memory allocation failed.\12\0"
	.text
	.align 2
	.globl	_ZN10LinkedList12insert_firstEi
	.def	_ZN10LinkedList12insert_firstEi;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN10LinkedList12insert_firstEi
_ZN10LinkedList12insert_firstEi:
.LFB1854:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movl	%edx, 40(%rbp)
	movq	$0, -8(%rbp)
	movl	$16, %ecx
	call	_Znwy
	movq	%rax, %rbx
	movq	%rbx, %rcx
	call	_ZN4NodeC1Ev
	movq	%rbx, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L19
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	jmp	.L18
.L19:
	movq	-8(%rbp), %rax
	movl	40(%rbp), %edx
	movl	%edx, (%rax)
	movq	32(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	32(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	$0, -8(%rbp)
	movq	32(%rbp), %rax
	movl	(%rax), %eax
	leal	1(%rax), %edx
	movq	32(%rbp), %rax
	movl	%edx, (%rax)
.L18:
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN10LinkedList11insert_lastEi
	.def	_ZN10LinkedList11insert_lastEi;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN10LinkedList11insert_lastEi
_ZN10LinkedList11insert_lastEi:
.LFB1855:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movl	%edx, 40(%rbp)
	movq	$0, -8(%rbp)
	movq	$0, -16(%rbp)
	movl	$16, %ecx
	call	_Znwy
	movq	%rax, %rbx
	movq	%rbx, %rcx
	call	_ZN4NodeC1Ev
	movq	%rbx, -16(%rbp)
	cmpq	$0, -16(%rbp)
	jne	.L22
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	jmp	.L21
.L22:
	movq	-16(%rbp), %rax
	movl	40(%rbp), %edx
	movl	%edx, (%rax)
	movq	-16(%rbp), %rax
	movq	$0, 8(%rax)
	movq	32(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	jne	.L24
	movq	32(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	$0, -16(%rbp)
	movq	32(%rbp), %rax
	movl	(%rax), %eax
	leal	1(%rax), %edx
	movq	32(%rbp), %rax
	movl	%edx, (%rax)
	jmp	.L21
.L24:
	movq	32(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.L25
.L26:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
.L25:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	jne	.L26
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	$0, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	32(%rbp), %rax
	movl	(%rax), %eax
	leal	1(%rax), %edx
	movq	32(%rbp), %rax
	movl	%edx, (%rax)
.L21:
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC6:
	.ascii "\12Position is invalid.\12\0"
	.text
	.align 2
	.globl	_ZN10LinkedList18insert_at_positionEii
	.def	_ZN10LinkedList18insert_at_positionEii;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN10LinkedList18insert_at_positionEii
_ZN10LinkedList18insert_at_positionEii:
.LFB1856:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$72, %rsp
	.seh_stackalloc	72
	leaq	64(%rsp), %rbp
	.seh_setframe	%rbp, 64
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movl	%edx, 40(%rbp)
	movl	%r8d, 48(%rbp)
	movq	$0, -8(%rbp)
	movq	$0, -24(%rbp)
	cmpl	$0, 48(%rbp)
	jle	.L28
	movq	32(%rbp), %rax
	movl	(%rax), %eax
	addl	$1, %eax
	cmpl	%eax, 48(%rbp)
	jle	.L29
.L28:
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	jmp	.L27
.L29:
	cmpl	$1, 48(%rbp)
	jne	.L31
	movl	40(%rbp), %edx
	movq	32(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN10LinkedList12insert_firstEi
	jmp	.L27
.L31:
	movl	$16, %ecx
	call	_Znwy
	movq	%rax, %rbx
	movq	%rbx, %rcx
	call	_ZN4NodeC1Ev
	movq	%rbx, -24(%rbp)
	cmpq	$0, -24(%rbp)
	jne	.L32
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	jmp	.L27
.L32:
	movq	-24(%rbp), %rax
	movl	40(%rbp), %edx
	movl	%edx, (%rax)
	movq	-24(%rbp), %rax
	movq	$0, 8(%rax)
	movq	32(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$1, -12(%rbp)
	jmp	.L33
.L34:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
	addl	$1, -12(%rbp)
.L33:
	movl	48(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -12(%rbp)
	jl	.L34
	movq	-8(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	-8(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	32(%rbp), %rax
	movl	(%rax), %eax
	leal	1(%rax), %edx
	movq	32(%rbp), %rax
	movl	%edx, (%rax)
.L27:
	addq	$72, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN10LinkedList12delete_firstEv
	.def	_ZN10LinkedList12delete_firstEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN10LinkedList12delete_firstEv
_ZN10LinkedList12delete_firstEv:
.LFB1857:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movl	$0, -4(%rbp)
	movq	$0, -16(%rbp)
	movq	32(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	jne	.L36
	movl	$-1, %eax
	jmp	.L37
.L36:
	movq	32(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	movq	32(%rbp), %rax
	movq	8(%rax), %rax
	movq	8(%rax), %rdx
	movq	32(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	-16(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-16(%rbp), %rbx
	testq	%rbx, %rbx
	je	.L38
	movq	%rbx, %rcx
	call	_ZN4NodeD1Ev
	movl	$16, %edx
	movq	%rbx, %rcx
	call	_ZdlPvy
.L38:
	movq	$0, -16(%rbp)
	movq	32(%rbp), %rax
	movl	(%rax), %eax
	leal	-1(%rax), %edx
	movq	32(%rbp), %rax
	movl	%edx, (%rax)
	movl	-4(%rbp), %eax
.L37:
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB1858:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	call	__main
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN10LinkedListC1Ev
	leaq	-16(%rbp), %rax
	movl	$10, %edx
	movq	%rax, %rcx
.LEHB0:
	call	_ZN10LinkedList11insert_lastEi
	leaq	-16(%rbp), %rax
	movl	$20, %edx
	movq	%rax, %rcx
	call	_ZN10LinkedList11insert_lastEi
	leaq	-16(%rbp), %rax
	movl	$30, %edx
	movq	%rax, %rcx
	call	_ZN10LinkedList11insert_lastEi
	leaq	-16(%rbp), %rax
	movl	$40, %edx
	movq	%rax, %rcx
	call	_ZN10LinkedList11insert_lastEi
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN10LinkedList7displayEv
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN10LinkedList11count_nodesEv
	movl	%eax, %edx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEi
	movq	%rax, %rcx
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	call	_ZNSolsEPFRSoS_E
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN10LinkedList12delete_firstEv
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN10LinkedList7displayEv
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN10LinkedList12delete_firstEv
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN10LinkedList7displayEv
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN10LinkedList12delete_firstEv
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN10LinkedList7displayEv
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN10LinkedList12delete_firstEv
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN10LinkedList7displayEv
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN10LinkedList12delete_firstEv
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN10LinkedList7displayEv
.LEHE0:
	movl	$0, %ebx
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN10LinkedListD1Ev
	movl	%ebx, %eax
	jmp	.L43
.L42:
	movq	%rax, %rbx
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN10LinkedListD1Ev
	movq	%rbx, %rax
	movq	%rax, %rcx
.LEHB1:
	call	_Unwind_Resume
.LEHE1:
.L43:
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA1858:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1858-.LLSDACSB1858
.LLSDACSB1858:
	.uleb128 .LEHB0-.LFB1858
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L42-.LFB1858
	.uleb128 0
	.uleb128 .LEHB1-.LFB1858
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSE1858:
	.text
	.seh_endproc
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB2391:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSt8ios_base4InitD1Ev
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
	.seh_proc	_Z41__static_initialization_and_destruction_0ii
_Z41__static_initialization_and_destruction_0ii:
.LFB2390:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	cmpl	$1, 16(%rbp)
	jne	.L47
	cmpl	$65535, 24(%rbp)
	jne	.L47
	leaq	_ZStL8__ioinit(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rax
	movq	%rax, %rcx
	call	atexit
.L47:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_GLOBAL__sub_I__ZN4NodeC2Ev;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__ZN4NodeC2Ev
_GLOBAL__sub_I__ZN4NodeC2Ev:
.LFB2392:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	$65535, %edx
	movl	$1, %ecx
	call	_Z41__static_initialization_and_destruction_0ii
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I__ZN4NodeC2Ev
	.ident	"GCC: (x86_64-posix-seh-rev1, Built by MinGW-W64 project) 12.2.0"
	.def	_ZdlPvy;	.scl	2;	.type	32;	.endef
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, "dr"
	.globl	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.linkonce	discard
.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_:
	.quad	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
