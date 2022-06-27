typedef   signed int __attribute__((bitwise)) bs32;

static int ltu(bs32 x, bs32 y)  { return (x <  y); }
static int lteu(bs32 x, bs32 y) { return (x <= y); }
static int gteu(bs32 x, bs32 y) { return (x >= y); }
static int gtu(bs32 x, bs32 y)  { return (x >  y); }

/*
 * check-name: bitwise-cmps
 * check-command: test-linearize -Wno-decl $file
 *
 * check-output-ignore
 * check-output-excludes: setb\\.
 * check-output-excludes: setbe\\.
 * check-output-excludes: setae\\.
 * check-output-excludes: seta\\.
 */
