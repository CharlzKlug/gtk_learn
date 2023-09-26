#include <glib.h>
#include <gmodule.h>
#include <glib/gprintf.h> // Для g_printf

G_MODULE_EXPORT gboolean print_the_message (gpointer data) {
  g_printf ("%s\n", (gchar*) data);
  return TRUE;
}

G_MODULE_EXPORT gboolean print_another_one (gpointer data) {
  g_printf ("%s\n", (gchar*) data);
  return TRUE;
}
