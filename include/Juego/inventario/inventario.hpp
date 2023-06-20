#pragma once

#include <iostream>
#include <vector>
#include <string>

class Arma {
    // Implementación de la clase Arma
};

class Armadura {
    // Implementación de la clase Armadura
};

class Accesorio {
    // Implementación de la clase Accesorio
};

class Consumible {
    // Implementación de la clase Consumible
};

class Mapa {
    // Implementación de la clase Mapa
};

class Inventario {
private:
    std::vector<Arma> armas;
    std::vector<Armadura> armaduras;
    std::vector<Accesorio> accesorios;
    std::vector<Consumible> consumibles;
    Mapa mapa;

public:
    void agregarArma(const Arma& arma) {
        armas.push_back(arma);
    }

    void agregarArmadura(const Armadura& armadura) {
        armaduras.push_back(armadura);
    }

    void agregarAccesorio(const Accesorio& accesorio) {
        accesorios.push_back(accesorio);
    }

    void agregarConsumible(const Consumible& consumible) {
        consumibles.push_back(consumible);
    }

    void agregarMapa(const Mapa& mapa) {
        this->mapa = mapa;
    }

    void mostrarInventario() {
        std::cout << "----- Inventario -----" << std::endl;
        std::cout << "Armas:" << std::endl;
        for (const auto& arma : armas) {
            // Mostrar información del arma
        }

        std::cout << "Armaduras:" << std::endl;
        for (const auto& armadura : armaduras) {
            // Mostrar información de la armadura
        }

        std::cout << "Accesorios:" << std::endl;
        for (const auto& accesorio : accesorios) {
            // Mostrar información del accesorio
        }

        std::cout << "Consumibles:" << std::endl;
        for (const auto& consumible : consumibles) {
            // Mostrar información del consumible
        }

        std::cout << "Mapa: ";
        // Mostrar información del mapa

        std::cout << "-----------------------" << std::endl;
    }
};

