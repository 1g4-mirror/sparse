#define __bitwise __attribute__((bitwise))

#define is_signed_type(type)  (((type)-1) <= 0)

typedef   signed int __bitwise s;
typedef unsigned int __bitwise u;

int fos(void);
int fou(void);


int fos(void) { return  is_signed_type(s); }
int fou(void) { return !is_signed_type(u); }

/*
 * check-name: bitwise-is-signed
 * check-command: test-linearize -Wno-decl $file
 *
 * check-output-ignore
 * check-output-returns: 1
 */
