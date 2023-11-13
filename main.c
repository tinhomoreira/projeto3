#include <stdio.h>
#include "lab.h" 

int main() {
    struct Task tasks[100];
    int numTasks = 0;

    int opcao;
    do {
        printf("==(¬‿¬)== Gerenciador de Tarefas ==(¬‿¬)==\n");
        printf("1. Cadastrar Tarefa :)\n");
        printf("2. Listar Tarefas\n");
        printf("3. Deletar Tarefa :(\n");
        printf("0. Sair ;(\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarTarefa(tasks, &numTasks);
                break;
            case 2:
                listarTarefas(tasks, numTasks);
                break;
            case 3: {
                int index;
                printf("Digite o índice da tarefa a ser deletada: ");
                scanf("%d", &index);
                deletarTarefa(tasks, &numTasks, index - 1);
                break;
            }
            case 4:
                alterarTarefa(tasks, numTasks);
                break;
            case 5:
                filtrarPorPrioridade(tasks, numTasks);
                break;
            case 6:
                filtrarPorEstado(tasks, numTasks);
                break;
            case 7:
                filtrarPorCategoria(tasks, numTasks);
                break;
            case 8:
                filtrarPorPrioridadeECategoria(tasks, numTasks);
                break;
            case 9:
                exportarPorPrioridade(tasks, numTasks);
                break;
            case 10:
                exportarPorCategoria(tasks, numTasks);
                break;
            case 11:
                exportarPorPrioridadeECategoria(tasks, numTasks);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
