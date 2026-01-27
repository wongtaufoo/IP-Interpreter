typdef struct Var{
	char name;
	int start;
	int end;
	struct Var* next;
}Var;

struct varNode{
	struct	Var;
	struct *varNode next;
}
