#include <RPG/Items/armas/Espadon.hpp>


int main() {
    Espadon espadonFuego("Espadón de Fuego", "Fuego", 55, 15);
    Espadon espadonBasico("Espadón Basico", "Basico", 40, 35);
    Espadon espadonRayo("Espadón de Rayo", "Rayo", 55, 15);
    Espadon espadonHielo("Espadón de Hielo", "Hielo", 55, 15);

    espadonFuego.mostrarEstado();
    espadonBasico.mostrarEstado();
    espadonRayo.mostrarEstado();
    espadonHielo.mostrarEstado();

    return 0;
}