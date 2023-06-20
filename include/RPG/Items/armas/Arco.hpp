#pragma once
#include <iostream>
#include <string>
#include <random>

class Arco {
private:
    std::string nombre;
    int DañoBase;
    int durabilidad;
    int probabilidadCritico;

public:
    Arco(std::string Nombre, int DañoBase, int Durabilidad, int ProbabilidadCritico) {
        nombre = Nombre;
        DañoBase = DañoBase;
        durabilidad = Durabilidad;
        probabilidadCritico = ProbabilidadCritico;
    }

    void disparar(std::string tipoMunicion) {
        int daño = DañoBase;
        bool golpeCritico = false;

        //-------------------------- Calcular golpe crítico
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 100);
        int numeroAleatorio = dis(gen);

        if (numeroAleatorio <= probabilidadCritico) {
            daño *= 2; //----------------------------- Duplicar el daño en caso de golpe crítico
            golpeCritico = true;
        }

        if (durabilidad > 0) {
            std::cout << "¡Has disparado con el " << nombre << " y has causado " << daño << " puntos de daño con una flecha " << tipoMunicion;
            if (golpeCritico) {
                std::cout << " (¡Golpe crítico!)" << std::endl;
            } else {
                std::cout << std::endl;
            }
            durabilidad--;
        } else {
            std::cout << nombre << " Tu arma se a roto y no puede ser utilizada." << std::endl;
        }
    }

    void modificarDurabilidad(int nuevaDurabilidad) {
        durabilidad = nuevaDurabilidad;
    }

    void mostrarEstado() {
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Daño Base: " << DañoBase << std::endl;
        std::cout << "Durabilidad: " << durabilidad << std::endl;
        std::cout << "Probabilidad de Golpe Crítico: " << probabilidadCritico << "%" << std::endl;
    }
};

int main() {
    Arco MunicionElemental("Municion Elemental", 50, 15, 20);

    MunicionElemental.mostrarEstado();

    MunicionElemental.disparar("Básica");
    MunicionElemental.disparar("Veneno");
    MunicionElemental.disparar("Fuego");
    MunicionElemental.disparar("Hielo");

    MunicionElemental.mostrarEstado();

    return 0;
}
