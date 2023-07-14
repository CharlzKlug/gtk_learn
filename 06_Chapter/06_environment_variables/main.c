#include <glib.h>

int main() {

  // Печатает текущую директорию
  gchar* string= NULL;
  g_assert(string == NULL);
  string= g_get_current_dir();
  g_print("%s\n", string);
  g_free(string);
  string= NULL;
  // Все вот эти манипуляции с указателями нужны для очистки значения,
  // возвращаемого от g_get_current_dir
  
  // Печатает текущую домашнюю директорию
  g_print("%s\n", g_get_home_dir());

  // Печатает имя хоста
  g_print("%s\n", g_get_host_name());

  // Печатает реальное имя пользователя
  g_print("%s\n", g_get_real_name());

  // Печатает временную директорию
  g_print("%s\n", g_get_tmp_dir());

  // Печатает имя текущего пользователя
  g_print("%s\n", g_get_user_name());

  // Проба g_getenv
  g_print("%s\n", g_getenv("PATH"));
  return 0;
}
