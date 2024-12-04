#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <vector>
#include "Songs.h"

std::vector<Songs> loadSongs(const std::string& fileName) {
    std::vector<Songs> songs;
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Error opening file " << fileName << std::endl;
        return songs;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string songName;
        std::string songAuthor;

        std::getline(ss, songAuthor, ',');
        std::getline(ss, songName, ',');

        Songs song;
        song.name = songName;
        song.author = songAuthor;

        songs.emplace_back(song);
    }
    file.close();
    return songs;

}


int main()
{
    //This is the vector of songs
    std::vector<Songs> songs = loadSongs("spotify_millsongdata.csv");

    //this was just a test to see if it loaded into the vector

    // for (size_t i = 0; i < std::min(songs.size(), size_t(10)); ++i) {
    //     std::cout << "Name: " << songs[i].name << ", Author: " << songs[i].author << std::endl;
    // }




    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Song Searcher");
    // run the program as long as the window is open




    sf::Font font;
    font.loadFromFile("OpenSans-Regular.ttf");

    sf::Texture background;
    background.loadFromFile("Backgroundforproject3.jpg");
    sf::Sprite backgroundSprite(background);

    sf::RectangleShape separator(sf::Vector2f(600, 2));
    separator.setFillColor(sf::Color::White);

    sf::RectangleShape separator1(sf::Vector2f(600, 2));
    separator1.setFillColor(sf::Color::White);
    separator1.setPosition(100, 180); // Below Song 1

    sf::RectangleShape separator2(sf::Vector2f(600, 2));
    separator2.setFillColor(sf::Color::White);
    separator2.setPosition(100, 230); // Below Song 2

    sf::RectangleShape separator3(sf::Vector2f(600, 2));
    separator3.setFillColor(sf::Color::White);
    separator3.setPosition(100, 280); // Below Song 3

    sf::RectangleShape separator4(sf::Vector2f(600, 2));
    separator4.setFillColor(sf::Color::White);
    separator4.setPosition(100, 330); // Below Song 4


    sf::Text SongSearch("SONG SEARCH", font, 30);
    sf::Text entertext("Enter the song name:", font, 16);
    sf::Text bline("|", font, 12);


    sf::RectangleShape inputBox(sf::Vector2f(400, 30)); // Size of the input box
    inputBox.setFillColor(sf::Color::White);            // Background color
    inputBox.setOutlineColor(sf::Color::Black);         // Border color
    inputBox.setOutlineThickness(2);                    // Border thickness
    inputBox.setPosition(200, 180);                     // Position of the box


    std::string input;
    SongSearch.setFillColor(sf::Color::Black);
    entertext.setFillColor(sf::Color::Black);
    bline.setFillColor(sf::Color::Black);

    SongSearch.setPosition(305, 50);
    entertext.setPosition(200, 150);
    bline.setPosition(220, 185);


    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::TextEntered) {
                if (event.key.code == sf::Keyboard::Enter or event.key.code == 10) {
                    sf::RenderWindow window2(sf::VideoMode(800, 600), "Song Founderer");

                    sf::Texture background2;
                    background2.loadFromFile("Backgroundforproject3.jpg");
                    sf::Sprite backgroundSprite2(background2);


                    sf::Text songtitle(input,font,25);
                    songtitle.setFillColor(sf::Color::Black);
                    songtitle.setPosition(330, 100);

                    sf::Text title("Songs like: ", font, 30);
                    title.setFillColor(sf::Color::Black);
                    title.setPosition(300, 50);

                    //these are the top five answers they are just placeholders rn
                    std::string name1 = "Billy Jean";
                    std::string name2 = "Thriller";
                    std::string name3 = "GLO in A GLE";
                    std::string name4 = "PaperLong";
                    std::string name5 = "WAP";


                    sf::Text num1("1.", font, 30);
                    num1.setFillColor(sf::Color::Black);
                    num1.setPosition(100, 150);

                    sf::Text num1answer(name1, font, 30);
                    num1answer.setFillColor(sf::Color::Black);
                    num1answer.setPosition(150, 150);


                    sf::Text num2("2.", font, 30);
                    num2.setFillColor(sf::Color::Black);
                    num2.setPosition(100, 200);

                    sf::Text num2answer(name2, font, 30);
                    num2answer.setFillColor(sf::Color::Black);
                    num2answer.setPosition(150, 200);


                    sf::Text num3("3.", font, 30);
                    num3.setFillColor(sf::Color::Black);
                    num3.setPosition(100, 250);

                    sf::Text num3answer(name3, font, 30);
                    num3answer.setFillColor(sf::Color::Black);
                    num3answer.setPosition(150, 250);

                    sf::Text num4("4.", font, 30);
                    num4.setFillColor(sf::Color::Black);
                    num4.setPosition(100, 300);

                    sf::Text num4answer(name4, font, 30);
                    num4answer.setFillColor(sf::Color::Black);
                    num4answer.setPosition(150, 300);

                    sf::Text num5("5.", font, 30);
                    num5.setFillColor(sf::Color::Black);
                    num5.setPosition(100, 350);

                    sf::Text num5answer(name5, font, 30);
                    num5answer.setFillColor(sf::Color::Black);
                    num5answer.setPosition(150, 350);




                    window2.setActive(true);
                    while (window2.isOpen()) {
                        sf::Event event2;
                        while (window2.pollEvent(event2))
                        {

                            if (event2.type == sf::Event::Closed)
                                window2.close();
                        }
                        window2.clear(sf::Color::Blue);

                        window2.draw(backgroundSprite2);

                        window2.draw(songtitle);
                        window2.draw(title);
                        window2.draw(num1);
                        window2.draw(num1answer);
                        window2.draw(num2);
                        window2.draw(num2answer);
                        window2.draw(num3);
                        window2.draw(num3answer);
                        window2.draw(num4);
                        window2.draw(num4answer);
                        window2.draw(num5);
                        window2.draw(num5answer);
                        // window2.draw(separator1);
                        // window2.draw(separator2);
                        // window2.draw(separator3);
                        // window2.draw(separator4);




                        window2.display();
                    }
                }
                if (event.text.unicode == sf::Keyboard::Backspace
                    or event.text.unicode == 8) {
                    if (!input.empty()) input.pop_back();
                    bline.setString(input+'|');
                    }
                else {
                    // if (isalpha(event.text.unicode)) {
                        char c = (char)event.text.unicode;
                        // if (input.size() == 0) {
                        //     c = std::toupper(event.text.unicode);
                        // }
                        // else {
                        //     c = std::tolower(event.text.unicode);
                        // }
                        input += c;
                        bline.setString(input+'|');

                   // }
                }
            }
        }

        window.clear(sf::Color::White);

        window.draw(backgroundSprite);
        window.draw(SongSearch);
        window.draw(entertext);
        window.draw(inputBox);
        window.draw(bline);




        window.display();
    }
    return 0;
}
