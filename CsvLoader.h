/*
Nombre: César Daniel Aguilar Kuri
Matricula: A01712823
Nombre del Proyecto: Steal a Brainrot!
Materia: Programación de estructuras de datos y algoritmos fundamentales
Profesor: Eduardo Daniel Juárez Pineda
*/

#ifndef CSVLOADER_H
#define CSVLOADER_H

#include <fstream>   // ifstream, ofstream // O(1)
#include <sstream>   // stringstream        // O(1)
#include <vector>    // vector              // O(1)
#include <string>    // string              // O(1)
#include <algorithm> // find                // O(1)
#include <cctype>    // isspace             // O(1)
#include <iostream>  // cout, cerr          // O(1)

using namespace std; // O(1)

// Lee CSV: Nombre,Rareza,Costo (con comillas opcionales en Nombre)
// Complejidad total: O(n)
bool cargarDesdeCSV(const string& rutaCSV,          // O(1)
                    vector<string>& nombres,        // O(n)
                    vector<string>& rarezas,        // O(n)
                    vector<float>&  costos,         // O(n)
                    const vector<string>& existentrarity) // O(1) 
{
    ifstream in(rutaCSV);           // abrir archivo // O(1)
    if (!in.is_open()) {            // O(1)
        cerr << "No se pudo abrir el archivo: " << rutaCSV << "\n"; // O(1)
        return false;               // O(1)
    }

    // Lambda para validar rareza comparando contra existentrarity
    // find recorre existentrarity: O(n)
    auto rarezaValida = [&](const string& r){                      // O(n)
        return find(existentrarity.begin(), existentrarity.end(),  // O(n)
                    r) != existentrarity.end();                    // O(1)
    };

    string linea;        // O(1)
    bool   primera = true; // O(1)
    size_t lineNum = 0;  // O(1)

    // Leer línea por línea // O(L)
    while (std::getline(in, linea)) { // O(n)
        ++lineNum;                    // O(1)

        if (primera) { // saltar encabezados // O(1)
            primera = false;          // O(1)
            continue;                 // O(1)
        }
        if (linea.empty()) continue;  // O(1)

        //CSV simple: Nombre (puede venir entre comillas y con comas), Rareza, Costo
        string nombre, rareza, costoStr; // O(1)
        stringstream ss(linea);          // O(1)

        // 1) Nombre (soporta comillas)
        if (ss.peek() == '"') {                  // O(1)
            ss.get();                            // O(1) 
            std::getline(ss, nombre, '"');       // O(n) 
            if (ss.peek() == ',') ss.get();      // O(1) 
        } else {
            std::getline(ss, nombre, ',');       // O(n)
        }

        // 2) Rareza
        std::getline(ss, rareza, ',');          // O(n)

        // 3) Costo (resto de la línea)
        std::getline(ss, costoStr);             // O(n)

        // Trim básicos (opcional)
        auto trim = [](string& s){                     // O(n)
            while (!s.empty() &&                      // O(n)
                   isspace((unsigned char)s.front())) // O(1)
                s.erase(s.begin());                   // O(n)
            while (!s.empty() &&                      // O(n)
                   isspace((unsigned char)s.back()))  // O(1)
                s.pop_back();                         // O(1)
        };
        trim(nombre);  // O(1)
        trim(rareza);  // O(1)
        trim(costoStr); // O(1)

        if (nombre.empty() || rareza.empty() || costoStr.empty()) { // O(1)
            cerr << "Línea " << lineNum << ": campos vacíos, se omite.\n"; // O(1)
            continue; // O(1)
        }

        // Validar rareza // O(n)
        if (!rarezaValida(rareza)) { // O(n)
            cerr << "Línea " << lineNum << ": rareza '" << rareza
                 << "' inválida, se fuerza a Common.\n"; // O(1)
            rareza = "Common"; // O(1)
        }

        // Convertir costo
        try {
            float costo = std::stof(costoStr); // O(1) 
            if (costo < 0.0f) costo = 0.0f;    // O(1)
            nombres.push_back(nombre);         // O(1)
            rarezas.push_back(rareza);         // O(1) 
            costos.push_back(costo);           // O(1) 
        } catch (...) {
            cerr << "Línea " << lineNum
                 << ": costo inválido '" << costoStr << "', se omite.\n"; // O(1)
        }
    }
    return true; // O(1)
}

bool guardarEnCSV(const string& rutaCSV,          // O(1)
                  const vector<string>& nombres,  // O(n)
                  const vector<string>& rarezas,  // O(n)
                  const vector<float>&  costos)   // O(n)
{
    if (nombres.size() != rarezas.size() ||       // O(1)
        nombres.size() != costos.size()) {        // O(1)
        cerr << "No se pudo guardar: los vectores tienen tamaños distintos.\n"; // O(1)
        return false;                             // O(1)
    }

    ofstream out(rutaCSV);          // O(1) 
    if (!out.is_open()) {           // O(1)
        cerr << "No se pudo abrir el archivo para escritura: " << rutaCSV << "\n"; // O(1)
        return false;               // O(1)
    }

    // Encabezado // O(1)
    out << "Nombre,Rareza,Costo\n"; // O(1)

    size_t n = nombres.size();      // O(1)
    for (size_t i = 0; i < n; ++i) {         // O(n)
        const string& nombre = nombres[i];   // O(1)
        const string& rareza = rarezas[i];   // O(1)
        float costo          = costos[i];    // O(1)

        // Si el nombre contiene coma, lo guardamos entre comillas
        bool necesitaComillas = (nombre.find(',') != string::npos); // O(1)

        if (necesitaComillas) out << '"'; // O(1)
        out << nombre;                    // O(1)
        if (necesitaComillas) out << '"'; // O(1)

        out << "," << rareza << "," << costo << "\n"; // O(1)
    }

    return true; // O(1)
}

#endif // CSVLOADER_H
