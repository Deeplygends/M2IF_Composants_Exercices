
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

	int valeur1=0;
	int valeur2=0;

	//valeur1=composant1(data1,data2);
	valeur1 = function1(data1, data2);
	valeur2 = function2(data1,data2);

	//std::cout << getComposant1Version() << std::endl;
	std::cout << "valeur 1 :" << valeur1 << " valeur 2 :" << valeur2 << std::endl;
}

