/****************************************************************************/
/*                                                                          */
/*!  @brief Example to test and demonstrate the using of findProcesses().   */
/*                                                                          */
/*!  Very easy reconstruction of the shell-command "pidof" by using the     */
/*!  macro OFP_LAMBDA.                                                      */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/*! @file   mypidof.c                                                       */
/*! @see    find_processes.c                                                */
/*! @see    find processes.h                                                */
/*! @author Ulrich Becker                                                   */
/*! @date   17.01.2017                                                      */
/****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <find_process.h>

int main( int argc, char** ppArgv )
{
   if( argc != 2 )
   {
      fprintf( stderr, "Missing argument!\n" );
      return EXIT_FAILURE;
   }
   if( findProcesses( ppArgv[1],
                      OFP_LAMBDA( pArgObj,
                      {
                         printf( "%d\n", pArgObj->pid );
                         return 0; /* continue browsing */
                      }),
                      NULL,
                      //FPROC_RLINK | FPROC_BASENAME
                      FPROC_BASENAME
                      //0
                    ) > 0
     ) /* End of if() */
      return EXIT_SUCCESS; /* At least one running process was found. */
   return EXIT_FAILURE; /* No running process found or error */
}

/*================================== EOF ====================================*/
