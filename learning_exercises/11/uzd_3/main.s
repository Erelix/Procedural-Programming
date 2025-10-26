	.file	"main.c"
	.text
	.def	time;	.scl	3;	.type	32;	.endef
	.seh_proc	time
time:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movq	%rax, %rcx
	movq	__imp__time64(%rip), %rax
	call	*%rax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	fillArray
	.def	fillArray;	.scl	2;	.type	32;	.endef
	.seh_proc	fillArray
fillArray:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	24(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	movl	$0, -4(%rbp)
	jmp	.L4
.L5:
	call	rand
	movq	16(%rbp), %rdx
	movq	(%rdx), %rdx
	movl	-4(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$2, %rcx
	leaq	(%rdx,%rcx), %r8
	movslq	%eax, %rdx
	imulq	$1374389535, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$5, %edx
	movl	%eax, %ecx
	sarl	$31, %ecx
	subl	%ecx, %edx
	imull	$100, %edx, %ecx
	subl	%ecx, %eax
	movl	%eax, %edx
	movl	%edx, (%r8)
	addl	$1, -4(%rbp)
.L4:
	movl	-4(%rbp), %eax
	cmpl	24(%rbp), %eax
	jl	.L5
	nop
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "%d \0"
	.text
	.globl	printArray
	.def	printArray;	.scl	2;	.type	32;	.endef
	.seh_proc	printArray
printArray:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L7
.L8:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, %edx
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	printf
	addl	$1, -4(%rbp)
.L7:
	movl	-4(%rbp), %eax
	cmpl	24(%rbp), %eax
	jl	.L8
	nop
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 8
.LC1:
	.ascii "\12\12%d kartus irasyta.\12%d kartus nuskaityta.\12\12\0"
.LC2:
	.ascii "\12All good\0"
.LC3:
	.ascii "\12Something's wrong\0"
.LC4:
	.ascii "\12\12\12Press enter to end\0"
.LC5:
	.ascii "%c\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$96, %rsp
	.seh_stackalloc	96
	.seh_endprologue
	call	__main
	movl	$10, -4(%rbp)
	movl	$0, %ecx
	call	time
	movl	%eax, %ecx
	call	srand
	movl	-4(%rbp), %edx
	leaq	-32(%rbp), %rax
	movq	%rax, %rcx
	call	fillArray
	movl	-4(%rbp), %edx
	leaq	-40(%rbp), %rax
	movq	%rax, %rcx
	call	fillArray
	movl	-4(%rbp), %edx
	leaq	-48(%rbp), %rax
	movq	%rax, %rcx
	call	fillArray
	movq	-32(%rbp), %rdx
	movl	-4(%rbp), %ecx
	movq	-16(%rbp), %rax
	movl	%ecx, %r8d
	movq	%rax, %rcx
	call	saveToFile
	movq	-48(%rbp), %rdx
	movl	-4(%rbp), %ecx
	movq	-16(%rbp), %rax
	movl	%ecx, %r8d
	movq	%rax, %rcx
	call	saveToFile
	movq	-32(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movq	-48(%rbp), %rax
	movq	%rax, %rcx
	call	free
	leaq	-56(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	loadFromFile
	movq	-56(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movq	-40(%rbp), %rdx
	movl	-4(%rbp), %ecx
	movq	-24(%rbp), %rax
	movl	%ecx, %r8d
	movq	%rax, %rcx
	call	saveToFile
	movq	-40(%rbp), %rax
	movq	%rax, %rcx
	call	free
	leaq	-56(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	loadFromFile
	movq	-56(%rbp), %rax
	movq	%rax, %rcx
	call	free
	leaq	-56(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	loadFromFile
	movq	-56(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movq	.refptr.loadCount(%rip), %rax
	movl	(%rax), %edx
	movq	.refptr.saveCount(%rip), %rax
	movl	(%rax), %eax
	movl	%edx, %r8d
	movl	%eax, %edx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movq	.refptr.saveCount(%rip), %rax
	movl	(%rax), %eax
	cmpl	$3, %eax
	jne	.L10
	movq	.refptr.loadCount(%rip), %rax
	movl	(%rax), %eax
	cmpl	$3, %eax
	jne	.L10
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L11
.L10:
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	printf
.L11:
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	-57(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC5(%rip), %rax
	movq	%rax, %rcx
	call	scanf
	movl	$0, %eax
	addq	$96, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (MinGW-W64 x86_64-ucrt-mcf-seh, built by Brecht Sanders) 13.2.0"
	.def	malloc;	.scl	2;	.type	32;	.endef
	.def	rand;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	srand;	.scl	2;	.type	32;	.endef
	.def	saveToFile;	.scl	2;	.type	32;	.endef
	.def	free;	.scl	2;	.type	32;	.endef
	.def	loadFromFile;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr.saveCount, "dr"
	.globl	.refptr.saveCount
	.linkonce	discard
.refptr.saveCount:
	.quad	saveCount
	.section	.rdata$.refptr.loadCount, "dr"
	.globl	.refptr.loadCount
	.linkonce	discard
.refptr.loadCount:
	.quad	loadCount
