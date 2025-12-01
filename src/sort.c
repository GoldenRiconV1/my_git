/*
** EPITECH PROJECT, 2025
** G-CPE-110-LYN-1-1-organized-33
** File description:
** sort.c
*/

#include "./include/my.h"

int sort(void *data, char **args)
{
    context_t *ctx = (context_t *)data;

    if (args == NULL || args[0] == NULL)
        return 84;
    merge_sort(&ctx->head, args);
    return 0;
}

static int nodes_compare(node_t *noeud_a, node_t *noeud_b, char **args)
{
    int i = 0;
    int invers = 0;
    int result = 0;

    while (args[i]) {
        invers = 1;
        if (args[i] && args[i + 1] == "-r")
            invers = -1;
        if (args[i] == "-r")
            i++;
        if (args[i] == "TYPE")
            result = noeud_a->type - noeud_b->type;
        if (args[i] == "ID")
            result = noeud_a->id - noeud_b->id;
        if (args[i] == "NAME")
            result = my_strcmp(noeud_a->name, noeud_b->name);
        if (result != 0)
            return result * invers;
        i++;
        if (invers == -1)
            i++;
    }
    return 0;
}

static void middle_list(node_t *head, )

// // Fonction split_list(source, pointeur_debut, pointeur_fin):
// //     lent = source
// //     rapide = source->suivant

// //     // Avancer tant que le rapide ne touche pas la fin
// //     TANT QUE rapide N'EST PAS NULL:
// //         rapide = rapide->suivant
// //         SI rapide N'EST PAS NULL:
// //             lent = lent->suivant
// //             rapide = rapide->suivant

// //     // Le 'lent' est au milieu
// //     *pointeur_debut = source
// //     *pointeur_fin = lent->suivant
// //     lent->suivant = NULL // Coupure physique de la liste


// // Fonction merge_sort(reference_tete, args):
// //     tete = *reference_tete
// //     // Cas d'arrêt : liste vide ou 1 seul élément
// //     SI tete est NULL OU tete->suivant est NULL:
// //         RETOURNER

// //     // 1. Couper en deux
// //     liste_gauche = NULL
// //     liste_droite = NULL
// //     split_list(tete, &liste_gauche, &liste_droite)

// //     // 2. Appels récursifs
// //     merge_sort(&liste_gauche, args)
// //     merge_sort(&liste_droite, args)

// //     // 3. Fusionner selon les critères
// //     *reference_tete = merge_lists(liste_gauche, liste_droite, args)

