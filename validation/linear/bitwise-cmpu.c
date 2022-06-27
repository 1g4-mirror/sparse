typedef unsigned int __attribute__((bitwise)) bu32;

static int ltu(bu32 x, bu32 y)  { return (x <  y); }
static int lteu(bu32 x, bu32 y) { return (x <= y); }
static int gteu(bu32 x, bu32 y) { return (x >= y); }
static int gtu(bu32 x, bu32 y)  { return (x >  y); }

/*
 * check-name: bitwise-cmpu
 * check-command: test-linearize -Wno-decl $file
 * check-known-to-fail
 *
 * check-output-ignore
 * check-output-excludes: setlt\\.
 * check-output-excludes: setlte\\.
 * check-output-excludes: setgte\\.
 * check-output-excludes: setgt\\.
 */
