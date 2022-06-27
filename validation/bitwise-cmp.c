#define M 0xffffffff

typedef int __attribute__((bitwise)) b32;

static int eq0(b32 x, b32 y)  { return (x == 0); }
static int eqm(b32 x, b32 y)  { return (x == M); }
static int eqx(b32 x, b32 y)  { return (x == y); }

static int ne0(b32 x, b32 y)  { return (x != 0); }
static int nem(b32 x, b32 y)  { return (x != M); }
static int nex(b32 x, b32 y)  { return (x != y); }

static int lt0(b32 x, b32 y)  { return (x <  0); }
static int ltm(b32 x, b32 y)  { return (x <  M); }
static int ltx(b32 x, b32 y)  { return (x <  y); }

static int lte0(b32 x, b32 y) { return (x <= 0); }
static int ltem(b32 x, b32 y) { return (x <= M); }
static int ltex(b32 x, b32 y) { return (x <= y); }

static int gte0(b32 x, b32 y) { return (x >= 0); }
static int gtem(b32 x, b32 y) { return (x >= M); }
static int gtex(b32 x, b32 y) { return (x >= y); }

static int gt0(b32 x, b32 y)  { return (x >  0); }
static int gtm(b32 x, b32 y)  { return (x >  M); }
static int gtx(b32 x, b32 y)  { return (x >  y); }

/*
 * check-name: bitwise-cmp
 * check-known-to-fail
 */
