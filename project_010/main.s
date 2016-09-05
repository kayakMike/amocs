	.syntax unified
	.arch armv7-m
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.thumb
	.syntax unified
	.file	"main.c"
	.text
	.align	2
	.global	main
	.thumb
	.thumb_func
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	sub	sp, sp, #16
	add	r7, sp, #0
	str	r0, [r7, #4]
	str	r1, [r7]
	movs	r3, #2
	movs	r2, #0
	movs	r1, #14
	movs	r0, #1
	bl	sclk_configure
	ldr	r2, .L3
	ldr	r3, .L3
	ldr	r3, [r3]
	orr	r3, r3, #268435456
	str	r3, [r2]
	movs	r3, #0
	strb	r3, [r7, #15]
.L2:
	ldr	r3, .L3+4
	mov	r2, #268435456
	str	r2, [r3]
	ldr	r3, .L3+8
	mov	r2, #268435456
	str	r2, [r3]
	b	.L2
.L4:
	.align	2
.L3:
	.word	537510016
	.word	537510044
	.word	537510040
	.size	main, .-main
	.align	2
	.global	pll0_disconnect
	.thumb
	.thumb_func
	.type	pll0_disconnect, %function
pll0_disconnect:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	add	r7, sp, #0
	ldr	r3, .L8
	ldr	r3, [r3]
	ubfx	r3, r3, #25, #1
	uxtb	r3, r3
	cmp	r3, #1
	bne	.L7
	ldr	r2, .L8+4
	ldr	r3, [r2]
	bfc	r3, #1, #1
	str	r3, [r2]
	ldr	r2, .L8+8
	ldr	r3, [r2]
	movs	r1, #170
	bfi	r3, r1, #0, #8
	str	r3, [r2]
	ldr	r2, .L8+8
	ldr	r3, [r2]
	movs	r1, #85
	bfi	r3, r1, #0, #8
	str	r3, [r2]
.L7:
	nop
	mov	sp, r7
	@ sp needed
	pop	{r7}
	bx	lr
.L9:
	.align	2
.L8:
	.word	1074774152
	.word	1074774144
	.word	1074774156
	.size	pll0_disconnect, .-pll0_disconnect
	.align	2
	.global	pll0_connect
	.thumb
	.thumb_func
	.type	pll0_connect, %function
pll0_connect:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	add	r7, sp, #0
	ldr	r3, .L13
	ldr	r3, [r3]
	ubfx	r3, r3, #25, #1
	uxtb	r3, r3
	cmp	r3, #0
	bne	.L12
	ldr	r2, .L13+4
	ldr	r3, [r2]
	orr	r3, r3, #2
	str	r3, [r2]
	ldr	r2, .L13+8
	ldr	r3, [r2]
	movs	r1, #170
	bfi	r3, r1, #0, #8
	str	r3, [r2]
	ldr	r2, .L13+8
	ldr	r3, [r2]
	movs	r1, #85
	bfi	r3, r1, #0, #8
	str	r3, [r2]
.L12:
	nop
	mov	sp, r7
	@ sp needed
	pop	{r7}
	bx	lr
.L14:
	.align	2
.L13:
	.word	1074774152
	.word	1074774144
	.word	1074774156
	.size	pll0_connect, .-pll0_connect
	.align	2
	.global	pll0_disable
	.thumb
	.thumb_func
	.type	pll0_disable, %function
pll0_disable:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	add	r7, sp, #0
	ldr	r3, .L18
	ldr	r3, [r3]
	ubfx	r3, r3, #24, #1
	uxtb	r3, r3
	cmp	r3, #1
	bne	.L17
	ldr	r2, .L18+4
	ldr	r3, [r2]
	bfc	r3, #0, #1
	str	r3, [r2]
	ldr	r2, .L18+8
	ldr	r3, [r2]
	movs	r1, #170
	bfi	r3, r1, #0, #8
	str	r3, [r2]
	ldr	r2, .L18+8
	ldr	r3, [r2]
	movs	r1, #85
	bfi	r3, r1, #0, #8
	str	r3, [r2]
.L17:
	nop
	mov	sp, r7
	@ sp needed
	pop	{r7}
	bx	lr
.L19:
	.align	2
.L18:
	.word	1074774152
	.word	1074774144
	.word	1074774156
	.size	pll0_disable, .-pll0_disable
	.align	2
	.global	xosc_enable
	.thumb
	.thumb_func
	.type	xosc_enable, %function
xosc_enable:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	sub	sp, sp, #12
	add	r7, sp, #0
	str	r0, [r7, #4]
	ldr	r3, .L26
	ldr	r3, [r3]
	ubfx	r3, r3, #5, #1
	uxtb	r3, r3
	cmp	r3, #0
	bne	.L25
	ldr	r3, [r7, #4]
	ldr	r2, .L26+4
	cmp	r3, r2
	bhi	.L22
	ldr	r2, .L26
	ldr	r3, [r2]
	bfc	r3, #4, #1
	str	r3, [r2]
	b	.L23
.L22:
	ldr	r2, .L26
	ldr	r3, [r2]
	orr	r3, r3, #16
	str	r3, [r2]
.L23:
	ldr	r2, .L26
	ldr	r3, [r2]
	orr	r3, r3, #32
	str	r3, [r2]
	nop
.L24:
	ldr	r3, .L26
	ldr	r3, [r3]
	ubfx	r3, r3, #6, #1
	uxtb	r3, r3
	cmp	r3, #0
	beq	.L24
.L25:
	nop
	adds	r7, r7, #12
	mov	sp, r7
	@ sp needed
	pop	{r7}
	bx	lr
.L27:
	.align	2
.L26:
	.word	1074774432
	.word	14999999
	.size	xosc_enable, .-xosc_enable
	.align	2
	.global	pll0_enable
	.thumb
	.thumb_func
	.type	pll0_enable, %function
pll0_enable:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	add	r7, sp, #0
	ldr	r3, .L32
	ldr	r3, [r3]
	ubfx	r3, r3, #24, #1
	uxtb	r3, r3
	cmp	r3, #0
	bne	.L31
	ldr	r2, .L32+4
	ldr	r3, [r2]
	orr	r3, r3, #1
	str	r3, [r2]
	ldr	r2, .L32+8
	ldr	r3, [r2]
	movs	r1, #170
	bfi	r3, r1, #0, #8
	str	r3, [r2]
	ldr	r2, .L32+8
	ldr	r3, [r2]
	movs	r1, #85
	bfi	r3, r1, #0, #8
	str	r3, [r2]
	nop
.L30:
	ldr	r3, .L32
	ldr	r3, [r3]
	ubfx	r3, r3, #26, #1
	uxtb	r3, r3
	cmp	r3, #0
	beq	.L30
.L31:
	nop
	mov	sp, r7
	@ sp needed
	pop	{r7}
	bx	lr
.L33:
	.align	2
.L32:
	.word	1074774152
	.word	1074774144
	.word	1074774156
	.size	pll0_enable, .-pll0_enable
	.align	2
	.global	sclk_configure
	.thumb
	.thumb_func
	.type	sclk_configure, %function
sclk_configure:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r4, r7, lr}
	sub	sp, sp, #12
	add	r7, sp, #0
	mov	r4, r0
	mov	r0, r1
	mov	r1, r2
	mov	r2, r3
	mov	r3, r4
	strb	r3, [r7, #7]
	mov	r3, r0	@ movhi
	strh	r3, [r7, #4]	@ movhi
	mov	r3, r1
	strb	r3, [r7, #6]
	mov	r3, r2
	strb	r3, [r7, #3]
	bl	pll0_disconnect
	bl	pll0_disable
	ldrb	r3, [r7, #7]	@ zero_extendqisi2
	cmp	r3, #1
	bne	.L35
	ldr	r0, .L36
	bl	xosc_enable
.L35:
	ldr	r2, .L36+4
	ldr	r3, [r2]
	movs	r1, #1
	bfi	r3, r1, #0, #2
	str	r3, [r2]
	ldr	r2, .L36+8
	ldrh	r3, [r7, #4]	@ movhi
	ubfx	r3, r3, #0, #15
	uxth	r1, r3
	ldr	r3, [r2]
	bfi	r3, r1, #0, #15
	str	r3, [r2]
	ldr	r2, .L36+12
	ldr	r3, [r2]
	movs	r1, #170
	bfi	r3, r1, #0, #8
	str	r3, [r2]
	ldr	r2, .L36+12
	ldr	r3, [r2]
	movs	r1, #85
	bfi	r3, r1, #0, #8
	str	r3, [r2]
	ldr	r2, .L36+8
	ldrb	r1, [r7, #6]	@ zero_extendqisi2
	ldr	r3, [r2]
	bfi	r3, r1, #16, #8
	str	r3, [r2]
	ldr	r2, .L36+12
	ldr	r3, [r2]
	movs	r1, #170
	bfi	r3, r1, #0, #8
	str	r3, [r2]
	ldr	r2, .L36+12
	ldr	r3, [r2]
	movs	r1, #85
	bfi	r3, r1, #0, #8
	str	r3, [r2]
	ldr	r2, .L36+16
	ldrb	r3, [r7, #3]
	strb	r3, [r2]
	bl	pll0_enable
	bl	pll0_connect
	nop
	adds	r7, r7, #12
	mov	sp, r7
	@ sp needed
	pop	{r4, r7, pc}
.L37:
	.align	2
.L36:
	.word	12000000
	.word	1074774284
	.word	1074774148
	.word	1074774156
	.word	1074774276
	.size	sclk_configure, .-sclk_configure
	.ident	"GCC: (crosstool-NG crosstool-ng-1.22.0 - cortex_m3) 5.2.0"
