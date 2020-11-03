#include "../../../header/miniJeu/CorrigeCopie/CorrigeCopie.h"

struct QuestRep
{
	std::string question;
	std::vector<std::string> tabRepVrai;
	std::vector<std::string> tabRepFaux;
};

std::vector<QuestRep> getTabQuest()
{
	std::vector<QuestRep> tab;
	QuestRep tabQuest;
	std::vector<std::string> tabRepVrai;
	std::vector<std::string> tabRepFaux;


	//1
	tabQuest.question = "Quel est la taille d'une adresse dans la mémoire";
	tabRepVrai.push_back("8 octets");
	tabRepVrai.push_back("64 bits");
	tabRepFaux.push_back("8 bits");
	tabRepFaux.push_back("64 octets");
	tabRepFaux.push_back("16 bits");
	tabRepFaux.push_back("1 octets");
	tabRepFaux.push_back("52 bits");
	tabRepFaux.push_back("42 octets");

	tabQuest.tabRepVrai = tabRepVrai;
	tabQuest.tabRepFaux = tabRepFaux;

	tabRepVrai.resize(0);
	tabRepFaux.resize(0);

	tab.push_back(tabQuest);


	//2
	tabQuest.question = "Ecrivez une blague drole";
	tabRepVrai.push_back("Un geek ne crie pas, il URL !");
	tabRepVrai.push_back("Un geek ne descend pas du métro. Il libère la RAM.");
	tabRepFaux.push_back("J'ai fait une blague sur Carrefour, mais elle n'a pas supermarché.");
	tabRepFaux.push_back("Il n'y a pas de chauve à Ajaccio, mais à Calvi si.");

	tabQuest.tabRepVrai = tabRepVrai;
	tabQuest.tabRepFaux = tabRepFaux;

	tabRepVrai.resize(0);
	tabRepFaux.resize(0);

	tab.push_back(tabQuest);


	//3
	tabQuest.question = "i++ ou ++i ?";
	tabRepVrai.push_back("++i");
	tabRepFaux.push_back("i++");

	tabQuest.tabRepVrai = tabRepVrai;
	tabQuest.tabRepFaux = tabRepFaux;

	tabRepVrai.resize(0);
	tabRepFaux.resize(0);

	tab.push_back(tabQuest);


	//4
	tabQuest.question = "Je crée une fonction Puissance(const int& n) pour calculer la puissance de n, est-il conseillé d'utiliser la récursivité ?";
	tabRepVrai.push_back("Je peux, mais il est préférable d'éviter.");
	tabRepVrai.push_back("Non je fais une boucle.");
	tabRepFaux.push_back("Oui, c'est une bonne idée.");
	tabRepFaux.push_back("Non pour la calculer je demande à l'utilisateur de le faire.");

	tabQuest.tabRepVrai = tabRepVrai;
	tabQuest.tabRepFaux = tabRepFaux;

	tabRepVrai.resize(0);
	tabRepFaux.resize(0);

	tab.push_back(tabQuest);


	//5
	tabQuest.question = "Marc LAPORTE est-il le meilleur proffesseur du monde ?";
	tabRepVrai.push_back("Bien évidemment !");
	tabRepVrai.push_back("Ouais, en plus il est beau !");
	tabRepVrai.push_back("Tout simplement oui !");
	tabRepFaux.push_back("Je préfère Java.");
	tabRepFaux.push_back("Je préfère la BD.");
	tabRepFaux.push_back("Non c'est mon papa le meilleur !!!!!!");
	tabRepFaux.push_back("Bah non.");

	tabQuest.tabRepVrai = tabRepVrai;
	tabQuest.tabRepFaux = tabRepFaux;

	tabRepVrai.resize(0);
	tabRepFaux.resize(0);

	tab.push_back(tabQuest);


	//6
	tabQuest.question = "Ecrivez le corps de la fonction find(n,tab) où on recherche n dans tab :";
	tabRepVrai.push_back("for(unsigned i = 0 ; i < tab.size() ; ++i) if (tab[i] == n) return i;");
	tabRepFaux.push_back("if (n == tab) return true;");
	tabRepFaux.push_back("if (n != tab) return false;");
	tabRepFaux.push_back("return n;");

	tabQuest.tabRepVrai = tabRepVrai;
	tabQuest.tabRepFaux = tabRepFaux;

	tabRepVrai.resize(0);
	tabRepFaux.resize(0);

	tab.push_back(tabQuest);

	//7
	tabQuest.question = "Combien de bits contient un octet ?";
	tabRepVrai.push_back("8 bits");
	tabRepFaux.push_back("64 bits");
	tabRepFaux.push_back("Je sais pas.");

	tabQuest.tabRepVrai = tabRepVrai;
	tabQuest.tabRepFaux = tabRepFaux;

	tabRepVrai.resize(0);
	tabRepFaux.resize(0);

	tab.push_back(tabQuest);


	//8
	tabQuest.question = "Combien d'octets dans un bits ?";
	tabRepVrai.push_back("Pas possible.");
	tabRepVrai.push_back("Un octets fait 8 bits mais l'inverse est impossible.");
	tabRepFaux.push_back("8 octets");
	tabRepFaux.push_back("64 octets");
	tabRepFaux.push_back("128 octets");

	tabQuest.tabRepVrai = tabRepVrai;
	tabQuest.tabRepFaux = tabRepFaux;

	tabRepVrai.resize(0);
	tabRepFaux.resize(0);

	tab.push_back(tabQuest);


	//9
	tabQuest.question = "Pètes et répètes sont sur un bateau, pètes tombent à l'eau, qui c'est qui reste sur le bateau ?";
	tabRepVrai.push_back("Répètes.");
	tabRepFaux.push_back("Pètes.");
	tabRepFaux.push_back("Petit bateau, qui navigue sur les flots.");

	tabQuest.tabRepVrai = tabRepVrai;
	tabQuest.tabRepFaux = tabRepFaux;

	tabRepVrai.resize(0);
	tabRepFaux.resize(0);

	tab.push_back(tabQuest);

	//10
	tabQuest.question = "Écrivez un pointeur sur un int :";
	tabRepVrai.push_back("int* n = new int();");
	tabRepVrai.push_back("int i; int* n = &i;");
	tabRepFaux.push_back("int n = new int();");
	tabRepFaux.push_back("int* n = int();");
	tabRepFaux.push_back("int* n = new unsigned();");

	tabQuest.tabRepVrai = tabRepVrai;
	tabQuest.tabRepFaux = tabRepFaux;

	tabRepVrai.resize(0);
	tabRepFaux.resize(0);

	tab.push_back(tabQuest);

	return tab;

}

