#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 3000

typedef struct Vector{
  char name[10];
  double vec[3];
}Vec;

void generatevec(char* buffer, Vec* A, Vec* B)
{
  char number[MAX];
  int acc, acc2, i, j, arrowA=-1, arrowB=-1, lowBracketA = -1, highBracketA = -1, lowBracketB = -1, highBracketB = -1;
  for(i=0; i< strlen(buffer); i++)
  {
    if(buffer[i] == '-') 
    {
        arrowA = i;
        break;
    }
  }
  for(i=arrowA + 1; i< strlen(buffer); i++)
  {
    if(buffer[i] == '-') 
    {
        arrowB = i;
    }
  }
  for(i=arrowA; i>-1; i--)
  {
    if(buffer[i] == '(')
    {
      lowBracketA = i;
      break;
    }
  }
  for(i=arrowA; i<strlen(buffer); i++)
  {
    if(buffer[i] == ')')
    {
      highBracketA = i;
      break;
    }
  }
  for(i=arrowB; i>-1; i--)
  {
    if(buffer[i] == '(')
     {
      lowBracketB = i;
      break;
    }
  }
  for(i=arrowB; i<strlen(buffer); i++)
  {
    if(buffer[i] == ')')
     {
      highBracketB = i;
      break;
    }
  }
  for(i = lowBracketA; i<=highBracketA; i++)
        A->name[i - lowBracketA] = buffer[i];
  A->name[i - lowBracketA] = '\0';
  for(i = lowBracketB; i<=highBracketB; i++)
        B->name[i - lowBracketB] = buffer[i];
  B->name[i - lowBracketB] = '\0';
  
  for(i = highBracketA; i<strlen(buffer); i++)
  {
    if(buffer[i] == '(')
    {
      lowBracketA = i;
      break;
    }
  }
  for(i = lowBracketA; i<strlen(buffer); i++)
  {
    if(buffer[i] == ')')
    {
      highBracketA = i;
      break;
    }
  }
  for(i = highBracketB; i<strlen(buffer); i++)
  {
    if(buffer[i] == '(')
    {
      lowBracketB = i;
      break;
    }
  }
  for(i = lowBracketB; i<strlen(buffer); i++)
  {
    if(buffer[i] == ')')
    {
      highBracketB = i;
      break;
    }
  }
  acc = 0;
  acc2 = 0;
  for(i = lowBracketA; i<highBracketA; i++)
  {
    
    if(buffer[i] != '(' && buffer[i] != ','&&buffer[i] != ' '&& buffer[i] != ';')
    {
      if(acc<3)
      {
       
        for(j=i; j<highBracketA; j++)
        { 
          if(buffer[j] != ')' && buffer[j] != ','&& buffer[j] != ' ' && buffer[j] != ';')
          {
            
            number[acc2] = buffer[j];
            acc2++;
          }
          else 
          {
            i = j;
            break;
          }
        
        }
        number[acc2+1] = '\0';
      
        acc2 = 0;
        
        A->vec[acc] = atof(number);
        acc ++;
        int k;
        for(k=0; k<30; k++)
          number[k] = 0;
      
     
      }
    }
  }
  acc = 0;
  acc2 = 0;
  for(i = lowBracketB; i<highBracketB; i++)
  {
    
    if(buffer[i] != '(' && buffer[i] != ','&&buffer[i] != ' '&& buffer[i] != ';')
    {
      if(acc<3)
      {
       
        for(j=i; j<highBracketB; j++)
        { 
          if(buffer[j] != ')' && buffer[j] != ','&& buffer[j] != ' ' && buffer[j] != ';')
          {
            number[acc2] = buffer[j];
            acc2++;
          }
          else 
          {
            i = j;
            break;
          }
        
        }
        number[acc2+1] = '\0';
       
        acc2 = 0;
        
        B->vec[acc] = atof(number);
        acc ++;
        int k;
        for(k=0; k<30; k++)
          number[k] = 0;
      
      
      }
    }
  }

}
void getoperation(char* buffer, int* operation, Vec* A, Vec* B)
{
  char nameA[10];
 
  int acc, acc2, i, j, arrowA=-1, arrowB=-1, lowBracketA = -1, highBracketA = -1, lowBracketB = -1, highBracketB = -1;
  for(i=0; i< strlen(buffer); i++)
  {
    if(buffer[i] == '-') 
    {
        arrowA = i;
        break;
    }
  }
  for(i=arrowA + 1; i< strlen(buffer); i++)
  {
    if(buffer[i] == '-') 
    {
        arrowB = i;
    }
  }
  //printf("arrowA = %d, arrowB = %d\n", arrowA, arrowB);
  for(i=arrowA; i>-1; i--)
  {
    if(buffer[i] == '(')
    {
      lowBracketA = i;
      break;
    }
  }
  for(i=arrowA; i<strlen(buffer); i++)
  {
    if(buffer[i] == ')')
    {
      highBracketA = i;
      break;
    }
  }
  for(i=arrowB; i>-1; i--)
  {
    if(buffer[i] == '(')
     {
      lowBracketB = i;
      break;
    }
  }
  //printf("lowA = %d, highA = %d lowB = %d\n", lowBracketA, highBracketA, lowBracketB);
  for(i = lowBracketA; i<=highBracketA; i++)
  {
    nameA[i - lowBracketA] = buffer[i];
    //printf("letra %c na posicao %d do nome\n", buffer[i], i-lowBracketA);
  }
  //printf("\\0 na posicao %d\n", i+1-lowBracketA);
  nameA[i+1-lowBracketA] = '\0';
  
  //printf("nameA = %s\n", nameA);
  //printf("A->name = %s\n", A->name);
  operation[0] = -1;
  for(i=highBracketA; i<lowBracketB; i++)
  {
    
    if(buffer[i] =='+')
      operation[0] = 0;
    if(buffer[i]=='-')
      operation[0] = 1;
    if(buffer[i]=='x'|| buffer[i] == 'X')
      operation[0] = 2;
    if(buffer[i]=='.' || buffer[i] == '*')
      operation[0] = 3;
  }
  
  if(strcmp(nameA, A->name) == 0)
  {
    //printf("A esquerda\n");
    operation[1] = 0;
  }
  if(strcmp(nameA, B->name) == 0)
  {
    //printf("B esquerda\n");
    operation[1] = 1;
  }
}
void generateunary(char* buffer, int* operation, Vec* A, Vec* B)
{
  char number[MAX];
  operation[0] = -1;
  char nameA[10];
  int acc, acc2, i, j, arrowA=-1, arrowB=-1, lowBracketA = -1, highBracketA = -1, lowBracketB = -1, highBracketB = -1;
  for(i=0; i<strlen(buffer); i++)
  {
    if(buffer[i]=='m') {operation[0] = 5; break;}
    if(buffer[i]=='e') {operation[0] = 4; break;}
    
  }
    
  for(i=0; i< strlen(buffer); i++)
  {
    if(buffer[i] == '-') 
    {
        arrowA = i;
        break;
    }
  }
  for(i=arrowA + 1; i< strlen(buffer); i++)
  {
    if(buffer[i] == '-') 
    {
        arrowB = i;
    }
  }
  //printf("arrowA = %d, arrowB = %d\n", arrowA, arrowB);
  for(i=arrowA; i>-1; i--)
  {
    if(buffer[i] == '(')
    {
      lowBracketA = i;
      break;
    }
  }
  for(i=arrowA; i<strlen(buffer); i++)
  {
    if(buffer[i] == ')')
    {
      highBracketA = i;
      break;
    }
  }
  for(i=arrowB; i>-1; i--)
  {
    if(buffer[i] == '(')
     {
      lowBracketB = i;
      break;
    }
  }
  for(i = lowBracketA; i<=highBracketA; i++)
  {
    nameA[i - lowBracketA] = buffer[i];
  }
  nameA[i+1-lowBracketA] = '\0';
  
  if(strcmp(nameA, A->name) == 0)
  {
    operation[1] = 0;
  }
  if(strcmp(nameA, B->name) == 0)
  {
    operation[1] = 1;
  }
  acc2 = 0;
  if(operation[0] == 4)
  {
    for(j=highBracketA+1; j<strlen(buffer); j++)
        { 
          if(buffer[j] != ' ' && buffer[j] != '\0')
          {
            number[acc2] = buffer[j];
            acc2++;
          }

        
        }
        number[acc2+1] = '\0';
        operation[2] = atoi(number);
  }
}
int addV(Vec* A, Vec* B)
{
  int i;
  Vec C;
  for(i=0; i<3; i++)
  {
    C.vec[i] = A->vec[i] + B->vec[i];
  }
  printf("(result->) = (%f, %f, %f)\n", C.vec[0], C.vec[1], C.vec[2]);
  return 1;
}
int subV(Vec* A, Vec* B, int left)
{
  int i;
  Vec C;
  for(i=0; i<3; i++)
  {
    if(left){
          C.vec[i] = B->vec[i] - A->vec[i];
    }else C.vec[i] = A->vec[i] - B->vec[i];
  }
  printf("(result->) = (%f, %f, %f)\n", C.vec[0], C.vec[1], C.vec[2]);
  return 1;
}

