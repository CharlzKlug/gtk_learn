#include <gtk/gtk.h>

int main (int argc, char *argv[]) {
  GtkWidget *window, *swin, *viewport, *table1, *table2, *vbox;
  GtkAdjustment *horizontal, *vertical;
  GtkWidget *buttons1[10][10], *buttons2[10][10];
  unsigned int i, j;

  gtk_init (&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "Scrolled Windows & Viewports");
  gtk_container_set_border_width (GTK_CONTAINER (window), 10);
  gtk_widget_set_size_request (window, 100, 100);

  g_signal_connect (G_OBJECT (window), "destroy",
		    G_CALLBACK (gtk_main_quit), NULL);

  table1 = gtk_grid_new();
  table2 = gtk_grid_new();
  
  gtk_grid_set_row_spacing (GTK_GRID (table1), 5);
  gtk_grid_set_row_spacing (GTK_GRID (table2), 5);
  gtk_grid_set_column_spacing (GTK_GRID (table1), 5);
  gtk_grid_set_column_spacing (GTK_GRID (table2), 5);

  /* Pack each table with 100 buttons. */
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      buttons1[i][j] = gtk_button_new_with_label ("CLOSE");
      buttons2[i][j] = gtk_button_new_with_label ("CLOSE");
      gtk_button_set_relief (GTK_BUTTON (buttons1[i][j]), GTK_RELIEF_NONE);
      gtk_button_set_relief (GTK_BUTTON (buttons2[i][j]), GTK_RELIEF_NONE);

      gtk_grid_attach (GTK_GRID (table1), buttons1[i][j], i, j, 1, 1);
      gtk_grid_attach (GTK_GRID (table2), buttons2[i][j], i, j, 1, 1);
    }
  }

  /* Create a scrolled window and a viewport, each with one table. Use the 
   * adjustments in the scrolled window to synchronize both containers. */
  swin = gtk_scrolled_window_new (NULL, NULL);
  horizontal = gtk_scrolled_window_get_hadjustment (GTK_SCROLLED_WINDOW (swin));
  vertical = gtk_scrolled_window_get_vadjustment (GTK_SCROLLED_WINDOW (swin));
  /* viewport = gtk_viewport_new (horizontal, vertical); */
  viewport = gtk_viewport_new (NULL, NULL);

  gtk_container_set_border_width (GTK_CONTAINER (swin), 5);
  gtk_container_set_border_width (GTK_CONTAINER (viewport), 5);

  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (swin),
				  GTK_POLICY_ALWAYS, GTK_POLICY_ALWAYS);
  /* gtk_scrolled_window_add_with_viewport (GTK_SCROLLED_WINDOW (swin), table1); */
  gtk_container_add (GTK_CONTAINER (viewport), table2);
  gtk_container_add (GTK_CONTAINER (swin), table1);

  /* Pack the widgets into a GtkVBox and then into the window. */
  vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);
  gtk_box_pack_start (GTK_BOX (vbox), viewport, TRUE, TRUE, 5);
  gtk_box_pack_start (GTK_BOX (vbox), swin, TRUE, TRUE, 5);

  gtk_container_add (GTK_CONTAINER (window), vbox);
  gtk_widget_show_all (window);

  gtk_main();
  return 0;
}
