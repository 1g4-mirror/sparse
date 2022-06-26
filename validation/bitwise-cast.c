typedef unsigned int u32;
typedef u32 __attribute__((bitwise)) __be32;

/* Implicit casts of 0, legal */
static __be32 foo(void)
{
	__be32 x = 0;

	return 0;
}

/* Explicit cast of 0, legal */
static __be32 bar(void)
{
	return (__be32)0;
}

/* Implicit casts of nonzero, bad */
static __be32 baz(void)
{
	__be32 x = 0x2a;

	return 99;
}

/* Explicit cast of nonzero, bad */
static __be32 quux(void)
{
	return (__be32)1729;
}

/* Explicit case of nonzero forced, legal */
static __be32 quuy(void)
{
	return (__attribute__((force)) __be32) 1730;
}

/* Implicit casts of all ones, legal */
static __be32 foo1(void)
{
	__be32 x = 0xffffffff;
	return x;
}

/* Explicit cast of all ones, legal */
static __be32 bar1(void)
{
	return (__be32)0xffffffff;
}

/* Implicit casts of minus one, legal */
static __be32 foom(void)
{
	__be32 x = -1;
	return x;
}

/* Explicit cast of minus one, legal */
static __be32 barm(void)
{
	return (__be32)-1;
}

/*
 * check-name: conversions to bitwise types
 * check-command: sparse -Wbitwise $file
 * check-error-start
bitwise-cast.c:21:20: warning: incorrect type in initializer (different base types)
bitwise-cast.c:21:20:    expected restricted __be32 [usertype] x
bitwise-cast.c:21:20:    got int
bitwise-cast.c:23:16: warning: incorrect type in return expression (different base types)
bitwise-cast.c:23:16:    expected restricted __be32
bitwise-cast.c:23:16:    got int
bitwise-cast.c:29:17: warning: cast to restricted __be32
 * check-error-end
 */
