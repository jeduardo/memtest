all: release

memtest: memtest.c
	gcc -o memtest memtest.c

clean:
	rm memtest

check: memtest
	valgrind --error-exitcode=1 --leak-check=full ./memtest -m 12
	valgrind --error-exitcode=1 --leak-check=full ./memtest -m 2 -s 1
	./memtest -m 1 -s 0
	./memtest -m 0; if [ $$? -eq 1 ] ; then /bin/true ; else /bin/false; fi 
	./memtest -m -1; if [ $$? -eq 1 ] ; then /bin/true ; else /bin/false; fi 

release: memtest check
