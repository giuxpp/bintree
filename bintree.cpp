/* Binary tree generation code in C++*/
/** Include Section */
#include <iostream>

/** Typedefs and structs **/
typedef struct node
{
    int num;
    struct node * R;
    struct node * L;
    struct node * prev;
}nodeType;

/** Local Variables and macros */
using namespace std;

node * pBegin = NULL;

/** Function prototypes **/
node * GetNode(void);
void AddNode (node *, node *&);
int PrintMinor (node *node);
int PrintMayor (node *node);
void PrintFullTree (node *, int);
void RecorridoPreOrden (node *tree);
void RecorridoPostOrden (node *tree);
void RecorridoInOrden (node *tree);
bool Search (int, node *);
void DeleteNode (int n, nodeType *&tree);

node *locNodePtr = pBegin;

/*** MAIN FUNCTION ***/
int main (void)
{
    node *temp_node;

    int size, list[11]={5,4,6,3,7,2,8,1,9,0,10};
    char select;
    system("clear");
    srand(time(NULL));

    /* Llenar arbol con datos random -100 a 100*/
    for (int i = 0; i<sizeof(list)/sizeof(int); i++){
        temp_node = GetNode();
        //temp_node->num = list[i];
        temp_node->num = rand()%200-100;
        AddNode(temp_node, pBegin);
    }

    /* Imprimir todo el arbol */
    cout<<"Printing full tree...\n"<<endl;
    PrintFullTree(pBegin,0);
    cout<<endl;
    
    /* Mostrar menor y mayor */
    cout<<"The minor element is: "<<PrintMinor(pBegin)<<endl;
    cout<<"The minor element is: "<<PrintMayor(pBegin)<<endl;
    
    /* Buscar un elemento */
    int nsearch;
    cout<<"Cual nodo deseas buscar?: "; cin>>nsearch;
    if (Search(nsearch, pBegin)) cout<<"El Elemento "<<nsearch<<" SI se encontró\n";    
    else cout<<"El Elemento "<<nsearch<<" NO se encontró\n";    

    /* Recorridos */
    cout<<"Recorrido en PRE ORDEN:\n";
    RecorridoPreOrden(pBegin); cout<<endl;
    
    cout<<"Recorrido en POST ORDEN:\n";
    RecorridoPostOrden(pBegin); cout<<endl;
    
    cout<<"Recorrido EN ORDEN:\n";
    RecorridoInOrden(pBegin); cout<<endl;

    cin.get();
    return 0;
}
/*********************/

/* Name:    GetNode()   
   Brief: This function returns a new node with an assigned memory 
   Return: returns a pointer to a new node                        */
node* GetNode(void)
{
    node *item = (node*) malloc(sizeof(node));
    item->L = NULL;
    item->R = NULL;
    item->prev = NULL;
    return item;
}

void DeleteNode (int n, nodeType *&tree)
{
    if (!Search(n, pBegin)) cout<<"El numero "<<n<<" No eixste\n";
    else{

    }
}

bool Search (int num, node *tree)
{
    if (!tree){
        return false;
    }
    else if (num == tree->num){
        return true;
    }
    else if (num <= tree->num){
        return Search(num, tree->L);
    }
    else {
        return Search(num, tree->R);
    }
}

void AddNode (node *node, nodeType *&tree)
{
    if (tree){
        if (node->num <= tree->num){            
            AddNode (node, tree->L);
        }
        else {
            AddNode (node, tree->R);            
        }   
    }
    else{
        node->prev = tree;
        tree = node;        
    }
}

int PrintMinor (node *node)
{
    if (!node->L){
        return node->num;
    }
    else {
        return PrintMinor(node->L);
    }
}

int PrintMayor (node *node)
{
    if (!node->R){
        return node->num;
    }
    else {
        return PrintMinor(node->R);
    }
}

void PrintFullTree (node * TreePtr, int cont)
{  /*El arbol se imprimirá en forma horizontal.. Arriba la parte derecha y Abajo la izquieda.. */
    if (TreePtr)
    {        
        PrintFullTree(TreePtr->R,cont+1);  /* Print right side of the tree...*/
        for (int i=0; i<cont; i++){ cout<<"   "; } // agrego espacios segun el elemento para darle orden visual   
        cout<<TreePtr->num<<endl;
        PrintFullTree(TreePtr->L,cont+1);  /* Print right side of the tree...*/
    }
}

void RecorridoPreOrden (node *tree)
{
    if (tree){     
        cout<<tree->num<<"\t";
        RecorridoPreOrden(tree->L);
        RecorridoPreOrden(tree->R);
    }
}
void RecorridoPostOrden (node *tree)
{  
    if (tree){                
        RecorridoPostOrden(tree->L);
        RecorridoPostOrden(tree->R);    
        cout<<tree->num<<"\t";
    }     
}
void RecorridoInOrden(node *tree)
{
    if (tree) {
        RecorridoInOrden(tree->L);
        cout<<tree->num<<"\t";
        RecorridoInOrden(tree->R);
    }
}