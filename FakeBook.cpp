//Notes de compréhension pour Christophe
#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <string>
//Ici on a 6 includes, iostream tu connais déjà; vector c'est en gros un container de tout pleins d'objets plus simplement et
//naÏvement c'est une liste; sstream ne fais pas attention à ça, j'utilise cela étant donné que j'ai un petit problème mais
//fait comme si ce n'était pas là; iterator me sert pour overloader l'opérateur<< qui va me permettre d'afficher une instance
//de l'objet std::vector<T> (T est une template -> ce qui signifie que le fonctionnement est défini pour n'importe quel type
//(car typename) Je t'expliquerai mieux plus tard, c'est encore trop tôt; string tu connais ce sont des chaînes de caractères

typedef std::vector<std::string> string_container;
//Là en gros je "définis" un type en tant qu'alias, cad que lorsque je vais utiliser string_container, aux yeux du compilateur
//il y aura écrit std::vector<std::string> c'est une pratique qui peut être plutot intéressante quand on doit très souvent
//utilisé un type et qu'il est long a écrire (comme ici en l'occurence). N'oublie jamais que les programmeurs sont des fainéants.

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {

    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, "\n"));
    return out;
}
//Ca aussi c'est un peu trop compliqué, il y a des notions d'opérateurs, d'itérateurs, de template. Mais en gros, ça permet à
//notre objet vector de pouvoir être affiché grâce à un std::cout (tu remarqueras les << que l'on retrouve dans "operator<<"
//qui sont en effet les mêmes que ceux que l'on utilise pour std::cout << "quelque chose";). Pourquoi faut-il overloadé
//(redéfinir si tu préferes) l'opérateur<< de l'objet vector ? Car les vectors sont des objets plus complexes que les entiers
//ou les strings et qu'ils ne possèdent pas par défaut cet opérateur (tu peux essayer de std::cout un vector, tu obtiendras
//une bien jolie erreur)

namespace patch { //Patched std::to_string

    template <typename T> std::string to_string( const T& n ) {

        std::ostringstream stm;
        stm << n;
        return stm.str();
    }
}
//En revanche ne fais vraiment pas attention à ça, j'ai eu une problème, que tu n'as pas (en théorie). En gros la fonction
//to_string prend en paramètre une template (un entier par exemple) et va convertir cette template (dans notre cas un entier)
//en un string. C'est magique.

string_container generate_book(std::size_t page_number);
//Prototype de la fonction generate_book
//Cette fonction va générer un livre (wouuuah) d'un nombre de page désiré (page_number).

int main() {

    std::string user_input; //"G" for turn page to left, "R" for turn page to right
    std::size_t number_page = 1;
    bool in = true;
    //On définit toutes nos variables

    string_container book = generate_book(12);
    //On génère notre livre de 12 pages

    while(in) {
    //Algèbre booléenne. Tu dois voir chaque condition/boucle (sauf for, enfin si mais c'est plus compliqué que ça)
    //comme ne s'éxecutant que si sa condition est égale à true (je te renvoie sur la page wikipedia de
    //l'algèbre de Boole et des tables de vérité. C'est vraiment très intéressant et c'est absolument
    //primordial en programmation.)

        std::cout << "What would you like to do ? (G for turn page to left and R for turn page to right, exit for exit)" << std::endl;
        std::cin >> user_input;
        //On demande à l'utilisateur ce qu'il veut faire

        if (user_input == "G" && number_page > 1) number_page--;
        //Si l'utilisateur veut tourner la page à gauche (G) ET que la valeur de la page sur laquelle nous sommes
        //(par défaut 1 lors de l'initialisation) alors on décremente la valeur de la page et donc par exemple
        //si on était à la page 3 on passe à la page 2
        else if (user_input == "R" && number_page < book.size() - 1) number_page++;
        //Exactement la même chose sauf que là c'est pour tourner la page à droite.
        else if (user_input == "exit") in = false;
        //Cette condition sert à arrêter le programmer en gros : Dans le cas où l'utilisateur écrit "exit", on passe
        //in à false et donc le while(in) ne sera plus vérifié (while(in) correspond à while(in == true), c'est du
        //sucre syntaxique) et donc on quitte la boucle.
        else std::cout << "Please retry" << std::endl;
        //Dans le cas où l'utilisateur a mis une valeur qui n'est pas prise en compte par le programme.

        std::cout << book.at(number_page) << std::endl;
        //L'objet vector possède une fonction nommé at(x) qui permet de prendre la valeur qui se trouve à l'index
        //numéro x. Et donc on va afficher la valeur qui se trouve à l'objet x du vector book. Par exemple pour
        //book.at(3) on va afficher le contenu qu'à le vecteur à l'index numéro 3
        //Aussi, si les tests "number_page < book.size() - 1" et "number_page > 1" sont utiles c'est par ce que si
        //on s'amuse à appuyer trop de fois sur G ou R (tourner trop de fois la page vers la gauche ou la droite)
        //et bien on va avoir un erreur par ce que la valeur limite du vecteur a été dépassé (je t'expliquerai cela
        //en détail bien plus tard.
    }

    return 0; //Arrêt du programme.
}

string_container generate_book(std::size_t page_number) {
//La fameuse définition de notre fonction generate_book

    string_container tmp;
    //tmp est la variable que l'on va utiliser pour gérer notre livre, c'est cette variable que l'on va retourner
    //à la fin de la fonction afin d'obtenir notre livre.
    //En quelque sorte si tu veux la variable tmp modélise/représente le livre !

    for(std::size_t it = 1; it < page_number + 2; ++it) {
        //Les programmeurs sont fainéants, voilà pourquoi ils utilisent des boucles :)

        tmp.push_back("Welcome to page number " + patch::to_string(it - 1));
        //La fonction push_back qui est une fonction membre de l'objet vector (on verra plus tard ce qu'est un vector
        //et ce qu'est une fonction membre et tout ce qui va avec) permet d'ajouter une valeur à notre "liste". Si tu
        //souhaites mieux comprendre je t'invite à faire une ou deux recherches sur les vecteurs (recherche google :
        //"c++ std::vector", tu devrais assez facilement trouver de bons tutoriels expliquant très bien ce qu'est un vector
        //Dans ce cas là la fonction push_back nous permet d'ajouter des pages à notre livre.
    }

    return tmp;
    //Notre variable tmp du début que l'on retrouve ici qui va nous permettre "d'obtenir" un livre.
}
