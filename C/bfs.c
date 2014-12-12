#include<stdio.h>
#include<stdlib.h>

char que[20];  // queue for intermediate result
int front=0, rear=0; // queue pointer

char result[20];
int p=0;

typedef enum {false, true} bool;

/************************
defined the graph to use
a--d----e
|   \   |
b----c /
************************/
int n=5;  // number of vertex, or nodes
char b[20] = {'a', 'b', 'c', 'd', 'e'}; // node value
char ajMat[20][20] = {  // edges defined in two dimentional array 
      {'n', 'y', 'n', 'y', 'n'},
      {'y', 'n', 'y', 'n', 'n'},
      {'n', 'y', 'n', 'y', 'y'},
      {'y', 'n', 'y', 'n', 'y'},
      {'n', 'n', 'y', 'y', 'n'}
};

int bfs(int i );
void display(void);

int main()
{
    int i;

    for(i=0;i<n;i++)
       bfs(i);

    display();
    return 0;
}
void display()
{
     int i;
     printf("BFS of Graph : ");
     for(i=0; i<n; i++)
        printf("%c ",result[i]);
}

void insert(char val)
{
    que[front]=val;
    front++;
}

char del(void)
{
    rear=rear+1;
    return que[rear-1];
}

bool unVisit(char val)
{
    int i;
    for(i=0; i<front; i++)
    {
         if(val==que[i])
             return false;
    }
    return true;
}

int bfs(int i)
{
     char m;
     int j;
     if(front==0)
     {
         insert(b[i]);
     }
     for(j=0; j<n; j++)
     {
         if(ajMat[i][j]=='y')
         {
              if(unVisit(b[j]))
              {
                   insert(b[j]);
              }
         }
     }
     m=del();
     result[p]=m;
     p++;
     return 0;
}

