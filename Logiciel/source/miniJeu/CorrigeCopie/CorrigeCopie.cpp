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

    std::fstream file;
    file.open("../ressource/CorrigeCopie/QuestionList.txt",std::ios::in);
    if (file.is_open()) {
        std::string line;
		if (std::getline(file, line)) {
			tabQuest.question = line.substr(2, std::string::npos);
		}
        while (std::getline(file, line)) {
			if (line[0] == 'Q') {
				tabQuest.tabRepVrai = tabRepVrai;
				tabQuest.tabRepFaux = tabRepFaux;

				tabRepVrai.resize(0);
				tabRepFaux.resize(0);

				tab.push_back(tabQuest);
				
				tabQuest.question = line.substr(2, std::string::npos);
			}
			if (line[0] == 'V') {
				tabRepVrai.push_back(line.substr(2, std::string::npos));
			}
			if (line[0] == 'F') {
				tabRepFaux.push_back(line.substr(2, std::string::npos));
			}
		}
	}
	return tab;
}

void CorrigeCopie::CorrigeCopie::computeTabText()
{
	for (Reponse& QR : tabLibelle)
	{
		std::string str = QR.question.getString();
		unsigned short sizeLine = 0;
		for (unsigned i = 0 ; i < str.size() ; ++i)
		{
			sizeLine += 1;
			if (str[i] == '\n') sizeLine = 0;
			if ((QR.question.getCharacterSize() + QR.question.getLetterSpacing()) * sizeLine >= feuille.getSize().x)
			{
				QR.nbligne += 1;
				for (i; str[i] != ' ' && i != 0; --i);
				sizeLine = 0;
				str.insert(++i, "\n");
				i += 1;
			}
		}
		QR.question.setString(str);

		str = QR.reponse.getString();
		sizeLine = 0;
		for (unsigned i = 0; i < str.size(); ++i)
		{
			sizeLine += 1;
			if (str[i] == '\n') sizeLine = 0;
			if (QR.reponse.getCharacterSize() * sizeLine + QR.reponse.getLetterSpacing() * sizeLine >= feuille.getSize().x)
			{
				for (i; str[i] != ' ' && i != 0; --i);
				sizeLine = 0;
				str.insert(++i, "\n");
				i += 1;
			}
		}
		QR.reponse.setString(str);
	}
}

void CorrigeCopie::CorrigeCopie::setup()
{
	std::vector<QuestRep> tab = getTabQuest();

    const unsigned nbQuestion = std::min(int(tab.size()), int(app.difficulty) + 2);
	const unsigned short sizeQuest = 200;
	
    chrono.setTempsMax((8+3*nbQuestion)*pow(0.95, std::max(app.difficulty+2-(int)tab.size(), 0)));

	tabLibelle.resize(nbQuestion);

	//Definit les questions réponses et vrai faux
	for (unsigned i = 0; i < tabLibelle.size(); ++i)
	{
		unsigned n = std::rand() % tab.size();
        tabLibelle[i].question.setString(sf::String::fromUtf8(tab[n].question.cbegin(), tab[n].question.cend()));

		if (std::rand() % 2 == 0)
		{
			tabLibelle[i].VF = true;
			unsigned int randVal = std::rand() % tab[n].tabRepVrai.size();
			tabLibelle[i].reponse.setString(sf::String::fromUtf8(tab[n].tabRepVrai[randVal].cbegin(),tab[n].tabRepVrai[randVal].cend()));
		}
		else
		{
			tabLibelle[i].VF = false;
			unsigned int randVal = std::rand() % tab[n].tabRepFaux.size();
			tabLibelle[i].reponse.setString(sf::String::fromUtf8(tab[n].tabRepFaux[randVal].cbegin(),tab[n].tabRepFaux[randVal].cend()));
		}

		tab.erase(tab.begin() + n);
	}
	
	tabBouton.resize(tabLibelle.size());
	for (unsigned i = 0; i < tabBouton.size() ; ++i)
	{
		sf::Texture texture;
		
		tabBouton[i].first = new BoutonVF(app.window , true);
		texture.loadFromFile("../ressource/CorrigeCopie/bon.png");
		tabBouton[i].first->setSpriteText(texture);
		tabBouton[i].second = new BoutonVF(app.window , false);
		texture.loadFromFile("../ressource/CorrigeCopie/faux.png");
		tabBouton[i].second->setSpriteText(texture);
	}
	

	//Definit les graphisme du Texte
	for (unsigned i = 0; i < tabLibelle.size(); ++i)
	{
		tabLibelle[i].question.setFont(font);
		tabLibelle[i].reponse.setFont(font);

		tabLibelle[i].question.setCharacterSize(20);
		tabLibelle[i].reponse.setCharacterSize(15);

		tabLibelle[i].question.setStyle(sf::Text::Bold);

		tabLibelle[i].question.setFillColor(sf::Color::Black);
		tabLibelle[i].reponse.setFillColor(sf::Color::Blue);
	}

	feuille.setSize(sf::Vector2f(app.window.getView().getSize().x-200, (nbQuestion * sizeQuest) + 100));
	feuille.setFillColor(sf::Color::White);

	computeTabText();
}

