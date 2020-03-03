	.file	"compiler.c"
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "masm.exe \0"
.LC1:
	.ascii "link.exe \0"
.LC2:
	.ascii "td.exe \0"
.LC3:
	.ascii "%s %s\0"
.LC4:
	.ascii "%s %s;\0"
.LC5:
	.ascii ".exe\0"
.LC6:
	.ascii "%s%s\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB18:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$80, %rsp
	.seh_stackalloc	80
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	call	__main
	leaq	.LC0(%rip), %rax
	movq	%rax, -32(%rbp)
	leaq	.LC1(%rip), %rax
	movq	%rax, -40(%rbp)
	leaq	.LC2(%rip), %rax
	movq	%rax, -48(%rbp)
	movq	24(%rbp), %rax
	addq	$16, %rax
	movq	(%rax), %rax
	movq	%rax, %rcx
	call	atoi
	movl	%eax, -4(%rbp)
	movq	24(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	strcpy
	leaq	-24(%rbp), %rcx
	leaq	-32(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rcx, %r9
	movq	%rdx, %r8
	leaq	.LC3(%rip), %rdx
	movq	%rax, %rcx
	call	printf
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	system
	leaq	-24(%rbp), %rcx
	leaq	-40(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rcx, %r9
	movq	%rdx, %r8
	leaq	.LC4(%rip), %rdx
	movq	%rax, %rcx
	call	sprintf
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	system
	cmpl	$0, -4(%rbp)
	je	.L2
	leaq	-24(%rbp), %rcx
	leaq	-48(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rcx, %r9
	movq	%rdx, %r8
	leaq	.LC3(%rip), %rdx
	movq	%rax, %rcx
	call	sprintf
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	system
	jmp	.L3
.L2:
	leaq	-24(%rbp), %rdx
	movq	-16(%rbp), %rax
	leaq	.LC5(%rip), %r9
	movq	%rdx, %r8
	leaq	.LC6(%rip), %rdx
	movq	%rax, %rcx
	call	sprintf
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	system
.L3:
	movl	$0, %eax
	addq	$80, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (tdm64-1) 5.1.0"
	.def	atoi;	.scl	2;	.type	32;	.endef
	.def	strcpy;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	system;	.scl	2;	.type	32;	.endef
	.def	sprintf;	.scl	2;	.type	32;	.endef
