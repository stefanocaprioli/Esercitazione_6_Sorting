#include <chrono>
#include <iostream>
#include "SortingAlgorithm.hpp"
#include <Eigen/Eigen>
#include <vector>
#include <cstdlib>

using namespace std;
using namespace SortLibrary;
using namespace chrono;

int main( int argc, char *argv[]) // argv[] è un array di puntatori a stringhe, argc è il numero di parametri passati
{
    if (argc == 1){
        cerr << "Inserire la dimensione del vettore in: " << argv[0] << endl;
        return 1;
    }

    unsigned int n = 120; // creo molti vettori randomici delle dimensioni richieste

    vector<int> dimensioni;
    dimensioni.resize(argc-1);

    for ( unsigned int i = 1; i < argc; i++)
    {
        dimensioni[i-1] = stoi(argv[i]);

    }
    vector<int> vect1;
    vector<int> vect2;

    for  ( unsigned int i = 0; i < dimensioni.size(); i++)
    {

        double mediaBubble = 0;
        double mediaMerge = 0;



        for (unsigned int j = 0; j < n; j++)
        {

            vect1.resize(dimensioni[i]);
            vect2.resize(dimensioni[i]);
            for (unsigned int m = 0; m < dimensioni[i]; m++ )
            {
                vect1[m] = rand();
                vect2[m] = rand();
            }

            chrono::steady_clock::time_point t_begin_Bubble = chrono::steady_clock::now();
            SortLibrary::BubbleSort(vect1);
            chrono::steady_clock::time_point t_end_Bubble = chrono::steady_clock::now();
            double tempoTrascorsoBubble = chrono::duration_cast<chrono::microseconds>(t_end_Bubble-t_begin_Bubble).count();

            chrono::steady_clock::time_point t_begin_Merge = chrono::steady_clock::now();
            SortLibrary::MergeSort(vect2);
            chrono::steady_clock::time_point t_end_Merge = chrono::steady_clock::now();
            double tempoTrascorsoMerge = chrono::duration_cast<chrono::microseconds>(t_end_Merge-t_begin_Merge).count();


            mediaBubble = mediaBubble + tempoTrascorsoBubble;
            mediaMerge = mediaMerge + tempoTrascorsoMerge;

        }
        cout << "Per il vettore randomico di dimensione " << dimensioni[i] << ", Bubble ha una media di " << mediaBubble/n <<" ms, mentre Merge ha una media di " <<mediaMerge/n << " ms." << endl;

    }


    return 0;


}
