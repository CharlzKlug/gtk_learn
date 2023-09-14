#include <glib.h>
#include <stdio.h>

int main() {
  gchar str[] = "qwerty";
  
  GQuark k = g_quark_from_string(str);
  printf("%s\n", str);
  printf("%d\n", k);

  if (g_quark_try_string("qwerty")) {
    printf("There is quark\n");
  }

  if (!g_quark_try_string("asdf")) {
    printf("There no quark\n");
  }

  printf("%s\n", g_quark_to_string(k));
  return 0;
}
