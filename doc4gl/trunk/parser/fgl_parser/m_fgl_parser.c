
/**
 *  @file
 *  Experimental main to test the new parser.
 *  @todo : Change this to use a unit test tool in C
 */

main() 
{
		if ( parse_4gl("test/fgl/simple/hello.4gl") )
			printf("Hello.4gl test failed\n");
		else
			printf("Hello.4gl test OK\n");

		if ( parse_4gl("test/fgl/simple/reserved_hello.4gl") )
			printf("Reserved Hello.4gl test failed\n");
		else
			printf("Reserved Hello.4gl test OK\n");
}
