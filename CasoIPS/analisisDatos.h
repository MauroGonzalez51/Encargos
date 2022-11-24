#include <bits/stdc++.h>

const std::string rutaArchivo = "CasoIPS/files/registroDatos.csv";

struct {
    std::set <std::string> codigoEmpresasRemitorasSET;

    std::vector <std::string> identificacionPacientes;
    std::vector <std::string> nombrePacientes;
    std::vector <std::string> codigoEmpresasRemitoriasVECTOR;
    std::vector <int> tipoExamenes;
    std::vector <std::string> fechaExamenes;
    std::vector <int> edadesPacientes;
    std::vector <std::string> generoPacientes;
    std::vector <float> estaturaPacientes;
    std::vector <float> pesoPacientes;

    struct {
        std::vector <float> frecuenciaCardiaca;
        std::vector <float> presionSistolica;
        std::vector <float> presionDiastolica;
        std::vector <float> IMC;
        std::vector <std::string> factorRiesgo;
    } datosMedicos;
} allDatos;

void leerDatos() {
    std::ifstream datosPacientes (rutaArchivo);

    if (datosPacientes.is_open()) {
        std::string linea;
        char delimitador = ';';

        std::getline(datosPacientes, linea);
        while (std::getline(datosPacientes, linea)) {
            std::stringstream streamLine (linea);
            std::array <std::string, 14> rawDatos;

            for (int i = 0; i < rawDatos.size(); i++)
                std::getline(streamLine, rawDatos.at(i), delimitador);
            
            allDatos.identificacionPacientes.push_back(rawDatos.at(0));
            allDatos.nombrePacientes.push_back(rawDatos.at(1));
            allDatos.codigoEmpresasRemitoriasVECTOR.push_back(rawDatos.at(2));
            allDatos.tipoExamenes.push_back(std::stoi(rawDatos.at(3)));
            allDatos.fechaExamenes.push_back(rawDatos.at(4));
            allDatos.edadesPacientes.push_back(std::stoi(rawDatos.at(5)));
            allDatos.generoPacientes.push_back(rawDatos.at(6));
            allDatos.estaturaPacientes.push_back(std::stof(rawDatos.at(7)));
            allDatos.pesoPacientes.push_back(std::stof(rawDatos.at(8)));
            allDatos.datosMedicos.frecuenciaCardiaca.push_back(std::stof(rawDatos.at(9)));
            allDatos.datosMedicos.presionSistolica.push_back(std::stof(rawDatos.at(10)));
            allDatos.datosMedicos.presionDiastolica.push_back(std::stof(rawDatos.at(11)));
            allDatos.datosMedicos.IMC.push_back(std::stof(rawDatos.at(12)));
            allDatos.datosMedicos.factorRiesgo.push_back(rawDatos.at(13));
        }
    }
}

void analizarDatos() {
    leerDatos();
    
}