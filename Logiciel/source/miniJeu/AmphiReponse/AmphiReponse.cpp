#include "../../../header/miniJeu/AmphiReponse/AmphiReponse.h"

std::vector<std::string> getTabQ()
{
	std::vector<std::string> tab;
	std::fstream questionFile;
    questionFile.open("../ressource/AmphiReponse/Questions.txt",std::ios::in);
    if (questionFile.is_open()) {
        std::string question;
        while (std::getline(questionFile, question))
			tab.push_back(question);
    }
	return tab;
}

std::vector<std::string> getTabR()
{
	std::vector<std::string> tab;
	std::fstream answerFile;
    answerFile.open("../ressource/AmphiReponse/Reponses.txt",std::ios::in);
    if (answerFile.is_open()) {
        std::string answer;
        while (std::getline(answerFile, answer))
			tab.push_back(answer);
    }
	return tab;
}

std::vector<std::string> getTabM()
{
	std::vector<std::string> tab;
	std::fstream diversionFile;
    diversionFile.open("../ressource/AmphiReponse/Diversions.txt",std::ios::in);
    if (diversionFile.is_open()) {
        std::string diversion;
        while (std::getline(diversionFile, diversion))
			tab.push_back(diversion);
    }
	return tab;
}

void AmphiReponse::AmphiReponse::setup()
{
    const unsigned short decalage = 200;
	
	
	nbQuestion = 2 + (app.difficulty > 3 ? 3 : app.difficulty);
	const unsigned short nbMauvaiseReponse = (app.difficulty/3 > 6 ? 6 : app.difficulty/3);
	
    chrono.setTempsMax(5+3*std::pow(0.95, std::max(int(app.difficulty-4), 0)));

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
    std::vector<unsigned short> posx; //Génération d'un vecteur pour les positions x
    for (unsigned short x = 0; x < 8; ++x)
        posx.push_back(x);
    std::random_shuffle(posx.begin(), posx.end());
    std::vector<unsigned short> posy; //Génération d'un vecteur pour les positions y
    for (unsigned short y = 0; y < 8; ++y)
        posy.push_back(y);
    std::random_shuffle(posy.begin(), posy.end());
	for (unsigned i = 0; i < tabQuest.size(); ++i)
	{
		unsigned short n = std::rand() % tabNum.size();
        tabQuest[tabNum[n]]->setPosition(decalage + posx[i]*(app.window.getView().getSize().x - 2.5*decalage)/posx.size(), app.window.getView().getSize().y - (posy[i]+2) * 30);
		tabNum.erase(tabNum.begin() + n);
	}

	// Set position des Questions de facon random
	tabNum.resize(tabQuest.size());
    posx.resize(0); //Génération d'un vecteur pour les positions
    for (unsigned short x = 0; x < 8; ++x)
        posx.push_back(x);
    std::random_shuffle(posx.begin(), posx.end());
    posy.resize(0); //Génération d'un vecteur pour les positions
    for (unsigned short y = 0; y < 6; ++y)
        posy.push_back(y);
	for (unsigned i = 0; i < tabNum.size(); ++i)
		tabNum[i] = i;
	for (unsigned i = 0; i < tabQuest.size(); ++i)
	{
		unsigned short n = std::rand() % tabNum.size();
		if (tabQuest[tabNum[n]]->getMatch() != nullptr)
		{
            tabQuest[tabNum[n]]->getMatch()->setPosition(posx[i]*(decalage + app.window.getView().getSize().x - 2.5*decalage)/posx.size(), (posy[i]+1) * 35);
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
	app.window.draw(chrono);
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
	{
		end(true);
	}
	
	chrono.update();
	
	if (chrono.getTimePassed() > chrono.getTempsMax() && ! isFinished)
	{
		end(false, "Le temps est écoulé.");
	}
}

AmphiReponse::AmphiReponse::AmphiReponse(AppData& appData) : MiniJeu(appData), chrono(app.window)
{
	app.window.sf::Window::setMouseCursorVisible(false);
	std::srand(std::time(nullptr));

	main = Grabber::Grabber();
	main.setX(app.window.getView().getSize().x / 2);
	main.setY(app.window.getView().getSize().y / 2);

	sf::Texture texture;
	texture.loadFromFile("../ressource/image/hand.png");
	main.setSprite(texture);

	laporteTexture.loadFromFile("../ressource/image/laporteColere.png");
	laporteSprite.setTexture(laporteTexture);
	laporteX = 10;
	laporteY = app.window.getView().getSize().y - 300;

	backImage.loadFromFile("../ressource/AmphiReponse/background.png");
	background.setTexture(backImage);
}

AmphiReponse::AmphiReponse::~AmphiReponse()
{
	for (unsigned i(0); i < tabQuest.size(); ++i)
		delete tabQuest[i];

	app.window.setMouseCursorVisible(true);
}
