#include <glib.h>
#include <stdio.h>

/* Структура, с которой будем работать */
struct myStructure {
  int k;
  double f;
};

int main() {

  /* Выделяем память под две структуры */
  struct myStructure* ms_array= NULL;
  ms_array= g_new0(struct myStructure, 2);

  /* Заполняем структуры */
  ms_array[0].k= 1;
  ms_array[0].f= 42.3;

  ms_array[1].k= 2;
  ms_array[1].f= 15.37;

  /* Печатаем содержимое структур */
  for (int i= 0; i < 2; i++) {
    printf("[%d], k: %d, f: %f\n", i, ms_array[i].k, ms_array[i].f);
  }

  /* Заполняем содержимое структуры мусором перед освобождением памяти */
  char* chr= NULL;
  chr= (char*)ms_array;

  for (int i=0; i < sizeof(struct myStructure) * 2; i++) {
    chr[i]= 255;
  }

  /* Освобождаем память */
  g_free(ms_array);

  /* ЗаNULL-яем указатели */
  ms_array= NULL;
  chr= NULL;
  
  return 0;
}
