#include "GestorDatosVistaEmpleado.hpp"

DoubleLinkedList<std::string> GestorDatosVistaEmpleado::SolicitarDatosParaAgregar()
{
    DoubleLinkedList<std::string> atributosEmpleado;
    try
    {
        std::cin.ignore();

        SolicitarInformacionAlpha("Nombre: ", atributosEmpleado);
        SolicitarInformacionAlpha("Apellido: ", atributosEmpleado);
        SolicitarInformacionAlpha("Tipo de identificaci�n (C�dula de ciudadan�a, c�dula de extranjer�a o tarjeta de identidad): ", atributosEmpleado);
        SolicitarInformacionNum("Numero identificaci�n: ", atributosEmpleado);

        char sexo;
        do
        {
            std::cout << "Sexo (F/M): ";
            std::cin >> sexo;

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << "Error: Por favor, ingrese solo 'F' o 'M'." << std::endl;
            }
            else
            {
                sexo = std::tolower(sexo); // Convertir a min�scula
                if (sexo != 'f' && sexo != 'm')
                    std::cerr << "Error: Por favor, ingrese solo 'F' o 'M'." << std::endl;
                else
                    break; // Salir del bucle si la entrada es v�lida
            }
        } while (true);

        std::string sexoString(1, sexo);
        atributosEmpleado.AddLast(sexoString);

        std::cin.ignore(); // Limpiar el buffer del teclado

        SolicitarInformacionNum("Telefono Fijo: ", atributosEmpleado);
        SolicitarInformacionNum("Telefono Celular: ", atributosEmpleado);
        std::string email;
        do
        {
            std::cout << "Email: ";
            std::cin >> email;

            // Verificar que todos los caracteres son alfanuméricos, '@' o '.'
            bool todosValidos = true;
            for (size_t i = 0; i < email.length(); ++i)
            {
                char c = email[i];
                if (!(std::isalnum(c) || c == '@' || c == '.'))
                {
                    todosValidos = false;
                    break; // Salir del bucle si se encuentra un carácter no válido
                }
            }

            if (todosValidos)
            {
                atributosEmpleado.AddLast(email);
                break; // Salir del bucle si todos son válidos
            }
            else
            {
                std::cerr << "Error: El email debe contener solo caracteres alfanuméricos, '@' o '.'." << std::endl;
            }
        } while (true);

        std::cin.ignore(); // Limpiar el buffer del teclado
        std::string fechaNacimiento;
        do
        {
            std::cout << "Fecha De Nacimiento: ";
            std::cin >> fechaNacimiento;

            // Verificar que todos los caracteres son alfanuméricos o '/'
            bool todosValidos = true;
            for (size_t i = 0; i < fechaNacimiento.length(); ++i)
            {
                char c = fechaNacimiento[i];
                if (!(std::isalnum(c) || c == '/'))
                {
                    todosValidos = false;
                    break; // Salir del bucle si se encuentra un carácter no válido
                }
            }

            if (todosValidos)
            {
                atributosEmpleado.AddLast(fechaNacimiento);
                break; // Salir del bucle si todos son válidos
            }
            else
            {
                std::cerr << "Error: La fecha de nacimiento solo puede tener números o /" << std::endl;
            }
        } while (true);

        std::cin.ignore(); // Limpiar el buffer del teclado

        SolicitarInformacionAlpha("Ciudad de Nacimiento: ", atributosEmpleado);
        SolicitarInformacionAlpha("Pais de Nacimiento: ", atributosEmpleado);
        SolicitarInformacionAlpha("Pais Residencia: ", atributosEmpleado);
        SolicitarInformacionAlpha("Ciudad de Residencia: ", atributosEmpleado);

        std::string direccion;
        PRINT("Dirección: ");
        std::getline(std::cin, direccion);
        atributosEmpleado.AddLast(direccion);

        SolicitarInformacionAlpha("Barrio: ", atributosEmpleado);
        SolicitarInformacionAlpha("Actividad Laboral: ", atributosEmpleado);

        char op;
        do
        {
            std::cout << "Tiene hijos? (S/N): ";
            std::cin >> op;

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << "Error: Por favor, ingrese solo 'S' o 'N'." << std::endl;
            }
            else
            {
                op = std::tolower(op); // Convertir a min�scula
                if (op != 's' && op != 'n')
                    std::cerr << "Error: Por favor, ingrese solo 'S' o 'N'." << std::endl;
                else
                    break; // Salir del bucle si la entrada es v�lida
            }
        } while (true);

        std::string tieneHijos(1, op);
        atributosEmpleado.AddLast(tieneHijos);

        std::string numHijos;
        if (tieneHijos == "s")
        {
            std::string numHijos;
            std::cout << "Numero de Hijos: ";
            std::cin >> numHijos;
        }
        else
            numHijos = "0";

        atributosEmpleado.AddLast(numHijos);

        std::cin.ignore();
        SolicitarInformacionAlpha("Sucursal donde trabaja: ", atributosEmpleado);
        atributosEmpleado.AddLast(convertirAString(calcularEdad(obtenerFechaDesdeString(atributosEmpleado.getData(9)))));
        atributosEmpleado.AddLast("");

        return atributosEmpleado;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return DoubleLinkedList<std::string>();
    }
    catch (...)
    {
        std::cerr << "Error desconocido durante la captura de informaci�n del empleado." << std::endl;
        return DoubleLinkedList<std::string>();
    }
}

