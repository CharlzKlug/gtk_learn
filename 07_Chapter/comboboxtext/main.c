#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
  GtkWidget *my_combo_box, *window;
  
  gtk_init(&argc, &argv);

  my_combo_box= gtk_combo_box_text_new();
  gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(my_combo_box), "Test1");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(my_combo_box), "Test2");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(my_combo_box), "Test3");

  window= gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "ComboBox Test App");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  gtk_container_add(GTK_CONTAINER(window), my_combo_box);
  
  gtk_widget_show_all(window);
  
  gtk_main();
  return 0;
}
