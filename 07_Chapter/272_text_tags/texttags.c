#include <gtk/gtk.h>

typedef struct {
  gchar *str;
  double scale;
} text_to_double;

const text_to_double text_scales[] = {
  {"Quarter Sized", (double) 0.25},
  {"Double Extra Small", PANGO_SCALE_XX_SMALL},
  {"Extra Small", PANGO_SCALE_X_SMALL},
  {"Small", PANGO_SCALE_SMALL},
  {"Medium", PANGO_SCALE_MEDIUM},
  {"Large", PANGO_SCALE_LARGE},
  {"Extra Large", PANGO_SCALE_X_LARGE},
  {"Double Extra Large", PANGO_SCALE_XX_LARGE},
  {"Double Sized", (double) 2.0},
  {NULL, 0}
};

static void format(GtkWidget*, GtkTextView*);
static void scale_changed(GtkComboBox*, GtkTextView*);
static void clear_clicked(GtkButton*, GtkTextView*);

int main(int argc, char *argv[]) {
  GtkWidget *window, *scrolled_win, *textview, *hbox, *vbox;
  GtkWidget *bold, *italic, *underline, *strike, *scale, *clear;
  GtkTextBuffer *buffer;
  gint i= 0;

  gtk_init(&argc, &argv);

  window= gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Text Tags");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);
  gtk_widget_set_size_request(window, 500, -1);

  textview= gtk_text_view_new();
  buffer= gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview));

  gtk_text_buffer_create_tag(buffer, "bold", "weight", PANGO_WEIGHT_BOLD, NULL);
  gtk_text_buffer_create_tag(buffer, "italic", "style", PANGO_STYLE_ITALIC, NULL);
  gtk_text_buffer_create_tag(buffer, "strike", "strikethrough", TRUE, NULL);
  gtk_text_buffer_create_tag(buffer, "underline", "underline", PANGO_UNDERLINE_SINGLE, NULL);

  bold = gtk_button_new_with_label("Bold");
  italic= gtk_button_new_with_label("Italic");
  underline= gtk_button_new_with_label("Underline");
  strike= gtk_button_new_with_label("Strikethrough");
  clear= gtk_button_new_with_label("Clear");
  /* scale= gtk_combo_box_new(); */
  scale= gtk_combo_box_text_new();

  /* Add choices to the GtkComboBox widget. */
  for (i= 0; text_scales[i].str != NULL; i++) {
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(scale), "1");
    /* gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(scale), text_scales[i].str); */
    /* gtk_text_buffer_create_tag(buffer, text_scales[i].str, "scales", */
    /* 			       text_scales[i].scale, NULL); */
  }

  /* Add the name of the text tag as a data parameter of the object. */
  g_object_set_data(G_OBJECT(bold), "tag", "bold");
  g_object_set_data(G_OBJECT(italic), "tag", "italic");
  g_object_set_data(G_OBJECT(underline), "tag", "underline");
  g_object_set_data(G_OBJECT(strike), "tag", "strike");

  /* Connect each of the buttons and the combo box to the necessary signals. */
  /* g_signal_connect(G_OBJECT(bold), "clicked", */
  /* 		   G_CALLBACK(format), (gpointer) textview); */
  /* g_signal_connect(G_OBJECT(italic), "clicked", */
  /* 		   G_CALLBACK(format), (gpointer) textview); */
  /* g_signal_connect(G_OBJECT(underline), "clicked", */
  /* 		   G_CALLBACK(format), (gpointer) textview); */
  /* g_signal_connect(G_OBJECT(strike), "clicked", */
  /* 		   G_CALLBACK(format), (gpointer) textview); */
  /* g_signal_connect(G_OBJECT(scale), "changed", */
  /* 		   G_CALLBACK(scale_changed), (gpointer) textview); */
  /* g_signal_connect(G_OBJECT(clear), "clicked", */
  /* 		   G_CALLBACK(clear_clicked), (gpointer) textview); */

  
  return 0;
}

/* Retrieve the tag from the "tag" object data and apply it to the selection. */
static void format(GtkWidget *widget, GtkTextView *textview) {
  GtkTextIter start, end;
  GtkTextBuffer *buffer;
  gchar *tagname;

  tagname= (gchar*)g_object_get_data(G_OBJECT(widget), "tag");
  buffer= gtk_text_view_get_buffer(textview);
  gtk_text_buffer_get_selection_bounds(buffer, &start, &end);
  gtk_text_buffer_apply_tag_by_name(buffer, tagname, &start, &end);
}

/* Apply the selected text size property as the tag. */
static void scale_changed(GtkComboBox *combo, GtkTextView *textview) {
  const gchar *text;

  if (gtk_combo_box_get_active(combo) == -1)
    return;

  /* text= gtk_combo_box_get_active_text(combo); */
  /* g_object_set_data(G_OBJECT(combo), "tag", (gpointer)text); */
  /* format(GTK_WIDGET(combo), textview); */
  /* gtk_combo_box_set_active(combo, -1); */
}

/* Remove all of the tags from the selected text. */
static void clear_clicked(GtkButton *button, GtkTextView *textview) {}
