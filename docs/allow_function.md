
## Remplit une zone de mémoire avec une valeur donnée
- void *memset(void *s, int c, size_t n);

## Affiche une chaîne de caractères formatée
- int printf(const char *format, ...);

## Alloue un bloc de mémoire de taille spécifiée.
- void *malloc(size_t size);

## Libère un bloc de mémoire précédemment alloué
- void free(void *ptr);

## Ecrit des données dans un fichier ou un descripteur de fichier
- ssize_t write(int fd, const void *buf, size_t count);

## Suspend l'exécution du processus pendant un temps donné
- int usleep(useconds_t usec);

## Obtient l'heure actuelle (heure et microsecondes)
- int gettimeofday(struct timeval *tv, struct timezone *tz);

## Crée un nouveau thread d'exécution.
- int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);

## Détache un thread, permettant sa libération à la fin
- int pthread_detach(pthread_t thread);

## Attend la fin d'un thread et récupère sa valeur de retour
- int pthread_join(pthread_t thread, void **retval);

## Initialise un mutex (verrou d'exclusion mutuelle)
- int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);

## Détruit un mutex.
- int pthread_mutex_destroy(pthread_mutex_t *mutex);

## Verrouille un mutex
- int pthread_mutex_lock(pthread_mutex_t *mutex);

## Déverrouille un mutex.
- int pthread_mutex_unlock(pthread_mutex_t *mutex);
