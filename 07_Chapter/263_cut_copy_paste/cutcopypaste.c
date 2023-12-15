#include <gtk/gtk.h>

static void destroy(GtkWidget*, gpointer);
static void cut_clicked(GtkButton*, GtkTextView*);
static void copy_clicked(GtkButton*, GtkTextView*);
static void paste_clicked(GtkButton*, GtkTextView*);

int main(int argc, char *argv[]) {
  GtkWidget *window, *scrolled_win, *textview, *cut, *copy, *paste, *hbox, *vbox;

  gtk_init(&argc, &argv);

  window= gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Cut, Copy & Paste");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  textview= gtk_text_view_new();

  cut= gtk_button_new_with_label("Cut");
  copy= gtk_button_new_with_label("Copy");
  paste= gtk_button_new_with_label("Paste");

  g_signal_connect(G_OBJECT(window), "destroy",
		   G_CALLBACK(destroy), NULL);
  g_signal_connect(G_OBJECT(cut), "clicked",
		   G_CALLBACK(cut_clicked),
		   (gpointer)textview);
  g_signal_connect(G_OBJECT(copy), "clicked",
		   G_CALLBACK(copy_clicked),
		   (gpointer)textview);
  g_signal_connect(G_OBJECT(paste), "clicked",
		   G_CALLBACK(paste_clicked),
		   (gpointer) textview);
  
  scrolled_win= gtk_scrolled_window_new(NULL, NULL);
  gtk_widget_set_size_request(scrolled_win, 300, 300);
  gtk_container_add(GTK_CONTAINER(scrolled_win), textview);

  hbox= gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
  gtk_box_pack_start(GTK_BOX(hbox), cut, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(hbox), copy, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(hbox), paste, TRUE, TRUE, 0);

  vbox= gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
  gtk_box_pack_start(GTK_BOX(vbox), scrolled_win, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, TRUE, 0);

  gtk_container_add(GTK_CONTAINER(window), vbox);
  gtk_widget_show_all(window);

  gtk_main();
  return 0;
}

/* Stop the GTK+ main loop function when the window is destroyed. */
static void destroy(GtkWidget *window, gpointer data) {
  gtk_main_quit();
}

/* Copy the selected text to the clipboard and remove it from the buffer. */
static void cut_clicked(GtkButton *cut, GtkTextView *textview) {
  GtkClipboard *clipboard= gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
  GtkTextBuffer *buffer= gtk_text_view_get_buffer(textview);
  gtk_text_buffer_cut_clipboard(buffer, clipboard, TRUE);
}

/* Copy the selected text to the clipboard. */
static void copy_clicked(GtkButton *copy, GtkTextView *textview) {
  GtkClipboard *clipboard= gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
  GtkTextBuffer *buffer= gtk_text_view_get_buffer(textview);
  gtk_text_buffer_copy_clipboard(buffer, clipboard);
}

/* Insert the text from the clipboard into the text buffer. */
static void paste_clicked(GtkButton *paste, GtkTextView *textview) {
  GtkClipboard *clipboard= gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
  GtkTextBuffer *buffer= gtk_text_view_get_buffer(textview);
  gtk_text_buffer_paste_clipboard(buffer, clipboard, NULL, TRUE);
}
