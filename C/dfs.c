#include<stdio.h>
#include<stdlib.h>

char stack[20]; // stack to save the node
int top=-1; // stack pointer

char result[20]; // result stored here
int p=0;

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

//prototype
char dfs(int i);
void display(void);

typedef enum {false, true} bool;
int main() {
    int l=0;
    int i;
    char k=b[0];

    for(i=0;i<n;i++)
    {
         l=0;
         while(k!=b[l])
           l++;
         k=dfs(l);
    }
    display();
    return 0;
}
void display(void)
{
     int i;
     printf(" DFS of Graph : ");
     for(i=0; i<n; i++)
        printf("%c ", result[i]);
}

void push(char val)
{
     top=top+1;
     stack[top]=val;
}

char pop()
{
     return stack[top];
}

// decide if a node is visited or not
// by checking the result array and stack
bool unVisit(char val)
{
      int i;

      for(i=0; i<p; i++)
        if(val==result[i])
            return false;
      for(i=0; i<=top; i++)
        if(val==stack[top])
            return false;

      return true;
}
char dfs(int i)
{
     int j;
     char m;

     if(top==-1)
     {
          push(b[i]);
     }
     m=pop();
     top--;
     result[p++]=m;
     for(j=0; j<n; j++)
     {
          if(ajMat[i][j]=='y')
          {
               if(unVisit(b[j]))
               {
                     push(b[j]);
               }
          }
     }
    return stack[top];
}

