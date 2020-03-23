
add:
.globl add
		addiu	$sp, $sp, -132
		sw	$fp, 0($sp)
		add	$fp, $sp, $0
		sw	$ra, 4($sp)
		addiu	$t9, $ra, 0
		sw	$s0, 8($sp)
		sw	$s1, 12($sp)
		sw	$s2, 16($sp)
		sw	$s3, 20($sp)
		sw	$s4, 24($sp)
		sw	$s5, 28($sp)
		sw	$s6, 32($sp)
		sw	$s7, 36($sp)
		sw	$gp, 40($sp)
		nop
		li	$t0, 1
		sw	$t0, 100($fp)		# (assign) storing var result
		li	$t0, 2
		sw	$t0, 92($fp)		# (assign) storing var result
		li	$t0, 3
		sw	$t0, 84($fp)		# (assign) storing var result
		li	$t0, 0
		add	$v0, $t0, $0
		j	add_end_0

add_end_0:
		lw	$s0, 8($fp)
		lw	$s1, 12($fp)
		lw	$s2, 16($fp)
		lw	$s3, 20($fp)
		lw	$s4, 24($fp)
		lw	$s5, 28($fp)
		lw	$s6, 32($fp)
		lw	$s7, 36($fp)
		lw	$ra, 4($fp)
		lw	$fp, 0($fp)
		nop
		addiu	$sp, $sp, 132
		beq	$ra, $0, end
		nop
		jr	$ra
		nop

main:
.globl main
		addiu	$sp, $sp, -100
		sw	$fp, 0($sp)
		add	$fp, $sp, $0
		sw	$ra, 4($sp)
		addiu	$t9, $ra, 0
		sw	$s0, 8($sp)
		sw	$s1, 12($sp)
		sw	$s2, 16($sp)
		sw	$s3, 20($sp)
		sw	$s4, 24($sp)
		sw	$s5, 28($sp)
		sw	$s6, 32($sp)
		sw	$s7, 36($sp)
		sw	$gp, 40($sp)
		nop
		sw	$v0, 92($fp)		# (assign) storing function result
		li	$t0, 0
		add	$v0, $t0, $0
		j	main_end_1

main_end_1:
		lw	$s0, 8($fp)
		lw	$s1, 12($fp)
		lw	$s2, 16($fp)
		lw	$s3, 20($fp)
		lw	$s4, 24($fp)
		lw	$s5, 28($fp)
		lw	$s6, 32($fp)
		lw	$s7, 36($fp)
		lw	$ra, 4($fp)
		lw	$fp, 0($fp)
		nop
		addiu	$sp, $sp, 100
		beq	$ra, $0, end
		nop
		jr	$ra
		nop

end:
