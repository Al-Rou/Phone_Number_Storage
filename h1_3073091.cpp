#include <iostream>
#include <iomanip>

using namespace std;

enum TelefonNummerTyp {Wohnung, Arbeit, Fax, Handy, EtwasAnderes};
struct kontakt
{
    string telNum, kontaktName;
    TelefonNummerTyp telTyp;
};
const int maxKontakt = 5;
int aktuellZahl = 0;
kontakt *kontaktListe = new kontakt [maxKontakt];
//Die oben geschriebenen Zeilen stehen nach was die Aufgabe angewiesen hat.
//Runter gibt das Program der Liste anfangende Werte.
void initialArr ()
{
for (int a = 0; a < maxKontakt; a++)
        {
            kontaktListe[a].kontaktName = "~";//Dieses Zeichen hat fast der groesste ASCII-Wert. Den benutzt man
            kontaktListe[a].telNum = "~";     //spaeter, wenn man die Liste sortiert machen moechte.
            kontaktListe[a].telTyp = Wohnung; //Ein Wort wie z.B. "Leer" haette vielleicht besser sein koennen, aber
        }                                     //die Aufgabe hat dazu nicht erlaubt!
}

bool lesenFunk () //Diese Funktion fuellt die Liste, definiert nach was die Aufgabe angewiesen hat!
{
    if (aktuellZahl >= maxKontakt)
    {
        return false;
    }
    else {

    cout << "Geben Sie den Namen des Kontaktes ein (Enter name of the contact): " << endl;

    if ( cin.peek() == '\n' )
		cin.ignore();
    getline(cin, kontaktListe[aktuellZahl].kontaktName);//Das Program fuellt die Liste von der ersten Zelle, wie
    cout << "Geben Sie die Telefonnummer des Kontaktes ein: " << endl;//der Zaehler zaelt.

    getline(cin, kontaktListe[aktuellZahl].telNum);//Spaeter sortiert das Program die Eingaben!
    cout << "Welcher Typ ist die Telefonnummer?" << endl << "Wohnung"
    << endl << "Arbeit" << endl << "Fax" << endl << "Handy" << endl << "EtwasAnderes" << endl
    << "Typen Sie den Typ: ";
    string tempTyp;
    getline (cin, tempTyp);
    switch (tempTyp[0])
    {
       case 'W' : kontaktListe[aktuellZahl].telTyp = Wohnung; break;
       case 'A' : kontaktListe[aktuellZahl].telTyp = Arbeit; break;
       case 'F' : kontaktListe[aktuellZahl].telTyp = Fax; break;
       case 'H' : kontaktListe[aktuellZahl].telTyp = Handy; break;
       case 'E' : kontaktListe[aktuellZahl].telTyp = EtwasAnderes; break;
       default : cout << "Falscher Eintrag fuer den Typ!" << endl;//Falls der Benutzer etwas Fehlerhaftes typt, muss
       kontaktListe[aktuellZahl].kontaktName = "~";               //das Program dabei flexibel sein.
       kontaktListe[aktuellZahl].telNum = "~";
       aktuellZahl--;//Da der Zaehler nach dem "return true" in der naechsten Zeile zunehmen wird, muss das Program
                    //hier den zwingen, eins abzunehmen.
    }
        return true;
}
}

void inOrdnungFunk () //Diese Funktion ist nicht explizit in der Aufgabe genannt, aber sie ist dazu gebracht, wenn
{                     //man in verschiedenen Plaetzen die Daten sortiert machen muss.
    kontakt tempK;    //Der beruehmte Algorithmus ist dabei benutzt worden.
    for (int j = 0; j < maxKontakt-1; j++)
    {
        for (int k = j+1; k < maxKontakt; k++)
        {
            if (kontaktListe[j].kontaktName > kontaktListe[k].kontaktName)
            {
                tempK = kontaktListe[j];
                kontaktListe[j] = kontaktListe[k];
                kontaktListe[k] = tempK;
            }

        }
    }
}

