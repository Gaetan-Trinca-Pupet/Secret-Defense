#include "../../../header/miniJeu/AmphiReponse/AmphiReponse.h"

std::vector<std::string> AmphiReponse::AmphiReponse::getTabQ() const
{
	std::vector<std::string> tab;
	tab.push_back("i++ OU ++i ?"); //0
	tab.push_back("Pourquoi ça marche pas ?"); //1
	tab.push_back("Comment écrire for ?"); //2
	tab.push_back("Je peux aller au toilette ?"); //3
	tab.push_back("J'arrive pas à voir"); //4
	return tab;
}

std::vector<std::string> AmphiReponse::AmphiReponse::getTabR() const
{
	std::vector<std::string> tab;
	tab.push_back("++i"); //0
	tab.push_back("Parce que t'es nul !"); //1
	tab.push_back("for (;;);"); //2
	tab.push_back("Non tu restes"); //3
	tab.push_back("Rapproche toi"); //4
	return tab;
}

std::vector<std::string> AmphiReponse::AmphiReponse::getTabM() const
{
	std::vector<std::string> tab;
	tab.push_back("J'aime les pommes");
	tab.push_back("Il faut débrancher le PC");
	tab.push_back("Demande a Casali");
	tab.push_back("Où sont mes lunettes");
	tab.push_back("i++");
	tab.push_back("Au revoir.");
	return tab;
}

void AmphiReponse::AmphiReponse::setup()
{
	const unsigned short decalage = 250;
	
	
	nbQuestion = 2 + (app.difficulty > 3 ? 3 : app.difficulty);
	const unsigned short nbMauvaiseReponse = (app.difficulty/3 > 6 ? 6 : app.difficulty/3);

	std::vector<std::string> tabQ = getTabQ();
	std::vector<std::string> tabR = getTabR();
	std::vector<std::string> tabM = getTabM();



	std::vector<unsigned short> tabNum;

	

	//Choisis les Questions Réponses et les ajoute dans le tableau
	tabNum.resize(nbQuestion);
	for (unsigned i = 0; i < tabNum.size(); ++i)
		tabNum[i] = i;
	tabQuest.resize(nbQuestion);
	for (unsigned i = 0; i < tabQuest.size(); ++i)
	{
		unsigned short n = std::rand() % tabNum.size();
		tabQuest[i] = new QuestionReponse(new QuestionReponse(nullptr, tabQ[tabNum[n]], true), tabR[tabNum[n]]);
		tabNum.erase(tabNum.begin() + n);
	}

	// Rajoute des mauvaise réponse au tableau
	tabNum.resize(tabM.size());
	for (unsigned i = 0; i < tabNum.size(); ++i)
		tabNum[i] = i;
	for (unsigned i = 0; i < nbMauvaiseReponse; i++)
	{
		unsigned short n = std::rand() % tabNum.size();
		tabQuest.push_back(new QuestionReponse(nullptr, tabM[tabNum[n]]));
		tabNum.erase(tabNum.begin() + n);
	}

	// Ajout dans main les Reponse
	for (unsigned i = 0; i < tabQuest.size(); ++i)
		main.add(tabQuest[i]);

	// Set position des Réponses de facon random
	tabNum.resize(tabQuest.size());
	for (unsigned i = 0; i < tabNum.size(); ++i)
		tabNum[i] = i;
	for (unsigned i = 0; i < tabQuest.size(); ++i)
	{
		unsigned short n = std::rand() % tabNum.size();
		tabQuest[tabNum[n]]->setPosition((decalage + ((app.window.getSize().x - decalage) / tabQuest.size()) * i) + ((app.window.getSize().x - decalage) / tabQuest.size())/2, app.window.getSize().y - (i % 2 == 0 ? 100 + (i % 4 == 0 ? 150 : 0) : 150 + (i % 3 == 0 ? 50 : 0)));
		tabNum.erase(tabNum.begin() + n);
	}

	// Set position des Questions de facon random
	tabNum.resize(tabQuest.size());
	for (unsigned i = 0; i < tabNum.size(); ++i)
		tabNum[i] = i;
	for (unsigned i = 0; i < tabQuest.size(); ++i)
	{
		unsigned short n = std::rand() % tabNum.size();
		if (tabQuest[tabNum[n]]->getMatch() != nullptr)
		{
			tabQuest[tabNum[n]]->getMatch()->setPosition(decalage + (((app.window.getSize().x - decalage) / tabQuest.size()) * i), (i % 2 == 0 ? 50 + (i % 4 == 0 ? 150 : 0) : 100 + (i%3 == 0 ? 50 : 0)));
		}
		tabNum.erase(tabNum.begin() + n);
	}
}

void AmphiReponse::AmphiReponse::draw()
{
	background.setPosition(-1 + std::rand() % 3 , -1 + std::rand() % 3);
	app.window.draw(background);
	for (unsigned i(0); i < tabQuest.size(); ++i)
		tabQuest[i]->draw(app.window);
	main.draw(app.window);

	laporteSprite.setPosition(laporteX + (std::rand() % 10), laporteY + (std::rand() % 10));
	app.window.draw(laporteSprite);
}

void AmphiReponse::AmphiReponse::update()
{
	main.update(app.window);
	for (QuestionReponse* prise : tabQuest)
		if (prise->isMatched() and main.find(prise))
		{
			main.remove(prise);
			--nbQuestion;
		}
	if (nbQuestion <= 0)
		isFinished = true;
}

AmphiReponse::AmphiReponse::AmphiReponse(AppData& appData) : MiniJeu(appData)
{
	app.window.sf::Window::setMouseCursorVisible(false);
	std::srand(std::time(nullptr));

	main = Grabber::Grabber();
	main.setX(app.window.getSize().x / 2);
	main.setY(app.window.getSize().y / 2);

	sf::Texture texture;
	texture.loadFromFile("../ressource/image/hand.png");
	main.setSprite(texture);

	laporteTexture.loadFromFile("../ressource/image/laporteColere.png");
	laporteSprite.setTexture(laporteTexture);
	laporteX = 10;
	laporteY = app.window.getSize().y - 300;

	backImage.loadFromFile("../ressource/AmphiReponse/background.png");
	background.setTexture(backImage);
}

AmphiReponse::AmphiReponse::~AmphiReponse()
{
	for (unsigned i(0); i < tabQuest.size(); ++i)
		delete tabQuest[i];
}
