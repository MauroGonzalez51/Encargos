// ------------------------------ ENCABEZADOS Y CONSTANTES DEL PROGRAMA --------------------------------------------|>
//-------------------------------------------------------------------------|>

#include <bits/stdc++.h>

const std::string folderPath = "studentManagement/files/";

const int cantidadEstudiantes = 5;

std::vector <std::string> asignaturasGeneral = {"Informatica", "Fisica", "Quimica"};

struct {
    std::string nombre;
    std::string clave;
    int cantidadIntentos = 3;
} datosProfesor;

struct {
    std::string nombre;
    std::string codigo;
    std::array <float> notasFinales;
} estudiantes[cantidadEstudiantes];

struct {
    int excelente = 0;
    int sobresaliente = 0;
    int regular = 0;
    int insuficiente = 0;
    int deficiente = 0;
} categoriasEstudiantes;

// ------------------------------ FUNCIONES PARA INICIALIZAR Y ESCRIBIR EN EL LOG ----------------------------------|>
//-------------------------------------------------------------------------|>

std::ofstream logFile (folderPath + "logFile", std::ios::app);

//-------------------------------------------------------------------------|>

void escribirLinea(const int cantidadCaracteres, const std::string c) {
    logFile << std::endl;
    for (int i = 0; i < cantidadCaracteres; i++)
        logFile << c;
    logFile << std::endl;
}

//-------------------------------------------------------------------------|>

const char* horaActual() {
    time_t now = time(0);
    const char* horaActual = ctime(&now);
    return horaActual;
}

//-------------------------------------------------------------------------|>

void escribirLog() {
    if (logFile.is_open()) {
        escribirLinea(80, "-");
        logFile << "Programa Iniciado: " << horaActual() << std::endl;
    }
}

//-------------------------------------------------------------------------|>

void escribirLog(const std::string mensaje) {
    if (logFile.is_open()) 
        logFile << "[INFO] " << mensaje << std::endl;
}

// ------------------------------ FUNCIONES PARA INICIALIZAR LOS USUARIOS - PROFESORES -----------------------------|>
//-------------------------------------------------------------------------|>

bool usuarioExiste(const std::string nombreUsuario, const std::string clave) {
    std::ifstream archivo (folderPath + nombreUsuario + ".txt");
    bool archivoExiste = false;
    if (archivo.is_open()) {
        std::string auxUsuario, auxClave;
        std::getline(archivo, auxUsuario);
        std::getline(archivo, auxClave);
        if ((nombreUsuario == auxUsuario) && (clave == auxClave)) archivoExiste = true;
    }
    return archivoExiste;
}

//-------------------------------------------------------------------------|>

bool crearUsuario(const std::string usuario, const std::string clave) {
    bool archivoCreado = false;
    if (usuarioExiste(usuario, clave)) escribirLog("El usuario " + usuario + " ya existe -> No se creara un nuevo archivo");
    else {
        std::ofstream archivo (folderPath + usuario + ".txt", std::ios::app);
        if (archivo.is_open()) {
            archivo << usuario << std::endl;
            archivo << clave << std::endl;
            archivoCreado = true;
        }
    }
    return archivoCreado;
}

//-------------------------------------------------------------------------|>

void inicializarUsuarios() {
    std::vector <std::string> usuarios = {"luis", "jorge", "james", "johan", "kevin"};
    std::vector <std::string> claves = {"123", "456", "789", "abc", "efg"};

    for (int i = 0; i < 5; i++) {
        if (crearUsuario(usuarios.at(i), claves.at(i)))
            escribirLog("Usuario Creado: " +  usuarios.at(i));
    }
}

// ------------------------------ FUNCIONES AUXILIARES -------------------------------------------------------------|>
//-------------------------------------------------------------------------|>

void escribirLinea(const std::string c) {
    std::cout << std::endl;
    for (int i = 0; i < 40; i++)
        std::cout << c;
    std::cout << std::endl;
}

// ------------------------------ FUNCIONES DE VALIDACION - PROFESORES ---------------------------------------------|>
//-------------------------------------------------------------------------|>

bool validarUsuarioProfesor(const std::string usuario) {
    std::ifstream archivo (folderPath + usuario + ".txt");
    bool esValido = false;
    if (archivo.is_open()) {
        std::string auxUsuario;
        std::getline(archivo, auxUsuario);
        if (usuario == auxUsuario) esValido = true;
    }
    return esValido;
}




// ------------------------------ DATOS PROFESOR -------------------------------------------------------------------|>
//-------------------------------------------------------------------------|>

void datosProfesor() {
    escribirLinea("/");
    std::cout << "[PROFESOR]" << std::endl;

    do {
        // ------------- NOMBRE USUARIO ------------------------------------|>
        do {
            std::cout << "Ingrese su usuario: ";
            std::cin >> datosProfesor.nombre;

            if (validarUsuarioProfesor(datosProfesor.nombre)) break;
            else datosProfesor.cantidadIntentos--;
        } while ((true) && (datosProfesor.cantidadIntentos > 0));
        if (cantidadIntentos < 0) exit(EXIT_FAILURE);

        // ------------- CONTRASEÑA ----------------------------------------|>
        do {
            std::cout << "Ingrese su clave: ";
            std::cin >> datosProfesor.clave;

            if (validarClaveProfesor(datosProfesor.clave)) break;
            else datosProfesor.cantidadIntentos--;
        } while ((true) && (datosProfesor.cantidadIntentos > 0));
        if (cantidadIntentos < 0) exit(EXIT_FAILURE);
        break;
    } while (datosProfesor.cantidadIntentos > 0);
}

// ------------------------------ DATOS ESTUDIANTES ----------------------------------------------------------------|>
//-------------------------------------------------------------------------|>

void datosEstudiantes {
    std::cout << "[ESTUDIANTES]" << std::endl;

    for (int i = 0; i < cantidadEstudiantes; i++) {
        
        // ---------------- NOMBRE -------------------------|>
        do {
            std::cout << "{Estudiante " << i + 1 << "} Ingrese su nombre: ";
            std::cin >> estudiantes[i].nombre;
        } while (estudiantes[i].nombre.empty());

        // ---------------- CODIGO -------------------------|>
        do {
            std::cout << "{Estudiante " << i + 1 << "} Ingrese su codigo: ";
            std::cin >> estudiantes[i].codigo;
        } while (estudiantes[i].codigo);

        // ---------------- NOTAS FINALES ------------------|>
        for (int asignatura = 0; asignatura < estudiantes[i].notasFinales.size(); asignatura++) {
            float notaAux;
            do {
                std::cout << "{Estudiante " << i + 1 << "} {Asignatura " << asignaturasGeneral.at(asignatura) << "} Ingrese su nota: ";
                std::cin >> notaAux;
            } while (notaAux < 0.0);
            estudiantes[i].notasFinales.push_back(notaAux);               
        }
    }
}

// ------------------------------ ANALISIS DE DATOS ----------------------------------------------------------------|>
//-------------------------------------------------------------------------|>




// ------------------------------ FUNCION MAIN ---------------------------------------------------------------------|>
//-------------------------------------------------------------------------|>

int main(void) {
    inicializarUsuarios(); 
    datosProfesor();
    return EXIT_SUCCESS;
}