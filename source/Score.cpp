//
// Score.cpp for score in /home/lebeau_c/Projects/cpp_bomberman/Menu
//
// Made by lebeau_c
// Login   <lebeau_c@epitech.net>
//
// Started on  Thu May 15 11:47:10 2014 lebeau_c
// Last update Fri Jun 13 17:56:39 2014 Antoine BERGHEN
//

#include <fstream>
#include "Manager.hpp"
#include "Menu.hpp"
#include "Score.hpp"

Score::Score(Manager & manag) : ADisplay()
{
   _status = 0;
   std::cout << "Création du Score\n" << std::endl;
   initialize();
   _backS.setTexture(_background);
   this->_fileName = ".Score";
   _back = 0;
   _score = 0;
}

void	Score::draw(Manager & manag)
{
   go_back(manag);
   if (_score == 0)
     {
       manag.get_app()->clear();
       manag.get_app()->draw(_backS);  
       readScore(manag);
     }
}

void	Score::initialize()
{
   if (!_background.loadFromFile("img/Score.png"))
      std::cout<<"Erreur durant le chargement d'une texture"<<std::endl;
}

void	Score::go_back(Manager & manag)
{
   _mouseX = manag.getMouseX();
   _mouseY = manag.getMouseY();
   if (_mouseX >= 635 && _mouseX <= 712 && _mouseY >= 494 && _mouseY <= 524)
   {
      if (manag.getButton() == 1)
      {
	 setStatut(0);
	 _back = 1;
	 manag.resetButton();
      }
   }
   else
     manag.resetButton();
}

void	Score::display(Manager & manag)
{
   manag.get_app()->display();
}

void	Score::readScore(Manager & manag)
{
   std::ifstream	file(FILE_SCORE);
   std::string		line;
   int			x(160), y(160);

   if (file.is_open())
   {
      _font.loadFromFile("img/Neon.ttf");
      _text.setFont(_font);
      _text.setStyle(sf::Text::Bold);
      _text.setColor(sf::Color::Red);
      _text.setCharacterSize(30);
      while (getline(file, line))
      {
	 _text.setString(line);
	 _text.setPosition(x,y);
	 manag.get_app()->draw(_text);
	 getline(file, line);
	 _text.setString(line);
	 _text.setPosition(x + 500 - (line.length() * 30),y); //alignement par la droite pour le score
	 manag.get_app()->draw(_text);
	 y+=35;
      }
      display(manag);
      file.close();
   }
   else
      std::cout << "Unable to open score file\n";
}

std::vector<std::pair<std::string, int> >	Score::CheckScoreBeforeWriteSecond(std::string name, int score, std::vector<std::pair<std::string, int> > stock)
{
  int	verif = 0;
  std::vector<std::pair<std::string, int> >::iterator it;
  for (it = stock.begin() ; it != stock.end(); ++it)
    {
      if ((*it).first.compare(name) == 0)
	{
	  verif = 1;
	  if ((*it).second < score)
	    (*it).second = score;
	}
    }
  if (verif == 0)
    {
      std::pair<std::string, int> stock2 = make_pair(name, score);
      stock.push_back(stock2);
    }
  return (stock);
}

std::vector<std::pair<std::string, int> >	Score::CheckScoreBeforeWrite(std::string name, int score)
{
  std::ifstream	file(FILE_SCORE);
  std::vector <std::pair <std::string, int> > stock;

  if (file.is_open())
    {
      std::string line;
      while (getline(file, line))
	{
	  int	i1 = 0;
	  int	i2 = 0;
	  const char *stock2 = line.c_str();
	  while (stock2[i1] && (stock2[i1] != '\t' && stock2[i1] != ' '))
	    i1++;
	  i2 = i1;
	  while (stock2[i2] && (stock2[i2] == ' ' || stock2[i2] == '\t'))
	    i2++;
	  int	i3 = i2;
	  while (stock2[i3])
	    i3++;
	  std::string name = line.substr(0, i1);
	  std::string value = line.substr(i2, i3);
	  int	valeur = atoi(value.c_str());
	  std::pair<std::string, int> stock3 = std::make_pair (name, valeur);
	  stock.push_back(stock3);
	}
    }
  else
    std::cout << "Unable to open score file\n";
  stock = this->CheckScoreBeforeWriteSecond(name, score, stock);
  return (stock);
}

void	Score::writeScore(std::string name, int score)
{

  std::vector<std::pair<std::string, int> > stock;

   stock = this->CheckScoreBeforeWrite(name, score);
   std::ofstream	file(FILE_SCORE);
   if (file.is_open())
   {
     std::vector<std::pair<std::string, int> >::iterator it;
     for (it = stock.begin() ; it != stock.end(); ++it)
       file << (*it).first << "\t" << (*it).second << std::endl;
      file.close();
   }
   else
      std::cout << "Can't open file and wirte score\n";
}

Score::~Score()
{
}
