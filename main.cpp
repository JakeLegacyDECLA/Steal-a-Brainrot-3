/*
Nombre: César Daniel Aguilar Kuri
Matricula: A01712823
Nombre del Proyecto: Steal a Brainrot!
Materia: Programación de estructuras de datos y algoritmos fundamentales
Profesor: Eduardo Daniel Juárez Pineda
*/


// LIBRERIAS
#include <iostream>   // O(1)
#include <vector>     // O(1)
#include <string>     // O(1)
#include <algorithm>  // O(1) // find
#include <limits>     // O(1) // numeric_limits

// CLASES
#include "MergeSort.h"  // O(1)
#include "CsvLoader.h"  // O(1)
#include "DList.h"      // O(1)

using namespace std; // O(1)


struct Row {          // O(1)
    string nombre;    // O(1)
    string rareza;    // O(1)
    float  costo;     // O(1)
};

// MÉTODOS
void mostrarArreglos(const vector<string>& nombres,  // O(n)
                     const vector<string>& rarezas,  // O(n)
                     const vector<float>& costos) {  // O(n)
    cout << "Nombre, Rareza, Costo\n"; // O(1)
    for (size_t i = 0; i < nombres.size(); ++i) { // O(n)
        cout << nombres[i] << ", " << rarezas[i] << ", " << costos[i] << "\n"; // O(1)
    }
}

