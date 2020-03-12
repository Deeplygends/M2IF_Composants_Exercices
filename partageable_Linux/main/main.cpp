
#include <iostream>
#include <dlfcn.h>
#include <stdio.h>
#include <string>


static int operation(int a, int b, std::string compo)
{
        int (*func)(int,int);
        int t = 0;
        void *handle;
        
        std::cout << std::endl << "Loading Handler";
        // Ouverture de la bibliothèque
        if(compo == "Composant2")
                handle = dlopen("./libComposant2.so", RTLD_LAZY);
        else
                 handle = dlopen("./libComposant1.so", RTLD_LAZY);
        if(handle == NULL)
        {
                printf("erreur dlopen : %s\n", dlerror());
                exit(EXIT_FAILURE);
        }

        // Chargement de la fonction "func"
        if(compo.compare("Composant2") == 0)
        {
                *(void **) (&func) = dlsym(handle, "composant2");
                 std::cout << std::endl << "Call function composant2";
                if (func == NULL)
                {
                        printf("Error occured");
                        printf("erreur dlsym : %s\n", dlerror());
                        dlclose(handle);
                        exit(EXIT_FAILURE);
                }

                // Exécution de la fonction "func"
                t = func(a,b);
                std::cout << std::endl << " value return " << t << std::endl;
        }
        else
        {
              *(void **) (&func) = dlsym(handle, "composant1");
                std::cout << std::endl << "Call function composant1";
                if (func == NULL)
                {
                        printf("Error occured");
                        printf("erreur dlsym : %s\n", dlerror());
                        dlclose(handle);
                        exit(EXIT_FAILURE);
                }

                // Exécution de la fonction "func"
                t = func(a,b);  
                std::cout << std::endl << " value return " << t << std::endl;
        }
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
                std::string arg1(argv[1]);
                std::cout << std::endl << "In the loop " << arg1;
                if(arg1.compare("Composant1") == 0)
                {
                        std::cout << std::endl << "into component 1";
                        valeur = operation(data1, data2, arg1);
                }
                else if(arg1.compare("Composant2") == 0)
                {
                        std::cout << std::endl << "into component 2";
                        valeur = operation(data1, data2, arg1);
                }
        }

        std::cout << std::endl;
	//std::cout << getComposant1Version() << std::endl;
	std::cout << "valeur :" << valeur << std::endl;
}