int internV(Vec* A, Vec* B)
{
  int i;
  double acc = 0;
  for(i=0; i<3; i++)
  {
    
          acc += B->vec[i] * A->vec[i];
   
  }
  printf("(result->) = %f\n",  acc);
  return 1;
}
int vecProd(Vec* A, Vec* B, int left)
{
 
  Vec C;
  if(left){
          C.vec[0] = (B->vec[1]*A->vec[2])  - (B->vec[2]*A->vec[1]);
          C.vec[1] = (B->vec[2]*A->vec[0])  - (B->vec[0]*A->vec[2]);
          C.vec[2] = (B->vec[0]*A->vec[1])  - (B->vec[1]*A->vec[0]);
    }else {
          C.vec[0] = (A->vec[1]*B->vec[2])  - (A->vec[2]*B->vec[1]);
          C.vec[1] = (A->vec[2]*B->vec[0])  - (A->vec[0]*B->vec[2]);
          C.vec[2] = (A->vec[0]*B->vec[1])  - (A->vec[1]*B->vec[0]);
    }
    printf("(result->) = (%f, %f, %f)\n", C.vec[0], C.vec[1], C.vec[2]);
    return 1;
}

int escV(Vec* A, Vec* B, int left, int scalar)
{
  int i;
  Vec C;
  for(i=0; i<3; i++)
  {
    if(left){
            C.vec[i] = scalar * B->vec[i];
      }else {
            C.vec[i] = scalar * A->vec[i];
      }
  }
    printf("(result->) = (%f, %f, %f)\n", C.vec[0], C.vec[1], C.vec[2]);
    return 1;
}

