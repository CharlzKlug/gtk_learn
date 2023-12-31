#include <gmodule.h>
#include <glib.h>
#include <glib/gprintf.h>

typedef gboolean (* PrintMessageFunc) (gpointer data);
typedef gboolean (* PrintAnotherFunc) (gpointer data);
typedef gint (* SomeFunc) (gint a, gint b);

int main (int argc, char *argv[]) {
  GModule *module;
  PrintMessageFunc print_the_message;
  PrintAnotherFunc print_another_one;
  SomeFunc some_func;
  
  gchar *text = "This is some text";

  /* Make sure module loading is supported on the user's machine. */
  g_assert (g_module_supported ());

  /* Open the library and resolve symbols only when necessary. Libraries on
   * Windows will have a .dll appendix. */
  module = g_module_open ("/usr/lib/plugin.so", G_MODULE_BIND_LAZY);

  if (!module) {
    g_error ("Error: %s\n", (gchar*) g_module_error ());
    return -1;
  }

  /* Load the print_the_message() function. */
  if (!g_module_symbol (module, "print_the_message",
			(gpointer*) &print_the_message)) {
    g_error ("Error: %s\n", (gchar*) g_module_error ());
    return -1;
  }

  /* Load the destroy_the_evidence() function. */
  if (!g_module_symbol (module, "print_another_one",
			(gpointer*) &print_another_one)) {
    g_error ("Error: %s\n", (gchar*) g_module_error ());
    return -1;
  }

  /* Load the some_func function. */
  if (!g_module_symbol (module, "some_func",
			(gpointer*) &some_func)) {
    g_error ("Error: %s\n", (gchar*) g_module_error ());
    return -1;
  }
  
  /* Run both loaded functions since there were no errors reported loading
   * neither the module nor the symbols. */
  print_the_message ((gpointer) text);
  print_another_one ("Another Message!");

  g_printf("Value from shared library: %d\n", some_func(4, 5));
  
  /* Close the module and free allocated resources. */
  if (!g_module_close (module)) {
    g_error ("Error: %s\n", (gchar*) g_module_error ());
  }

  return 0;
}
