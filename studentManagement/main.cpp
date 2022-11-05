// -------------------------- ENCABEZADOS Y CONSTANTES DEL PROGRAMA ---------------------------------------------------------------------------|
//------------------------------------------------------------------------------------------------|

#include <bits/stdc++.h>
#include <conio.h>

const std::string folderPath = "studentManagement/files/";

const int cantidadEstudiantes = 1;

struct {
    std::string nombre;
    std::string clave;
    std::string genero;
    std::string nombreAsignatura;
    int asignatura;
    double notaFinal;
} estudiantes[cantidadEstudiantes];

// -------------------------- FUNCIONES PARA INICIALIZAR Y ESCRIBIR EN EL LOG -----------------------------------------------------------------|
// -----------------------------------------------------------------------------------------------| >

std::ofstream logFile (folderPath +  "logFile.txt", std::ios::app);

// -----------------------------------------------------------------------------------------------| >

void escribirLinea(const int cantidadCaracteres, const std::string c) {
    logFile << std::endl;
    for (int i = 0; i < cantidadCaracteres; i++) 
        logFile << c;
    logFile << std::endl;
}

// -----------------------------------------------------------------------------------------------| >

const char* horaActual() {
    time_t now = time(0);
    const char* horaActual = ctime(&now);

    return horaActual;
}

// -----------------------------------------------------------------------------------------------| >

void escribirLog() {
    if (logFile.is_open()) {
        escribirLinea(80, "-");
        logFile << "Programa iniciado: " << horaActual() << std::endl;
    }
}

// -----------------------------------------------------------------------------------------------| >

void escribirLog(const std::string mensaje) {
    if (logFile.is_open())
        logFile << "[INFO] " << mensaje << std::endl;

}

// -------------------------- FUNCIONES PARA CREAR LAS INSTANCIAS DE LOS USUARIOS -------------------------------------------------------------|
// -----------------------------------------------------------------------------------------------| >

bool crearUsuario(const std::string usuario, const std::string clave) {
    bool archivoCreado = false;

    if (std::filesystem::exists(folderPath + usuario + ".txt"))
        escribirLog("El usuario: " + usuario +  " ya existe -> no se creara un nuevo archivo");
    else {
        std::ofstream archivo (folderPath + usuario + ".txt", std::ios::app);
        if (archivo.is_open()) {
            archivo << usuario << std::endl;
            archivo << clave << std::endl;
            archivoCreado = true;
        }
        archivo.close();
    } 


    return archivoCreado;
}

// -----------------------------------------------------------------------------------------------| >

void inicializarUsuarios() {
    std::vector <std::string> usuarios = {"luis", "jorge", "james", "johan", "kevin"};
    std::vector <std::string> claves = {"123", "456", "789", "abc", "efg"};

    for (int i = 0; i < 5; i++) {
        if (crearUsuario(usuarios.at(i), claves.at(i)))
            escribirLog("Usuario Creado: " +  usuarios.at(i));
    }
}

// -------------------------- FUNCIONES AUXILIARES PARA INGRESAR DATOS ------------------------------------------------------------------------|
// -----------------------------------------------------------------------------------------------| >

void escribirLinea(const std::string c) {
    std::cout << std::endl;
    for (int i = 0; i < 40; i++) 
        std::cout << c;
    std::cout << std::endl;
} 

// -------------------------- FUNCIONES DE VALIDACION -----------------------------------------------------------------------------------------|
// ---------------------------------------------------------------------| >

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

// ---------------------------------------------------------------------| >

bool validarGenero(const std::string c) {
    bool esValido = false;
    if ((c == "m") || (c == "f")) esValido = true;
    return esValido;
}

// ---------------------------------------------------------------------| >
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

// -------------------------- ALGORITMO PARA PEDIR DATOS --------------------------------------------------------------------------------------|
// ---------------------------------------------------------------------| >

void pedirDatos() {
    // std::cout << "Login de Usuario" << std::endl << std::endl;
    for (int i = 0; i < cantidadEstudiantes; i++) {
        escribirLinea("*");
        int cantidadIntentos = 3;

        do {
            std::cout << "Estudiante [" << i + 1 << "]" << std::endl;

            // -------------------- NOMBRE --------------------------| >
            do {
                std::cout << "Ingrese su nombre: ";
                std::getline(std::cin, estudiantes[i].nombre, '\n');

                if (validarNombre(estudiantes[i].nombre)) break;
                else cantidadIntentos--;
            } while ((true) && (cantidadIntentos > 0));

            // -------------------- GENERO --------------------------| >
            do {
                std::cout << "Ingrese su genero (m/f): ";
                std::cin >> estudiantes[i].genero;

                if (validarGenero(estudiantes[i].genero)) break;
                else cantidadIntentos--;
            } while ((true) && (cantidadIntentos > 0));

            // -------------------- ASIGNATURA ----------------------| >
            std::cout << "Ingrese la asignatura" << std::endl;
            std::cout << "1. Informatica" << std::endl;
            std::cout << "2. Fisica" << std::endl;
            std::cout << "3. Quimica" << std::endl;
            do {
                std::cout << "-> ";
                std::cin >> estudiantes[i].asignatura;
                
                if (validarAsignatura(estudiantes[i].asignatura, i)) break;
            } while ((true) && (cantidadIntentos > 0));

            // -------------------- NOTA FINAL ----------------------| >
            do {
                std::cout << "Ingrese su Nota Final: ";
                std::cin >> estudiantes[i].notaFinal;



            } while ((true) && (cantidadEstudiantes > 0));

            break;

        } while (cantidadIntentos > 0);
    }

}

// -------------------------- FUNCION MAIN ----------------------------------------------------------------------------------------------------|
// -----------------------------------------------------------------------------------------------| >
int main(void) {
    escribirLog();
    inicializarUsuarios();
    pedirDatos();
    return EXIT_SUCCESS;
}