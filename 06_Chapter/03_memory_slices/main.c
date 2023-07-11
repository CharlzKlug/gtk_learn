#include <gtk/gtk.h>
/* #include <glib.h> */

#define SLICE_SIZE 10

typedef struct {
  GtkWidget *window;
  GtkWidget *label;
} Widgets;

int main(int argc, char* argv[]) {
  gchar *strings[100];
  gint i;

  for (i= 0; i < 100; i++)
    strings[i]= g_slice_alloc (SLICE_SIZE);

  /* ... Use the strings in some way ... */

  /* Free all of the memory after you are done using it. */
  for (i= 0; i < 100; i++)
    g_slice_free1(SLICE_SIZE, strings[i]);

  gtk_init(&argc, &argv);

  Widgets *w= g_slice_new(Widgets);

  /* Use the structure just as you would any other structure. */
  w->window= gtk_window_new(GTK_WINDOW_TOPLEVEL);
  w->label= gtk_label_new("I belong to widgets!");

  /* Free the block of memory of size "Widgets" so it can be reused. */
  g_slice_free(Widgets, w);
  
  return 0;
}
