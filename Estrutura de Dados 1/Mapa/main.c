#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

typedef struct {
    Node* top;
} Stack;

void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

void enqueue(Queue* queue, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro: falha na alocação de memória\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (queue->front == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

char dequeue(Queue* queue) {
    if (queue->front == NULL) {
        return '\0';
    }

    Node* temp = queue->front;
    char data = temp->data;

    queue->front = queue->front->next;
    free(temp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return data;
}

void printQueue(Queue* queue) {
    Node* current = queue->front;

    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }

    printf("\n");
}

void initStack(Stack* stack) {
    stack->top = NULL;
}

void push(Stack* stack, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro: falha na alocação de memória\n");
        return;
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

char pop(Stack* stack) {
    if (stack->top == NULL) {
        return '\0';
    }

    Node* temp = stack->top;
    char data = temp->data;

    stack->top = stack->top->next;
    free(temp);

    return data;
}

void printStack(Stack* stack) {
    Node* current = stack->top;

    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }

    printf("\n");
}

void convertDNA(Queue* dnaQueue, Stack* dnaStack) {
    char complement;
    char base;

    while (dnaQueue->front != NULL) {
        base = dequeue(dnaQueue);

        switch (base) {
            case 'A':
                complement = 'T';
                break;
            case 'T':
               complement = 'A';
                break;
            case 'C':
                complement = 'G';
                break;
            case 'G':
                complement = 'C';
                break;
            default:
                continue; // Ignorar nucleotídeo inválido
        }

        push(dnaStack, complement);
    }
}

int main() {
    Queue dnaQueue;
    Stack dnaStack;

    initQueue(&dnaQueue);
    initStack(&dnaStack);

    // Ler a entrada de DNA
    char dna[100];
    printf("Digite a sequencia de DNA: ");
    fgets(dna, sizeof(dna), stdin);

    // Armazenar na fila
    int i = 0;
    while (dna[i] != '\0' && dna[i] != '\n') {
        enqueue(&dnaQueue, dna[i]);
        i++;
    }

    // Converter para a dupla fita do DNA
    convertDNA(&dnaQueue, &dnaStack);

    // Imprimir a fila e a pilha
    printf("Fila original: ");
    printQueue(&dnaQueue);

    printf("Pilha convertida: ");
    printStack(&dnaStack);

    return 0;
}
