
#include <iostream>
#include <dlfcn.h>
#include <stdio.h>
#include "string.h"

static int function1(int a, int b)
{
	int (*func)(int,int);
	int t = 0;
	void *handle;
        // Ouverture de la bibliothèque
        handle = dlopen("./libComposant1.so", RTLD_LAZY);
        if(handle == NULL)
        {
                printf("erreur dlopen : %s\n", dlerror());
                exit(EXIT_FAILURE);
        }

        // Chargement de la fonction "func"
        *(void **) (&func) = dlsym(handle, "composant1");
        if (func == NULL)
        {
		printf("Error occured");
                printf("erreur dlsym : %s\n", dlerror());
                dlclose(handle);
                exit(EXIT_FAILURE);
        }

        // Exécution de la fonction "func"
        t = func(a,b);

        // Fermeture de la bibliothèque
        dlclose(handle);

	return t;
}
static int function2(int a, int b)
{
        int (*func)(int,int);
        int t = 0;
        void *handle;
        // Ouverture de la bibliothèque
        handle = dlopen("./libComposant2.so", RTLD_LAZY);
        if(handle == NULL)
        {
                printf("erreur dlopen : %s\n", dlerror());
                exit(EXIT_FAILURE);
        }

        // Chargement de la fonction "func"
        *(void **) (&func) = dlsym(handle, "composant2");
        if (func == NULL)
        {
                printf("Error occured");
                printf("erreur dlsym : %s\n", dlerror());
                dlclose(handle);
                exit(EXIT_FAILURE);
        }

        // Exécution de la fonction "func"
        t = func(a,b);

        // Fermeture de la bibliothèque
        dlclose(handle);

        return t;
}
int main(int argc, char ** argv)
{
	int data1=3;
	int data2=5;

	int valeur=0;
        std::cout << argc << " " << argv[1];
        if(argc == 2)
        {
                if(argv[1] == "Composant1")
                        valeur = function1(data1, data2);
                else if(argv[1] == "Composant2")
                        valeur = function2(data1, data2);
        }

        std::cout << std::endl;
	//std::cout << getComposant1Version() << std::endl;
	std::cout << "valeur :" << valeur << std::endl;
}

