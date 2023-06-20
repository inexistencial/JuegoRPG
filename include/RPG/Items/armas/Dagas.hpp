#pragma once
#include <iostream>
#include <string>
#include <random>

class Dagas {
private:
    std::string nombre;
    int DañoBasico;
    int DañoVeneno;
    int DañoFuego;
    int DañoHielo;
    int durabilidad;
    int ProbabilidadCriticos;

public:
    Dagas(std::string Nombre, int dañoBasico, int dañoVeneno, int dañoFuego, int dañoHielo, int Durabilidad, int probabilidadCritico) {
        nombre = Nombre;
        DañoBasico = dañoBasico;
        DañoVeneno = dañoVeneno;
        DañoFuego = dañoFuego;
        DañoHielo = dañoHielo;
        durabilidad = Durabilidad;
        ProbabilidadCriticos = probabilidadCritico;
    }

    void atacar(std::string tipoElemento) {
        int Daño = 0;
        bool golpeCritico = false;

        // ------------------------------------------- Calcular golpe crítico
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 100);
        int numeroAleatorio = dis(gen);

        if (numeroAleatorio <= ProbabilidadCriticos) {
            Daño *= 2; //----------------------------- Duplicar el daño en caso de golpe crítico
            golpeCritico = true;
        }

        if (durabilidad > 0) {
            if (tipoElemento == "Básico")
                Daño = DañoBasico;
            else if (tipoElemento == "Veneno")
                Daño = DañoVeneno;
            else if (tipoElemento == "Fuego")
                Daño = DañoFuego;
            else if (tipoElemento == "Hielo")
                Daño = DañoHielo;

            std::cout << "¡Has atacado con " << nombre << " y has causado " << Daño << " puntos de daño";
            if (golpeCritico) {
                std::cout << " (¡Golpe crítico!)" << std::endl;
            } else {
                std::cout << std::endl;
            }
            durabilidad--;
        } else {
            std::cout << "Las " << nombre << " están desgastadas y no pueden ser utilizadas." << std::endl;
        }
    }

    void modificarDurabilidad(int nuevaDurabilidad) {
        durabilidad = nuevaDurabilidad;
    }

    void mostrarEstado() {
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Durabilidad: " << durabilidad << std::endl;
    }
};

int main() {
    Dagas dagasElementales("Dagas Elementales", 10, 15, 20, 12, 8, 30);

    dagasElementales.mostrarEstado();

    dagasElementales.atacar("Básico");
    dagasElementales.atacar("Veneno");
    dagasElementales.atacar("Fuego");
    dagasElementales.atacar("Hielo");

    dagasElementales.mostrarEstado();

    return 0;
}
