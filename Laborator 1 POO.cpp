#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Publicatie 
{
protected:
    std::string titlu;

public:
    Publicatie(const std::string& titlu) : titlu(titlu) {}

    std::string getTitlu() const 
    {
        return titlu;
    }
};

class Carte : public Publicatie 
{
private:
    std::string autor;
    std::string ISBN;

public:
    Carte(const std::string& titlu, const std::string& autor, const std::string& ISBN)
        : Publicatie(titlu), autor(autor), ISBN(ISBN) {}

    std::string getAutor() const 
    {
        return autor;
    }

    std::string getISBN() const 
    {
        return ISBN;
    }

    std::string getInfo() const
    {
        return "Carte: " + titlu + ", Autor: " + autor + ", ISBN: " + ISBN;
    }
};

class Biblioteca 
{
private:
    std::vector<Carte> carti;

public:
    void Adauga_Carte(const Carte& carte) 
    {
        carti.push_back(carte);
        std::cout << "Cartea a fost adaugata: " << carte.getTitlu() << std::endl;
    }

    void Elimina_Carte(const std::string& ISBN) 
    {
        auto it = std::remove_if(carti.begin(), carti.end(), [&ISBN](const Carte& carte) {
            return carte.getISBN() == ISBN;
        });

        if (it != carti.end()) 
        {
            std::cout << "Cartea cu ISBN " << ISBN << " a fost eliminata." << std::endl;
            carti.erase(it, carti.end());
        } 
        else 
        {
            std::cout << "Cartea cu ISBN " << ISBN << " nu a fost găsita." << std::endl;
        }
    }

    void Afiseaza_Carti() const 
    {
        if (carti.empty()) 
        {
            std::cout << "Biblioteca este goala." << std::endl;
        } 
        else 
        {
            std::cout << "Cărti în biblioteca:" << std::endl;
            for (const auto& carte : carti) 
            {
                std::cout << carte.getInfo() << std::endl;
            }
        }
    }
};

void Afiseaza_Meniu() 
{
    std::cout << "\n -|- Meniu Biblioteca -|-\n";
    std::cout << "1. Adauga carte\n";
    std::cout << "2. Elimina carte dupa ISBN\n";
    std::cout << "3. Afiseaza toate cartile\n";
    std::cout << "0. Iesire\n";
    std::cout << "Alege o optiune: ";
}

int main() 
{
    Biblioteca biblioteca;
    int optiune;
    std::string titlu, autor, ISBN;

    do {
        Afiseaza_Meniu();
        std::cin >> optiune;

        switch (optiune) 
        {
        case 1: 
        {
            std::cout << "Introdu titlul cartii: ";
            std::cin.ignore(); 
            std::getline(std::cin, titlu);
            std::cout << "Introdu autorul cartii: ";
            std::getline(std::cin, autor);
            std::cout << "Introdu ISBN-ul cartii: ";
            std::getline(std::cin, ISBN);
            Carte carteNoua(titlu, autor, ISBN);
            biblioteca.Adauga_Carte(carteNoua);
            break;
        }
        case 2: 
        {
            std::cout << "Introdu ISBN-ul cartii de eliminat: ";
            std::cin.ignore();
            std::getline(std::cin, ISBN);
            biblioteca.Elimina_Carte(ISBN);
            break;
        }
        case 3:
            biblioteca.Afiseaza_Carti();
            break;
        case 0:
            std::cout << "Iesire din program.\n";
            break;
        default:
            std::cout << "Optiune invalida! Alege din nou.\n";
        }
    } while (optiune != 0);

    return 0;
}
