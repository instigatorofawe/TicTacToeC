//
// Created by Ran Liu on 4/24/2020.
//

#include "gui.h"
#include <gtk/gtk.h>


void activate (GtkApplication* app, gpointer user_data) {
    GtkWidget *window;

    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Window");
    gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
    gtk_widget_show_all (window);
}
