# M2IF_Composants_Exercices

12 Mars 2020

Rendu de partageable_Linux => 

	Contient les fichiers sources pour le bonus
								- Ne pas linker les librairies explicitement
								- Récupération du composant a utilisé en ligne de commande
								- utilisation de dlopen et dlsym
						=> Screen demandé dans le dossier screen_exercice_12032020 :
								- Google Cloud VM
								- Compilation de partageble Linux
								- Objdump de main et libcomposant1.so
Rendu de exerciceHash_Linux => Contient les fichiers sources pour l'exercice
		
		la génération s'effectue en faisant un make PARAM=NomDuHash
				NomDuHash peut prendre les valeurs suivantes:
					- NaiveHashComponent
					- sha3Component
					- sha256Component
		Cela génère un dossier bin/ avec la librairie de hash passé en parametre qui pourra être utilisé par le main
		Des screens de chaque compilation sont disponible dans screen_exercice_12032020

		Le Makefile a été modifié pour lancé un clean avant de faire une installation

		Il faut noté que le sha3 utilise l'algorithme kecc
