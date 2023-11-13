#include <stdio.h>
#include <stdlib.h>
#include "lab.h" 

// Função para cadastrar uma nova tarefa
void cadastrarTarefa(struct Task tasks[], int *numTasks) {
    // Verifica se a lista de tarefas está cheia
    if (*numTasks >= 100) {
        printf("A lista de tarefas está cheia. Não é possível adicionar mais tarefas.\n");
        return;
    }

    // Cria uma nova tarefa
    struct Task newTask;
    printf("Digite a prioridade da sua tarefa (0 a 10): ");
    scanf("%d", &newTask.priority);

    printf("Digite a descrição da sua tarefa (até 300 caracteres): ");
    getchar();
    fgets(newTask.description, sizeof(newTask.description), stdin);

    printf("Digite a categoria da sua tarefa (até 100 caracteres): ");
    fgets(newTask.category, sizeof(newTask.category), stdin);

    // Adiciona a nova tarefa na lista 
    tasks[*numTasks] = newTask;
    (*numTasks)++;
    printf("Tarefa cadastrada com sucesso!\n");
}

// Função para listar todas as tarefas
void listarTarefas(struct Task tasks[], int numTasks) {
    // Verifica se não há tarefas cadastradas
    if (numTasks == 0) {
        printf("Não há tarefas cadastradas.\n");
        return;
    }

    // Mostra as informações de cada tarefa na lista
    printf("Lista de tarefas:\n");
    for (int i = 0; i < numTasks; i++) {
        printf("Tarefa %d:\n", i + 1);
        printf("Prioridade: %d\n", tasks[i].priority);
        printf("Descrição: %s", tasks[i].description);
        printf("Categoria: %s", tasks[i].category);
        printf("--------------------\n");
    }
}

// Função para deletar uma tarefa com base no índice fornecido
void deletarTarefa(struct Task tasks[], int *numTasks, int index) {
    // Verifica se o índice é válido
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

// Função para alterar os detalhes de uma tarefa
void alterarTarefa(struct Task tasks[], int numTasks) {
    // Verifica se não há tarefas cadastradas
    if (numTasks == 0) {
        printf("Não há tarefas cadastradas.\n");
        return;
    }

    // Solicita o índice da tarefa a ser alterada
    int index;
    printf("Digite o índice da tarefa a ser alterada: ");
    scanf("%d", &index);

    // Verifica se o índice é válido
    if (index < 1 || index > numTasks) {
        printf("Índice inválido.\n");
        return;
    }
    struct Task *task = &tasks[index - 1];

    // Solicita o campo a ser alterado
    int opcao;
    printf("Escolha o campo a ser alterado:\n");
    printf("1. Prioridade\n");
    printf("2. Descrição\n");
    printf("3. Categoria\n");
    printf("4. Estado\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    // Realiza a alteração com base na opção escolhida
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
            getchar();  
            fgets(task->category, sizeof(task->category), stdin);
            break;
        case 4:
            printf("Digite o novo estado: ");
            getchar();  
            fgets(task->estado_tarefa, sizeof(task->estado_tarefa), stdin);
            break;
        default:
            printf("Opção inválida.\n");
    }
}

// Função para filtrar tarefas por prioridade
void filtrarPorPrioridade(struct Task tasks[], int numTasks) {
    // Solicita a prioridade desejada
    int prioridade;
    printf("Digite a prioridade desejada: ");
    scanf("%d", &prioridade);

    // Mostra tarefas com a prioridade especificada
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

// Função para filtrar tarefas por estado
void filtrarPorEstado(struct Task tasks[], int numTasks) {
    // Solicita o estado desejado
    char estado[50];
    printf("Digite o estado desejado: ");
    getchar();
    fgets(estado, sizeof(estado), stdin);
    estado[strlen(estado) - 1] = '\0';  

    // Imprime tarefas com o estado especificado
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

// Função para filtrar tarefas por categoria e exibir ordenadas por prioridade
void filtrarPorCategoria(struct Task tasks[], int numTasks) {
    // Solicita a categoria desejada
    char categoria[100];
    printf("Digite a categoria desejada: ");
    getchar();
    fgets(categoria, sizeof(categoria), stdin);
    categoria[strlen(categoria) - 1] = '\0';  

    // Ordena as tarefas por prioridade
    for (int i = 0; i < numTasks - 1; i++) {
        for (int j = i + 1; j < numTasks; j++) {
            if (tasks[i].priority < tasks[j].priority) {
                struct Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    // Imprime tarefas com a categoria especificada, ordenadas por prioridade
    printf("Tarefas com categoria %s, ordenadas por prioridade:\n", categoria);
    for (int i = 0; i < numTasks; i++) {
        if (strcmp(tasks[i].category, categoria) == 0) {
            printf("Prioridade: %d\n", tasks[i].priority);
            printf("Descrição: %s", tasks[i].description);
            printf("Estado: %s\n", tasks[i].estado_tarefa);
            printf("--------------------\n");
        }
    }
}

// Função para filtrar tarefas por prioridade e categoria
void filtrarPorPrioridadeECategoria(struct Task tasks[], int numTasks) {
    // Solicita a prioridade e a categoria desejadas
    int prioridade;
    char categoria[100];

    printf("Digite a prioridade desejada: ");
    scanf("%d", &prioridade);

    printf("Digite a categoria desejada: ");
    getchar();
    fgets(categoria, sizeof(categoria), stdin);
    categoria[strlen(categoria) - 1] = '\0';  

    // Mostra as tarefas com a prioridade e categoria especificadas
    printf("Tarefas com prioridade %d e categoria %s:\n", prioridade, categoria);
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].priority == prioridade && strcmp(tasks[i].category, categoria) == 0) {
            printf("Descrição: %s", tasks[i].description);
            printf("Estado: %s\n", tasks[i].estado_tarefa);
            printf("--------------------\n");
        }
    }
}

// Funções para exportar tarefas para arquivos, filtradas por prioridade, categoria ou ambos
void exportarPorPrioridade(struct Task tasks[], int numTasks) {
    // Solicita a prioridade desejada para exportação
    int prioridade;
    printf("Digite a prioridade desejada para exportação: ");
    scanf("%d", &prioridade);

    // Abre o arquivo de texto
    FILE *arquivo = fopen("export_por_prioridade.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de exportação.\n");
        return;
    }

    // Escreve as tarefas com a prioridade especificada no arquivo
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].priority == prioridade) {
            fprintf(arquivo, "%d, %s, %s, %s", tasks[i].priority, tasks[i].category, tasks[i].estado_tarefa, tasks[i].description);
            fprintf(arquivo, "\n");
        }
    }

    // Fecha o arquivo de texto
    fclose(arquivo);
    printf("Tarefas exportadas por prioridade com sucesso!\n");
}

