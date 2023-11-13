#include <stdio.h>
#include <stdlib.h>
#include "lab.h"

void cadastrarTarefa(struct Task tasks[], int *numTasks) {
    if (*numTasks >= 100) {
        printf("A lista de tarefas está cheia. Não é possível adicionar mais tarefas.\n");
        return;
    }

    struct Task newTask;
    printf("Digite a prioridade da sua tarefa (0 a 10): ");
    scanf("%d", &newTask.priority);

    printf("Digite a descrição da sua tarefa (até 300 caracteres): ");
    getchar();
    fgets(newTask.description, sizeof(newTask.description), stdin);

    printf("Digite a categoria da sua tarefa (até 100 caracteres): ");
    fgets(newTask.category, sizeof(newTask.category), stdin);

    tasks[*numTasks] = newTask;
    (*numTasks)++;
    printf("Tarefa cadastrada com sucesso!\n");
}

void listarTarefas(struct Task tasks[], int numTasks) {
    if (numTasks == 0) {
        printf("Não há tarefas cadastradas.\n");
        return;
    }

    printf("Lista de tarefas:\n");
    for (int i = 0; i < numTasks; i++) {
        printf("Tarefa %d:\n", i + 1);
        printf("Prioridade: %d\n", tasks[i].priority);
        printf("Descrição: %s", tasks[i].description);
        printf("Categoria: %s", tasks[i].category);
        printf("--------------------\n");
    }
}

void deletarTarefa(struct Task tasks[], int *numTasks, int index) {
    if (index < 0 || index >= *numTasks) {
        printf("Índice inválido.\n");
        return;
    }

    for (int i = index; i < *numTasks - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    (*numTasks)--;
    printf("Tarefa deletada com sucesso! :)\n");
}

void alterarTarefa(struct Task tasks[], int numTasks) {
    if (numTasks == 0) {
        printf("Não há tarefas cadastradas.\n");
        return;
    }

    int index;
    printf("Digite o índice da tarefa a ser alterada: ");
    scanf("%d", &index);

    if (index < 1 || index > numTasks) {
        printf("Índice inválido.\n");
        return;
    }

    struct Task *task = &tasks[index - 1];

    int opcao;
    printf("Escolha o campo a ser alterado:\n");
    printf("1. Prioridade\n");
    printf("2. Descrição\n");
    printf("3. Categoria\n");
    printf("4. Estado\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Digite a nova prioridade: ");
            scanf("%d", &task->priority);
            break;
        case 2:
            printf("Digite a nova descrição: ");
            getchar();  // Limpar o buffer do teclado
            fgets(task->description, sizeof(task->description), stdin);
            break;
        case 3:
            printf("Digite a nova categoria: ");
            getchar();  // Limpar o buffer do teclado
            fgets(task->category, sizeof(task->category), stdin);
            break;
        case 4:
            printf("Digite o novo estado: ");
            getchar();  // Limpar o buffer do teclado
            fgets(task->estado_tarefa, sizeof(task->estado_tarefa), stdin);
            break;
        default:
            printf("Opção inválida.\n");
    }
}
