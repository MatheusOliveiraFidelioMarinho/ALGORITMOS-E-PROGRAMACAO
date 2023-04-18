int main(){
	int n1 = 0, n2 = 0;
	char operador;
	
	printf("---CALC---\n");
	
	printf("Informe a n1: ");
	scanf("%d", &n1);
	
	printf("Informe a operacao: ");
	scanf(" %c", &operador);
	
	printf ("informe n2: ");
	scanf("%d", &n2);
	
	if(operador == '+'){
		printf("SOMA: %d", n1+n2);
	}else{
		if(operador == '-'){
			printf("SUB: %d", n1-n2);
		}else{
		}
	}
	return 0;
}
