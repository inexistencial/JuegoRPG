#pragma once
#include <iostream>
#include <string>

class Espada {
private:
    std::string nombre;
    std::string elemento;
    int daño;
    int durabilidad;

public:
    Espada(std::string Nombre, std::string Elemento, int Daño, int Durabilidad) {
        nombre = Nombre;
        elemento = Elemento;
        daño = Daño;
        durabilidad = Durabilidad;
    }

    void atacar() {
        if (durabilidad > 0) {
            std::cout << "¡Has atacado con " << nombre << " Tu ataque a infligido " << daño << " puntos de daño " << "de tipo " << elemento << "!" << std::endl;
            durabilidad--;
        } else {
            std::cout << nombre << " Tu arma se a roto y no puede ser utilizada." << std::endl;
        }
    }

    void modificarDaño(int nuevoDaño) {
        daño = nuevoDaño;
    }

    void modificarDurabilidad(int nuevaDurabilidad) {
        durabilidad = nuevaDurabilidad;
    }

    void mostrarEstado() {
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Elemento: " << elemento << std::endl;
        std::cout << "Daño: " << daño << std::endl;
        std::cout << "Durabilidad: " << durabilidad << std::endl;
    }
};

int main() {
    Espada espadaFuego("Espada de Fuego", "Fuego", 40, 10);
    Espada espadaBasica("Espada Basico", "Basico", 36, 24);
    Espada espadaAire("Espada de Aire", "Aire", 55, 8);
    Espada espadaHielo("Espada de Hielo", "Hielo", 55, 5);

    espadaFuego.mostrarEstado();
    espadaBasica.mostrarEstado();
    espadaAire.mostrarEstado();
    espadaHielo.mostrarEstado();

    return 0;
}

