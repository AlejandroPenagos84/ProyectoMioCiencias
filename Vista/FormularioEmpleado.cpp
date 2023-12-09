#include "FormularioEmpleado.hpp"

FormularioEmpleado::FormularioEmpleado() {}
void FormularioEmpleado::SolicitarInformacionAlpha(std::string mensajeAtributo, Empleado &empleado, std::string Empleado::*atributo)
{
    do
    {
        PRINT(mensajeAtributo);
        std::getline(std::cin, empleado.*atributo);
        if (!std::all_of((empleado.*atributo).begin(), (empleado.*atributo).end(), ::isalpha))
            std::cerr << mensajeErrorLetras << std::endl;
    } while (!std::all_of((empleado.*atributo).begin(), (empleado.*atributo).end(), ::isalpha));
}

void FormularioEmpleado::SolicitarInformacionNum(std::string mensajeAtributo, Empleado &empleado, std::string Empleado::*atributo)
{
    do
    {
        std::cout << mensajeAtributo;
        std::getline(std::cin, empleado.*atributo);
        if (!std::all_of((empleado.*atributo).begin(), (empleado.*atributo).end(), ::isdigit))
            std::cerr << mensajeErrorNumeros << std::endl;
    } while (!std::all_of((empleado.*atributo).begin(), (empleado.*atributo).end(), ::isdigit));
}

void FormularioEmpleado::SolicitarTelefono(std::string mensajeAtributo, Empleado &empleado, std::string Empleado::*atributo)
{
    do
    {
        std::cout << mensajeAtributo;
        std::cin >> empleado.*atributo;

        // Verificar si la entrada es un n�mero
        if (std::cin.fail() || !std::all_of((empleado.*atributo).begin(), (empleado.*atributo).end(), ::isdigit))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Error: El tel�fono debe ser un n�mero v�lido." << std::endl;
        }
        else if ((empleado.*atributo).length() != 10)
        {
            // Verificar la longitud del n�mero (ajusta seg�n sea necesario)
            std::cerr << "Error: El tel�fono debe tener 10 d�gitos." << std::endl;
        }
        else
        {
            break; // Salir del bucle si la entrada es v�lida
        }
    } while (true);
}

Empleado FormularioEmpleado::SolicitarDatos()
{
    Empleado empleado;

    try
    {
        SolicitarInformacionAlpha("Nombre: ", empleado, &Empleado ::nombre);
        SolicitarInformacionAlpha("Apellido: ", empleado, &Empleado ::apellido);
        SolicitarInformacionAlpha("Tipo de identificaci�n (C�dula de ciudadan�a, c�dula de extranjer�a o tarjeta de identidad): ", empleado, &Empleado::tipoIdentificacion);
        SolicitarInformacionNum("Numero identificaci�n: ", empleado, &Empleado::numIdentificacion);

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

        empleado.sexo = sexo == 'm' ? true : false;

        SolicitarTelefono("Telefono Fijo: ", empleado, &Empleado::telefonoFijo);
        SolicitarTelefono("Telefono Celular: ", empleado, &Empleado::telefonoCelular);

        std::cin.ignore(); // Limpiar el buffer del teclado

        do
        {
            std::cout << "Email: ";
            std::cin >> empleado.email;

            // Verificar que todos los caracteres son alfanum�ricos, '@' o '.'
            if (std::all_of(empleado.email.begin(), empleado.email.end(),
                            [](char c)
                            { return std::isalnum(c) || c == '@' || c == '.'; }))
            {
                break; // Salir del bucle si todos son v�lidos
            }
            else
            {
                std::cerr << "Error: El email debe contener solo caracteres alfanum�ricos, '@' o '.'." << std::endl;
            }
        } while (true);

        std::cin.ignore(); // Limpiar el buffer del teclado

        do
        {
            std::cout << "Fecha De Nacimiento: ";
            std::cin >> empleado.fechaNacimiento;

            // Verificar que todos los caracteres son alfanum�ricos, '@' o '.'
            if (std::all_of(empleado.fechaNacimiento.begin(), empleado.fechaNacimiento.end(),
                            [](char c)
                            { return std::isalnum(c) || c == '/'; }))
            {
                break; // Salir del bucle si todos son v�lidos
            }
            else
            {
                std::cerr << "Error: La fehca de nacimiento solo puede tener n�meros o /" << std::endl;
            }
        } while (true);

        std::cin.ignore(); // Limpiar el buffer del teclado

        SolicitarInformacionAlpha("Ciudad de Nacimiento: ", empleado, &Empleado::ciudadNacimiento);
        SolicitarInformacionAlpha("Pais de Nacimiento: ", empleado, &Empleado::paisNacimiento);
        SolicitarInformacionAlpha("Ciudad de Residencia: ", empleado, &Empleado::ciudadResidencia);
        SolicitarInformacionAlpha("Pais Residencia: ", empleado, &Empleado::paisResidencia);

        SolicitarInformacionAlpha("Barrio: ", empleado, &Empleado::barrio);
        SolicitarInformacionAlpha("Actividad Laboral: ", empleado, &Empleado::actividadLaboral);

        PRINT("Dirección: ");
        std::cin >> empleado.direccion;
        std::cin.ignore();

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

        empleado.tieneHijos = op == 's' ? true : false;

        if (empleado.tieneHijos)
        {
            std::cout << "Numero de Hijos: ";
            std::cin >> empleado.numHijos;
        }
        return empleado;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return Empleado();
    }
    catch (...)
    {
        std::cerr << "Error desconocido durante la captura de informaci�n del empleado." << std::endl;
        return Empleado();
    }
}
