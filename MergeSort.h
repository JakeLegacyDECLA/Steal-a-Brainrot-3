/*
Nombre: César Daniel Aguilar Kuri
Matricula: A01712823
Nombre del Proyecto: Steal a Brainrot!
Materia: Programación de estructuras de datos y algoritmos fundamentales
Profesor: Eduardo Daniel Juárez Pineda
*/

#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
#include <cctype>
#include <string>
#include <list>
#include <unordered_map>

using namespace std;

// ===== Jerarquía global de rarezas =====
// Common (menos importante) -> Secret (más importante)
inline int rarityRank(const string& r) { // O(1)
    static const unordered_map<string,int> RANK = { // O(1)
        {"Common",      1},
        {"Rare",        2},
        {"Epic",        3},
        {"Legendary",   4},
        {"BrainrotGod", 5},
        {"Secret",      6}
    };
    auto it = RANK.find(r); // O(1)
    return (it == RANK.end()) ? 0 : it->second; // 0 si no se reconoce (queda al inicio) // O(1)
}

//combina 2 subarreglos [left..mid] y [mid+1..right] usando el comparador "cmp" 
template <class Compare>
inline void combinar(                         // O(n)
    vector<string>& nombres,                  // O(1)
    vector<string>& rarezas,                  // O(1)
    vector<float>&  costos,                   // O(1)
    size_t left, size_t mid, size_t right,    // O(1)
    Compare cmp)                              // O(1)
{
    size_t n1 = mid - left + 1; //elementos mitad izquierda // O(1)
    size_t n2 = right - mid;    //elementos mitad derecha   // O(1)

    //arreglos temporales // O(n)
    vector<string> LeftNombres(n1), RightNombres(n2);
    vector<string> LeftRarezas(n1), RightRarezas(n2);
    vector<float>  LeftCostos(n1),  RightCostos(n2);

    //copiar lado izquierdo // O(n)
    for (size_t i = 0; i < n1; i++) { // O(n)
        LeftNombres[i] = nombres[left + i]; // O(1)
        LeftRarezas[i] = rarezas[left + i]; // O(1)
        LeftCostos[i]  = costos[left + i];  // O(1)
    }

    //copiar lado derecho // O(n)
    for (size_t j = 0; j < n2; j++) { // O(n)
        RightNombres[j] = nombres[mid + 1 + j]; // O(1)
        RightRarezas[j] = rarezas[mid + 1 + j]; // O(1)
        RightCostos[j]  = costos[mid + 1 + j];  // O(1)
    }

    size_t i = 0;         // O(1)
    size_t j = 0;         // O(1)
    size_t k = left;      // O(1)

    //mezclar usando el comparador "cmp" // O(n)
    while (i < n1 && j < n2) { // O(n)
        if (cmp(LeftNombres[i], LeftRarezas[i], LeftCostos[i],
                RightNombres[j], RightRarezas[j], RightCostos[j])) { // O(1)
            nombres[k] = LeftNombres[i]; // O(1)
            rarezas[k] = LeftRarezas[i]; // O(1)
            costos[k]  = LeftCostos[i];  // O(1)
            i++;                         // O(1)
        } else { // O(1)
            nombres[k] = RightNombres[j]; // O(1)
            rarezas[k] = RightRarezas[j]; // O(1)
            costos[k]  = RightCostos[j];  // O(1)
            j++;                          // O(1)
        }
        k++; // O(1)
    }

    //copiar remanentes lado izquierdo (obviamente, si hay) // O(n)
    while (i < n1) {                 // O(n)
        nombres[k] = LeftNombres[i]; // O(1)
        rarezas[k] = LeftRarezas[i]; // O(1)
        costos[k]  = LeftCostos[i];  // O(1)
        i++;                         // O(1)
        k++;                         // O(1)
    }

    //copiar remanentes lado derecho (obviamente, si hay) // O(n)
    while (j < n2) {                  // O(n)
        nombres[k] = RightNombres[j]; // O(1)
        rarezas[k] = RightRarezas[j]; // O(1)
        costos[k]  = RightCostos[j];  // O(1)
        j++;                          // O(1)
        k++;                          // O(1)
    }
}

