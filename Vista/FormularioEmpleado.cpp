#include "FormularioEmpleado.hpp"

DoubleLinkedList<std::string> FormularioEmpleado::SolicitarDatos()
{
    Empleado empleado;
    DoubleLinkedList<std::string> atributosEmpleado;
    try
    {
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

        SolicitarTelefono("Telefono Fijo: ", atributosEmpleado);
        SolicitarTelefono("Telefono Celular: ", atributosEmpleado);

        std::cin.ignore(); // Limpiar el buffer del teclado

        std::string email;
        do
        {
            std::cout << "Email: ";
            std::cin >> email;

            // Verificar que todos los caracteres son alfanum�ricos, '@' o '.'
            if (std::all_of(email.begin(), email.end(),
                            [](char c)
                            { return std::isalnum(c) || c == '@' || c == '.'; }))
            {
                atributosEmpleado.AddLast(email);
                break; // Salir del bucle si todos son v�lidos
            }
            else
            {
                std::cerr << "Error: El email debe contener solo caracteres alfanum�ricos, '@' o '.'." << std::endl;
            }
        } while (true);

        std::cin.ignore(); // Limpiar el buffer del teclado

        std::string fechaNacimiento;
        do
        {
            std::cout << "Fecha De Nacimiento: ";
            std::cin >> fechaNacimiento;

            // Verificar que todos los caracteres son alfanum�ricos, '@' o '.'
            if (std::all_of(fechaNacimiento.begin(), fechaNacimiento.end(),
                            [](char c)
                            { return std::isalnum(c) || c == '/'; }))
            {
                atributosEmpleado.AddLast(fechaNacimiento);
                break; // Salir del bucle si todos son v�lidos
            }
            else
            {
                std::cerr << "Error: La fehca de nacimiento solo puede tener n�meros o /" << std::endl;
            }
        } while (true);

        std::cin.ignore(); // Limpiar el buffer del teclado

        SolicitarInformacionAlpha("Ciudad de Nacimiento: ", atributosEmpleado);
        SolicitarInformacionAlpha("Pais de Nacimiento: ", atributosEmpleado);
        SolicitarInformacionAlpha("Ciudad de Residencia: ", atributosEmpleado);
        SolicitarInformacionAlpha("Pais Residencia: ", atributosEmpleado);

        std::string direccion;
        PRINT("Dirección: ");
        std::cin >> direccion;
        std::cin.ignore();

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
        return atributosEmpleado;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Error desconocido durante la captura de informaci�n del empleado." << std::endl;
    }
}

void FormularioEmpleado::SolicitarInformacionAlpha(std::string mensajeAtributo, DoubleLinkedList<std::string> &atributosEmpleados)
{
    std::string atributo;
    do
    {
        PRINT(mensajeAtributo);
        std::getline(std::cin, atributo);
        if (!std::all_of((atributo).begin(), (atributo).end(), ::isalpha))
            std::cerr << mensajeErrorLetras << std::endl;
        else
            atributosEmpleados.AddLast(atributo);
    } while (!std::all_of((atributo).begin(), (atributo).end(), ::isalpha));
}

void FormularioEmpleado::SolicitarInformacionNum(std::string mensajeAtributo, DoubleLinkedList<std::string> &atributosEmpleados)
{
    std::string atributo;
    do
    {
        PRINT(mensajeAtributo);
        std::getline(std::cin, atributo);
        if (!std::all_of((atributo).begin(), (atributo).end(), ::isdigit))
            std::cerr << mensajeErrorNumeros << std::endl;
        else
            atributosEmpleados.AddLast(atributo);

    } while (!std::all_of((atributo).begin(), (atributo).end(), ::isdigit));
}

void FormularioEmpleado::SolicitarTelefono(std::string mensajeAtributo, DoubleLinkedList<std::string> &atributosEmpleados)
{
    do
    {
        std::cout << mensajeAtributo;
        std::string atributo;

        // Verificar si la entrada es un n�mero
        if (std::cin.fail() || !std::all_of((atributo).begin(), (atributo).end(), ::isdigit))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Error: El tel�fono debe ser un n�mero v�lido." << std::endl;
        }
        else if ((atributo).length() != 10)
        {
            // Verificar la longitud del n�mero (ajusta seg�n sea necesario)
            std::cerr << "Error: El tel�fono debe tener 10 d�gitos." << std::endl;
        }
        else
        {
            atributosEmpleados.AddLast(atributo);
            break; // Salir del bucle si la entrada es v�lida
        }
    } while (true);
}
