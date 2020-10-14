#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void) {
	system("color 4F");
	char restart;
do{
system("cls");
puts("Pokemon Lovers");
puts("-------------------------------------------------------------------------");
menu();
printf("\n");
printf("\n Para volver al menu presiona 'y', para salir presiona cualquier letra\n");
scanf(" %c", &restart);
}while (restart == 'y');
return 0;
}

menu(){
int option;	
printf(" Digite 1 para comenzar\n Digite 2 para la descripcion del juego\n");
scanf("%i", &option);
switch(option){
	case 1: 
	start();	
    break;

    case 2: 
	description();
    break;
 
}
}

description(){
system("cls");
printf("EL objetivo del juego es adivinar el pokemon del jugador. Si es correcto, el programa dice ¡Lo adivine! y si no, el programa le pedira al jugador el pokemon y una pregunta para identificarlo. Después, reajustara las preguntas con las nuevas opciones.\n");	
}

struct Node { 
    char *data; 
    struct Node* left, *right; 
}; 

struct Node* createNode(char *data) { 
    struct Node* newNode = malloc(sizeof(struct Node)); 
    newNode->data = data; 
    newNode->left = newNode->right = NULL; 
    return newNode; 
} 

void postorderTraversal(struct Node* root) {
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%s ->", root->data);
}

start(){
	system("cls");
	system("color 7C");
	int option, option2, answer, answer2;
	struct Node* root   = createNode("Pikachu"); 
	struct Node* current = root;

	option = ask();
	 
	if(option == 1){
	  while (current != 0) {
		// Si current node tiene hijos es una pregunta
		if (current->left != NULL) {
			option2 = ask();
			if(option2 == 1){
			printf("\n%s?\n", current->data);
			printf("1. Si\t2. No\n");
			scanf("%i", &answer);
			if (answer == 1){
			 current = current->left;
			} else if (answer == 2){
				current = current->right;
			  }
			} else {
			  traversal(root);
			  return 1;
			}
		
		// Si no tiene hijos es una respuesta
		} else {
			printf("\nEs %s?\n", current->data);
			printf("1. Si\t2. No\n");
			scanf("%i", &answer2);
			 if (answer2 == 1) {
			 printf("Adivine! Es %s\n", current->data);
			 return 1;
		   } else {
				// Aprende nuevo pokemon
				learnNewPokemon(current);
			}
		}
      } 
	} else 	{
        traversal(root);
	}
}

traversal(struct Node* root){
	printf("\nPostorder traversal \n");
    postorderTraversal(root);
}

int ask(){
	int option;
	printf("\nEstas pensando en un pokemon?\n");
	printf("1. Si\t2. No\n");
	scanf("%i", &option);
	switch (option){
		case 1:
		return 1;	
        break;

        case 2: 
	    return 0;
        break;
	}
}

learnNewPokemon(struct Node* current){
	char newPokemon[15], newQuestion[20], currentPokemon;
	int option;
	currentPokemon = current->data;
	printf("\nCual era el pokemon?\n");
	scanf("%s", &newPokemon);
	printf("\n Que diferencia a un %s de un %s?\n", current->data, newPokemon);	
	scanf(" %[^\t\n]s", &newQuestion);
	struct Node* node1 = createNode(newPokemon);
	node1->data = (char *) malloc(25);
	strcpy(node1->data,newPokemon);
	struct Node* node2 = createNode(current->data);
	printf("\nSi el pokemon es %s cual seria la respuesta?\n", current->data);
	printf("1. Si\t2. No\n");
	scanf("%i", &option);
    if (option == 2){
		current->left = node1;
		current->right = node2;
		} else {
	    current->left= node2;
		current->right = node1;
	     }
       
   current->data = (char *) malloc(20);
   strcpy(current->data,newQuestion);	
}