// Captura un bloque de N personajes y los AGREGA (continúa desde el tamaño actual)
void capturarPersonajes(vector<string>& nombres,              // O(n)
                        vector<string>& rarezas,              // O(n)
                        vector<float>& costos,                // O(n)
                        const vector<string>& existentrarity) // O(n)
{   // Complejidad total O(n) respecto al número de personajes capturados

    int cuantos = 0; // O(1)
    cout << "¿Cuántos personajes ingresarás en este bloque? "; // O(1)
    while (!(cin >> cuantos) || cuantos <= 0) { // O(n)
        cout << "Valor inválido. Ingresa un entero > 0: "; // O(1)
        cin.clear(); // O(1)
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // O(1)
    }
    // limpiar salto antes de usar getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // O(1)

    for (int k = 0; k < cuantos; ++k) { // O(n)
        string nombre, rareza; // O(1)
        float  costo;          // O(1)

        size_t idx = nombres.size(); // índice real siguiente // O(1)
        cout << "\nRegistro no. " << (idx + 1) << "\n"; // O(1)

        // nombre
        cout << "Nombre del personaje: "; // O(1)
        getline(cin >> ws, nombre);       // O(1)
        while (nombre.empty()) {          // O(n)
            cout << "El nombre no puede estar vacío. Intenta de nuevo: "; // O(1)
            getline(cin >> ws, nombre); // O(1)
        }

        // rareza (validada)
        cout << "Rarezas válidas: Common, Rare, Epic, Legendary, BrainrotGod, Secret\n"; // O(1)
        cout << "Rareza: "; // O(1)
        getline(cin >> ws, rareza); // O(1)
        while (find(existentrarity.begin(), existentrarity.end(), rareza) // O(n)
               == existentrarity.end()) {                                 // O(1)
            cout << "Rareza inválida. Debe ser una de: "; // O(1)
            for (const auto& r : existentrarity) { // O(n)
                cout << r << " "; // O(1)
            }
            cout << "\nIntenta de nuevo: "; // O(1)
            getline(cin >> ws, rareza);     // O(1)
        }

        // costo
        cout << "Costo (>= 0): "; // O(1)
        while (!(cin >> costo) || costo < 0.0f) { // O(n)
            cout << "Costo inválido. Debe ser >= 0. Intenta de nuevo: "; // O(1)
            cin.clear(); // O(1)
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // O(1)
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // O(1)

        nombres.push_back(nombre); // O(1) promedio
        rarezas.push_back(rareza); // O(1) promedio
        costos.push_back(costo);   // O(1) promedio
    }
    cout << "\nCaptura completa. Total acumulado: " << nombres.size() << "\n"; // O(1)
}

// MAIN 
int main() { // Complejidad global depende de las opciones del usuario
    // Arreglos PERSISTENTES para toda la sesión
    DListFavoritos<Row> favoritos; // O(1)

    vector<string> nombres; // O(1)
    vector<string> rarezas; // O(1)
    vector<float>  costos;  // O(1)
    vector<string> existentrarity = { // O(1)
        "Common","Rare","Epic","Legendary","BrainrotGod","Secret"
    };

    while (true) { // bucle principal del menú // O(1) por iteración
        // Menú
        cout << "\nBienvenido a Steal a Brainrot!\n"; // O(1)
        cout << "Selecciona la opción que quieres ejecutar:\n"; // O(1)
        cout << "1. Cargar lista predeterminada de personajes desde CSV\n"; // O(1)
        cout << "2. Ingresar personajes, rarezas y costos a arreglos\n"; // O(1)
        cout << "3. Consultar arreglos\n"; // O(1)
        cout << "4. Ordenar personajes por costo (Merge Sort)\n"; // O(1)
        cout << "5. Ordenar personajes por nombre (Merge Sort)\n"; // O(1)
        cout << "6. Ordenar personajes por rareza (Merge Sort)\n"; // O(1)
        cout << "7. Agregar personaje a favoritos (por índice)\n"; // O(1)
        cout << "8. Eliminar favorito (por nombre)\n"; // O(1)
        cout << "9. Mostrar favoritos (inicio a fin)\n"; // O(1)
        cout << "10. Mostrar favoritos (fin a inicio)\n"; // O(1)
        cout << "11. Navegar favoritos (actual / sig / ant)\n"; // O(1)
        cout << "12. Sobrescribir el CSV con el orden actual\n"; // O(1)
        cout << "13. Salir\n"; // O(1)
        cout << "> "; // O(1)

        int op; // O(1)
        if (!(cin >> op)) { // O(1)
            // entrada no numérica
            cin.clear(); // O(1)
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // O(1)
            cout << "Entrada inválida.\n"; // O(1)
            continue; // O(1)
        }

        // Rango válido
        if (op < 1 || op > 13) { // O(1)
            cout << "Opción no válida. Intenta (1-13).\n"; // O(1)
            continue; // O(1)
        }

        if (op == 1) { // O(1)
            string ruta; // O(1)
            cout << "Ingrese ruta del CSV: "; // O(1)
            getline(cin >> ws, ruta); // O(1)

            size_t antes = nombres.size(); // O(1)
            if (cargarDesdeCSV(ruta, nombres, rarezas, costos, existentrarity)) { // O(n)
                cout << "\nSe añadieron " << (nombres.size() - antes) // O(1)
                     << " registros desde " << ruta << "\n"; // O(1)
                mostrarArreglos(nombres, rarezas, costos); // O(n)
            } else { // O(1)
                cout << "No se pudo cargar el archivo.\n"; // O(1)
            }
            continue; // O(1)
        }

        // Acciones
        if (op == 2) { // O(1)
            capturarPersonajes(nombres, rarezas, costos, existentrarity); // O(n)
            continue; // O(1)

        } else if (op == 3) { // O(1)
            cout << "\nConsulta de Arreglos:\n"; // O(1)
            mostrarArreglos(nombres, rarezas, costos); // O(n)
            continue; // O(1)

        } else if (op == 4) { // O(1)
            cout << "[Merge Sort] (Ordena por Costo)\n"; // O(1)
            cout << "Arreglos actuales: \n"; // O(1)
            mostrarArreglos(nombres, rarezas, costos); // O(n)
            cout << "==================================\n"; // O(1)
            cout << "Arreglos con Merge Sort (Costo): \n"; // O(1)
            mergeSortPorCosto(nombres, rarezas, costos); // O(n log n)
            mostrarArreglos(nombres, rarezas, costos);   // O(n)
            continue; // O(1)

        } else if (op == 5) { // O(1)
            cout << "[Merge Sort] (Ordena por Nombre)\n"; // O(1)
            cout << "Arreglos actuales: \n"; // O(1)
            mostrarArreglos(nombres, rarezas, costos); // O(n)
            cout << "==================================\n"; // O(1)
            cout << "Arreglos con Merge Sort (Nombre): \n"; // O(1)
            mergeSortPorNombre(nombres, rarezas, costos); // O(n log n)
            mostrarArreglos(nombres, rarezas, costos);     // O(n)
            continue; // O(1)   

        } else if (op == 6) { // O(1)
            cout << "[Merge Sort] (Ordena por Rareza)\n"; // O(1)
            cout << "Arreglos actuales: \n"; // O(1)
            mostrarArreglos(nombres, rarezas, costos); // O(n)
            cout << "==================================\n"; // O(1)
            cout << "Arreglos con Merge Sort (Rareza): \n"; // O(1)
            mergeSortPorRareza(nombres, rarezas, costos); // O(n log n)
            mostrarArreglos(nombres, rarezas, costos);     // O(n)
            continue; // O(1)

        } else if (op == 7) { // O(1)
            cout << "[Estructura Lineal DList] (Agregar personaje a favoritos por índice)\n"; // O(1)
            if (nombres.empty()) { // O(1)
                cout << "No hay personajes en los arreglos. Ingresa o carga primero.\n"; // O(1)
                continue; // O(1)
            }

            mostrarArreglos(nombres, rarezas, costos); // O(n)
            int idx; // O(1)
            cout << "Ingresa el índice (1.." << nombres.size()
                 << ") del personaje que quieres agregar a favoritos: "; // O(1)
            while (!(cin >> idx) || idx < 1 || (size_t)idx > nombres.size()) { // O(n)
                cout << "Índice inválido. Intenta de nuevo: "; // O(1)
                cin.clear(); // O(1)
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // O(1)
            }

            size_t pos = (size_t)idx - 1; // O(1)

            Row fav;                        // O(1)
            fav.nombre = nombres[pos];      // O(1)
            fav.rareza = rarezas[pos];      // O(1)
            fav.costo  = costos[pos];       // O(1)

            favoritos.addFavorite(fav);     // O(1)
            cout << "Personaje agregado a favoritos.\n"; // O(1)
            continue; // O(1)

        } else if (op == 8) { // O(1)
            cout << "[Estructura Lineal DList] (Eliminar favorito por nombre)\n"; // O(1)
            if (favoritos.empty()) { // O(1)
                cout << "No hay favoritos.\n"; // O(1)
                continue; // O(1)
            }
            string nombreBorrar; // O(1)
            cout << "Nombre del favorito a eliminar: "; // O(1)
            getline(cin >> ws, nombreBorrar); // O(1)

            if (favoritos.removeFavorite(nombreBorrar)) { // O(n)
                cout << "Favorito eliminado correctamente.\n"; // O(1)
            } else {
                cout << "No se encontró ese favorito.\n"; // O(1)
            }
            continue; // O(1)

        } else if (op == 9) { // O(1)
            cout << "[Estructura Lineal DList] (Mostrar favoritos de inicio a fin)\n"; // O(1)
            favoritos.printForward(); // O(n)
            continue; // O(1)

        } else if (op == 10) { // O(1)
            cout << "[Estructura Lineal DList] (Mostrar favoritos de fin a inicio)\n"; // O(1)
            favoritos.printBackward(); // O(n)
            continue; // O(1)

        } else if (op == 11) { // O(1)
            cout << "[Estructura Lineal DList] (Navegar favoritos)\n"; // O(1)
            if (favoritos.empty()) { // O(1)
                cout << "No hay favoritos. Agrega algunos primero.\n"; // O(1)
                continue; // O(1)
            }

            // Empezamos en el primero
            favoritos.moveToFirst(); // O(1)
            char cmd = ' ';          // O(1)
            while (true) {           // O(n)
                Row actual; // O(1)
                if (favoritos.getCurrent(actual)) { // O(1)
                    cout << "\nFavorito actual: " << actual.nombre
                        << " | " << actual.rareza
                        << " | " << actual.costo << "\n"; // O(1)
                } else {
                    cout << "\nNo hay favorito actual.\n"; // O(1)
                }

                cout << "Comandos: [n] siguiente, [p] anterior, [i] primero, "
                        "[u] último, [s] salir\n"; // O(1)
                cout << "> "; // O(1)
                cin >> cmd;   // O(1)

                if (cmd == 'n' || cmd == 'N') { // O(1)
                    if (!favoritos.moveNext()) { // O(1)
                        cout << "Ya estás en el último favorito.\n"; // O(1)
                    }
                } else if (cmd == 'p' || cmd == 'P') { // O(1)
                    if (!favoritos.movePrev()) { // O(1)
                        cout << "Ya estás en el primer favorito.\n"; // O(1)
                    }
                } else if (cmd == 'i' || cmd == 'I') { // O(1)
                    favoritos.moveToFirst(); // O(1)
                } else if (cmd == 'u' || cmd == 'U') { // O(1)
                    favoritos.moveToLast(); // O(1)
                } else if (cmd == 's' || cmd == 'S') { // O(1)
                    break; // O(1)
                } else {
                    cout << "Comando no válido.\n"; // O(1)
                }
            }
            continue; // O(1)

        } else if (op == 12) { // O(1)
            string ruta; // O(1)
            cout << "Ruta del CSV a sobrescribir: "; // O(1)
            getline(cin >> ws, ruta); // O(1)

            if (guardarEnCSV(ruta, nombres, rarezas, costos)) { // O(n)
                cout << "Se guardó el CSV con el orden actual.\n"; // O(1)
                continue; // O(1)
            } else {
                cout << "No se pudo guardar el CSV.\n"; // O(1)
                continue; // O(1)
            }

        } else if (op == 13) { // O(1)
            cout << "Sesión terminada, hasta luego!\n"; // O(1)
            break; // O(1)
        }
    }

    return 0; // O(1)
}
