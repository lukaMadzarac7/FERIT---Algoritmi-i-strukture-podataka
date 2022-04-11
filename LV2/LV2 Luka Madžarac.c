
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* next;
};

int Vsearch(int p[], int n, int br);
int Lsearch(struct Node* head, int x);


int main()
{
    time_t t1, t2;
    int i = 0;
    int j = 0;
    int n = 0;
    int *p;
    time_t t;
    srand(time(NULL));

    printf("Unesi duljinu polja: ");
    scanf("%d", &n);

    int b = n * sizeof(int);
    p = (int *)malloc(b);
    
    t1 = clock();
    for (i=0; i<n; i++){
        p[i] = (rand() % (1000 - 0)) + 0;
    }
    t2 = clock();
    int Te2MinusTe1 = t2 - t1;
    t2 = 0;
    t1 = 0;
    printf("Vrijeme kreiranja polja (mikroS): %d \n", Te2MinusTe1);
    //ispis polja
    /*
    for (i=0; i<n; i++){
        printf("%d  ", p[i]);
    }
    printf("\n");
    */
    
    

    //FillList
    struct Node *headNode, *currentNode, *temp;
    int length = n;
    t1 = clock();
    for (i = 0; i < length; i++)
    {
        currentNode = (struct Node *)malloc(sizeof(struct Node));

        //6
        currentNode->data = p[i];

        //7
        if (i == 0)
        {
            headNode = temp = currentNode;
        }
        else
        {
            //8
            temp->next = currentNode;
            temp = currentNode;
        }
    }

    temp->next = NULL;

    temp = headNode;
    t2 = clock();
    Te2MinusTe1 = 0;
    Te2MinusTe1 = t2 - t1;
    printf("Vrijeme kreiranja liste(mikroS): %d \n", Te2MinusTe1);
    
    //Print list
    /*
    struct Node* x = headNode;
    while(x!=NULL){
        printf("%d  ", x->data);
        x = x->next;
    }
    printf("\n");
    */
    
    int br = 0;
    printf("Koji se broj traži? Odgovor: ");
    scanf("%d", &br);
    printf("\n");
    
    int rezV = Vsearch(p, n, br);
    if (rezV ==-1){
        printf("Broj se ne nalazi u polju :(");
    }
    else{
        printf("Broj se nalazi na %d. mjestu u polju", rezV);
        
    }
    printf("\n");
    int rezL = Lsearch(headNode, br);
    if (rezL == 0){
        printf("Broj se ne nalazi u listi :(");
        
    }
    else{
        printf("Broj se nalazi u listi :)");
        
    }

}

int Vsearch(int p[], int n, int br)
{
    time_t t1, t2;
    t1 = clock();
    int i;
    for (i = 0; i < n; i++){
        if (p[i] == br){
            t2 = clock();
            int Te2MinusTe1 = t2 - t1;
            printf("Vrijeme za sekv. pret. polja(mikroS): %d \n", Te2MinusTe1);
            return i;
            
        }
    }
    t2 = clock();
    int Te2MinusTe1 = t2 - t1;
    printf("Vrijeme za sekv. pret. polja(mikroS): %d \n", Te2MinusTe1);
    return -1;
}

int Lsearch(struct Node* head, int x)
{
    time_t t1, t2;
    t1 = clock();
    struct Node* current = head;
    while (current != NULL)
    {
        if (current->data == x){
            t2 = clock();
            int Te2MinusTe1 = t2 - t1;
            printf("Vrijeme za sekv. pret. liste(mikroS): %d \n", Te2MinusTe1);
            return 1;
            
            
        }
        current = current->next;
    }
    t2 = clock();
    int Te2MinusTe1 = t2 - t1;
    printf("Vrijeme za sekv. pret. liste(mikroS): %d \n", Te2MinusTe1);
    return 0;
}