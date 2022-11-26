// -------------------------- ENCABEZADOS Y CONSTANTES DEL PROGRAMA ---------------------------------------------------------------------------|
//------------------------------------------------------------------------------------------------|

#include <bits/stdc++.h>

const std::string folderPath = "studentManagement/files/";

const int cantidadEstudiantes = 5;

std::vector <std::string> asignaturasGeneral = {"Informatica", "Fisica", "Quimica"};
struct {
    std::string nombre;
    std::string clave;
    std::string genero;
    int asignatura;
    std::vector <float> notaFinal(3);
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

bool validarNombre(const std::string usuario) {
    std::ifstream archivo (folderPath + usuario + ".txt");
    bool esValido = false;

    if (archivo.is_open()) {
        std::string auxUsuario;

        std::getline(archivo, auxUsuario);
        if (usuario == auxUsuario) esValido = true;
    }

    return esValido;
}

// ---------------------------------------------------------------------|>

bool validarGenero(const std::string c) {
    bool esValido = false;
    if ((c == "m") || (c == "f")) esValido = true;
    return esValido;
}

// ---------------------------------------------------------------------|>
bool validarAsignatura(const int asignatura, const int indice) {
    bool esValido = false;

    std::vector <int> opcionesValidas = {1, 2, 3};
    for (int &i : opcionesValidas) {
        if (asignatura == i) esValido = true;
    }
    
    if (esValido) {
        std::vector <std::string> asignaturas = {"Informatica", "Fisica", "Quimica"};
        estudiantes[indice].nombreAsignatura = asignaturas.at(asignatura - 1);
    }

    return esValido;
}

// ---------------------------------------------------------------------|>

bool validarNota(const double notaFinal) {
    bool esValido = false;
    if ((notaFinal >= 0.0) && (notaFinal <= 100.0)) esValido = true;
    return esValido;
}

// ---------------------------------------------------------------------|>

bool validarClave(const std::string usuario, const std::string clave) {
    bool esValido = false;
    std::ifstream archivo (folderPath + usuario + ".txt");

    if (archivo.is_open()) {
        std::string linea, auxClave;
        std::getline(archivo, linea);
        std::getline(archivo, auxClave);
        if (clave == auxClave) esValido = true;
    }

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

                if (validarNombre(estudiantes[i].nombre)) break;
                else cantidadIntentos--;
            } while ((true) && (cantidadIntentos > 0));
            if (cantidadIntentos < 0) exit(EXIT_FAILURE);

            // -------------------- CLAVE ---------------------------|>
            do {
                std::cout << "Ingrese su clave: ";
                std::getline(std::cin, estudiantes[i].clave, '\n');

                if (validarClave(estudiantes[i].nombre, estudiantes[i].clave)) break;
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

            // -------------------- ASIGNATURA ----------------------|>
            // std::cout << "Ingrese la asignatura" << std::endl;
            // std::cout << "1. Informatica" << std::endl;
            // std::cout << "2. Fisica" << std::endl;
            // std::cout << "3. Quimica" << std::endl;
            // do {
            //     std::cout << "-> ";
            //     std::cin >> estudiantes[i].asignatura;

            //     if (validarAsignatura(estudiantes[i].asignatura, i)) break;
            //     else cantidadIntentos--;
            // } while ((true) && (cantidadIntentos > 0));
            // if (cantidadIntentos < 0) exit(EXIT_FAILURE);

            // -------------------- NOTA FINAL ----------------------|>
            // do {
            //     std::cout << "Ingrese su Nota Final: ";
            //     std::cin >> estudiantes[i].notaFinal;

            //     if (validarNota(estudiantes[i].notaFinal)) break;
            //     else cantidadIntentos--;
            // } while ((true) && (cantidadIntentos > 0));

            // if (cantidadIntentos < 0) exit(EXIT_FAILURE);

            // -------------------- NOTA x ASIGNATURA ---------------|>


            break;

        } while (cantidadIntentos > 0);
    }

}

// -------------------------- FUNCION MAIN ----------------------------------------------------------------------------------------------------|
// -----------------------------------------------------------------------------------------------|>

int main(void) {
    
    return EXIT_SUCCESS;
}