typdef struct Var{
	char name;
	int start;
	int end;
}Var;

struct varNode{
	struct	Var;
	struct *varNode next;
}