//Hace el ordenado de los 2 subarreglos que salieron (left y right)
template <class Compare>
inline void mergeSortPartes(                // O(n log n)
    vector<string>& nombres,                // O(1)
    vector<string>& rarezas,                // O(1)
    vector<float>&  costos,                 // O(1)
    size_t left, size_t right, Compare cmp) // O(1)
{
    if (left >= right) { // O(1)
        return;          // O(1)
    }

    size_t mid = left + (right - left) / 2; // O(1)

    // Ordenar mitad izquierda // O(n log n)
    mergeSortPartes(nombres, rarezas, costos, left, mid, cmp);

    // Ordenar mitad derecha // O(n log n)
    mergeSortPartes(nombres, rarezas, costos, mid + 1, right, cmp);

    // Combinar ambas mitades // O(n)
    combinar(nombres, rarezas, costos, left, mid, right, cmp);
}

/* ===========================================================
   1) Merge Sort por Costo (menor a mayor), desempata por nombre
   =========================================================== */

inline void mergeSortPorCosto(          // O(n log n)
    vector<string>& nombres,
    vector<string>& rarezas,
    vector<float>&  costos)
{
    size_t n = nombres.size();                          // O(1)
    if (rarezas.size() != n || costos.size() != n) {    // O(1)
        return;
    }
    if (n < 2) return;                                  // O(1)

    auto cmpCosto = [](const string& nombre1, const string& rareza1, float costo1,
                       const string& nombre2, const string& rareza2, float costo2) {
        (void)rareza1; (void)rareza2; // no usados directamente en la comparación principal

        if (costo1 < costo2) return true;
        if (costo1 > costo2) return false;
        // desempate por nombre (estable/determinista)
        return nombre1 < nombre2;
    };

    mergeSortPartes(nombres, rarezas, costos, 0, n - 1, cmpCosto);
}

/* ===========================================================
   2) Merge Sort por Nombre (alfabético), desempata por costo
   =========================================================== */

inline void mergeSortPorNombre(         // O(n log n)
    vector<string>& nombres,
    vector<string>& rarezas,
    vector<float>&  costos)
{
    size_t n = nombres.size();                          // O(1)
    if (rarezas.size() != n || costos.size() != n) {    // O(1)
        return;
    }
    if (n < 2) return;                                  // O(1)

    auto cmpNombre = [](const string& nombre1, const string& rareza1, float costo1,
                        const string& nombre2, const string& rareza2, float costo2) {
        (void)rareza1; (void)rareza2; // no usados en la comparación principal

        if (nombre1 < nombre2) return true;
        if (nombre1 > nombre2) return false;
        // desempate por costo
        return costo1 < costo2;
    };

    mergeSortPartes(nombres, rarezas, costos, 0, n - 1, cmpNombre);
}

/* ===========================================================
   3) Merge Sort por Rareza (Common -> Secret), desempata por nombre
   =========================================================== */

inline void mergeSortPorRareza(         // O(n log n)
    vector<string>& nombres,
    vector<string>& rarezas,
    vector<float>&  costos)
{
    size_t n = nombres.size();                          // O(1)
    if (rarezas.size() != n || costos.size() != n) {    // O(1)
        return;
    }
    if (n < 2) return;                                  // O(1)

    auto cmpRareza = [](const string& nombre1, const string& rareza1, float costo1,
                        const string& nombre2, const string& rareza2, float costo2) {
        (void)costo1; (void)costo2; // no usados en la comparación principal

        int a = rarityRank(rareza1);
        int b = rarityRank(rareza2);

        if (a < b) return true;
        if (a > b) return false;
        // misma rareza -> desempate por nombre
        return nombre1 < nombre2;
    };

    mergeSortPartes(nombres, rarezas, costos, 0, n - 1, cmpRareza);
}

#endif // MERGESORT_H
