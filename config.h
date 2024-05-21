#ifndef config
#define config

#include <stdio.h>
#include <stdlib.h>

#ifndef DEBUG
#define DEBUG 1
#endif

#define TRUE  0
#define FALSE 1

#define MAX_STRING_LENGTH 1024

#if (DEBUG == 1)
#define info(args...)                                                                              \
	{                                                                                          \
		fprintf(stderr, "info (%s): ", __PRETTY_FUNCTION__);                               \
		fprintf(stderr, args);                                                             \
		fprintf(stderr, "\n");                                                             \
	};

#define debug(args...)                                                                             \
	{                                                                                          \
		fprintf(stderr, "\e[0;32mdebug (%s):\e[0m ", __PRETTY_FUNCTION__);                 \
		fprintf(stderr, args);                                                             \
		fprintf(stderr, "\n");                                                             \
	};

#define warning(args...)                                                                           \
	{                                                                                          \
		fprintf(stderr, "\e[0;33mwarning (%s):\e[0m ", __PRETTY_FUNCTION__);               \
		fprintf(stderr, args);                                                             \
		fprintf(stderr, "\n");                                                             \
	};

#define error(args...)                                                                             \
	{                                                                                          \
		fprintf(stderr, "\e[0;31merror:\e[0m ");                                           \
		fprintf(stderr, args);                                                             \
		fprintf(stderr, "\n");                                                             \
	};
#else /* DEBUG=0 */
#define info(args...)	 {};
#define debug(args...)	 {};
#define warning(args...) {};
#define error(args...)	 {};
#endif /* DEBUG */

#define fatal(args...)                                                                             \
	{                                                                                          \
		fprintf(stderr, "\e[0;31mfatal:\e[0m ");                                           \
		fprintf(stderr, args);                                                             \
		fprintf(stderr, "\n");                                                             \
		exit(1);                                                                           \
	};

#endif
