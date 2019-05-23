#ifndef L_INTERP_C
#define L_INTERP_C

#include <EXTERN.h>		/* from the Perl distribution     */
#include <perl.h>		/* from the Perl distribution     */

static PerlInterpreter *my_perl;       /***    The Perl interpreter    ***/

int
perlThings (int argc, char **argv, char **env)
{
  PERL_SYS_INIT3 (&argc, &argv, &env);
  my_perl = perl_alloc ();
  perl_construct (my_perl);
  PL_exit_flags |= PERL_EXIT_DESTRUCT_END;
  perl_parse (my_perl, NULL, argc, argv, (char **) NULL);
  perl_run (my_perl);
  perl_destruct (my_perl);
  perl_free (my_perl);
  PERL_SYS_TERM ();
}

#endif