int modV(Vec* A, Vec* B, int left)
{
  int i;
  double mod = 0;
  for(i=0; i<3; i++)
  {
    if(left){
            mod += (B->vec[i]*B->vec[i]);
      }else {
           mod += (A->vec[i]*A->vec[i]);
      }
  }
    mod = sqrt(mod);
    printf("Modulo = %f\n", mod);
    return 1;
}

int operate(char* buffer, Vec* A, Vec* B, int type)
{
  int result;
  int operation[3];
  if (type == 2){
    getoperation(buffer, operation, A, B);
  }
  if (type == 1){
    generateunary(buffer, operation, A, B);
  }
  switch(operation[0]){
    case 0:
      result = addV(A, B);
      break;
    case 1:
      result = subV(A, B, operation[1]);
      break;
    case 2:
      result = vecProd(A, B, operation[1]);
      break;
    case 3:
      result = internV(A, B);
      break;
    case 4:
      result = escV( A, B, operation[1], operation[2]);
      break;
    case 5:
      result = modV(A, B, operation[1]);
      break;
    default:
      printf("Operação não reconhecida pelo programa\n");
      result = 0;
      break;
  }
  return result;
}
int printopcoes()
{
  int type;
  printf("Podemos ter operacoes binarias e unarias:\n");
  printf("Digite 1 para unarias e 2 para binarias\n");
  scanf("%d", &type);
  if(type ==2)
  printf("\tExemplo binarias (A->) + (B->)\nDisponiveis: soma:'+' subtracao:'-' prod interno: '*' prod vetorial: 'x' \n");
  if(type == 1)
  printf("\tExemplo unarias mod (A->)\nDisponiveis: modulo = 'mod (vetor->)' escalar = 'esc (vetor->) y'\n");
  return type;
}
void interface()
{
  int type;
  char vectors[MAX];
  char operation[MAX];
  Vec A, B;
  int i;
  printf("--------------Entre com os vetores----------------\n");
  fgets(vectors, MAX, stdin);
  generatevec(vectors, &A, &B);
  
  printf("--------------Vetores lidos com sucesso---------\n");
  do{
    printf("-------------Entre com a operacao-----------\n");
    type = printopcoes();
    fgets(operation, MAX, stdin);
    fgets(operation, MAX, stdin);
    //printf("%s\n", operation);
    
  }while(!operate(operation, &A, &B, type));
}
int main (int argc, char** argv)
{
  interface();
  return 0;
}