void CorrigeCopie::CorrigeCopie::setup()
{
	tempsMax = 1000;
	tempsPasse = 0;

	std::vector<QuestRep> tab = getTabQuest();

	const unsigned nbQuestion = std::rand() % tab.size();
	const unsigned short sizeQuest = 200;
	
	

	tabLibelle.resize(nbQuestion);

	//Definit tout
	for (unsigned i = 0; i < tabLibelle.size(); ++i)
	{
		unsigned n = std::rand() % tab.size();
		tabLibelle[i].second.first.setString(tab[n].question);

		if (std::rand() % 2 == 0)
		{
			tabLibelle[i].first = true;
			tabLibelle[i].second.second.setString(tab[n].tabRepVrai[std::rand() % tab[n].tabRepVrai.size()]);
		}
		else
		{
			tabLibelle[i].first = false;
			tabLibelle[i].second.second.setString(tab[n].tabRepFaux[std::rand() % tab[n].tabRepFaux.size()]);
		}

		tab.erase(tab.begin() + n);
	}

	//Definit les graphisme du Texte
	for (unsigned i = 0; i < tabLibelle.size(); ++i)
	{
		tabLibelle[i].second.first.setFont(font);
		tabLibelle[i].second.second.setFont(font);

		tabLibelle[i].second.first.setCharacterSize(20);
		tabLibelle[i].second.second.setCharacterSize(15);

		tabLibelle[i].second.first.setStyle(sf::Text::Bold);

		tabLibelle[i].second.first.setFillColor(sf::Color::Black);
		tabLibelle[i].second.second.setFillColor(sf::Color::Blue);
	}


	sizeFeuille = (nbQuestion * sizeQuest) + 100;
	feuille.setSize(sf::Vector2f(app.window.getSize().x-200,sizeFeuille));
	feuille.setFillColor(sf::Color::White);
}

void CorrigeCopie::CorrigeCopie::update()
{
	posCamera = (sizeFeuille + (app.window.getSize().y / 2)) * (tempsPasse / tempsMax);

	feuille.setPosition(100, int((app.window.getSize().y / 2) - posCamera));
	for (unsigned i = 0; i < tabLibelle.size(); ++i)
	{
		tabLibelle[i].second.first.setPosition(150 , int((app.window.getSize().y / 2) + 50 + (200 * i) - posCamera));
		tabLibelle[i].second.second.setPosition(150, int((app.window.getSize().y / 2) + 100 + (200 * i) - posCamera));
	}

	tempsPasse += 1;
	if (tempsPasse > tempsMax) isFinished = true;
}

void CorrigeCopie::CorrigeCopie::draw()
{
	app.window.draw(feuille);

	for (unsigned i = 0; i < tabLibelle.size(); ++i)
	{
		app.window.draw(tabLibelle[i].second.first);
		app.window.draw(tabLibelle[i].second.second);
	}
}

CorrigeCopie::CorrigeCopie::CorrigeCopie(AppData& appData) : MiniJeu(appData)
{
	std::srand(std::time(0));
	posCamera = 0;
	font.loadFromFile("../ressource/fonts/unispace rg.ttf");
}

CorrigeCopie::CorrigeCopie::~CorrigeCopie()
{

}