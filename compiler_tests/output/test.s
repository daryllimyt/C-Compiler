.text

g:
		addiu	$sp, $sp, -60
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
		.cprestore 44
		li	$t0, 20
		add	$v0, $t0, $0
		j	g_end_0

g_end_0:
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
		addiu	$sp, $sp, 60
		beq	$ra, $0, end
		jr	$ra
		nop

f:
		addiu	$sp, $sp, -60
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
		.cprestore 44
		add	$v0, $t0, $0
		j	f_end_1

f_end_1:
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
		addiu	$sp, $sp, 60
		beq	$ra, $0, end
		jr	$ra
		nop

end:
