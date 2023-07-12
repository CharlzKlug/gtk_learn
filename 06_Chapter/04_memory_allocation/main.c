#include <glib.h>
#include <stdio.h>

struct myStructure {
  int k;
  double f;
};

int main() {
  struct myStructure* ms_array= NULL;
  ms_array= g_new0(struct myStructure, 2);

  /* ms1->k= 1; */
  /* ms1->f= 42.3; */

  /* printf("k: %d, f: %f\n", ms1->k, ms1->f); */

  ms_array[0].k= 1;
  ms_array[0].f= 42.3;

  ms_array[1].k= 2;
  ms_array[1].f= 15.37;

  for (int i= 0; i < 2; i++) {
    printf("[%d], k: %d, f: %f\n", i, ms_array[i].k, ms_array[i].f);
  }

  /* ((char*)ms_array)= 255; */
  char* chr= NULL;
  chr= (char*)ms_array;

  for (int i=0; i < sizeof(struct myStructure) * 2; i++) {
    chr[i]= 255;
  }
  
  g_free(ms_array);
  
  ms_array= NULL;
  chr= NULL;
  
  return 0;
}
