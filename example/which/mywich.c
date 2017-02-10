/****************************************************************************/
/*                                                                          */
/*!     @brief Example to test and demonstrate the using of addPath().      */
/*                                                                          */
/*!        Very easy reconstruction of the shell-command "which"            */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/*! @file   mywhich.c                                                       */
/*! @see    find_processes.c                                                */
/*! @see    find processes.h                                                */
/*! @author Ulrich Becker                                                   */
/*! @date   23.01.2017                                                      */
/****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <find_process.h>

int main( int argc, char** ppArgv )
{
   char buffer[256];

   if( argc < 2 )
   {
      fprintf( stderr, "Missing argument!\n" );
      return EXIT_FAILURE;
   }

   if( addPath( buffer, sizeof( buffer ), ppArgv[1] ) != 0 )
   {
      fprintf( stderr, "ERROR %d: %s\n", errno, buffer );
      return EXIT_FAILURE;
   }

   printf( "%s\n", buffer );
   return EXIT_SUCCESS;
}

/*================================== EOF ====================================*/
