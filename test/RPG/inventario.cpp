#include <Juego/inventario/inventario.hpp>

int main() {
    Inventario inventario;

    // Agregar elementos al inventario
    Arma espada("Espada", 20);
    inventario.agregarArma(espada);

    Armadura armadura("Armadura de Placas", 50);
    inventario.agregarArmadura(armadura);

    Accesorio anillo("Anillo de Poder", "Aumenta la fuerza del usuario");
    inventario.agregarAccesorio(anillo);

    Consumible pocion("Poción de Vida", "Recupera puntos de vida");
    inventario.agregarConsumible(pocion);

    Mapa mapa("Mapa del Mundo");
    inventario.agregarMapa(mapa);

    // Mostrar el inventario
    inventario.mostrarInventario();

    return 0;
}