flowardp: flowardp_main
	./main
flowardp_main: main.o flowardp.o
	gcc main.o flowardp.o -o main
flowarmem: flowarmem_main
	./main
flowarmem_main: main.o flowarmem.o
	gcc main.o flowarmem.o -o main
flowarrec: flowarrec_main
	./main
flowarrec_main: main.o flowarrec.o
	gcc main.o flowarrec.o -o main
main.o:main.c solve.h
	gcc -c main.c
flowardp.o:flowardp.c solve.h
	gcc -c flowardp.c
flowarmem.o:flowarmem.c solve.h
	gcc -c flowarmem.c
flowarrec.o:flowarrec.c solve.h
	gcc -c flowarrec.c
clean:
	rm -f main main.o flowardp.o flowarmem.o flowarrec.o
