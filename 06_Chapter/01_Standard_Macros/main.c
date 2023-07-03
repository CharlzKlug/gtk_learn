#include <glib.h>
#include <stdio.h> // Для printf

int main() {
  printf("GLib major version: %d\n", GLIB_MAJOR_VERSION);
  printf("GLib minor version: %d\n", GLIB_MINOR_VERSION);
  printf("GLib micro version: %d\n", GLIB_MICRO_VERSION);

  if (GLIB_CHECK_VERSION(2, 12, 1)) {
    printf("My GLib version is equal or greater than 2.12.1\n");
  } else {
    printf("GLib version is lower than 2.12.1\n");
  }

  printf("glib_check_version says: %s\n", glib_check_version(2, 108, 1));

  printf("ABS(-4): %d, ABS(4): %d\n", ABS(-4), ABS(4));
  printf("CLAMP(1, 0, 10): %d, CLAMP(9, 0, 10): %d, CLAMP(11, 0, 10): %d, CLAMP(-1, 0, 10): %d\n",
	 CLAMP(1, 0, 10), CLAMP(9, 0, 10), CLAMP(11, 0, 10), CLAMP(-1, 0, 10));
  printf("G_DIR_SEPARATOR: %c, G_DIR_SEPARATOR_S: %s\n",
	 G_DIR_SEPARATOR, G_DIR_SEPARATOR_S);

  gint i= 42;
  gpointer i_pointer;
  i_pointer= GINT_TO_POINTER(i);
  printf("GINT_TO_POINTER: %p, i: %d\n", i_pointer, i);
  printf("GPOINTER_TO_INT: %d\n", GPOINTER_TO_INT(i_pointer));

  gsize k= 43;
  gpointer k_pointer;
  k_pointer= GSIZE_TO_POINTER(k);
  printf("GSize: %ld, GPointer: %p\n", k, k_pointer);
  printf("GPOINTER_TO_SIZE: %ld\n", GPOINTER_TO_SIZE(k_pointer));

  guint uint1= 113;
  gpointer uint_pointer;
  uint_pointer= GUINT_TO_POINTER(uint1);
  printf("UInt: %d, UInt pointer: %p\n", uint1, uint_pointer);
  printf("GPOINTER_TO_UINT: %d\n", GPOINTER_TO_UINT(uint_pointer));

#ifdef G_OS_WIN32
  printf("This is Windows specific code\n");
#endif

#ifdef G_OS_BEOS
  printf("This is Beos specific code\n");
#endif
  
#ifdef G_OS_UNIX
  printf("This is Unix specific code\n");
#endif

  printf("G_PI: %f\n", G_PI);
  return 0;
}
