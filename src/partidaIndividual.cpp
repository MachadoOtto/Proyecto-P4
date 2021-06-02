/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#include <../include/partidaIndividual.h>

PartidaIndividual::PartidaIndividual(DtPartidaIndividual* datos) {
    identificador = datos.getIdentificador();
    fecha = datos.getFechaHora();
    duracion = datos.getDuracion();
    activa = datos.getActiva();
    host = NULL;
    videogame = NULL;
}

void PartidaIndividual::setPartidaAnterior(PartidaIndividual* pAnt) {
    partidaAnterior = pAnt;
}

PartidaIndividual* PartidaIndividual::getPartidaAnterior() { return partidaAnterior; }

virtual DtPartida* PartidaIndividual::obtenerDatosPartida() {
    DtPartida* datosP = new DtPartidaIndividual(identificador, fecha, duracion, activa);
    return datosP;
}

virtual void PartidaIndividual::finalizarPartida(DtFechaHora horaFinal) {
    this.setActiva(false);
    this.asignarHoraFinalizacion(horafinal);
}

virtual void PartidaIndividual::eliminarAssoc() {
    host.remove(this);
}

virtual void PartidaIndividual::remove(Jugador* player) { 
    if (player == host)
        host = NULL; 
}

virtual PartidaIndividual::~Partida() { }