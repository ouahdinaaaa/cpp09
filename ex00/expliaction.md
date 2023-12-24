


Explication sujet

-> Prendre fichier format CSV 
-> prendre en parametre un fichier qui contient line
            -- "date | valeur"
            date : "Annee - Mois - Jour"
            valeur nombre decimale "0-1000"



            GESTION D'ERREUUUR :

    - Si fichier pas accesible afficher "Error: not open"
    - Si nombre non positif : "Error number not positive"
    - Si date invalid : bad input -> [date ivalide]
    - Si valeur fichier trop grand : "Error: too large nb"


        METHODE STRCUTURE DE COMMENT FAIRE
    - Fonction parser(string file)
    {
        - lit le fichier et stock les donnes extraite dans le vecteur dateBase
    }

    - Dans le constructeur on va appeler parser qui vas parser le dossier.


    Fonction Find date : 
        - Trouve la date la plus proche ou inferieur a celle fournis en utilisant le vector

    Fonction ExchangeRate :
        - Utilise le vecteur datebase pour trouver taux de chamge correspondant a la date donnee

    