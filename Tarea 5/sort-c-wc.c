#include <string.h>

int strCmp(char *s1, char *s2) {
    char c1;
    char c2;

    for (;;) {
      c1= *s1;
      c2= *s2;

      if (c1==0)
        break;

      if (c1!=c2)
        break;

      s1++;
      s2++;
    }

    return c1 - c2;
}

int num_palabras(char *s){
  int cantidad = 0;
  for(int i=0; s[i]!= 0; i++){
    if(s[i] != ' ' && (s[i+1]==' ' || s[i+1]==0)){
      cantidad++;
    }
  }
  return cantidad;
}

void sort(char **a, int n) {
  char **ult= &a[n-1];
  char **p= a;
  while (p<ult) {

    int n1 = num_palabras(p[0]);
    int n2 = num_palabras(p[1]);
    int t1 = n1 - n2;

    if (t1 <= 0)
      p++;
    else {
      char *tmp= p[0];
      p[0]= p[1];
      p[1]= tmp;
      p= a;
    }
  }
}


