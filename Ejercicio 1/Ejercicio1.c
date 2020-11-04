#include <stdio.h>


int main(int argc, char **argv, char **envp) {
	int i=0;
	
	/*
		Aquí printeamos la cantidad de argumentos en argc, las direcciones a las que apuntan argv y envp 
		y las direcciones de argc, argv, envp y i en la pila
	*/
	printf("argc: %d, argv: %p, envp: %p\ndirs: %p %p %p, &i: %p\n", argc, argv, envp, &argc, &argv, &envp,&i);

	/*
		Aqui printeamos el numero de argumento, la direcion en memoria de cada argumento de argv en la pila ,y las direcciones a las que apuntan y 
        que valores están almacenados en ellas
	*/
	for(i=0;i<argc;i++) {
		printf("Arg: %d, dir: %p, apunta a: %p, valor: %s\n", i,&(argv[i]),argv[i],argv[i]);
	}
	i=0;
	
	/*
		Printeamos la direccion de cada variable de entorno en envp en la pila ,y la direccion de memoria a la que apuntan
		y que valor contienen
	*/
	for(;*envp;envp++) {
		i++;
		printf("Envp: dir: %p, se encuentra la direccion %p a %s\n", envp,*envp,*envp);
	}
	/*
		Printeamos la cantidad de variables de entorno en envp
	*/
	printf("%d\n",i);
	return 0;
}