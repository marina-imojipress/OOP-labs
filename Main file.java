import java.util.ArrayList;
import java.util.List;


class Carte {
    private String titlu;
    private String autor;
    private String ISBN;

 
    public Carte(String titlu, String autor, String ISBN) 
    {
        this.titlu = titlu;
        this.autor = autor;
        this.ISBN = ISBN;
    }

   
    public String getTitlu() {
        return titlu;
    }

    public String getAutor() {
        return autor;
    }

    public String getISBN() {
        return ISBN;
    }

   
    @Override
    public String toString() {
        return "Carte: " + titlu + ", Autor: " + autor + ", ISBN: " + ISBN;
    }
}


class Biblioteca 
{
    private List<Carte> carti;

    public Biblioteca() 
    {
        this.carti = new ArrayList<>();
    }

    public void adaugaCarte(Carte carte) 
    {
        carti.add(carte);
        System.out.println("Cartea a fost adăugată: " + carte.getTitlu());
    }

    public void eliminaCarte(String ISBN) 
    {
        Carte deEliminat = null;
        for (Carte carte : carti) 
        {
            if (carte.getISBN().equals(ISBN)) 
            {
                deEliminat = carte;
                break;
            }
        }
        if (deEliminat != null) 
        {
            carti.remove(deEliminat);
            System.out.println("Cartea cu ISBN " + ISBN + " a fost eliminată.");
        } else {
            System.out.println("Cartea cu ISBN " + ISBN + " nu a fost găsită.");
        }
    }

    public void afiseazaCarti() 
    {
        if (carti.isEmpty()) 
        {
            System.out.println("Biblioteca este goală.");
        } else 
        {
            System.out.println("Cărți în bibliotecă:");
            for (Carte carte : carti) 
            {
                System.out.println(carte);
            }
        }
    }
}

public class Main 
{
    public static void main(String[] args) 
    {
   
        Biblioteca biblioteca = new Biblioteca();


        Carte carte1 = new Carte("Amintiri din copilărie", "Ion Creangă", "12345");
        Carte carte2 = new Carte("Enigma Otiliei", "George Călinescu", "67890");
        Carte carte3 = new Carte("Baltagul", "Mihail Sadoveanu", "54321");

        biblioteca.adaugaCarte(carte1);
        biblioteca.adaugaCarte(carte2);
        biblioteca.adaugaCarte(carte3);


        biblioteca.afiseazaCarti();

 
        biblioteca.eliminaCarte("67890");


        biblioteca.afiseazaCarti();
    }
}
