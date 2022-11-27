// -------------------------- ENCABEZADOS Y CONSTANTES DEL PROGRAMA ---------------------------------------------------------------------------|
//------------------------------------------------------------------------------------------------|

#include <bits/stdc++.h>

const std::string folderPath = "studentManagement/files/";

const int cantidadEstudiantes = 1;

std::vector <std::string> asignaturasGeneral = {"Informatica", "Fisica", "Quimica"};

struct {
    std::string nombre;
    std::string clave;
    std::string genero;
    int asignatura;
    std::array <float, 3> notasFinales;
} estudiantes[cantidadEstudiantes];

// -------------------------- FUNCIONES PARA INICIALIZAR Y ESCRIBIR EN EL LOG -----------------------------------------------------------------|
// -----------------------------------------------------------------------------------------------|>

std::ofstream logFile (folderPath +  "logFile.txt", std::ios::app);

// -----------------------------------------------------------------------------------------------|>

void escribirLinea(const int cantidadCaracteres, const std::string c) {
    logFile << std::endl;
    for (int i = 0; i < cantidadCaracteres; i++) 
        logFile << c;
    logFile << std::endl;
}

// -----------------------------------------------------------------------------------------------|>

const char* horaActual() {
    time_t now = time(0);
    const char* horaActual = ctime(&now);

    return horaActual;
}

// -----------------------------------------------------------------------------------------------|>

void escribirLog() {
    if (logFile.is_open()) {
        escribirLinea(80, "-");
        logFile << "Programa iniciado: " << horaActual() << std::endl;
    }
}

// -----------------------------------------------------------------------------------------------|>

void escribirLog(const std::string mensaje) {
    if (logFile.is_open())
        logFile << "[INFO] " << mensaje << std::endl;

}

// -------------------------- FUNCIONES AUXILIARES PARA INGRESAR DATOS ------------------------------------------------------------------------|
// -----------------------------------------------------------------------------------------------|>

void escribirLinea(const std::string c) {
    std::cout << std::endl;
    for (int i = 0; i < 40; i++) 
        std::cout << c;
    std::cout << std::endl;
} 

// -------------------------- FUNCIONES DE VALIDACION -----------------------------------------------------------------------------------------|
// ---------------------------------------------------------------------|>

bool validarGenero(const std::string c) {
    bool esValido = false;
    if ((c == "m") || (c == "f")) esValido = true;
    return esValido;
}

// ---------------------------------------------------------------------|>

bool validarNota(const double notaFinal) {
    bool esValido = false;
    if ((notaFinal >= 0.0) && (notaFinal <= 100.0)) esValido = true;
    return esValido;
}

// -------------------------- ALGORITMO PARA PEDIR DATOS --------------------------------------------------------------------------------------|
// ---------------------------------------------------------------------|>

void pedirDatos() {
    // std::cout << "Login de Usuario" << std::endl << std::endl;
    for (int i = 0; i < cantidadEstudiantes; i++) {
        escribirLinea("*");
        int cantidadIntentos = 3;

        do {
            std::cout << "Estudiante [" << i + 1 << "]" << std::endl;

            // -------------------- NOMBRE --------------------------|>
            do {
                std::cout << "Ingrese su nombre: ";
                std::getline(std::cin, estudiantes[i].nombre, '\n');

                if (!estudiantes[i].nombre.empty()) break;
                else cantidadIntentos--;
            } while ((true) && (cantidadIntentos > 0));
            if (cantidadIntentos < 0) exit(EXIT_FAILURE);
            
            // -------------------- GENERO --------------------------|>
            do {
                std::cout << "Ingrese su genero (m/f): ";
                std::cin >> estudiantes[i].genero;

                if (validarGenero(estudiantes[i].genero)) break;
                else cantidadIntentos--;
            } while ((true) && (cantidadIntentos > 0));
            if (cantidadIntentos < 0) exit(EXIT_FAILURE);

            // -------------------- NOTA x ASIGNATURA ---------------|>

            for (int j = 0; j < estudiantes[i].notasFinales.size(); j++) {
                std::cout << "Ingrese su nota {" << asignaturasGeneral.at(j) << "}: ";
                std::cin >> estudiantes[i].notasFinales.at(j);
            }

            break;

        } while (cantidadIntentos > 0);
    }

}

// -------------------------- FUNCION MAIN ----------------------------------------------------------------------------------------------------|
// -----------------------------------------------------------------------------------------------|>

int main(void) {
    pedirDatos(); 
    return EXIT_SUCCESS;
}