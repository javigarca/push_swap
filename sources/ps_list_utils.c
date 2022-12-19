#include "push_swap.h"
t_stack	*ft_build_stack(int *dt)
{
	t_stack *stack;
	t_stack *next_node;
	t_stack *first_node;
	t_stack *last_node;
	int i;

	stack = (t_stack *) malloc(sizeof (t_stack));
	if (!stack)
		ft_exit_error(4);
	stack->data = dt[0];
	stack->next = stack;
	stack->prev = stack;
	first_node = stack;
	i = 1;
	while (dt[i])
	{
		next_node = (t_stack *) malloc(sizeof (t_stack));
		if (!next_node)
			ft_exit_error(4);
		next_node->data = dt[i];
		next_node->next = first_node;
        stack->next = next_node;
        last_node = stack;
        stack = next_node;
        stack->prev = last_node;
		i++;
	}
	last_node = stack;
	stack = stack->next;
    stack->prev = last_node;
    return (stack);
}

/*
   NODO *CrearNodo(int dato);
int InsertarInicio(NODO **cabeza, int dato);
int InsertarFinal(NODO **cabeza, int dato);
void ImprimirLista(NODO *cabeza);
int EliminarNodo(NODO **cabeza, int dato);


int main()
{
    NODO *cabeza = NULL;

    InsertarInicio(&cabeza, 1);
    InsertarInicio(&cabeza, 2);
    InsertarFinal(&cabeza, 3);
    InsertarFinal(&cabeza, 4);
    EliminarNodo(&cabeza, 4);
    ImprimirLista(cabeza);
    system("pause>nul");

    return 0;
}

//FunciÛn para eliminar un nodo de la lista
int EliminarNodo(NODO **cabeza, int dato)
{
    NODO *actual = *cabeza, *ant = NULL, *sig = NULL;

    while(actual != NULL)
    {
        if(actual->dato == dato)
        {
            if( actual == *cabeza)
            {
                *cabeza = actual->siguiente;
                if( actual->siguiente != NULL)
                    actual->siguiente->anterior = NULL;
            }
            else if( actual->siguiente == NULL)
            {
                ant = actual->anterior;
                actual->anterior = NULL;
                ant->siguiente = NULL;
            }
            else
            {
                ant = actual->anterior;
                actual->anterior = NULL;
                sig = actual->siguiente;
                actual->siguiente = NULL;
                ant->siguiente = sig;
                sig->anterior = ant;
            }
            free(actual);
            return 1;
        }
        actual = actual->siguiente;
    }
    return 0;
}

//FunciÛn para insertar al final de la lista
int InsertarFinal(NODO **cabeza, int dato)
{
    NODO *nuevo = NULL, *nAux = *cabeza;

    nuevo = CrearNodo(dato);
    if (nuevo != NULL)
    {
        while(nAux->siguiente != NULL){ nAux = nAux->siguiente;}
        nuevo->anterior = nAux;
        nAux->siguiente = nuevo;
        return 1;
    }
    return 0;
}

//FunciÛn para imprimir la lista
*/
void ft_print_stack(t_stack *stack)
{
    t_stack	*current;

	current = stack;
    printf("%d ", current->data);
    current = current->next;
    while(current != stack)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}
/*
//FunciÛn para insertar al inicio de la lista
int InsertarInicio(NODO **cabeza, int dato)
{
    NODO *nuevo = NULL;

    nuevo = CrearNodo(dato);
    if (nuevo != NULL)
    {
        nuevo->siguiente = *cabeza;
        nuevo->anterior = NULL;
        if( *cabeza != NULL)
            (*cabeza)->anterior = nuevo;
        *cabeza = nuevo;
        return 1;
    }
    return 0;
}

//FunciÛn para crear un nuevo nodo
t_stack	*CrearNodo(int dato)
{
    NODO* nuevo = NULL;

    nuevo = (NODO*)malloc(sizeof(NODO));
    if( nuevo != NULL)
    {
        nuevo->dato = dato;
        nuevo->siguiente = NULL;
        nuevo->anterior = NULL;
    }
    return nuevo;
}
*/