void exportarPorCategoria(struct Task tasks[], int numTasks) {
    // Solicita a categoria desejada para exportação
    char categoria[100];
    printf("Digite a categoria desejada para exportação: ");
    getchar();
    fgets(categoria, sizeof(categoria), stdin);
    categoria[strlen(categoria) - 1] = '\0';  

    // Abre o arquivo de exportação
    FILE *arquivo = fopen("export_por_categoria.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de exportação.\n");
        return;
    }

    // Escreve as tarefas com a categoria especificada no arquivo de texto
    for (int i = 0; i < numTasks; i++) {
        if (strcmp(tasks[i].category, categoria) == 0) {
            fprintf(arquivo, "%d, %s, %s, %s", tasks[i].priority, tasks[i].category, tasks[i].estado_tarefa, tasks[i].description);
            fprintf(arquivo, "\n");
        }
    }

    // Fecha o arquivo de texto
    fclose(arquivo);
    printf("Tarefas exportadas por categoria com sucesso!\n");
}

void exportarPorPrioridadeECategoria(struct Task tasks[], int numTasks) {
    // Solicita a prioridade e a categoria desejadas para exportação
    int prioridade;
    char categoria[100];

    printf("Digite a prioridade desejada: ");
    scanf("%d", &prioridade);

    printf("Digite a categoria desejada: ");
    getchar();
    fgets(categoria, sizeof(categoria), stdin);
    categoria[strlen(categoria) - 1] = '\0';  

    // Abre o arquivo de exportação
    FILE *arquivo = fopen("export_por_prioridade_e_categoria.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de exportação.\n");
        return;
    }

    // Escreve as tarefas com a prioridade e categoria especificadas no arquivo de texto
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].priority == prioridade && strcmp(tasks[i].category, categoria) == 0) {
            fprintf(arquivo, "%d, %s, %s, %s", tasks[i].priority, tasks[i].category, tasks[i].estado_tarefa, tasks[i].description);
            fprintf(arquivo, "\n");
        }
    }

    // Fecha o arquivo de texto com as infos salvas
    fclose(arquivo);
    printf("Tarefas exportadas por prioridade e categoria com sucesso!\n");
}
