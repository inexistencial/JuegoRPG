#pragma once
#include <iostream>
#include <string>

class Escudo {
private:
    std::string nombre;
    int resistenciaBasica;
    int resistenciaVeneno;
    int resistenciaFuego;
    int resistenciaHielo;
    int resistenciaRayo;
    int durabilidad;

public:
    Escudo(std::string Nombre, int ResistenciaBasica, int ResistenciaVeneno, int ResistenciaFuego, int ResistenciaHielo, int ResistenciaRayo, int Durabilidad) {
        nombre = Nombre;
        resistenciaBasica = ResistenciaBasica;
        resistenciaVeneno = ResistenciaVeneno;
        resistenciaFuego = ResistenciaFuego;
        resistenciaHielo = ResistenciaHielo;
        resistenciaRayo = ResistenciaRayo;
        durabilidad = Durabilidad;
    }

    int mitigarDanio(int Daño, std::string tipoElemento) {
        int dañoMitigado = Daño;

        if (tipoElemento == "Básico")
            dañoMitigado -= resistenciaBasica;
        else if (tipoElemento == "Veneno")
            dañoMitigado -= resistenciaVeneno;
        else if (tipoElemento == "Fuego")
            dañoMitigado -= resistenciaFuego;
        else if (tipoElemento == "Hielo")
            dañoMitigado -= resistenciaHielo;
        else if (tipoElemento == "Rayo")
            dañoMitigado -= resistenciaRayo;

        if (dañoMitigado < 0)
            dañoMitigado = 0;

        return dañoMitigado;
    }

    void recibirDaño(int Daño) {
        durabilidad -= Daño;
        if (durabilidad < 0)
            durabilidad = 0;
    }

    void mostrarEstado() {
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Durabilidad: " << durabilidad << std::endl;
    }
};

int main() {
    Escudo escudoElemental("Escudo Elemental", 5, 8, 10, 6, 7, 20);

    escudoElemental.mostrarEstado();

    int dañoBasico = 10;
    int dañoFuego = 15;
    int dañoVeneno = 12;
    int dañoHielo = 10;
    int dañoRayo = 8;

    //----------------------------- Ataque con daño básico
    std::cout << "¡Enemigo ataca con daño básico de " << dañoBasico << "!" << std::endl;
    int dañoMitigado = escudoElemental.mitigarDanio(dañoBasico, "Básico");
    std::cout << "Daño mitigado: " << dañoMitigado << std::endl;
    escudoElemental.recibirDaño(dañoMitigado);
    escudoElemental.mostrarEstado();

    //------------------------------ Ataque con daño de fuego
    std::cout << "¡Enemigo ataca con daño de fuego de " << dañoFuego << "!" << std::endl;
    dañoMitigado = escudoElemental.mitigarDanio(dañoFuego, "Fuego");
    std::cout << "Daño mitigado: " << dañoMitigado << std::endl;
    escudoElemental.recibirDaño(dañoMitigado);
    escudoElemental.mostrarEstado();

    //------------------------------- Ataque con daño de veneno
    std::cout << "¡Enemigo ataca con daño de veneno de " << dañoVeneno << "!" << std::endl;
    dañoMitigado = escudoElemental.mitigarDanio(dañoVeneno, "Veneno");
    std::cout << "Daño mitigado: " << dañoMitigado << std::endl;
    escudoElemental.recibirDaño(dañoMitigado);
    escudoElemental.mostrarEstado();

    //-------------------------------- Ataque con daño de hielo
    std::cout << "¡Enemigo ataca con daño de hielo de " << dañoHielo << "!" << std::endl;
    dañoMitigado = escudoElemental.mitigarDanio(dañoHielo, "Hielo");
    std::cout << "Daño mitigado: " << dañoMitigado << std::endl;
    escudoElemental.recibirDaño(dañoMitigado);
    escudoElemental.mostrarEstado();

    //--------------------------------- Ataque con daño de rayo
    std::cout << "¡Enemigo ataca con daño de rayo de " << dañoRayo << "!" << std::endl;
    dañoMitigado = escudoElemental.mitigarDanio(dañoRayo, "Rayo");
    std::cout << "Daño mitigado: " << dañoMitigado << std::endl;
    escudoElemental.recibirDaño(dañoMitigado);
    escudoElemental.mostrarEstado();

    return 0;
}

