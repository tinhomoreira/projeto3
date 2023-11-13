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

void filtrarPorPrioridade(struct Task tasks[], int numTasks) {
    int prioridade;
    printf("Digite a prioridade desejada: ");
    scanf("%d", &prioridade);

    printf("Tarefas com prioridade %d:\n", prioridade);
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].priority == prioridade) {
            printf("Descrição: %s", tasks[i].description);
            printf("Categoria: %s", tasks[i].category);
            printf("Estado: %s\n", tasks[i].estado_tarefa);
            printf("--------------------\n");
        }
    }
}
void filtrarPorEstado(struct Task tasks[], int numTasks) {
    char estado[50];
    printf("Digite o estado desejado: ");
    getchar();
    fgets(estado, sizeof(estado), stdin);
    estado[strlen(estado) - 1] = '\0';  

    printf("Tarefas com estado %s:\n", estado);
    for (int i = 0; i < numTasks; i++) {
        if (strcmp(tasks[i].estado_tarefa, estado) == 0) {
            printf("Prioridade: %d\n", tasks[i].priority);
            printf("Descrição: %s", tasks[i].description);
            printf("Categoria: %s", tasks[i].category);
            printf("--------------------\n");
        }
    }
}

void filtrarPorCategoria(struct Task tasks[], int numTasks) {
    char categoria[100];
    printf("Digite a categoria desejada: ");
    getchar();
    fgets(categoria, sizeof(categoria), stdin);
    categoria[strlen(categoria) - 1] = '\0';  

    printf("Tarefas com categoria %s, ordenadas por prioridade:\n", categoria);

    for (int i = 0; i < numTasks - 1; i++) {
        for (int j = i + 1; j < numTasks; j++) {
            if (tasks[i].priority < tasks[j].priority) {
                struct Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    for (int i = 0; i < numTasks; i++) {
        if (strcmp(tasks[i].category, categoria) == 0) {
            printf("Prioridade: %d\n", tasks[i].priority);
            printf("Descrição: %s", tasks[i].description);
            printf("Estado: %s\n", tasks[i].estado_tarefa);
            printf("--------------------\n");
        }
    }
}

void filtrarPorPrioridadeECategoria(struct Task tasks[], int numTasks) {
    int prioridade;
    char categoria[100];

    printf("Digite a prioridade desejada: ");
    scanf("%d", &prioridade);

    printf("Digite a categoria desejada: ");
    getchar();
    fgets(categoria, sizeof(categoria), stdin);
    categoria[strlen(categoria) - 1] = '\0';  

    printf("Tarefas com prioridade %d e categoria %s:\n", prioridade, categoria);
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].priority == prioridade && strcmp(tasks[i].category, categoria) == 0) {
            printf("Descrição: %s", tasks[i].description);
            printf("Estado: %s\n", tasks[i].estado_tarefa);
            printf("--------------------\n");
        }
    }
}
void exportarPorPrioridade(struct Task tasks[], int numTasks) {
    int prioridade;
    printf("Digite a prioridade desejada para exportação: ");
    scanf("%d", &prioridade);

    FILE *arquivo = fopen("export_por_prioridade.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de exportação.\n");
        return;
    }

    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].priority == prioridade) {
            fprintf(arquivo, "%d, %s, %s, %s", tasks[i].priority, tasks[i].category, tasks[i].estado_tarefa, tasks[i].description);
            fprintf(arquivo, "\n");
        }
    }

    fclose(arquivo);
    printf("Tarefas exportadas por prioridade com sucesso!\n");
}

void exportarPorCategoria(struct Task tasks[], int numTasks) {
    char categoria[100];
    printf("Digite a categoria desejada para exportação: ");
    getchar();
    fgets(categoria, sizeof(categoria), stdin);
    categoria[strlen(categoria) - 1] = '\0'; 

    FILE *arquivo = fopen("export_por_categoria.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de exportação.\n");
        return;
    }

    for (int i = 0; i < numTasks; i++) {
        if (strcmp(tasks[i].category, categoria) == 0) {
            fprintf(arquivo, "%d, %s, %s, %s", tasks[i].priority, tasks[i].category, tasks[i].estado_tarefa, tasks[i].description);
            fprintf(arquivo, "\n");
        }
    }

    fclose(arquivo);
    printf("Tarefas exportadas por categoria com sucesso!\n");
}

void exportarPorPrioridadeECategoria(struct Task tasks[], int numTasks) {
    int prioridade;
    char categoria[100];

    printf("Digite a prioridade desejada: ");
    scanf("%d", &prioridade);

    printf("Digite a categoria desejada: ");
    getchar();
    fgets(categoria, sizeof(categoria), stdin);
    categoria[strlen(categoria) - 1] = '\0'; 

    FILE *arquivo = fopen("export_por_prioridade_e_categoria.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de exportação.\n");
        return;
    }

    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].priority == prioridade && strcmp(tasks[i].category, categoria) == 0) {
            fprintf(arquivo, "%d, %s, %s, %s", tasks[i].priority, tasks[i].category, tasks[i].estado_tarefa, tasks[i].description);
            fprintf(arquivo, "\n");
        }
    }

    fclose(arquivo);
    printf("Tarefas exportadas por prioridade e categoria com sucesso!\n");
}
