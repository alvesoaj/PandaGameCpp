//============================================================================
// Name        : Main.cpp
// Author      : zerokol
//============================================================================

// importando bibliotecas
#include <pandaFramework.h>
#include <pandaSystem.h>
#include <animControlCollection.h>
#include <auto_bind.h>

// criando um objeto do tipo PandaFramework
PandaFramework framework;

int main(int argc, char* argv[]) {
	// inicializando o framework
	framework.open_framework(argc, argv);
	// abrindo a janela principal
	WindowFramework* win = framework.open_window();
	// com o auxílio do objeto WindowFramework, instanciando a câmera principal
	NodePath camera = win->get_camera_group();
	// com o auxílio do objeto WindowFramework, carregando o Modelo teapot
	NodePath teapot = win->load_model(framework.get_models(), "teapot");
	// vinculando o modelo teapot a raiz da cena gráfica
	teapot.reparent_to(win->get_render());
	// posicionando espacialmente o objeto teapot
	teapot.set_pos(-5, 0, 0);
	// carregando o ator, panda
	NodePath panda = win->load_model(framework.get_models(), "panda");
	// vinculando o ator panda a raiz da cena gráfica
	panda.reparent_to(win->get_render());
	// posicionando espacialmente o objeto panda
	panda.set_pos(5, 0, 0);
	// com o auxílio do objeto WindowFramework, indicando qual animação o ator panda deve atuar
	win->load_model(panda, "panda-walk");
	// instanciando um objeto AnimControlCollction, para gerenciar as animações do ator panda
	AnimControlCollection pandaAnims;
	// vinculando o ator panda ao seu controlador
	auto_bind(panda.node(), pandaAnims);
	// ativando a animação no ator panda, com restart false
	pandaAnims.loop("panda_soft", false);
	// posicionando espacialmente a camera padrão
	camera.set_pos(0, -30, 6);
	// colocando a aplicaçao em loop
	framework.main_loop();
	// limpando a aplicação
	framework.close_framework();
	return 0;
}
