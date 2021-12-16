// exercice1 
#include <iostream>
#include <cmath>

using namespace std;

class complexe { //cr"atio de la classe complexe
    double Re;
    double Img;

public:
    complexe(double a = 0, double b = 0) //déclaration des variables par defaut
    {
        Re = a;
        Img = b;
    }
    void afficher()
    {
    	cout << Re;
    	
    	//Pour ne pas afficher 4 + -6i (si Img est negatif)
        if (Img >= 0)
            cout << " + ";
            
        cout << Img << "i" << endl;
    }
    double module()
    {
        return sqrt(Re * Re + Img + Img);
    }
    complexe conjugue()
    {
        complexe c;
        c.Re = Re;
        c.Img = -Img;
        return c;
    }
    
    //Opérateur : complexe + complexe
    complexe operator+(complexe a)
    {
        complexe s;
        s.Re = Re + a.Re;
        s.Img = Img + a.Img;
        return s;
    }
    
    //Opérateur : complexe + double
    complexe operator+(double x)
    {
        complexe s;
        s.Re = Re + x;
        s.Img = Img;
        return s;
    }
    
    //Opérateur : complexe - complexe
    complexe operator-(complexe a)
    {
        complexe s;
        s.Re = Re - a.Re;
        s.Img = Img - a.Img;
        return s;
    }
    
    //Opérateur : complexe * complexe
    complexe operator*(complexe a)
    {
        complexe p;
        p.Re = Re * a.Re - Img * a.Img;
        p.Img = Re * a.Img + Img * a.Re;
        return p;
    }
    //Même principe pour la division (utiliser le conjugé)
    
    //Opérateur : double + complexe
    friend complexe operator+(double, complexe);

};
complexe operator+(double x, complexe a)
{
    complexe s;
    s.Re = a.Re + x;
    s.Img = a.Img;
    return s;
    
    /*
    2ème Méthode
    On peut utiliser l'operateur complexe + double
    return a + x;
    */
}
int main()
{
    complexe a(1, 3), b(2, 7), c;
    cout << "Complexe A = ";
    a.afficher();
    cout << "Le module de A est : " << a.module() << endl;
    cout << "Le conjugue de A est : ";
    a.conjugue().afficher();
    
    cout << "A = ";
    a.afficher();
    cout << "B = ";
    b.afficher();
    
    cout << "A + B = ";
    c = (a + b);
	c.afficher();
    
    cout << "A + 12 = ";
    c = (a + 12);
	c.afficher();
    
    cout << "8 + A = ";
    c = (8 + a);
	c.afficher();
    
    cout << "A * B = ";
    c = (a * b);
	c.afficher();
    
    cout << "B - A = ";
    c = (b - a);
	c.afficher();
}

//exercice2:
#include<iostream>
using namespace std;
int main(){
char chaine[13]="021020001258";
int i;
cout<<"la date est : le jour ";
for( i = 0; i < 2; i++)
{
    cout<<chaine[i];
};
cout<<" du mois ";
for( i = 2; i < 4; i++)
{
    cout<<chaine[i];
};
cout<<" de l'annee ";
for( i = 4; i < 8; i++)
{
    cout<<chaine[i];
};
cout<<" a l'heure ";
for( i = 8; i < 10; i++)
{
    cout<<chaine[i];
};
cout<<" : ";
for( i = 10; i < 12; i++)
{
    cout<<chaine[i];
}; 
}

//exercice3:
#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> maliste;    //déclaration une liste
    //déclaration des variables
    int n; 
    int i;
    cout<<"inserez les nombres a trier "<<endl;
    for (i = 0;; i++)  
    {
    cin>>n;
    if(n==0)
    {
        break;  
    }
    maliste.push_back(n); 
    }
    list<int>::iterator it;  
    maliste.sort();    
    it=maliste.begin();
    cout<<"votre liste de nombre triee est : ";
    for (it;it!=maliste.end();it++)  
    {
            cout<<*it<<"  ";
    }

//exercice4:
#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<string> maliste;   //déclaration une liste
    string n;
    int i;
    cout<<"inserez le nom, le prenom et l'age de chaque personne sous form de nom,prenom,age. inserez arreter quand vous terminez :"<<endl;
    for (i = 0;; i++) 
    {
    cin>>n;
    if(n=="arreter")
    {
        break;   
    }
    maliste.push_back(n); 
    }
    list<string>::iterator it;  
    maliste.sort();     
    it=maliste.begin();
    cout<<"votre liste  est : ";
    for (it;it!=maliste.end();it++)  
    {
            cout<<*it<<"  ";
    }
}
 //exercice5 :
 #include<iostream>
#include<set>
#include<list>
#include<vector>
using namespace std;
    set<int> myset;
    set<int>::iterator itr;
    bool recherche(int a)    
    {
        for (itr = myset.begin(); itr != myset.end(); itr++)
        {   
            if(a==*itr){return true;}; 
        }
        return false;
    };
    
int main()
{
    int i;
    for ( i = 1; i < 101; i++)
    {
        myset.insert(i);
    }
    cout<<recherche(1)<<endl;
    cout<<recherche(27)<<endl;
    cout<<recherche(100)<<endl;
    cout<<recherche(500)<<endl;
};
//exercice6 :
#include <iostream>
#include <exception>
using namespace std;
class Test{
public:
static int tableau[] ;
public :
static int division(int indice, int diviseur){
	
	if(diviseur == 0 && (indice<0 || indice>10))
	       throw "Division par zero !! , l'indice invalide";
	else if (diviseur == 0 )
			throw "Division par zero !!";
	else if(indice<0 || indice>10)   
	        throw "l'indice invalide";
	        
return tableau[indice]/diviseur;
}
};
int Test::tableau[] = {17, 12, 15, 38, 29, 157, 89, -22, 0, 5} ;
int main()
{
int x, y;
cout << "Entrez l'indice de l'entier a diviser: " << endl;
cin >> x ;
cout << "Entrez le diviseur: " << endl;
cin >> y ;
 
  try{
        cout << "Le resultat de la division est: "<< endl<<Test::division(x,y) <<endl;;	
	 }catch(const char* msg){
		cerr<<msg;
	}	
 	
return 0;
}







