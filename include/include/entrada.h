#ifndef ENTRADA_H
#define ENTRADA_H

#include "cliente.h"

void lerNome(Cliente *c);
void lerEndereco(Cliente *c);
void lerTelefone(Cliente *c);
void lerValorMovel(Cliente *c);
void lerValorImpermeabilizacao(Cliente *c);
char perguntarContinuar();

#endif
