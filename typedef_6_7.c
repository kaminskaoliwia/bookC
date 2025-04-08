
// typedef is for creating new data type names.

typedef int Length; // makes the name "Length" a synonym to int

typedef struct tnode *Treeptr;

// Przykład na podstawie drzewa
typedef struct tnode {
    char *word; // points to the text
    int count // number of occurance
    Treeptr left; // left child
    Treeptr right; // right child
} Treenode;

/*
 this creates two new type keywords called Treenode (a structure) and Treeptr (a pointer to the structure)
it does not create a new type, adds a new name for some exisisting type,
in effect typedef is like #define but it is interpreted by the compiler no the preprocessor 
*/