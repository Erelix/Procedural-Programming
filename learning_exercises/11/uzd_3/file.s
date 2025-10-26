	.file	"file.c"
	.text
	.globl	loadCount
	.bss
	.align 4
loadCount:
	.space 4
	.globl	saveCount
	.align 4
saveCount:
	.space 4
	.section .rdata,"dr"
.LC0:
	.ascii "ab\0"
.LC1:
	.ascii "m1m3.txt\0"
.LC2:
	.ascii "m2.txt\0"
.LC3:
	.ascii "%d\12\0"
	.text
	.globl	saveToFile
	.def	saveToFile;	.scl	2;	.type	32;	.endef
	.seh_proc	saveToFile
saveToFile:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	movl	saveCount(%rip), %eax
	testl	%eax, %eax
	je	.L2
	movl	saveCount(%rip), %eax
	cmpl	$1, %eax
	jne	.L3
.L2:
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	fopen
	movq	%rax, 16(%rbp)
	jmp	.L4
.L3:
	movl	saveCount(%rip), %eax
	cmpl	$2, %eax
	jne	.L4
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	fopen
	movq	%rax, 16(%rbp)
.L4:
	movl	32(%rbp), %edx
	movq	16(%rbp), %rax
	movl	%edx, %r8d
	leaq	.LC3(%rip), %rdx
	movq	%rax, %rcx
	call	fprintf
	movl	$0, -4(%rbp)
	jmp	.L5
.L6:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movq	16(%rbp), %rax
	movl	%edx, %r8d
	leaq	.LC3(%rip), %rdx
	movq	%rax, %rcx
	call	fprintf
	addl	$1, -4(%rbp)
.L5:
	movl	-4(%rbp), %eax
	cmpl	32(%rbp), %eax
	jl	.L6
	movl	saveCount(%rip), %eax
	addl	$1, %eax
	movl	%eax, saveCount(%rip)
	movq	16(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC4:
	.ascii "r\0"
	.text
	.globl	loadFromFile
	.def	loadFromFile;	.scl	2;	.type	32;	.endef
	.seh_proc	loadFromFile
loadFromFile:
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
	movq	%rdx, 40(%rbp)
	movl	loadCount(%rip), %eax
	testl	%eax, %eax
	je	.L8
	movl	loadCount(%rip), %eax
	cmpl	$1, %eax
	jne	.L9
.L8:
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	fopen
	movq	%rax, 32(%rbp)
	jmp	.L10
.L9:
	movl	loadCount(%rip), %eax
	cmpl	$2, %eax
	jne	.L10
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	fopen
	movq	%rax, 32(%rbp)
.L10:
	movq	32(%rbp), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %r8
	movl	$8, %edx
	movq	%rax, %rcx
	call	fgets
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	atoi
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, %rdx
	movq	40(%rbp), %rax
	movq	%rdx, (%rax)
	movl	$0, -4(%rbp)
	jmp	.L11
.L12:
	movq	40(%rbp), %rax
	movq	(%rax), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	leaq	(%rax,%rdx), %rbx
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	atoi
	movl	%eax, (%rbx)
	addl	$1, -4(%rbp)
.L11:
	movq	32(%rbp), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %r8
	movl	$8, %edx
	movq	%rax, %rcx
	call	fgets
	testq	%rax, %rax
	jne	.L12
	movl	loadCount(%rip), %eax
	addl	$1, %eax
	movl	%eax, loadCount(%rip)
	movq	32(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	nop
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (MinGW-W64 x86_64-ucrt-mcf-seh, built by Brecht Sanders) 13.2.0"
	.def	fopen;	.scl	2;	.type	32;	.endef
	.def	fprintf;	.scl	2;	.type	32;	.endef
	.def	fclose;	.scl	2;	.type	32;	.endef
	.def	fgets;	.scl	2;	.type	32;	.endef
	.def	atoi;	.scl	2;	.type	32;	.endef
	.def	malloc;	.scl	2;	.type	32;	.endef