void CorrigeCopie::CorrigeCopie::update()
{
	
	
	posCamera = (feuille.getSize().y + (app.window.getView().getSize().y / 2)) * (chrono.getTimePassed() / chrono.getTempsMax() );

	feuille.setPosition(100, int((app.window.getView().getSize().y / 2) - posCamera));
	for (unsigned i = 0; i < tabLibelle.size(); ++i)
	{
		tabLibelle[i].question.setPosition(150 , int((app.window.getView().getSize().y / 2) + 50 + (200 * i) - posCamera));
		tabLibelle[i].reponse.setPosition(150, int((app.window.getView().getSize().y / 2) + 50 + tabLibelle[i].question.getCharacterSize()*(tabLibelle[i].nbligne + 1) + (200 * i) - posCamera));

		tabBouton[i].first->setPosition(int(feuille.getPosition().x + feuille.getSize().x - 200) , int((app.window.getView().getSize().y / 2) + 50 + (200 * i) - posCamera));
		tabBouton[i].second->setPosition(int(feuille.getPosition().x + feuille.getSize().x - 100) , int((app.window.getView().getSize().y / 2) + 50 + (200 * i) - posCamera));
	}

	for (unsigned i = 0; i < tabBouton.size(); ++i)
	{
		tabBouton[i].first->update();
		tabBouton[i].second->update();
	}

	// Checks if the buttons are pressed
	for(unsigned i = 0 ; i < tabBouton.size() ; ++i)
	{
		if(!(tabBouton[i].first->hasBeenClicked() || tabBouton[i].second->hasBeenClicked()))
		{
			tabBouton[i].first->onClick();
			tabBouton[i].second->onClick();
		}
	}
	
	for(unsigned i = 0 ; i < tabLibelle.size() ; ++i)
	{
		if(tabBouton[i].first->hasBeenClicked() || tabBouton[i].second->hasBeenClicked())
			if(tabLibelle[i].VF == (tabBouton[i].first->hasBeenClicked() ? tabBouton[i].first->isWhat() : tabBouton[i].second->isWhat()))
			{
				if(tabLibelle[i].isCorrect == false)
					AssetManager::playSound("../ressource/audio/bing.wav",20);
				tabLibelle[i].isCorrect = true;
			}
			else if (not isFinished)
			{
				AssetManager::playSound("../ressource/audio/bong.wav",20);
				end(false, "Votre correction est fausse.");
			}
	}
	unsigned short compte = 0;
	for(unsigned i = 0 ; i < tabLibelle.size() ; ++i)
		if(tabLibelle[i].isCorrect == true)
			++compte;
	if (tabLibelle.size() == compte)
		end(true);
	
	chrono.update();
	
	if (chrono.getTimePassed() > chrono.getTempsMax() && ! isFinished)
	{
		end(false, "Le temps est écoulé.");
	}
}

void CorrigeCopie::CorrigeCopie::draw()
{
	app.window.draw(feuille);

	for (unsigned i = 0; i < tabLibelle.size(); ++i)
	{
		app.window.draw(tabLibelle[i].question);
		app.window.draw(tabLibelle[i].reponse);
	}

	for (unsigned i = 0; i < tabBouton.size(); ++i)
	{
		if(not(tabBouton[i].first->hasBeenClicked() || tabBouton[i].second->hasBeenClicked()))
		{
			tabBouton[i].first->draw(app.window);
			tabBouton[i].second->draw(app.window);
		}
		else
			app.window.draw((tabLibelle[i].isCorrect ? tabBouton[i].first : tabBouton[i].second)->getSprite());
	}
	
	app.window.draw(chrono);
}

CorrigeCopie::CorrigeCopie::CorrigeCopie(AppData& appData) : MiniJeu(appData), chrono(app.window)
{
	std::srand(std::time(0));
	posCamera = 0;
	font.loadFromFile("../ressource/fonts/unispace rg.ttf");
}

CorrigeCopie::CorrigeCopie::~CorrigeCopie()
{
	for (unsigned i = 0; i < tabBouton.size(); ++i)
	{
		delete tabBouton[i].first;
		delete tabBouton[i].second;
	}
}
