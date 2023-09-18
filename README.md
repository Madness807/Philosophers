# Fonctions autorisées

| Fonction                  | Utilité                                                                            | Librairie         |
|---------------------------|------------------------------------------------------------------------------------|-------------------|
| `memset`                  | Initialise un bloc de mémoire avec une valeur donnée.                              | `<string.h>`      |
| `printf`                  | Affiche du texte formaté à l'écran.                                                | `<stdio.h>`       |
| `malloc`                  | Alloue un espace mémoire dynamiquement.                                            | `<stdlib.h>`      |
| `free`                    | Libère un espace mémoire précédemment alloué par `malloc`.                         | `<stdlib.h>`      |
| `write`                   | Écrit des données dans un descripteur de fichier.                                  | `<unistd.h>`      |
| `usleep`                  | Met le processus en pause pour un nombre donné de microsecondes.                   | `<unistd.h>`      |
| `gettimeofday`            | Obtient le temps courant avec une précision de microsecondes.                      | `<sys/time.h>`    |
| `pthread_create`          | Crée un nouveau thread.                                                            | `<pthread.h>`     |
| `pthread_detach`          | Détache un thread, permettant sa terminaison automatique à la fin de l'exécution.  | `<pthread.h>`     |
| `pthread_join`            | Attends la terminaison d'un thread.                                                | `<pthread.h>`     |
| `pthread_mutex_init`      | Initialise un mutex.                                                               | `<pthread.h>`     |
| `pthread_mutex_destroy`   | Détruit un mutex.                                                                  | `<pthread.h>`     |
| `pthread_mutex_lock`      | Verrouille un mutex, bloquant si le mutex est déjà verrouillé.                     | `<pthread.h>`     |
| `pthread_mutex_unlock`    | Déverrouille un mutex.                                                             | `<pthread.h>`     |