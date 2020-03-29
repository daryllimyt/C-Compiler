.data

# f1: function full
.set noreorder
.text
.align 2
.globl f1
f1:
    # store function arguments
    sw $a0, 0($sp)
    sw $a1, 4($sp)
    sw $a2, 8($sp)
    sw $a3, 12($sp)

    move $t0, $sp
    # f1: function entry
    addiu $sp, $sp, -12
    sw $fp, 4($sp)
    sw $ra, 8($sp)
    move $fp, $sp

    lw $t1, 0($t0)
    sw $t1, 0($sp)
    # f1: function body
    lw $v0, 0($fp)
    j _return_f1
    nop
    # f1: function return
_return_f1:
    move $sp, $fp
    lw $ra, 8($fp)
    lw $fp, 4($fp)
    addiu $sp, $sp, 12
    jr $ra
nop

.data

# f2: function full
.set noreorder
.text
.align 2
.globl f2
f2:
    # store function arguments
    sw $a0, 0($sp)
    sw $a1, 4($sp)
    sw $a2, 8($sp)
    sw $a3, 12($sp)

    move $t0, $sp
    # f2: function entry
    addiu $sp, $sp, -12
    sw $fp, 4($sp)
    sw $ra, 8($sp)
    move $fp, $sp

    lw $t1, 0($t0)      # Loading from argument slots ( first arg )
    sw $t1, 0($sp)      # Storing into local variable area on stack
    lw $t1, 4($t0)      # Loading from argument slots
    sw $t1, -4($sp)     # Storing into local variable area on stack
    lw $t1, 8($t0)      # Loading from argument slots
    sw $t1, -8($sp)     # Storing into local variable area on stack
    lw $t1, 12($t0)     # Loading from argument slots
    sw $t1, -12($sp)        # Storing into local variable area on stack
    lw $t1, 16($t0)     # Loading from argument slots ( last arg )
    sw $t1, -16($sp)        # Storing into local variable area on stack
    # f2: function body
    lw $v0, 0($fp)          # Loading first arg to reg
    sw $v0, -20($sp)        # Storing in first available memory below sp
    lw $v0, -4($fp)         # Loading second arg to reg
    sw $v0, -24($sp)        # Storing in second available memory below sp
    lw $t1, -24($sp)        # Loading these into available regs
    lw $t0, -20($sp)        # Loading these into available regs
    add $v0, $t0, $t1       # Evaluate expression
    sw $v0, -20($sp)        # Store result in first available below sp
    lw $v0, -8($fp)
    sw $v0, -24($sp)
    lw $t1, -24($sp)
    lw $t0, -20($sp)
    add $v0, $t0, $t1
    sw $v0, -20($sp)
    lw $v0, -12($fp)
    sw $v0, -24($sp)
    lw $t1, -24($sp)
    lw $t0, -20($sp)
    add $v0, $t0, $t1
    sw $v0, -20($sp)
    lw $v0, -16($fp)
    sw $v0, -24($sp)
    lw $t1, -24($sp)
    lw $t0, -20($sp)
    add $v0, $t0, $t1
    j _return_f2
nop
# f2: function return
_return_f2:
    move $sp, $fp
    lw $ra, 8($fp)
    lw $fp, 4($fp)
    addiu $sp, $sp, 12
    jr $ra
    nop

.data

# fmain: function full
.set noreorder
.text
.align 2
.globl fmain
fmain:
    # store function arguments
    sw $a0, 0($sp)
    sw $a1, 4($sp)
    sw $a2, 8($sp)
    sw $a3, 12($sp)

    move $t0, $sp
    # fmain: function entry
    addiu $sp, $sp, -12
    sw $fp, 4($sp)
    sw $ra, 8($sp)
    move $fp, $sp

    # fmain: function body
    li $v0, 1
    sw $v0, 0($sp)      # Storing local variables in memory ( first arg)
    li $v0, 2
    sw $v0, -4($sp)     # Storing local variables in memory
    li $v0, 3
    sw $v0, -8($sp)     # Storing local variables in memory
    li $v0, 4
    sw $v0, -12($sp)        # Storing local variables in memory
    li $v0, 5
    sw $v0, -16($sp)        # Storing local variables in memory ( last argument ) 
    
    # f2 entry
    lui $v0,%hi(f2)
    lw $v0,%lo(f2)($v0)
    addiu $sp, $sp, -40     # Decrement stack pointer for f2, 5 args * 4 bytes, this considers the variables already in the frame

    # loading from last arg to first arg, storing upwards from bottom of arg memory area.
    # This means first arg is at the top. At this point $fp = $sp + 40
    # Start loading args for f2
    lw $v0, -16($fp)        # Loading local variables from memory into registers ( last arg )
    sw $v0, 0($sp)          # Storing local variables from registers into arg slots
    lw $v0, -12($fp)        # Loading local variables from memory into registers
    sw $v0, 4($sp)          # Storing local variables from registers into arg slots
    lw $v0, -8($fp)     # Loading local variables from memory into registers
    sw $v0, 8($sp)          # Storing local variables from registers into arg slots
    lw $v0, -4($fp)     # Loading local variables from memory into registers    
    sw $v0, 12($sp)         # Storing local variables from registers into arg slots

    # f1 entry
    lui $v0,%hi(f1)
    lw $v0,%lo(f1)($v0)
    addiu $sp, $sp, -56  # Decrement stack pointer 8*7 for function call

    lw $v0, 0($fp)      # Loading local variables from memory into registers ( first arg )
    sw $v0, 0($sp)          # Storing local variables from registers into arg slots ( first arg )

    # f1 branch
    lw $a0, 0($sp)          # Load arguments for f1 into a0-a3
    jal f1
    nop
    addiu $sp, $sp, 56 # remove f1 frame
    # f1 exit

    sw $v0, 16($sp)     # storing function call result from register into arg slot
    # finish loading args for f2

    # f2 branch
    lw $a0, 0($sp)          # Load arguments for f2 into a0-a3          
    lw $a1, 4($sp)          # Load arguments for f2 into a0-a3
    lw $a2, 8($sp)          # Load arguments for f2 into a0-a3
    lw $a3, 12($sp)         # Load arguments for f2 into a0-a3
    jal f2
    nop
    addiu $sp, $sp, 40
    # f2 exit

    j _return_fmain
    nop
# fmain: function return
_return_fmain:
    move $sp, $fp
    lw $ra, 8($fp)
    lw $fp, 4($fp)
    addiu $sp, $sp, 12
    jr $ra
    nop

.data