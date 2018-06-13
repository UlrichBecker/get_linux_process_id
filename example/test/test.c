/****************************************************************************/
/*                                                                          */
/*!  @brief Example to test and demonstrate the using of findProcesses().   */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/*! @file   test.c                                                          */
/*! @see    find_processes.c                                                */
/*! @see    find processes.h                                                */
/*! @author Ulrich Becker                                                   */
/*! @date   17.01.2017                                                      */
/****************************************************************************/

/*
 * NOTE:
 * If you have been made and installed the shared-library via the makefile in
 * /src/makefile just compile this example by the following line:
 *
 * gcc -o t1 -lFindProcess test.c 
 *
 * otherwise invoke the makefile in this directory.
 */

#include <stdio.h>
#include <stdlib.h>
#include <find_process.h>

static int onFoundProcess( OFP_ARG_T* pArg )
{
   int i;
   char* currentArg;

   printf( "\nNumber:            %d\n", pArg->count );
   printf( "Name:              %s\n", pArg->name );
   printf( "pid =              %d\n", pArg->pid );
   printf( "Process directory: %s\n", pArg->procDir );
   printf( "Command-line:      " );
   currentArg = pArg->commandLine.buffer;
   for( i = 0; i < pArg->commandLine.argc; i++ )
      currentArg += printf( "%s ", currentArg );
   printf( "\n" );
   return 0;
}

int main( int argc, char** ppArgv )
{
   int ret;

   printf( "%d running processes\n", forAllProcesses( NULL, NULL ));

   if( argc != 2 )
   {
      fprintf( stderr, "Missing argument!\n" );
      return EXIT_FAILURE;
   }

   ret = findProcesses( ppArgv[1], onFoundProcess, ppArgv, FPROC_BASENAME | FPROC_RLINK );
   if( ret < 0 )
   {
      fprintf( stderr, "Error: findProcesses() returns by %d\n", ret );
      return EXIT_FAILURE;
   }

   printf( "%d running processes of program \"%s\" found\n", ret, ppArgv[1] );
   return EXIT_SUCCESS;
}

/*================================== EOF ====================================*/
