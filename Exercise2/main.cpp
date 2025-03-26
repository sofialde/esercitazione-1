#include <iostream>
#include<fstream>
#include <string>
#include <sstream>
#include <iomanip>

double f(double x)      //questa funzione riparametrizza i valori sul nuovo intervallo
{
    int a = 1;
    int b = 5;
    int c =-1;
    int d = 2;
    return ((x-a)*(d-c)/(b-a)+c);
}

int main()
{
    std::ifstream file("data.txt");
    if(file.fail())                 //verifico che il file si apra correttamente
    {
        std::cerr <<"errore nell'apertura del file"<<std::endl ;
        return 1 ;               
    }

    std::string linea;      //dichiaro le variabili
    double numero;
    double nuovo;     
    int N = 0;
    double somma = 0;
    double media = 0;

     std::ofstream file2("result.txt");     //apro file in scrittura (se il file non esiste lo crea, altrimenti ci scrive sopra)
      if(file2.fail())         
         {
          std::cerr <<"errore nell'apertura del file"<<std::endl ;
           return 1 ;               
          }    
     

        file2 << "# N Mean" << std::endl; // Scrive sul file
          

    while (std::getline(file,linea))
        {
        std::stringstream ss(linea);    //trasformo la stringa in uno stream
        if (ss>>numero) {               //se è un intero entro nell'if, altrimenti va avanti saltando la riga
            N+=1;                       
            nuovo = f(numero);          
            somma += nuovo;
            media = somma/N;            
            
            file2<<N<<" "<<std::setprecision(20)<<std::scientific<<media<<std::endl;   
        }
        
    }
    file2.close();

    std::cout << "Risultato salvato su result.txt!" << std::endl;
    file.close();

    return 0;
}
