	.text
	.abicalls
	.option	pic0
	.section	.mdebug.abi32,"",@progbits
	.nan	legacy
	.file	"p1main.c"
	.section	.rodata.cst4,"aM",@progbits,4
	.p2align	2
$CPI0_0:
	.4byte	1085276160
	.text
	.globl	main
	.p2align	2
	.type	main,@function
	.set	nomicromips
	.set	nomips16
	.ent	main
main:
	.frame	$fp,72,$ra
	.mask 	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	.set	noat
	addiu	$sp, $sp, -72
	sw	$ra, 68($sp)
	sw	$fp, 64($sp)
	move	 $fp, $sp
	move	 $1, $5
	move	 $2, $4
	sw	$zero, 60($fp)
	sw	$4, 56($fp)
	sw	$5, 52($fp)
	lui	$4, %hi($CPI0_0)
	lwc1	$f12, %lo($CPI0_0)($4)
	lui	$4, 256
	ori	$5, $4, 4
	sw	$1, 28($fp)
	sw	$2, 24($fp)
	jal	foo
	nop
	sdc1	$f0, 40($fp)
	lui	$1, 16752
	sw	$1, 36($fp)
	lui	$1, 38912
	sw	$1, 32($fp)
	ldc1	$f0, 40($fp)
	lui	$1, %hi($.str)
	addiu	$4, $1, %lo($.str)
	mfc1	$6, $f0
	mfhc1	$7, $f0
	jal	printf
	nop
	ldc1	$f0, 32($fp)
	lui	$1, %hi($.str.1)
	addiu	$4, $1, %lo($.str.1)
	mfc1	$6, $f0
	mfhc1	$7, $f0
	sw	$2, 20($fp)
	jal	printf
	nop
	addiu	$1, $zero, 0
	sw	$2, 16($fp)
	move	 $2, $1
	move	 $sp, $fp
	lw	$fp, 64($sp)
	lw	$ra, 68($sp)
	addiu	$sp, $sp, 72
	jr	$ra
	nop
	.set	at
	.set	macro
	.set	reorder
	.end	main
$func_end0:
	.size	main, ($func_end0)-main

	.type	$.str,@object
	.section	.rodata.str1.1,"aMS",@progbits,1
$.str:
	.asciz	"foo: %f\n"
	.size	$.str, 9

	.type	$.str.1,@object
$.str.1:
	.asciz	"double: %f\n"
	.size	$.str.1, 12


	.ident	"ecc version 2017-08-23 (http://ellcc.org) based on clang version 6.0.0 (trunk 311547)"
	.section	".note.GNU-stack","",@progbits
	.text
