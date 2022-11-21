#include <bits/stdc++.h>

struct {
    std::vector <std::string> nombreProductos;
    std::vector <float> precioUnitario;
} Inventario;

void escribirLinea(const std::string c) {
    std::cout << std::endl;
    for (int i = 0; i < 40; i++)
        std::cout << c;
    std::cout << std::endl;
}

void verInventario() {
    if (Inventario.nombreProductos.size() > 0) {
        for (int i = 0; i < Inventario.nombreProductos.size(); i++) {
            escribirLinea("*");
            std::cout << "Identificador: " << i + 1 << std::endl;
            std::cout << "Nombre del Producto: " << Inventario.nombreProductos.at(i) << std::endl;
            std::cout << "Precio Unitario: " << Inventario.precioUnitario.at(i) << std::endl;
        }
    } else 
        std::cout << std::endl << "No hay productos registrados en el inventario" << std::endl;
}

bool validarMensaje(char msg[3]) {
    // Basicamente lo que hace es validar si la opcion ingresada coincide con el "total" de opciones posibles
    std::array <std::string, 20> options = {"Si", "No", "si", "no", "SI", "NO", "S", "N", "s", "n", "y", "n", "Y", "N", "YES", "NO", "yes", "no", "Yes", "No"};
    // Flag = false significa que el programa va a salir
    bool Flag = false;
    for (int i = 0; i < options.size(); i++) {
        if (msg == options[i]) {
            Flag = true;
            if (i % 2 != 0){
                Flag = false;
            }
        }
    }
    return Flag;
}

void agregarProducto() {
    do {
        std::string nombreProducto;
        float precioUnitario;

        escribirLinea("/");
        std::cout << "Ingrese el nombre del producto: ";
        std::cin >> nombreProducto;

        std::cout << "Ingrese el precio Unitario del producto: ";
        std::cin >> precioUnitario;

        Inventario.nombreProductos.push_back(nombreProducto);
        Inventario.precioUnitario.push_back(precioUnitario);

        char msg[3];
        std::cout << "Desea agregar otro producto?" << std::endl;
        std::cout << "-> ";
        std::cin >> msg;

        if (!validarMensaje(msg))
            break;

    } while (true);
}

bool crearOrden(std::string nombreCliente, int cantidadOrdenada, int identificadorProducto) {
    bool success = false;
    std::ofstream archivo ("SistemaInventario/pedidos/Recibo-" + nombreCliente + ".txt", std::ios::app);

    if (archivo.is_open()) {
        archivo << "Orden a nombre de: " << nombreCliente<< std::endl;
        try {
            archivo << "Producto ordenado: " << Inventario.nombreProductos.at(identificadorProducto - 1) << std::endl;
            archivo << "Cantidad Ordenada: " << std::to_string(cantidadOrdenada) << std::endl;
            archivo << "Total a pagar: " << std::to_string(cantidadOrdenada * Inventario.precioUnitario.at(identificadorProducto - 1)) << std::endl;
            success = true;
        } catch (...) {
            archivo << "NULL" << std::endl;
            std::cout << "Producto no encontrado" << std::endl;
        }
    }
    return success;
}

void hacerPedido() {
    verInventario();
    escribirLinea("/");
    std::string nombreCliente;
    int cantidadOrdenada, identificadorProducto;

    std::cout << "Ingrese su nombre: ";
    std::cin >> nombreCliente;

    std::cout << "Ingrese el identificador del producto: ";
    std::cin >> identificadorProducto;

    std::cout << "Ingrese la cantidad deseada: ";
    std::cin >> cantidadOrdenada;

    (crearOrden(nombreCliente, cantidadOrdenada, identificadorProducto)) ? 
        std::cout << std::endl << "Orden realizada Correctamente" << std::endl :
            std::cout << std::endl << "Error al momento de realizar la orden" << std::endl;
}

int mainMenuDashboard() {
    escribirLinea("-");
    int opcion;
    std::cout << "1. Ver Inventario" << std::endl;
    std::cout << "2. Agregar a Inventario" << std::endl;
    std::cout << "3. Hacer un Pedido" << std::endl;
    std::cout << "4. Salir" << std::endl;
    std::cout << "-> ";
    std::cin >> opcion;

    return opcion;
}

void mainMenu() {
    do {
        switch(mainMenuDashboard()) {
            case 1: {
                verInventario();
                break;
            }

            case 2: {
                agregarProducto();
                break;
            }

            case 3: {
                hacerPedido();
                break;
            }

            default:
                exit(EXIT_FAILURE);
        }

    } while (true);
}

int main(void) {
    mainMenu();
    return EXIT_SUCCESS;
}