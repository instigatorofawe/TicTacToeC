#include <stdio.h>
#include <stdbool.h>
#include <gtk/gtk.h>

#include "util/game.h"
#include "gui/gui.h"

int main(int argc, char** argv) {
    char option[100];
    int option_number;
    int arg;

    GameTree *root = create_gametree(init_board());
//    solve_gametree_minimax(root); // Solve once upon initialization

    // Parse execution flags for GUI or command line
    bool gui = false;

    if (argc >= 2) {
        if (argv[1][0] == '-') {
            if (argv[1][1] == 'g') {
                gui = true;
            }
        }
    }

    int status = 0;

    if (gui) {
        GtkApplication *app;

        app = gtk_application_new ("org.tictactoe.c", G_APPLICATION_FLAGS_NONE);
        g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
        status = g_application_run (G_APPLICATION (app), 0, NULL); // Don't pass GApplication flags
        g_object_unref (app);

    } else {
        while (true) {
            printf("1. Single Player (Naive Minimax)\n2. Single Player (Alpha-Beta pruning)\n3. Single Player (Monte Carlo Tree Search)\n4. Multiplayer\n5. Exit\n");
            fgets(option, sizeof(option), stdin);
            arg = sscanf(option, "%d", &option_number);

            if (arg != 1) {
                printf("Invalid choice! Please enter a number.\n");
                continue;
            }

            switch (option_number) {
                case 1:
                    play_singleplayer(root, false);
                    solve_gametree_minimax(root);
                    break;
                case 2:
                    play_singleplayer(root, true);
                    break;
                case 4:
                    play_multiplayer();
                    break;
                case 5:
                    goto escape;
                default:
                    printf("Invalid choice!\n");
                    continue;
            }

            if (false) {
                escape:
                break;
            }
        }


    }

    delete_subtree(root);

    return status;
}
