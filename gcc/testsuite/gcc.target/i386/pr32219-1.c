/* { dg-do compile { target *-*-linux* } } */
/* { dg-options "-O2 -fpie" } */

/* Common symbol with -fpie.  */
int xxx;

int
foo ()
{
  return xxx;
}

/* { dg-final { scan-assembler "movl\[ \t\]xxx\\(%rip\\), %eax" { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-not "xxx@GOTPCREL" { target { ! ia32 } } } } */
/* { dg-final { scan-assembler "movl\[ \t\]xxx@GOTOFF\\(%\[^,\]*\\), %eax" { target ia32 } } } */
/* { dg-final { scan-assembler-not "movl\[ \t\]xxx@GOT\\(%\[^,\]*\\), %eax" { target ia32 } } } */
