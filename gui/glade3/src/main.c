#include <gtk/gtk.h>
#include <stdlib.h>

//initializing labels used
GtkWidget *g_lbl_hello;
GtkWidget *g_lbl_count;
GtkWidget *g_textview1;
GtkWidget *g_combo1;

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);
    
    // get pointers to the two labels
    g_lbl_hello = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_hello"));
    g_lbl_count = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_count"));
    g_textview1 = GTK_WIDGET (gtk_builder_get_object(builder, "textview1"));
    g_combo1 = GTK_WIDGET (gtk_builder_get_object(builder, "combo1"));
    
    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();

    return 0;
}


// on_clicked handler
void on_btn_hello_clicked()
{
    static unsigned int count = 0;
    char str_count[30] = {0};
    GtkTextBuffer *buffer;
  
    gtk_label_set_text(GTK_LABEL(g_lbl_hello), "Hello, world!");
  
  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (g_textview1));
  gtk_text_buffer_set_text (buffer, "Your 1st GtkTextView widget!", -1);  
  //gtk_label_set_text(GTK_LABEL(g_textview1), "Hello, world!");

    count++;
    //converts digit into string
    sprintf(str_count, "%d", count);
    gtk_label_set_text(GTK_LABEL(g_lbl_count), str_count);
  
    system("ls");
     
     int active_id=gtk_combo_box_get_active(GTK_COMBO_BOX(g_combo1));
     printf("selected id is %d\n",active_id);
}


void on_btn_file_clicked()
{
    //char cNome[250];
    //*cNome = gtk_file_chooser_get_uri(GTK_FILE_CHOOSER(filechooserbutton1));

  
  
     GtkWidget *dialog;
    dialog = gtk_file_chooser_dialog_new("Open File",
            NULL, GTK_FILE_CHOOSER_ACTION_OPEN,
            "_Cancel", GTK_RESPONSE_CANCEL,
            "_Open", GTK_RESPONSE_ACCEPT,
            NULL);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
        char *filename;
        GtkFileChooser *chooser = GTK_FILE_CHOOSER(dialog);
        filename = gtk_file_chooser_get_filename(chooser);
        g_message("File selected: %s", filename);
        g_free(filename);
    }

    gtk_widget_destroy (dialog);

  
}

// destructor
void on_window_main_destroy()
{
    gtk_main_quit();
}

