/********************************************
* IST ASA -> Proj 1                         *
* @autor Catarina Coelho 84706              *
* @autor Pedro Dias 84752                   *
********************************************/

#include <stdio.h>
#include <stdlib.h>

/*  final result  */
#define OK 0
#define INCOERENTE 1
#define INSUFICIENTE 2

/*  types of a vertex  */
#define NOT_VISITED 3
#define VISITED 4
#define LOCKED 5

/*  struct of a photo  */
typedef struct photo {
    int photoNumber;
    int state;
    int startTime;
    int endTime;
    struct photo *next;
} *Pphoto;

static Pphoto *graph;   /*pointer for the table of sources*/
int time;               /*time -> DFS Algorithm*/
int state;              /*final state*/
int *order;             /*final order of photos*/
int Nvertex;            /*number of vertex*/

/*  Headers  */
void initData(int n);
void deleteData(int tam);
Pphoto newPhoto (int photo);
void insertPhoto(int source, int destiny);
int verifyLink(int source, int destiny);
void dfs(int tam);
void dfsVisit(int source);


int main (){

    int nPhotos, nConnections, source, destiny, i;
    scanf("%d %d",&nPhotos, &nConnections);
    initData(nPhotos);

    for (i = 0; i < nConnections; i++){
        scanf("%d %d", &source, &destiny);
        insertPhoto(source, destiny);
    }
    dfs(nPhotos);

    if(state == INCOERENTE){printf("Incoerente\n");}
    else if (state == INSUFICIENTE){printf("Insuficiente\n");}
    else{
        for(i = 0; i < nPhotos; i++){
            printf("%d", order[i]);
            if (i < nPhotos - 1){printf(" ");}
        }
        printf("\n");
    }
    deleteData(nPhotos);
    return 0;
}


/*  Initializations of Table & vector of final order -> sources  */
void initData(int n){
    int i;
    graph = (Pphoto*) malloc(sizeof(Pphoto) * n);
    order = (int*) malloc(sizeof(int) * n);
    for(i = 0; i < n; i++){
        graph[i] = newPhoto(i + 1);
        order[i] = 0;
    }
}


/*  Delete all data created  */
void deleteData(int tam){
    int i;
    Pphoto item, next;
    for (i = 0; i < tam; i++){
        for(item = graph[i]; item != NULL; item = next ){
            next = item->next;
            free(item);
        }
    }
    free(graph);
    free(order);
}


/*  Insert new photo on the graph  */
void insertPhoto(int source, int destiny){
    Pphoto new = newPhoto(destiny);
    new->next = graph[source - 1]->next;
    graph[source - 1]->next = new;
}


/*  Create new photo  */
Pphoto newPhoto (int photo){
    Pphoto new = (Pphoto) malloc(sizeof(struct photo));
    new->photoNumber = photo;
    new->state = NOT_VISITED;
    new->startTime = 0;
    new->endTime = 0;
    new->next = NULL;
    return new;
}


/*  Verify link between photos  */
int verifyLink(int source, int destiny){
    Pphoto item;
    for(item = graph[source - 1]->next; item != NULL ; item = item->next){
        if(item->photoNumber == destiny) return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}


/*  DFS Algorithm  */
void dfs(int tam){
    int i;
    time = 1;
    state = OK;
    Nvertex = tam;

    /*verify if every vertex were visited*/
    for (i = 0; i < tam; i++){
        if(graph[i]->state == NOT_VISITED){
            dfsVisit(i + 1);
            if (state == INCOERENTE){break;}
        }
    }

    /*verify if exists more than one topological order*/
    if(state != INCOERENTE){
        for(i = 0; i < tam - 1; i++){
            if(verifyLink(order[i], order[i + 1]) != EXIT_SUCCESS){
                state = INSUFICIENTE;
                break;
            }

        }
    }
}


/*  DFS-Visit Algorithm  */
void dfsVisit(int source){
    Pphoto item;
    graph[source - 1]->state = VISITED;
    graph[source - 1]->startTime = time;
    time++;

    for(item = graph[source - 1]->next; item != NULL; item = item->next){
        int photoNum = item->photoNumber;

        if (graph[photoNum - 1]->state == VISITED){
            state = INCOERENTE;
            break;
        }
        else if (graph[photoNum - 1]->state == NOT_VISITED){
            dfsVisit(photoNum);
        }
    }
    graph[source - 1]->state = LOCKED;
    graph[source - 1]->endTime = time;
    order[--Nvertex] = source;
    time++;
}