bool loeschenFunk () //Die Funktion loescht ja eine bestimmte Eingabe.
{
    cout << "Geben Sie den Namen des Kontaktes ein, den Sie loeschen moechten: ";
    string entName;
    if ( cin.peek() == '\n' )
		cin.ignore();
    getline(cin, entName);
    for (int i = 0; i < maxKontakt; i++)
    {
        if (kontaktListe[i].kontaktName == entName)
        {
            kontaktListe[i].kontaktName = "~";//Dieselbe Methode ist benutzt worden, wie in der "Initialisierung"!:)
            kontaktListe[i].telNum = "~";
            kontaktListe[i].telTyp = Wohnung;
            return true;
        }
    }
    return false;
}

void loeschenAllFunk () //Alles ist hier ja klar!
{
    for (int i = 0; i < maxKontakt; i++)
    {
        kontaktListe[i].kontaktName = "~";
        kontaktListe[i].telNum = "~";
        kontaktListe[i].telTyp = Wohnung;
    }
}

void ausdruckenFunk () //<iomanip> ist hier benutzt worden.
{
    cout << setw(20) << "Name" << setw(20) << "Telefonnummer" << setw(20) << "Typ" << endl;
    for (int i = 0; i < maxKontakt; i++)
    {
        cout << setw(20) << kontaktListe[i].kontaktName << setw(20) << kontaktListe[i].telNum
        << setw(20);
        switch(kontaktListe[i].telTyp)
        {
            case Wohnung : cout << "Wohnung" << endl; break;
            case Arbeit : cout << "Arbeit" << endl; break;
            case Fax : cout << "Fax" << endl; break;
            case Handy : cout << "Handy" << endl; break;
            case EtwasAnderes : cout << "EtwasAnderes" << endl; break;
        }
    }
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Mehrere Eigenschaften, die nicht in der Aufgabe stehen,
aber ich habe gedacht, damit sieht mein Programm besser aus!
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int anzahlKon ()
{
    return aktuellZahl;
}
int listeKapazit ()
{
    return maxKontakt;
}
int restKapazit ()
{
    return (maxKontakt-aktuellZahl);
}

int main ()
{
    initialArr();
    int choice;
    do
    {
        cout << "Geben Sie die Nummer des Aktes, den Sie machen moechten: " << endl
        << "0) Ausgang" << endl << "1) Eingabe neues Kontaktes" << endl
        << "2) Einen Kontakt entfernen" << endl << "3) Alle Kontakte entfernen" << endl
        << "4) Alle Kontakte zeigen" << endl << "5) Anzahl der Kontakte" << endl
        << "6) Kapazitaet der Liste" << endl << "7) Uebrige Kapazitaet" << endl;
        cin >> choice;
        if (choice == 0)
            {return 0;//Das Programm endet nur dann, wenn der Benutzer durch "0" will.
            break;}
        else if (choice == 1)
        {
            bool valKon = lesenFunk();
                     if (valKon)
                        aktuellZahl++;
                     else
                        cout << "Die Liste ist voll!" << endl << aktuellZahl << " Kontakte" << endl;
            inOrdnungFunk(); //Sofort werden die Daten sortiert, fuer alle Faelle!
        }
        else if (choice == 2)
        {
            bool delKon = loeschenFunk();
            if (delKon)
            {
                aktuellZahl--;//Das Program muss den Zaehler auf dem neusten Stand behalten.
            }
            else
                cout << "Den Namen gibt es nicht!" << endl;
        }
        else if (choice == 3)
        {
            loeschenAllFunk();
        }
        else if (choice == 4)
        {
            inOrdnungFunk();
            ausdruckenFunk();
        }
        else if (choice == 5)
        {
            cout << anzahlKon() << " Kontakte gibt es in der Liste!" << endl;
        }
        else if (choice == 6)
        {
            cout << listeKapazit() << " Kontakte koennen hier gespeichert werden!" << endl;
        }
        else if (choice == 7)
        {
            cout << restKapazit() << " andere Kontakte koennen hinzugefuegt werden!" << endl;
        }
    } while (0 != 1);//Die Schleife muss niemals endet, sondern durch "return 0; break;", wenn der Benutzer will.
}