void GestorDatosVistaEmpleado::SolicitarInformacionAlpha(std::string mensajeAtributo, DoubleLinkedList<std::string> &atributosEmpleados)
{
    std::string atributo;
    do
    {
        PRINT(mensajeAtributo);
        std::getline(std::cin, atributo);
        if (!EsStringAlfabeticoConEspacios(atributo))
            std::cerr << mensajeErrorLetras << std::endl;
        else
            atributosEmpleados.AddLast(atributo);
    } while (!EsStringAlfabeticoConEspacios(atributo));
}

bool GestorDatosVistaEmpleado::EsStringAlfabeticoConEspacios(const std::string &str)
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        char c = str[i];
        if (!std::isalpha(c) && !std::isspace(c))
        {
            return false;
        }
    }
    return true;
}

void GestorDatosVistaEmpleado::SolicitarInformacionNum(std::string mensajeAtributo, DoubleLinkedList<std::string> &atributosEmpleados)
{
    std::string atributo;
    do
    {
        PRINT(mensajeAtributo);
        std::getline(std::cin, atributo);
        if (!EsStringConNumeros(atributo))
            std::cerr << mensajeErrorNumeros << std::endl;
        else
            atributosEmpleados.AddLast(atributo);

    } while (!EsStringConNumeros(atributo));
}

bool GestorDatosVistaEmpleado::EsStringConNumeros(const std::string &str)
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        char c = str[i];
        if (!std::isalnum(c))
        {
            return false;
        }
    }
    return true;
}

void GestorDatosVistaEmpleado::MostrarAtributos(DoubleLinkedList<std::string> atributos)
{
    PRINTLN("Atributos del empleado");
    PRINTLN("1. Nombre: " + atributos.getData(2));
    PRINTLN("2. Apellido: " + atributos.getData(3));
    PRINTLN("3. Tipo de Identificación: " + atributos.getData(4));
    PRINTLN("4. Número de Identificación: " + atributos.getData(5));
    PRINTLN("5. Sexo: " + atributos.getData(6));
    PRINTLN("6. Teléfono Celular: " + atributos.getData(7));
    PRINTLN("7. Teléfono Fijo: " + atributos.getData(8));
    PRINTLN("8. Email: " + atributos.getData(9));
    PRINTLN("9. Fecha de Nacimiento: " + atributos.getData(10));
    PRINTLN("10. Ciudad de Nacimiento: " + atributos.getData(11));
    PRINTLN("11. País de Nacimiento: " + atributos.getData(12));
    PRINTLN("12. País de Residencia: " + atributos.getData(13));
    PRINTLN("13. Ciudad de Residencia: " + atributos.getData(14));
    PRINTLN("14. Dirección: " + atributos.getData(15));
    PRINTLN("15. Barrio: " + atributos.getData(16));
    PRINTLN("16. Actividad Laboral: " + atributos.getData(17));
    PRINTLN("17. Tiene Hijos: " + atributos.getData(18));
    PRINTLN("18. Número de Hijos: " + atributos.getData(19));
    PRINTLN("19. Sucursal Donde Trabaja: " + atributos.getData(20));
    PRINTLN("20. Edad: " + atributos.getData(21));
    PRINTLN("\nSi quieres cambiar la edad, debes cambiar la fecha de nacimiento");
    PRINTLN("");
}

int GestorDatosVistaEmpleado::ElegirAtributo(DoubleLinkedList<std::string> atributos)
{
    int op;
    PRINTLN("Si quieres salir ingresa 0\n");
    MostrarAtributos(atributos);
    PRINT("Ingresa el número del atributos que quieres modificar: ");
    std::cin >> op;
    return op;
}

template <class T>
std::string GestorDatosVistaEmpleado::convertirAString(const T &valor)
{
    std::ostringstream stream;
    stream << valor;
    return stream.str();
}
