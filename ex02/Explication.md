




*-----------------------------EXPLICATTION--------------------------------*

                ALGO TRI SPECIAL(X) :

        1*) n = taille de la liste.
        si n == 1
            return X 
        liste deja triee.

        2*) Calcule la moitie de la liste :        
            -   m = [n /2].

        3*) Creation de paires delement 
            -   Les elements de la liste 'X' sont regroupe par paires consecutives. Par exemple, pour 'X = [3, 1, 4, 2]', les paires seraient [(3, 1), (4, 2)]

            -   Si la taille de la liste est Impaires, le derniers element (NotPlace) est conserver separement.

        4*) Selection des elements plus grands dans chaque paires :
            - Chaque paires examine. Si le premiers element de la paire est plus grand que le second, le permiers element est ajoute a une liste appelee 
            'ElementsPlusGrand'. Sinon, le deuxieme est ajoute.

        5*) Appel recursif de TriSpecial :
            -   L'algo est appele recursivement avec la liste 'ElementsPlusGrand'.
            Cette etape se repete jusqua que la taille de la list soit reduite a 1;
        
        6*)Fusion des resultat e la recursions avec les elements restant :
            -   Les elements qui ne sont pas dans la liste 'ElementPlusGrand' (c-a-d) les elements restants de la listes initials sont combines avec les resultat de lappel recursif.

            - Pour chaque element restant, une recherche binaire est utlisee pour inserer dans lordre dans la liste triee issue de la recursion.

        7*) Renvoi la liste triee.
            - La liste triee est renvoyee







*-------------------------------------------------------------------------*
